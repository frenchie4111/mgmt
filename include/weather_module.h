#ifndef WEATHER_MODULE_H
#define WEATHER_MODULE_H

#include "module.h"
#include <vector>

class weather_module:public module
{
    public:
        int limiter;
        string current_image_name;

        vector< string > weather;

        lyons_text mediumth;
        lyons_text largeth;

        SDL_Surface *weather_image;

        weather_module();

        string get_weather_info(string search);

        bool update_weather();
        void update_weather_image();
        void update();

        void draw(SDL_Surface *screen, int x, int y);
    protected:
    private:
};

#endif // WEATHER_MODULE_H
