#ifndef LYONSSDL_HPP
#define LYONSSDL_HPP
#include <SDL/SDL.h>
#include <string>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

bool init(SDL_Surface *screen, int width, int height, std::string message);
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination);
void apply_surface(int srcx, int srcy, int srcw, int srch, int x, int y, SDL_Surface* source, SDL_Surface* destination);
SDL_Surface *load_image( std::string filename );
SDL_Surface *load_image( std::string filename , bool optimize);
SDL_Surface *scale_load_image( std::string filename, int x, int y);
class lyons_text
{
    public:
        TTF_Font *font;
        SDL_Color textColor;
        int current_size;
        lyons_text();
        lyons_text(int size);
        void paint_text(int x, int y, string text, SDL_Surface *screen);
        void paint_text_center(int x, int y, string text, SDL_Surface *screen);
};
vector< string > loadFile(string path);

#endif // LYONSSDL_HPP
