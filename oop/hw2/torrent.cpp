#include "torrent.h"
#include <string>


using namespace std;

Torrent::Torrent(){}
Torrent::Torrent(string name, int size, string uploader_name, int downloads) : name(name), size(size), uploader_name(uploader_name), downloads(downloads){}
Torrent::Torrent(const Torrent &copy){
  name = copy.name;
  size = copy.size;
  uploader_name = copy.uploader_name;
  downloads = copy.downloads;
}

string Torrent::get_name(){ return name;}
int Torrent::get_size(){ return size;}
string Torrent::get_uploder_name(){ return uploader_name;}
int Torrent::get_downloads(){ return downloads;}
