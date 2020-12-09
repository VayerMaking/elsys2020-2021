int query_route(const string address, const int hop_count){
  if(address == ip){
    return 1;
  }
  for(auto it3 = table_of_routers.begin(); it3 != table_of_routers.end(); ++it3){
    if((*it3).ip_address == address){
      return 1;
    }
  }
  if(hop_count > 1){
    for(vector<known_routes>::iterator it = table_of_routers.begin(); it != table_of_routers.end(); ++it){
      if((*it).query_route(address, hop_count - 1)){

      }
      for(vector<known_routes>::iterator it2 = (*it)->table_of_routers.begin(); it2 != (*it)->table_of_routers.end(); ++it2){
        if((*it2).ip == address){
          if(table_of_routers.size() < max_routes){
            table_of_routers.push_back(*it2);
          }else if{
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
  if(content == "0" || ip_receiver == "0" || ip_sender == "0"){
    throw "no value";
  }
  if(ip_sender == "0.0.0.0" || ip_sender == "127.0.0.0" || ip_receiver == "0.0.0.0" || ip_receiver == "127.0.0.0"){
    throw "wrong address";
  }
  if(ip == p.ip_receiver){
    return;
  }
  for(vector<known_routes>::iterator it = table_of_routers.begin(); it != table_of_routers.end(); ++it){
    if((*it).ip == p.ip_receiver){
      (*it).number_of_packet += 1;
      p.ip_sender = (*it).ip;
      table_of_routers[(*it).position]->send_package(p);
    }else if(query_route(p.ip_receiver, hop_count) == 0){
      return;
    }
  }
}
