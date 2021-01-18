#ifndef WORKER_H
#define WORKER_H

#include<iostream>
#include<string>
#include<vector>
#include"mine.h"

using namespace std;

class Mine;

class Worker{
public:
    string name;
    int serial_number;
    int max_work_done;

    Worker();
    Worker(const Worker& temp);
    Worker(string name, int serial_number, int max_work_done);

    string get_name();
    int get_serial_number();
    int get_max_work_done();

    void print_worker(Worker worker);

    unsigned int choose_mine(vector<Mine> mines);

};

#endif
