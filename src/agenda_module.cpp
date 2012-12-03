#include "agenda_module.h"

#include "pstream.h"

agenda_module::agenda_module():module(250,400,"Daily Agenda")
{
    update_agenda();
    mediumth = lyons_text(15);
}

void agenda_module::update_agenda()
{
    vector<string> lines;
    redi::ipstream in("ls ./*.h");
    std::string str;
    while (std::getline(in, str)) 
    {
        std::cout << str << std::endl;
        lines.push_back(str)
    }
    agents = lines;
}
void agenda_module::update()
{
    if(limiter > 200)
    {
        update_agenda();
        limiter = 0;
    }
    limiter ++;
}

void agenda_module::draw(SDL_Surface *screen, int x, int y)
{
    module::draw(screen, x, y);

    for(int i = 0; i < agenda.size()-2; i++)
    {
        if(i % 2 != 0)
        {
            boxRGBA(screen, x, y+(i*30)+11, x+250, y+(i*30)+41, 20, 20, 20, 255);
        }
        mediumth.paint_text(x+2, y+11+(i * 30), agenda[i+2].substr(0, agenda[i+2].find(",")), screen);
        mediumth.paint_text(x+2, y+26+(i * 30), agenda[i+2].substr(agenda[i+2].find(",")+1), screen);
    }
}
