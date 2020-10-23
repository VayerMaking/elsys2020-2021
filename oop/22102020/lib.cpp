#include<iostream>
//#include<string>
#include<list>
#include<fstream>
using namespace std;

class Book{
public:
  string title;
  string author;
  int pages;
  int grade;

Book(){
  title = "";
  author = "";
  pages = 0;
  grade = 0;
}

Book(string title, string autor, int pages, int grade){
  this->title = title;
  this->author = author;
  this->pages = pages;
  this->grade = grade;
}

};

class Library{
private:
  list<Book> library;
public:
  void add_book(Book a){
    library.push_back(a);
  }

  void save_to_csv(){
    ofstream myFile("lib.csv");
    for(list<Book>::iterator it = library.begin(); it != library.end(); it++)
      {
          myFile << (*it).title << (*it).author << (*it).pages << (*it).grade;
      }

    myFile.close();
  }

};

int main(){
  Library lib;
  Book b1 = {"asdf", "qwerty", 123, 5};
  lib.add_book(b1);
  lib.save_to_csv();

  return 0;
}
