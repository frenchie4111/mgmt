#include "lyonsSDL.h"

using namespace std;
//My main SDL functions

bool init(SDL_Surface *screen, int width, int height, std::string message)
{
    SDL_Init( SDL_INIT_VIDEO );
    SDL_WM_SetCaption( message.c_str(), NULL );
    return true;
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, NULL, destination, &offset);
}
void apply_surface(int sx, int sy, int sw, int sh, int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
    SDL_Rect srcoffset;
    srcoffset.x = sx;
    srcoffset.y = sy;
    srcoffset.w = sw;
    srcoffset.h = sh;
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, &srcoffset, destination, &offset);
}

SDL_Surface *load_image( std::string filename )
{
    SDL_Surface* loadedImage = NULL;

    SDL_Surface* optimizedImage = NULL;

    loadedImage = SDL_LoadBMP( filename.c_str() );

    if( loadedImage != NULL)
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        if( optimizedImage != NULL )
        {
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0xFF, 0, 0xFF );
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }

        SDL_FreeSurface( loadedImage );
    }

    return optimizedImage;
}
SDL_Surface *load_image( std::string filename, bool optimize)
{
    SDL_Surface* loadedImage = NULL;

    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load( filename.c_str() );

    if(optimize)
    {
        if( loadedImage != NULL)
        {

                /*Uint32 colorkey = SDL_MapRGB( loadedImage->format, 0xFF, 0, 0xFF );
                SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY , colorkey );
                optimizedImage = SDL_DisplayFormatAlpha( loadedImage );
                //SDL_FreeSurface( loadedImage );
                return optimizedImage;
*/
        }
    }

    return loadedImage;
}
SDL_Surface *load_image( std::string filename , bool derp, bool derp2)
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image using SDL_image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }

    //Return the optimized image
    return optimizedImage;
}

lyons_text::lyons_text()
{
    TTF_Init();
    font = TTF_OpenFont( "arial.ttf", 10 );
    current_size = 10;
    textColor = {150, 150, 150};
}
lyons_text::lyons_text(int size)
{
    TTF_Init();
    font = TTF_OpenFont( "arial.ttf", size );
    current_size = 10;
    textColor = {150, 150, 150};
}
void lyons_text::paint_text(int x, int y, string text, SDL_Surface *screen)
{
    SDL_Surface *messagey;
    messagey = TTF_RenderText_Solid( font, text.c_str(), textColor );
    apply_surface(x, y, messagey, screen);
    SDL_FreeSurface(messagey);
}
void lyons_text::paint_text_center(int x, int y, string text, SDL_Surface *screen)
{
    SDL_Surface *messagey;
    messagey = TTF_RenderText_Solid( font, text.c_str(), textColor );
    apply_surface(x-(messagey->w/2), y, messagey, screen);
    SDL_FreeSurface(messagey);
}

vector< string > loadFile(string path)
{
    vector<string> lines;

    string anm = path;

    fstream f (anm.c_str(), fstream::in | fstream::out);
    string line;
    while(getline(f,line))
    {
        lines.push_back(line);
        line.clear();
    }
    f.close();

    return lines;
}
SDL_Surface *scale_load_image( std::string filename, int x, int y)
{
    SDL_Surface* loadedImage = NULL;

    loadedImage = IMG_Load( filename.c_str() );

    loadedImage = zoomSurface( loadedImage , (1-((((double)loadedImage->w)-x)/(loadedImage->w))), (1-((((double)loadedImage->h)-y)/(loadedImage->h))), 1);

    return loadedImage;
}
