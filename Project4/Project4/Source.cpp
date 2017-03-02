#include <stdlib.h>
#include "SDL/include/SDL.h"

#pragma comment( lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib")

int main(int argc, char* argv[])
{
	SDL_Surface *surface;
	Uint32 rmask, gmask, bmask, amask;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event Press_Esc_Event;
	bool quit = false;

	SDL_Init(SDL_INIT_EVERYTHING);
	
	// Create a rectangle
	SDL_Rect r;
	r.x = 50;
	r.y = 50;
	r.w = 50;
	r.h = 50;

	SDL_CreateWindowAndRenderer(1000, 700, SDL_WINDOW_RESIZABLE, &window, &renderer);

	while (quit == false)
	{
		
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		/* Clear the entire screen to our selected color. */
		SDL_RenderClear(renderer);

		/* Up until now everything was drawn behind the scenes.
		This will show the new, red contents of the window. */



		// Clear the window and make it all red
		SDL_RenderClear(renderer);

	

		// Change color to blue!
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

		// Render our SDL_Rect
		// The rectangle will now be blue
		SDL_RenderFillRect(renderer, &r);

		// Render the changes above
		SDL_RenderPresent(renderer);

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_UP:
					r.y--;
					break;
				case SDLK_LEFT:
					r.x--;
					break;
				case SDLK_RIGHT:
					r.x++;
					break;
				case SDLK_DOWN:
					r.y++;
					break;
				case SDLK_ESCAPE: quit = true;
					break;
				}
				break;
			}
		

		}

	}

	SDL_Quit();
	
	return(0);
}

