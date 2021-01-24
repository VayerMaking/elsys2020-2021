#include "game.h"
#include <string>

using namespace std;

GameTorrent::GameTorrent(){}
GameTorrent::GameTorrent(string name, int size, string uploader_name, int downloads, string platform, char maturity_level) :
Torrent(name, size, uploader_name, downloads), platform(platform), maturity_level(maturity_level){}
GameTorrent::GameTorrent(const GameTorrent &copy){
  platform = copy.platform;
  maturity_level = copy.maturity_level;
}

string GameTorrent::get_platform(){ return platform;}
char GameTorrent::get_maturity_level(){ return maturity_level;}

string GameTorrent::toString(){
  return "\n name:" + get_name() + "\n size:" + to_string(get_size()) + "\n uploader:" + get_uploder_name() + "\n downloads:" + to_string(get_downloads()) + "\n platform:" + get_platform() + "\n maturity level:" + get_maturity_level();
}
