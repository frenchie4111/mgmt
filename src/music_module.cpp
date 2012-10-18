#include "music_module.h"

music_module::music_module():module(400, 430, "FooBar2000 Now Playing")
{
    limiter = 0;

    mediumth = lyons_text(20);

    albumart = mf.get_updated_art();
    songtitle = mf.get_musictitle();
    albumartimg = scale_load_image(albumart, 400, 400);
}

music_module::music_module( settings_handler settings ):module(400, 430, "FooBar2000 Now Playing")
{
    mf = music_file(settings);

    limiter = 0;

    mediumth = lyons_text(20);

    albumart = mf.get_updated_art();
    songtitle = mf.get_musictitle();
    albumartimg = scale_load_image(albumart, 400, 400);
}

void music_module::draw(SDL_Surface *screen, int x, int y)
{
    module::draw(screen, x, y);

    cout << "       Drawing albumart" << endl;
    apply_surface(x, y+30, albumartimg, screen);
    cout << "       Drawing songitlte" << endl;

    mediumth.paint_text_center(x+200, y+10, songtitle, screen);
}

void music_module::update()
{
    //albumart = mf.get_updated_art();

    if(limiter < 50)
    {
        limiter++;
    }
    else
    {
        albumart = mf.get_updated_art();
        cout << "Albumart: " << albumart << endl;
        songtitle = mf.get_musictitle();
        cout << "Update check" << endl;
        if(albumart != "")
        {
            cout << "About to show ASDFGH: " << albumart;
            albumartimg = scale_load_image(albumart, 400, 400);
        }
        limiter = 0;
    }
}
