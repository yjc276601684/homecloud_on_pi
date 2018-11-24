#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <dirent.h>

using namespace std;

int main() {
	
	DIR *dir;
	struct dirent *ent;

	cout << "Content-type: text/html" << endl << endl;
	cout << "<html> \n";
	cout << "<head><title>Download files and Remove files</title></head>\n";
	cout << "<body>\n";

	cout << "<p><b>Below are the files currently in your directory</b></p>";
	cout << "<p> Download files by pressing on them, click the button beside it to delete them </p>";

	if ((dir = opendir("/var/www/html/saveFile")) != NULL) {
		while ((ent = readdir(dir)) != NULL) {

			string dirName = string(ent->d_name);

			if (dirName.compare(".") == 0 || dirName.compare("..") == 0) {
				continue;
			}

			cout << "<br>";
			string fileName  = "..//saveFile/" + dirName;
			string fullfileName = "/var/www/html/saveFile/" + dirName;
			cout << "<a href=' " << fileName.c_str() << "'" <<  " download='download'>" << ent->d_name << "</a>" << endl;
			cout << "<form action='removefile.cgi' target='_blank'> <input type = 'hidden' name = 'path' value = '" <<fullfileName.c_str() << "'> <input type='submit' value='delete'></form>";
			cout << "<br>";
		
		}
		closedir(dir);
	} else {	
		cout << "Unable to open directory" << endl;
	}

	cout << "</body></html>";

	return 0;
}

