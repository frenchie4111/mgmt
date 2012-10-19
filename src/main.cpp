#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>

#include <iostream>
#include <sstream>
#include <ctime>

#include "music_file.h"
#include "module_handler.h"
#include "lyonsSDL.h";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    

using namespace std;
int main ( int argc, char** argv )
{
    //Start my stuff

    module_handler mine;

    //End my stuff; start SDL stuff

    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    atexit(SDL_Quit);

    SDL_Surface* screen = SDL_SetVideoMode(1280, 800, 16, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);

    //End SDL stuff; start main loop

    bool done = false;
    while (!done)
    {
        //SDL_ShowCursor( SDL_DISABLE );
        //Start event (For closing) stuff

        SDL_Event event;
        if(SDL_PollEvent( &event ))
        {
            if(event.type == SDL_QUIT)
            {
                done = true;
            }
        }

        //End event stuff; Start input keys

        Uint8 *keystates = SDL_GetKeyState( NULL );
        if(keystates[ SDLK_ESCAPE ])
        {
            done = true;
        }

        //End input keys; Start drawing things

        //SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 40, 40, 40));

        cout << "Updating" << endl;
        mine.update();

        cout << "Drawing" << endl;
        mine.draw(screen);

        SDL_Flip(screen);
    }

    //End main loop; clean up
    printf("Exited cleanly\n");//*/
    return 0;
}
