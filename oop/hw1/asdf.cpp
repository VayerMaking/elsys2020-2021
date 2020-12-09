int query_route(const string address, const int hop_count)
{
    if (address == ip)
    {
        return 1;
    }
    for (auto it = routing_table.begin(); it != routing_table.end(); ++it)
    {
        if ((*it).ip == address)
        {
            return 1;
        }
    }

    if (hop_count > 1)
    {
        for (auto it_connected = connected.begin(); it_connected != connected.end(); ++it_connected)
        {
            if((*it_connected).query_route(address,hop_count-1)
            {

            }
            for (auto it_rt = (*it_connected)->routing_table.begin(); it_rt != (*it_connected)->routing_table.end(); ++it_rt)
            {
                if ((*it_rt).ip == address)
                {
                    if (routing_table.size() < max_routes)
                    {
                        routing_table.push_back((*it_rt));
                    }
                    else if (routing_table.size() == max_routes)
                    {
                        check_adress(address);
                        routing_table.pop_back();
                        routing_table.push_back((*it_rt));
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}
void send_package(const Package &package)
{
    Package p = package;
    check_content(p.getContent());
    check_adress(p.getIpDestination());
    if (ip == p.getIpDestination())
    {
        return;
    }
    for (auto it = routing_table.begin(); it != routing_table.end(); ++it)
    {
        if ((*it).ip == p.getIpDestination())
        {
            (*it).count_of_packages += 1;
            p.setIpSource((*it).ip);
            connected[(*it).position]->send_package(p);
        }
        else if (query_route(p.getIpDestination(), hops) == 0)
            return;
    }
}
void send_package(const Package &package)
   {
       if (sended == 10)
       {
           sorting();
           sended = 0;
       }
       Package p = package;
       check_content(p.getContent());
       check_adress(p.getIpDestination());
       if (ip == p.getIpDestination())
       {
           sended++;
       }
       else
       {
           for (auto it = routing_table.begin(); it != routing_table.end(); ++it)
           {
               if ((*it).ip == p.getIpDestination())
               {
                   (*it).count_of_packages += 1;
                   p.setIpSource((*it).ip);
                   //connected[(*it).position]->send_package(p);
                   sended++;
               }
               else if (query_route(p.getIpDestination(), hops) == 0)
                   return;
           }
       }
   }
