#ifndef MOVIE_H
#define MOVIE_H

#include "torrent.h"

using namespace std;

class MovieTorrent : public Torrent{
public:
    string director;
    int movie_lenght;
    string audio_stream_lang;

    MovieTorrent();
    MovieTorrent(string name, int size, string uploader_name, int downloads, string director, int movie_lenght, string audio_stream_lang);

    string get_director();
    int get_movie_lenght();
    string get_audio_stream_lang();

    string toString();
};

#endif
