#include <iostream>
#include <list>
#include <queue>

using namespace std;

class ProcessManager{
public:
  int cpu_threads;
  list<queue<Process>> collection;
  ProcessManager(int threads){
    this->cpu_threads = threads;
  }
  void addProcess(list<Process> processes){}
};

class Process{
public:
  int priority;
  float time;

  Process(){}
  Process(int priority, float time) : priority(priority), time(time){};
  virtual int get_priority(){return priority;}
  virtual float get_time(){return time;}

};

class FileCopy : public Process{
public:
  int files;
  float speed;
  const int priority = 4;

  FileCopy(int files, float speed) : priority(priority), time(time){};

  float override_time() override {return files / speed;}
  int calc_priority() override {return override_time() * priority;}
};

class AllocateMemory : public Process{
public:
  int size;
  float speed;
  const int priority = 7;

  AllocateMemory(int size, int total_size):size(size), total_size(total_size){}

  float override_time() override{srand(100); return size / totalsize * ((rand() % 1000) + 1);}
  int calc_priority() override{srand(10);return timefunc() * importance * ((rand() % 20) + 1);}
};
int main(){

  return 0;
}
