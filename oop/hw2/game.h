#ifndef GAME_H
#define GAME_H

#include "torrent.h"
#include <string>

using namespace std;

class GameTorrent : public Torrent{
public:
    string platform;
    char maturity_level; // e - everybody, m - >15, p - >18

    GameTorrent();
    GameTorrent(string name, int size, string uploader_name, int downloads, string platform, char maturity_level);
    GameTorrent(const GameTorrent &copy);
    string get_platform();
    char get_maturity_level();

    string toString();
};

#endif
