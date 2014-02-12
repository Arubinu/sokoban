/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 21:43:56 by apergens          #+#    #+#             */
/*   Updated: 2014/01/24 16:03:39 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

static int	ft_sdkn_video(t_game *game, char *title);
static int	ft_sdkn_audio(Mix_Music **sound, char *file);
static int	ft_sdkn_image(void);
static int	ft_sdkn_text(void);

int			main()
{
	t_game		game;
	Mix_Music	*sound;

	if (ft_sdkn_video(&game, "Sodokan"))
		return (EXIT_FAILURE);
	if (ft_sdkn_audio(&sound, "content/sounds/trance.wav"))
		return (EXIT_FAILURE);
	if (ft_sdkn_image() || ft_sdkn_text())
		return (EXIT_FAILURE);
	SDL_SetWindowTitle(game.win, "Sodokan");
	game.icon = IMG_Load("content/icons/200r.png");
	SDL_SetWindowIcon(game.win, game.icon);
	ft_sdkn_create_cube(&game.cube, 7);
	ft_sdkn_call_game(&game);
	ft_sdkn_free_cube(&game.cube, 7);
	TTF_Quit();
	IMG_Quit();
	if (sound != NULL)
		Mix_FreeMusic(sound);
	Mix_CloseAudio();
	if (game.image.surf != NULL)
		SDL_FreeSurface(game.image.surf);
	SDL_DestroyRenderer(game.render);
	SDL_DestroyWindow(game.win);
	SDL_Quit();
	return (EXIT_SUCCESS);
}

static int	ft_sdkn_video(t_game *game, char *title)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
	{
		ft_printf("SDL Error Load : %s\n", STDERR_FILENO, SDL_GetError());
		return (1);
	}
    game->win = SDL_CreateWindow(title, WIN_P, WIN_P, WIN_W, WIN_H, WIN_S);
	if (!game->win)
	{
		ft_printf("SDL Error Load Video : %s\n", STDERR_FILENO, SDL_GetError());
		return (1);
	}
	game->render = SDL_CreateRenderer(game->win, -1, WIN_R);
	game->image.surf = SDL_GetWindowSurface(game->win);
	return (0);
}

static int	ft_sdkn_audio(Mix_Music **sound, char *file)
{
	if (access(file, R_OK) < 0)
		return (0);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0)
	{
		ft_printf("SDL Error Load Audio : %s\n", STDERR_FILENO, Mix_GetError());
		return (1);
	}
	if ((*sound = Mix_LoadMUS(file)) == NULL)
	{
		ft_printf("SDL Error Load Audio : %s\n", STDERR_FILENO, file);
		return (1);
	}
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
	Mix_PlayMusic(*sound, -1);
	/*
	Mix_ResumeMusic()
	Mix_PauseMusic()
	Mix_PausedMusic() -> 1
	Mix_PlayingMusic() -> 1
	*/
	return (0);
}

static int	ft_sdkn_image(void)
{
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != (IMG_INIT_JPG | IMG_INIT_PNG))
	{
		ft_printf("SDL Error Load Image : %s\n", STDERR_FILENO, IMG_GetError());
		return (1);
	}
	return (0);
}

static int	ft_sdkn_text(void)
{
	if(TTF_Init() == -1)
	{
		ft_printf("SDL Error Load TTF : %s\n", STDERR_FILENO, TTF_GetError());
		return (1);
	}
	return (0);
}
