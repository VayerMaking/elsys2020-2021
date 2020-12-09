#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <cstring>

using namespace std;

struct known_routes{
  string ip_address;
  int index;
  int packages_sent;
};

class Package{
public:
  static int counter;
  string ip_sender;
  string ip_receiver;
  char* content;

  Package(char* content, string ip_sender, string ip_receiver){
    this->content = content;
    this->ip_sender = ip_sender;
    this->ip_receiver = ip_receiver;

  }

  ~Package(){
    delete[] content;
  }
private:

  int content_size;


  int number_of_packet = counter;
  int validate(){
    if(strlen(content) == content_size){
      return 1;
    }else{
      return 0;
    }
  }


};

class Router{
public:
  string name;
  string ip_address;
  vector<Router*> router;
  vector<known_routes> table_of_routers;
  const static int max_known_routes;
  const static int hop_count;

  Router(string name, string ip_address){
    this->name = name;
    this->ip_address = ip_address;
  }
  int get_hop_count() const {
      return hop_count;
    }
  void add_router(Router* router){
    this->router.push_back(router);
  }

  int query_route(const string address, const int hop_count){
    if(address == ip_address){
      return 1;
    }
    for(vector<known_routes>::iterator it3 = table_of_routers.begin(); it3 != table_of_routers.end(); ++it3){
      if((*it3).ip_address == address){
        return 1;
      }
    }
    if(hop_count > 1){
      for(vector<known_routes>::iterator it = table_of_routers.begin(); it != table_of_routers.end(); ++it){
        //if((*it)->query_route(address, hop_count - 1) == 1){
        //  return 1;
        //}
        for(vector<known_routes>::iterator it2 = table_of_routers.begin(); it2 != table_of_routers.end(); ++it2){
          if((*it2).ip_address == address){
            if(table_of_routers.size() < max_known_routes){
              table_of_routers.push_back(*it2);
            }else if (table_of_routers.size() == max_known_routes){
              table_of_routers.pop_back();
              table_of_routers.push_back(*it2);
            }
            return 1;
          }
        }
      }
    }
    return 0;
  }

  void send_package(const Package &package){
    Package p = package;
    if(p.content == "0" || p.ip_receiver == "0" || p.ip_sender == "0"){
      throw "no value";
    }
    if(p.ip_sender == "0.0.0.0" || p.ip_sender == "127.0.0.0" || p.ip_receiver == "0.0.0.0" || p.ip_receiver == "127.0.0.0"){
      throw "wrong address";
    }
    if(ip_address == p.ip_receiver){
      return;
    }
    for(vector<known_routes>::iterator it = table_of_routers.begin(); it != table_of_routers.end(); ++it){
      if((*it).ip_address == p.ip_receiver){
        (*it).packages_sent += 1;
        p.ip_sender = (*it).ip_address;
        //table_of_routers[(*it).index]->send_package(p);
      }else if(query_route(p.ip_receiver, hop_count) == 0){
        return;
      }
    }
  }
};
int main(){
  ifstream in1 = ifstream("./routers.txt");
  string routers_line;
  cout << "routers.txt" <<  endl;
  while (getline(in1, routers_line)){
      cout << routers_line <<  endl;
  }

  ifstream in2 = ifstream("./network.txt");
  string network_line;
  cout << "network.txt" <<  endl;
  while (getline(in2, network_line)){
      cout << network_line <<  endl;
  }

  ifstream in3 = ifstream("./packets.txt");
  string packets_line;
  cout << "packets.txt" <<  endl;
  while (getline(in3, packets_line)){
      cout << packets_line <<  endl;
  }
  return 0;
}
