#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedList {
  private:
    int data;
  DoublyLinkedList * next;
  DoublyLinkedList * prev;
  DoublyLinkedList * head;
  public:
    DoublyLinkedList() {
      head = NULL;

    }

  DoublyLinkedList(int data) {
    this -> data = data;
    next = NULL;
    prev = NULL;
  }

  void insertAtFront(int data) {
    DoublyLinkedList * node = new DoublyLinkedList(data);
    if (head == NULL) {
      prev = head;
      head = node;
      return;
    } else {

      node -> next = head;
      head -> prev = node;
      head = node;
      return;
    }

  }
  void insertAtBack(int data) {

    // List empty 
    if (!head) {
      insertAtFront(data);
      return;
    }
    // List not empty
    else {
      DoublyLinkedList * temp = head;
      while (temp -> next != NULL) {
        temp = temp -> next;
      }
      DoublyLinkedList * node = new DoublyLinkedList(data);
      temp -> next = node;
      node -> prev = temp;
    }

  }

  void insertAtPosition(int data, int p) {
    if (p == 1) {
      insertAtFront(data);
      return;
    }
    DoublyLinkedList * temp = head;

    DoublyLinkedList * node = new DoublyLinkedList(data);

    for (int i = 2; i <= p - 1; i++) {
      temp = temp -> next;
    }

    DoublyLinkedList * holdAddress = temp -> next;
    temp -> next = node;
    node -> next = holdAddress;
    node -> prev = temp;
    holdAddress -> prev = node;

    return;

  }

  void deleteAtFront() {

    if (!head) {
      cout << "List is empty! " << endl;
      return;
    }
    DoublyLinkedList * temp = head;

    head = head -> next;
    head -> prev = NULL;
    delete temp;

    return;
  }

  void deleteAtBack() {

    if (!head) {
      cout << "List is empty! " << endl;
      return;
    }

    DoublyLinkedList * temp = head;
    while (temp -> next -> next) {
      temp = temp -> next;
    }

    DoublyLinkedList * next = temp -> next;
    temp -> next = NULL;
    next -> prev = NULL;
    free(next);
    return;
  }

  void deleteAtPosition(int pos) {

    if(pos == 1){
      deleteAtFront();
      return;
    }

    DoublyLinkedList * temp = head;


    for(int i = 2; i <= pos - 1; i++){
       temp = temp -> next;
    }

    // cout << temp -> data << endl;
    // cout << temp -> next -> data << endl;

    DoublyLinkedList *next = temp -> next;

    temp -> next = next -> next;
    temp -> next -> next -> prev = temp;

    // DoublyLinkedList *del = temp -> next;
    delete next;

    return;

    


  }

  void printList() {
      DoublyLinkedList * head = this -> head;
      if (!this -> head) cout << "List is empty!" << endl;
      while (head) {
        cout << head -> data << " ";
        head = head -> next;
      }
      cout << endl;
    }


 void reverseLDoublyLinkedList(){
    DoublyLinkedList *head = this -> head;
    if(!head) return;

    DoublyLinkedList *curr = head;
    DoublyLinkedList *temp = NULL;

    while(curr){
      temp = curr -> prev;
      curr -> prev = curr -> next;
      curr -> next = temp;
      curr = curr -> prev;
    }

    this -> head =  temp -> prev;
    return;

  }
    ~DoublyLinkedList() {
      while (head != NULL) {
        DoublyLinkedList * current = head;
        while (head != NULL) {
          DoublyLinkedList * next = current -> next;
          delete current;
          current = next;
        }
        head = NULL;
      }
    }

};

int main() {

  DoublyLinkedList dl;

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = sizeof(arr) / sizeof(arr[0]);

  for (int i = n - 1; i >= 0; i--) {
    dl.insertAtFront(arr[i]);
  }
  // dl.insertAtFront(10);
  // dl.insertAtFront(20);

  // dl.insertAtFront(30);

  // dl.printList();

  // dl.insertAtBack(100);

  // dl.printList();

  // dl.insertAtPosition(123, 2);
  // dl.printList();

  // dl.deleteAtFront();
  // dl.printList();
  // // dl.printList();

  // dl.deleteAtBack();
  // dl.printList();

  dl.printList();

  dl.reverseLDoublyLinkedList();
  dl.printList();

  return 0;
}