#include "movie.h"
#include <string>


using namespace std;

MovieTorrent::MovieTorrent(){}
MovieTorrent::MovieTorrent(string name, int size, string uploader_name, int downloads, string director, int movie_lenght, string audio_stream_lang) :
Torrent(name, size, uploader_name, downloads), director(director), movie_lenght(movie_lenght), audio_stream_lang(audio_stream_lang){}

string MovieTorrent::toString(){}
