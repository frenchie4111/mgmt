#include "todo_module.h"

todo_module::todo_module():module(250, 310, "To Do")
{
    limiter = 0;
    scroll = 0;
    mediumth = lyons_text(15);
    update_list();
}
void todo_module::update_list()
{
    string cmd = "wget --quiet -O art/list.txt 'http://108.40.20.52/share/list/list.php'";
    system(cmd.c_str());

    vector<string> lines;

    string path = "art/list.txt";

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

    items = lines;
}
void todo_module::update()
{
    if(limiter > 200)
    {
        update_list();
        limiter = 0;
    }
    if(limiter % 50 == 0)
    {
        if(items.size() > 20)
        {
            scroll ++;
            if(scroll > items.size()-20)
            {
                scroll = 0;
            }
        }
        else
            scroll = 0;
    }
    limiter++;


}
void todo_module::draw(SDL_Surface *screen, int x, int y)
{
    module::draw(screen, x, y);
    int list_item_count = 0;
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i] != "" && items[i] != "\n")
        {
            if(i < 20)
            {
                if(list_item_count % 2 != 0)
                {
                    boxRGBA(screen, x, y+(list_item_count*15)+10, x+250, y+(list_item_count*15)+25, 20, 20, 20, 255);
                }
                mediumth.paint_text(x, y+(list_item_count*15)+10, " -" + items[i+scroll], screen);
            }
            list_item_count++;
        }
    }
}
