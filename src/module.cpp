#include "module.h"

module::module()
{
    w = 400;
    h = 400;
    name = "lame";
    limiter = 0;
}
module::module(int nw, int nh, string nname)
{
    w = nw;
    h = nh;
    name = nname;
    limiter = 0;
}
void module::draw(SDL_Surface *screen, int x, int y)
{
    boxRGBA(screen, x, y+10, x+w, y+h, 50, 50, 50, 255);
    boxRGBA(screen, x, y, x+w, y+10, 0, 0, 0, 255);

    th.paint_text_center(x+w/2, y, name, screen);
}
