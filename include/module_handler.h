#ifndef MODULE_HANDLER_H
#define MODULE_HANDLER_H

#include <vector>
#include <tr1/memory>

#include <SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_gfxPrimitives.h>

#include "lyonsSDL.h"
#include "module.h"
#include "music_module.h"
#include "music_file.h"
#include "timedate_module.h"
#include "todo_module.h"
#include "weather_module.h"
#include "agenda_module.h"

using namespace std;

class module_handler
{
    public:
        Uint32 startTime; //for fps
        int numFrames;

        music_module mm;
        timedate_module tdm;
        todo_module todom;
        weather_module wm;
        agenda_module am;

        lyons_text th;

        module_handler();

        void draw(SDL_Surface *screen);

        void update();
    protected:
    private:
};

#endif // MODULE_HANDLER_H
