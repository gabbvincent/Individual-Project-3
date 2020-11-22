#include <sstream>
#include <stdexcept>
#include <string>
#include <iostream>
using std::logic_error;
using std::ostringstream;
using std::string;
using namespace std;

template <typename T>
class DList {
public:
  // Default constructor.
  // Initializes head to nullptr, size to 0.
  DList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
  }

  // Destructor.
  // Invokes clear to free the memory associated with all nodes in the list.
  ~DList() {
    this->clear();
  }

  // Create a new node to contain value and insert the node
  // at the head of this SList. Increases the size by 1.
  void pushFront(T value) {
    Node* temp = new Node(value);
    
    temp->next = head;

    if (head != nullptr) {
      head->prev = temp;
    }

    head = temp;
    if (tail == nullptr) {
      tail = temp;
    }
    size++;
  }

  void pushBack(T value) {
    Node* temp = new Node(value);
    
    temp->prev = tail;

    if (tail != nullptr) {
      tail->next = temp;
    }

    tail = temp;
    if (head == nullptr) {
      head = temp;
    }
    size++;

  }

  // Remove the head node.
  // Throws std::logic_error("EMPTY LIST") when list is empty
  void popFront() noexcept(false) {

    Node* temp = head;

    head = head->next;
    if (head == nullptr) {
      tail = nullptr;
    } else {
      head->prev = nullptr;
    }
  
    delete temp;
    size--;
  }

  void popBack() {
    
    Node* temp = tail;

    tail = tail->prev;
    if (head == nullptr) {
      tail = nullptr;
    } else {
      tail->next = nullptr;
    }
  
    delete temp;
    size--;

  }

  bool remove (T value) {
    if (empty()) {
      return false;
    } else if (value == head->value) {
      popFront();
      return true;
    } else if (value == tail->value) {
      popBack();
      return true;
    } else {

      Node *temp = head;
      while (temp != nullptr && value != temp->value) {
        temp = temp->next;
      }

      if (temp == nullptr) {
        return false;
      } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
        return true;
      }
    }
  }

  bool eliminate(T value) {
    unsigned int removed(0);

    while (remove(value) == true) {
      removed++;
    }

    return removed > 0;
  }

  bool get(T value) {
    Node *temp = head;
    while (temp != nullptr) {
      if (temp->value == value) {
        return true;
      } else {
        temp = temp->next;
      }
    }

    return false;
  }  

  // Return the value stored in the head Node.
  // Throws std::logic_error("EMPTY LIST") when list is empty
  T front() noexcept(false) {
    if (head == nullptr) {
      cout << "EMPTY LIST" << endl;
    }

    return head->value;
  }

  T back() noexcept(false) {
    if (tail == nullptr) {
      cout << "EMPTY LIST" << endl;
    }

    return tail->value;

  }

  void insert(T value) {
    if (empty()) {
      pushFront(value);
    } else if (value <= head->value) {
      pushFront(value);
    } else if (value >= tail->value) {
      pushBack(value);
    } else {
      Node *n = new Node(value);
      Node *temp = head;
      while (value > temp->value) {
        temp = temp->next;
      }
      n->prev = temp->prev;
      n->next = temp;
      n->prev->next = n;
      temp->prev = n;

      size++;
    }
  }

  // Return the number of nodes in this list.
  unsigned int getSize() const {
    return size;
  }

  // Check to see if this list is empty.
  bool empty() const {
    return size == 0;
  }

  // Free the memory associated with all nodes in the list.
  // Resets head to nullptr and size to 0.
  void clear() {
    while (!empty()) {
      popFront();
    }
  }

  // Return a string representation of this list.
  // Displays the values (starting from head) of each node in the list,
  // separated by comma.
  //
  // EXAMPLE: "13,-1,0,99,-47"
  string toString() const {
    ostringstream output;

    Node* temp = head;
    while (temp != nullptr) {
      output << temp ->value;
      if (temp->next != nullptr) {
        output << ",";
      }
      temp = temp->next;
    }
    return output.str();
  }

private:
  unsigned int size; // the number of nodes in this list

  // A singly-linked list node with a pointer to next and a value field.
  // Implements a constructor to initialize the value field to the parameter value
  // and the pointer to nullptr.
  struct Node {
    Node *prev;
    Node *next;
    T value;

    Node(T newValue) {
      prev = nullptr;
      next = nullptr;
      value = newValue;
    }

  } * head, * tail; // a pointer to the first node in the list
};