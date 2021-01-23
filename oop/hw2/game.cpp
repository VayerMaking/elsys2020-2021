#include "game.h"
#include <string>

using namespace std;

GameTorrent::GameTorrent(){}
GameTorrent::GameTorrent(string name, int size, string uploader_name, int downloads, string platform, char maturity_level) :
Torrent(name, size, uploader_name, downloads), platform(platform), maturity_level(maturity_level){}


string GameTorrent::toString(){}
