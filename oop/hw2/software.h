#ifndef SOFTWARE_H
#define SOFTWARE_H

#include "torrent.h"

using namespace std;

class SoftwareTorrent : public Torrent{
public:
    string creator;
    string operating_system;
    string version; // major.minor.patch versioning

    SoftwareTorrent();
    SoftwareTorrent(string name, int size, string uploader_name, int downloads, string creator, string operating_system, string version);

    string toString();

    string get_creator();
    string get_operating_system();
    string get_version();
};

#endif
