#ifndef AGENDA_MODULE_H
#define AGENDA_MODULE_H

#include <vector>

#include <module.h>
#include "lyonsSDL.h"

class agenda_module : public module
{
    public:
        vector< string > agenda;

        lyons_text mediumth;

        agenda_module();

        void update_agenda();
        void update();

        void draw(SDL_Surface *screen, int x, int y);
    protected:
    private:
};

#endif // AGENDA_MODULE_H
