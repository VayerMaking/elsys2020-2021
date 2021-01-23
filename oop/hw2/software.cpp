#include "software.h"
#include <string>


using namespace std;

SoftwareTorrent::SoftwareTorrent(){}
SoftwareTorrent::SoftwareTorrent(string name, int size, string uploader_name, int downloads, string creator, string operating_system, string version) :
 Torrent(name, size, uploader_name, downloads), creator(creator), operating_system(operating_system), version(version){}
string SoftwareTorrent::toString(){}
