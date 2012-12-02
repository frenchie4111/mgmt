#ifndef MUSIC_FILE_H
#define MUSIC_FILE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>

#include "settings_handler.h"

using namespace std;

class music_file 
{
	string file_location;
	string last_downloaded;
	vector<string> file_vector;
	public:
        string ip;
        bool file_exists(string filename)
        {
          ifstream ifile(filename.c_str());
          return ifile;
        }
		music_file()
		{
			file_location = "this.txt";
			ip = "alaska4.student.rit.edu";
		}
		music_file(settings_handler settings)
		{
			file_location = "this.txt";
			ip = settings.get_setting("MUSIC_IP");
		}
		void update_file()
		{
		    cout << "About to download" << endl;
			string cmd = "wget --quiet -O art/" + file_location + " 'http://"+ip+"/ajquery/?cmd=&param1=&param3=js%2Fstate.json'";
			cout << "Got new this.txt" << endl;
			system(cmd.c_str());
			//system("wget --quiet -O this.txt 'http://mike.bluefile.org/ajquery/?cmd=&param1=&param3=js%2Fstate.json' >> /dev/null");
		};
		void update_vector() //To be called after file is updated
		{
			vector<string> lines;

            string path = "art/this.txt";

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

			file_vector = lines;
		}
		string get_musictitle() //Already update the shit please
		{
			//return file_vector[26].substr(11,file_vector[26].find("\",")-11);
			return get_info( "\"helper2\"" );
		}
		string get_artlink() //Already update the shit idiot
		{
			return get_info( "\"albumArt\"" );
		}
		string get_info( string search ) //update the file, please. Don't be stupid
		{
			int index = -411;
		    for(int i = 0; i < file_vector.size(); i++)
		    {
		        if(file_vector[i].find(search) < file_vector[i].size())
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
		        string out = file_vector[index];
		        out.replace(0, out.find(search + ":\"") + search.length() + 2 , "");
		        out.replace(out.length()-2, out.length(), "");
		        if( out.find("\"") < out.length() )
		        {
		        	out.replace(out.find("\""), out.find("\"")+1 , "");
		        }
		        return out;
		    }
		}
		string download_art()
		{
		    string url = get_artlink();
		    if( url != "No" )
		    {
			    string filename = url.substr(9, url.length()-9);
			    if(filename == "img/icon1rx.png")
	                    filename = "icon1rx.png";
			    if(last_downloaded != filename)
			    {
	                //cout << type;
	                cout << last_downloaded << " : " << filename << endl;
	                if(!file_exists("art/" + filename))
	                {
	                    string cmd = "wget --quiet -O art/" + filename + " http://" + ip + url;
	                    cout << "Got new image: " << filename << endl;
	                    //cout << cmd << endl;
	                    system(cmd.c_str());
	                }
	                else
	                {
	                    cout << "File already existed" << endl;
	                }
	                last_downloaded = filename;
	                cout << "Changing to: art/" << filename << endl;
	                return "art/" + filename;
			    }
			    else
	                return "";
	        }
	        else
	        	return "No";
		}
		string get_updated_art()
		{
		    //update_file();
		    //update_vector();
		    return download_art();
		}
};

#endif
