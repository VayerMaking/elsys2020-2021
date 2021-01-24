#include "software.h"
#include <string>


using namespace std;

SoftwareTorrent::SoftwareTorrent(){}
SoftwareTorrent::SoftwareTorrent(string name, int size, string uploader_name, int downloads, string creator, string operating_system, string version) :
 Torrent(name, size, uploader_name, downloads), creator(creator), operating_system(operating_system), version(version){}
SoftwareTorrent::SoftwareTorrent(const SoftwareTorrent &copy){
  creator = copy.creator;
  operating_system = copy.operating_system;
  version = copy.version;
}

string SoftwareTorrent::get_creator(){ return creator;}
string SoftwareTorrent::get_operating_system(){ return operating_system;}
string SoftwareTorrent::get_version(){ return version;}
string SoftwareTorrent::toString(){
  return "\n name:" + get_name() + "\n size:" + to_string(get_size()) + "\n uploader:" + get_uploder_name() + "\n downloads:" + to_string(get_downloads()) + "\n creator:" + get_creator() + "\n operatin system:" + get_operating_system() + "\n version:" + get_version();
}
