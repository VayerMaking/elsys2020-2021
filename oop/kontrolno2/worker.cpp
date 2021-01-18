#include"worker.h"
#include<iostream>
#include<string>
#include"mine.h"

using namespace std;

Worker::Worker(){}
Worker::Worker(const Worker& temp){name = temp.name; serial_number = temp.serial_number; max_work_done = temp.max_work_done;}
Worker::Worker(string name, int serial_number, int max_work_done) : name(name), serial_number(serial_number), max_work_done(max_work_done){}
string Worker::get_name(){return name;}
int Worker::get_serial_number(){return serial_number;}
int Worker::get_max_work_done(){return max_work_done;}

void Worker::print_worker(Worker worker){
  cout << "name: " << name << "serial_number: " << serial_number << "max_work_done: " << max_work_done;
}

unsigned int Worker::choose_mine(vector<Mine> mines){}
