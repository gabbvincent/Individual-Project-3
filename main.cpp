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

        if (nextline.size() == 0) {
          continue;
        }

        if (nextline.at(0) == '#') {
          //DO Nothing, # = comment
        } else if (nextline.at(0) == 'C') {
          list = new DList<int>;
          cout << "LIST CREATED" << endl;
        } else if (nextline.at(0) == 'X') {
          if (list == nullptr) {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          } else {
            list->clear();
            cout << "LIST CLEARED" << endl;
          }
        } else if (nextline.at(0) == 'D') {
          if (list == nullptr) {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          } else {
            delete list;
            list = nullptr;
            cout << "LIST DELETED" << endl;
          }
        } else if (nextline.at(0) == 'I') {
          if (list == nullptr) {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          } else {
            int data = stoi(nextline.substr(2));
            list->insert(data);
            cout << "VALUE " << data << " INSERTED" << endl;
          }
        } else if (nextline.at(0) == 'P') {
          if (list == nullptr) {
          cout << "MUST CREATE LIST INSTANCE" << endl; 
          } else {
            if (list->empty()) {
              cout << "EMPTY LIST" << endl;
            } else {
            cout << list->toString() << endl;
            }
          }
        } else if (nextline.at(0) == 'R') {
          if (list == nullptr) {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          } else {
            int data = stoi(nextline.substr(2));
            bool result = list->remove(data);
            if (result == true) {
              cout << "VALUE " << data << " REMOVED" << endl;
            } else {
              cout << "VALUE " << data << " NOT FOUND" << endl;
            }
          }
        } else if (nextline.at(0) == 'A') {
          if (list == nullptr) {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          } else {
            cout << "VALUE " << list->front() << " AT HEAD" << endl;
          }
        } else if (nextline.at(0) == 'Z') {
          if (list == nullptr) {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          } else {
            cout << "VALUE " << list->back() << " AT TAIL" << endl;
          }
        } else if (nextline.at(0) == 'F') {
          if (list == nullptr) {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          } else {
            int data = stoi(nextline.substr(2));
            list->pushFront(data);
            cout << "VALUE " << data << " ADDED TO HEAD" << endl;
          }
        } else if (nextline.at(0) == 'B') {
          if (list == nullptr) {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          } else {
            int data = stoi(nextline.substr(2));
            list->pushBack(data);
            cout << "VALUE " << data << " ADDED TO TAIL" << endl;
          }
        } else if (nextline.at(0) == 'N') {
          if (list == nullptr) {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          } else {
            cout << "LIST SIZE IS " << list->getSize() << endl;
          }
        } else if (nextline.at(0) == 'T') {
          if (list == nullptr) {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          } else {
            list->popFront();
            cout << "REMOVED HEAD" << endl;
          }
        } else if (nextline.at(0) == 'K') {
          if (list == nullptr) {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          } else {
            list->popBack();
            cout << "REMOVED TAIL" << endl;
          }
        } else if (nextline.at(0) == 'E') {
          if (list == nullptr) {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          } else {
            int data = stoi(nextline.substr(2));
            if (list->eliminate(data) == true) {
              cout << "VALUE " << data << " EMILINATED" << endl;
            } else {
              cout << "VALUE " << data << " NOT FOUND" << endl;
            }
          }
        } else if (nextline.at(0) == 'G') {
          if (list == nullptr) {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          } else {
            int data = stoi(nextline.substr(2));
            if (list->get(data) == true) {
              cout << "VALUE " << data << " FOUND" << endl;
            } else {
              cout << "VALUE " << data << " NOT FOUND" << endl; 
            }
          }
        }
      }

    } else {
      cout << "Failed to open file" << argv[1] << endl;
    }

  } else {
    cout << "Usage: " << argv[0] << " INPUT_FILE" << endl;
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