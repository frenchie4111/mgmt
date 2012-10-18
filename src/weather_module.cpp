#include "weather_module.h"

#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

bool file_exists(string filename)
{
  ifstream ifile(filename.c_str());
  return ifile;
}
weather_module::weather_module():module(140, 225, "Weather")
{
    update_weather();
    update_weather_image();

    mediumth = lyons_text(20);
    largeth = lyons_text(40);
    limiter = 0;
}

string weather_module::get_weather_info(string search)
{
    int index = -411;
    for(int i = 0; i < weather.size(); i++)
    {
        if(weather[i].find(search) < weather[i].size())
        {
            index = i;
            break;
        }
    }
    if(index == -411)
    {
        return "No";
    }
    else
    {
        string out = weather[index];
        out.replace(out.find("</" + search), out.length() , "");
        out.replace(0, out.find(search + ">") + search.length() + 1, "");
        return out;
    }
}

bool weather_module::update_weather()
{
    system("wget -O art/weather.txt http://w1.weather.gov/xml/current_obs/KROC.xml");

    vector<string> lines;

    string path = "art/weather.txt";

    fstream f(path.c_str(), fstream::in | fstream::out);
    string line;
    int line_num = 0;
    while(getline(f,line))
    {
            if(line_num > 19)
            {
                lines.push_back(line);
            }
            line_num++;

            //cout << ++temp << line << endl;
            line.clear();
    }
    f.close();

    bool out = false;
    if(weather == lines)
    {
        out = true;
    }
    else
        weather = lines;
    return out;
}
void weather_module::update_weather_image()
{
    string image_name = get_weather_info("icon_url_name");
    string image_base_url = get_weather_info("icon_url_base");
    cout << "Weather Image name: " << image_name << endl;
    if(!(image_name == current_image_name))
    {
        string image_type = image_name.substr(image_name.length()-4, 4);
        if(!file_exists("art/" + image_name))
        {
            string cmd = "wget -O art/" + image_name + " " + image_base_url + image_name;
            cout << "Weather Image download with: " << cmd << endl;
            system(cmd.c_str());
        }
        else
        {
            cout << "File already existed: " << image_name << endl;
        }

        weather_image = IMG_Load(("art/" + image_name).c_str());
    }
}
void weather_module::update()
{
    if(limiter > 200)
    {
        if(update_weather())
        {
            update_weather_image();
        }
        limiter = 0;
    }
    limiter ++;
}

void weather_module::draw(SDL_Surface *screen, int x, int y)
{
    cout << "       drawing parent" << endl;
    module::draw(screen, x, y);

    cout << "       drawing Current Conditions" << endl;
    th.paint_text_center(x+70, y+13, "Current Conditions", screen);
    apply_surface(x+70 - (weather_image->w/2), y+28, weather_image, screen);
    th.paint_text_center(x+70, y+90, get_weather_info("weather"), screen);

    cout << "       drawing Current Temperature" << endl;
    th.paint_text_center(x+70, y+115, "Current Temperature", screen);
    largeth.paint_text_center(x+70, y+123, get_weather_info("temp_f") + " F" , screen);

    cout << "       drawing Current Humidity" << endl;
    th.paint_text_center(x+70, y+173, "Current Humidity", screen);
    largeth.paint_text_center(x+70, y+181, get_weather_info("relative_humidity") + "%", screen);
}
