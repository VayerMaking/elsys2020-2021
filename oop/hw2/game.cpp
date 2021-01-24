#include "game.h"
#include <string>

using namespace std;

GameTorrent::GameTorrent(){}
GameTorrent::GameTorrent(string name, int size, string uploader_name, int downloads, string platform, char maturity_level) :
Torrent(name, size, uploader_name, downloads), platform(platform), maturity_level(maturity_level){}

string GameTorrent::get_platform(){ return platform;}
char GameTorrent::get_maturity_level(){ return maturity_level;}

string GameTorrent::toString(){
  return "GameTorrent:\n" + get_name() + to_string(get_size()) + get_uploder_name() + to_string(get_downloads()) + get_platform() + to_string(get_maturity_level());
}
