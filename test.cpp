#include <iostream>
using namespace std;

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main( int argc, char** argv )
  {
  if (argc != 2)
    {
    cerr << "usage:\n"
            "  filesize FILENAME\n\n";
    return 1;
    }

  struct stat filestatus;
  stat( argv[ 1 ], &filestatus );
  cout << filestatus.st_size << " bytes\n";

  return 0;
  }
