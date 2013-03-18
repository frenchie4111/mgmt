#include "timedate_module.h"

timedate_module::timedate_module():module(600, 200, "Time/Date")
{
    th = lyons_text(20);
    largeth = lyons_text(180);
}
void timedate_module::update()
{

}
void timedate_module::draw(SDL_Surface *screen, int x, int y)
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    stringstream ss1;
    stringstream ss2;
    stringstream ss3;
    stringstream ss4;
    stringstream ss5;

    string tempyear;
    string tempmonth;
    string tempday;
    string tempmin;
    string temphour;

    ss1 << (now->tm_year + 1900);
    ss1 >> tempyear;

    ss2 << (now->tm_mon + 1);
    ss2 >> tempmonth;

    ss3 << (now->tm_mday);
    ss3 >> tempday;

    ss4 << (now->tm_min);
    ss4 >> tempmin;
    if(tempmin.length() == 1)
    {
        tempmin = "0" + tempmin;
    }

    ss5 << ((now->tm_hour%12 == 0)?12:now->tm_hour%12);

    ss5 >> temphour;

    module::draw(screen, x, y);
    largeth.paint_text_center(x+300, y+10, temphour + ":" + tempmin, screen);
    th.paint_text_center(x+300, y+180, tempday + "/" + tempmonth + "/" + tempyear, screen);
}
