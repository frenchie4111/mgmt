#ifndef MODULE_H
#define MODULE_H

#include "lyonsSDL.h"

class module
{
    public:
        int w, h;
        string name;
        lyons_text th;
        int limiter;
        module();
        module(int nw, int nh, string nname);

        virtual void update() = 0;

        virtual void draw(SDL_Surface *screen, int x, int y);
    protected:
    private:
};

#endif // MODULE_H
