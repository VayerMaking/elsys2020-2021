#include "movie.h"
#include <string>


using namespace std;

MovieTorrent::MovieTorrent(){}
MovieTorrent::MovieTorrent(string name, int size, string uploader_name, int downloads, string director, int movie_lenght, string audio_stream_lang) :
Torrent(name, size, uploader_name, downloads), director(director), movie_lenght(movie_lenght), audio_stream_lang(audio_stream_lang){}
MovieTorrent::MovieTorrent(const MovieTorrent &copy){
  director = copy.director;
  movie_lenght = copy.movie_lenght;
  audio_stream_lang = copy.audio_stream_lang;
}

string MovieTorrent::get_director(){ return director;}
int MovieTorrent::get_movie_lenght(){ return movie_lenght;}
string MovieTorrent::get_audio_stream_lang(){ return audio_stream_lang;}

string MovieTorrent::toString(){
  return "\n name:" + get_name() + "\n size:" + to_string(get_size()) + "\n uploader:" + get_uploder_name() + "\n downloads:" + to_string(get_downloads()) + "\n director:" + get_director() + "\n movie lenght:" + to_string(get_movie_lenght()) + "\n audio_stream_lang:" + get_audio_stream_lang();
}
