#include "movie.h"
#include <string>


using namespace std;

MovieTorrent::MovieTorrent(){}
MovieTorrent::MovieTorrent(string name, int size, string uploader_name, int downloads, string director, int movie_lenght, string audio_stream_lang) :
Torrent(name, size, uploader_name, downloads), director(director), movie_lenght(movie_lenght), audio_stream_lang(audio_stream_lang){}

string MovieTorrent::get_director(){ return director;}
int MovieTorrent::get_movie_lenght(){ return movie_lenght;}
string MovieTorrent::get_audio_stream_lang(){ return audio_stream_lang;}

string MovieTorrent::toString(){
  return "MovieTorrent:\n" + get_name() + to_string(get_size()) + get_uploder_name() + to_string(get_downloads()) + get_director() + to_string(get_movie_lenght()) + get_audio_stream_lang();
}
