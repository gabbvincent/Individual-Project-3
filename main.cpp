#include "dlist.hpp"

#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  if (argc == 2) {

    ifstream fin(argv[1]);
    if (fin.is_open()) {

      DList<int> *list(nullptr);

      string nextline;
      while (getline(fin, nextline)) {

        if (nextline.at(0) == '#') {
          //DO Nothing, # = comment
        } else if (nextline.at(0) == 'C') {
          DList<int> *list = new DList<int>;
          cout << "LIST CREATED" << endl;
        } else if (nextline.at(0) == 'X') {
          if (list == nullptr) {
            cout << "MUST CREATE LSIT INSTANCE" << endl;
          } else {
          list->clear();
          cout << "LIST CLEARED" << endl;
          }
        }

      }

    } else {
      cout << "Failed to ope file" << argv[1] << endl;
    }

  } else {
    cout << "Usage: " << argv[0] << " INPUTE_FILE" << endl;
  }
}








/*
# any text      : ignore as comment
C               : create dynamic list instance
X               : clear the current list instance of contents
D               : delete the dynamic list instance and set to nullptr
I number        : insert number into list (sorted)
F number        : add number to front of list
B number        : add number to back of list
E number        : eliminate all occurrences of number from the list
R number        : remove the first occurrence of number from the list
G number        : get number from the list
A               : return contents of head node
Z               : return contents of tail node
T               : pop the head node
K               : pop the tail node
N               : return the size of the list
P               : print all items in the list
*/