#ifndef MUSIC_MODULE_H
#define MUSIC_MODULE_H


#include "module.h"
#include "music_file.h"

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

        music_module();

        void draw(SDL_Surface *screen, int x, int y);

        void update();
    protected:
    private:
};

#endif // MUSIC_MODULE_H
