#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
using namespace std;

class Package
{
    char *content;
    int lenght;
    string ip_source;
    string ip_destination;
    int validate()
    {
        if (strlen(content) == lenght)
            return 1;
        return 0;
    }
public:
    int number;
    static int count;
    string ipd()
    {
        return ip_destination;
    }
    Package(string ip_s, string ip_d, char *content)
    {
        if (ip_s == "0.0.0.0" || ip_d == "0.0.0.0" || ip_s == "127.0.0.0" || ip_d == "127.0.0.0")
            throw 8;
        else
        {
            this->ip_source = ip_s;
            this->ip_destination = ip_d;
        }
        if (content == NULL)
            throw "No content";
        else
        {
            this->content = content;
            this->number = Package::count++;
        }
    }
    ~Package() { delete[] content; }
};
struct route
{
    string ip;
    int position;
    int count_of_packages;
};

class Router
{
    string name;
    string ip;
    vector<Router *> c;
    static const int max;
    list<route> routing_table;

public:
    static const int hops;
    Router(string name, string ip) : name(name), ip(ip) {}
    void add_router(Router &router)
    {
        this->c.push_back(&router);
    }
    int query_route(const string address, const int hop_count)
    {
        int result = 0;
        if (address == this->ip)
        {
            return 1;
        }
        for (auto it = this->routing_table.begin(); it != this->routing_table.end(); ++it)
        {
            if ((*it).ip == address)
            {
                return 1;
            }
        }
        if (hop_count > 1)
        {
            for (auto it1 = this->c.begin(); it1 != this->c.end(); ++it1)
            {
                for (auto it2 = (*it1)->routing_table.begin(); it2 != (*it1)->routing_table.end(); ++it2)
                {
                    if ((*it2).ip == address)
                    {
                        this->routing_table.push_back((*it2));
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
        int result;
        if (this->ip == p.ipd())
        {
            cout << "Path found on current router" << endl;
            return;
        }
        else
        {
            cout << "Searching..." << endl;
            for (auto it = this->routing_table.begin(); it != this->routing_table.end(); ++it)
            {
                cout << "in known ip: " << (*it).ip << endl;
                if ((*it).ip == p.ipd())
                {
                    cout << "Succes..." << endl;
                    (*it).count_of_packages += 1;
                    send_package(p);
                }
            }
            if (query_route(p.ipd(), this->hops) == 0)
            {
                cout << "Sending Failed: No path found.." << endl;
                return;
            }
        }
    }
};

int main()
{
    Package::count = 0;
}
