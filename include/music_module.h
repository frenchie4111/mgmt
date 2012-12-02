#ifndef MUSIC_MODULE_H
#define MUSIC_MODULE_H


#include "module.h"
#include "music_file.h"
#include "settings_handler.h"

class music_module : public module
{
    public:
        music_file mf;
        lyons_text th;
        lyons_text mediumth;

        string albumart;
        SDL_Surface *albumartimg;
        string songtitle;

        int limiter;
        bool draw_check;
        bool file_check;

        music_module();
        music_module(settings_handler settings);

        void draw(SDL_Surface *screen, int x, int y);

        void update();
    protected:
    private:
};

#endif // MUSIC_MODULE_H
