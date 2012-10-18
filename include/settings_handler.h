#ifndef SETTINGS_HANDLER_H
#define SETTINGS_HANDLER_H

#include <map>
#include <iostream>

#include "lyonsSDL.h"

using namespace std;

class settings_handler
{
	public:
		map< string, string > settings;

		settings_handler();

		void load_settings();

		string get_setting(string setting_name);
};

#endif