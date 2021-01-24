#include "torrent.h"
#include <string>


using namespace std;

Torrent::Torrent(){}
Torrent::Torrent(string name, int size, string uploader_name, int downloads) : name(name), size(size), uploader_name(uploader_name), downloads(downloads){}
string Torrent::get_name(){ return name;}
int Torrent::get_size(){ return size;}
string Torrent::get_uploder_name(){ return uploader_name;}
int Torrent::get_downloads(){ return downloads;}
