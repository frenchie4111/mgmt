#ifndef TODO_MODULE_H
#define TODO_MODULE_H

#include "lyonsSDL.h"

#include "module.h"

class todo_module : public module
{
    public:
        int limiter;
        lyons_text mediumth;
        vector< string > items;

        int scroll;

        todo_module();

        void update_list();
        void update();

        void draw(SDL_Surface *screen, int x, int y);
    protected:
    private:
};

#endif // TODO_MODULE_H
