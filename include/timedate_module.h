#ifndef TIMEDATE_MODULE_H
#define TIMEDATE_MODULE_H

#include "module.h"
#include "lyonsSDL.h"
#include <ctime>
#include <sstream>

using namespace std;

class timedate_module : public module
{
    public:
        lyons_text th;
        lyons_text largeth;

        timedate_module();

        void draw(SDL_Surface *screen, int x, int y);

        void update();
    protected:
    private:
};

#endif // TIMEDATE_MODULE_H
