#ifndef MOVIE_H
#define MOVIE_H

#include "torrent.h"

using namespace std;

class MovieTorrent : public Torrent{
public:
    string director;
    int movie_lenght;
    string audio_stream_lang;

    MovieTorrent();//{}
    MovieTorrent(string name, int size, string uploader_name, int downloads, string director, int movie_lenght, string audio_stream_lang);// : name(name), size(size), uploader_name(uploader_name),
    // downloads(downloads), director(director), movie_lenght(movie_lenght), audio_stream_lang(audio_stream_lang){}

    string toString();//{}
};

#endif
