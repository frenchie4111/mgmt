#include "music_module.h"

music_module::music_module():module(400, 430, "FooBar2000 Now Playing")
{
    limiter = 0;
    draw_check = false;
    file_check = false;

    mediumth = lyons_text(20);

    file_check = mf.update_file();
    
    if( file_check )
    {
        mf.update_vector();

        if( mf.get_info("\"isPlaying\"") == "1" )
        {
            albumart = mf.get_updated_art();
            songtitle = mf.get_musictitle();
            albumartimg = scale_load_image(albumart, 400, 400);
            draw_check = true;
        }
    }
}

music_module::music_module( settings_handler settings ):module(400, 430, "FooBar2000 Now Playing")
{
    mf = music_file(settings);

    music_module();
}

void music_module::draw(SDL_Surface *screen, int x, int y)
{
    module::draw(screen, x, y);
    if( file_check && draw_check )
    {
        cout << "       Drawing albumart" << endl;
        apply_surface(x, y+30, albumartimg, screen);
        cout << "       Drawing songitlte" << endl;

        mediumth.paint_text_center(x+200, y+10, songtitle, screen);
    }
}

void music_module::update()
{
    if(limiter < 50)
    {
        limiter++;
    }
    else
    {
        file_check = mf.update_file();
        if( file_check )
        {
            mf.update_vector();
            if( mf.get_info("\"isPlaying\"") == "1" )
            {
                albumart = mf.get_updated_art();
                cout << "Albumart: " << albumart << endl;
                songtitle = mf.get_musictitle();
                cout << "Update check" << endl;
                if(albumart != "" && albumart != "No")
                {
                    cout << "About to show ASDFGH: " << albumart;
                    albumartimg = scale_load_image(albumart, 400, 400);
                }
                draw_check = true;
            }
            else
            {
                draw_check = false;
            }
            limiter = 0;
        }
        else
            cout << "   Not drawing mm" << endl;
    }
}
