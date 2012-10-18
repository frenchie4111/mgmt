#include <settings_handler.h>

settings_handler::settings_handler()
{
	load_settings();
}

void settings_handler::load_settings()
{
	vector< string > file_vector = loadFile("settings.dat");

	for(int i = 0; i < file_vector.size(); i++)
	{
		string file_line = file_vector[i];
		string setting_name = file_line.substr(0, file_line.find(" "));
		string setting_value = file_line.substr(file_line.find(" ")+1);
		settings[setting_name] = setting_value;
	}
}

string settings_handler::get_setting(string setting_name)
{
	if( settings.count(setting_name) > 0 )
	{
		return settings.find(setting_name)->second;
	}
	else
	{
		throw;
	}
}