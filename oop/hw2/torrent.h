#ifndef TORRENT_H
#define TORRENT_H

#include <string>

using namespace std;

class Torrent{
public:
    string name;
    int size;
    string uploader_name;
    int downloads;

    Torrent();
    Torrent(string name, int size, string uploader_name, int downloads);
    string get_name();
    int get_size();
    string get_uploder_name();
    int get_downloads();
};

#endif
