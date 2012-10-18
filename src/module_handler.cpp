#include "module_handler.h"

module_handler::module_handler()
{
}

void module_handler::draw(SDL_Surface *screen)
{
    cout << "   Drawing fill" << endl;
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 80, 80, 80));
    cout << "   Drawing top rect" << endl;
    boxRGBA(screen, 0, 0, 1280, 10, 0, 0, 0, 255);
    cout << "   Drawing text" << endl;
    //paintText(0,0,10,"mgmt - lyons", screen);
    th.paint_text_center(1280/2,0, "mgmt - lyons", screen);

    float fps = ( numFrames / ((float)SDL_GetTicks() - startTime) ) * 1000;

    stringstream ss;
    ss << fps;
    string derp;
    ss >> derp;
    string derp2 = "fps: " + derp;

    th.paint_text(0, 0, derp2, screen);

    if(numFrames > 50)
    {
        numFrames = 0;
        startTime = SDL_GetTicks();
    }
    numFrames++;

    mm.draw(screen, 10, 20);
    cout << "   Drawing tdm" << endl;
    tdm.draw(screen, 420, 20);
    cout << "   Drawing todom" << endl;
    todom.draw(screen, 420, 80);
    cout << "   Drawing wm" << endl;
    wm.draw(screen, 680, 80);
    cout << "   Drawing am" << endl;
    am.draw(screen, 830, 20);
}
void module_handler::update()
{
    mm.update();
    todom.update();
    wm.update();
    am.update();
}
