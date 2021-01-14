#include <iostream>
#include <string>

class Torrent{
public:
    string name;
    int size;
    string uploader_name;
    int downloads;

    Torrent(){}
};

class GameTorrent : public Torrent{
public:
    string platform;
    char maturity_level; // e - everybody, m - >15, p - >18

    GameTorrent(){}
    GameTorrent(string name, int size, string uploader_name, int downloads, string platform, char maturity_level) : name(name), size(size), uploader_name(uploader_name),
     downloads(downloads), platform(platform), maturity_level(maturity_level){}

    string toString(){}
};

class MovieTorrent : public Torrent{
public:
    string director;
    int movie_lenght;
    string audio_stream_lang;

    MovieTorrent(){}
    MovieTorrent(string name, int size, string uploader_name, int downloads, string director, int movie_lenght, string audio_stream_lang) : name(name), size(size), uploader_name(uploader_name),
     downloads(downloads), director(director), movie_lenght(movie_lenght), audio_stream_lang(audio_stream_lang){}

    string toString(){}
};

class SoftwareTorrent : public Torrent{
public:
    string creator;
    string operating_system;
    string version; // major.minor.patch versioning

    SoftwareTorrent(){}
    SoftwareTorrent(string name, int size, string uploader_name, int downloads, string creator, string operating_system, string version) : name(name), size(size), uploader_name(uploader_name),
     downloads(downloads), creator(creator), operating_system(operating_system), version(version){}

    string toString(){}
};

int main(){

  return 0;
}
