#include <SDL2/SDL.h>
#include <stdio.h>

void                        setPixelColor(SDL_Surface* screen)
{
	Uint8* pixels;
	Uint8* pixel;
	
	pixels = (Uint8*)(screen->pixels);

	for (int j = 3; j < 40; ++j)
	{
		pixel = pixels + ((screen->pitch*j) + 300);

		for (int i = 0; i < 2000; ++i)
		{
			++pixel;
			*pixel =  255;
		}
	}
}

int 						main()
{
	SDL_Window*		window;
	SDL_Surface*	screen;
	SDL_Event		event;
	int				is_running;

	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return 1;
	}
 
	window =  SDL_CreateWindow(	"First SDL Window",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								1000,
								600,
								SDL_WINDOW_RESIZABLE );

	is_running = 1;

	screen = SDL_GetWindowSurface(window);
	screen->format->BitsPerPixel = 8;
	screen->format->BytesPerPixel = 1;

	setPixelColor(screen);

	SDL_UpdateWindowSurface(window);

	while (is_running)
	{
		while(SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
				is_running = 0;
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
