#include "agenda_module.h"

agenda_module::agenda_module():module(250,400,"Daily Agenda")
{
    update_agenda();
    mediumth = lyons_text(15);
}

void agenda_module::update_agenda()
{
    system("google calendar today > art/agenda.txt");

    vector<string> lines;

    string path = "art/agenda.txt";

    fstream f(path.c_str(), fstream::in | fstream::out);
    string line;
    int temp = 0;
    while(getline(f,line))
    {
            lines.push_back(line);
            //cout << ++temp << line << endl;
            line.clear();
    }
    f.close();

    agenda = lines;
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
