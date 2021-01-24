#include "software.h"
#include <string>


using namespace std;

SoftwareTorrent::SoftwareTorrent(){}
SoftwareTorrent::SoftwareTorrent(string name, int size, string uploader_name, int downloads, string creator, string operating_system, string version) :
 Torrent(name, size, uploader_name, downloads), creator(creator), operating_system(operating_system), version(version){}
string SoftwareTorrent::get_creator(){ return creator;}
string SoftwareTorrent::get_operating_system(){ return operating_system;}
string SoftwareTorrent::get_version(){ return version;}
string SoftwareTorrent::toString(){
  return "SoftwareTorrent:\n" + get_name() + to_string(get_size()) + get_uploder_name() + to_string(get_downloads()) + get_creator() + "\n" + get_operating_system() + "\n" + get_version();
}
