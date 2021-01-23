#include "torrent.h"
#include <string>


using namespace std;

Torrent::Torrent(){}
Torrent::Torrent(string name, int size, string uploader_name, int downloads) : name(name), size(size), uploader_name(uploader_name), downloads(downloads){}
