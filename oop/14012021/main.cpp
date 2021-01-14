#include <iostream>
#include <list>
#include <string>

class Act{
public:
  list<string> actors;
  int number_of_act;

  Act(){}

  Act(list<string> actors, int number_of_act) : actors(actors), number_of_act(number_of_act){};
};

class MusicAct : public Act{
public:
  string song_name;

  MusicAct(){}

  MusicAct(list<string> actors, int number_of_act, string song_name) : actors(actors), number_of_act(number_of_act), song_name(song_name){};
};

class Musical{
public:
  string name;
  list<Act> actions;

  Musical(){}

  Musical(string name, list<Act> actions) : name(name), actions(actions){};

  void add_action(list<Act> action){}
  void print() const{}

};

int main(){

  return 0;
}
