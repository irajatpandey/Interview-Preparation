#include<bits/stdc++.h>
using namespace std;

class LinkedList{

    private:
        int data;
        LinkedList *next;
        LinkedList *head;
	public:
		
    LinkedList(){
        head = NULL;
    }

	LinkedList(int x){
		data = x;
        next = NULL;
	}	
    void insert(int x){
	 LinkedList *newNode = new LinkedList(x);
	 newNode -> next = (head);
	 (head) = newNode;
    }

    void insertAtEnd( int x){
        LinkedList *newNode = new LinkedList(x);
        LinkedList *temp = head;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }

    void insertAtPosition(int pos, int x){
        if(pos == 1){
            insert(x);
        }
        else{
        LinkedList *temp = head;
            for(int i = 2; i <= pos - 1; i++){
                temp = temp -> next;
            }
            LinkedList *newNode = new LinkedList(x);
            newNode -> next = temp -> next;
            temp -> next = newNode;
        }
    }
    
    void deleteAtBeginning(){
        if(!head) return;
        LinkedList *temp = head;

        head = head -> next;
        delete temp;
    }
    
    void deleteAtEnd(){

        if(!head) return;
        LinkedList *temp = head;
        while(temp -> next-> next != NULL){
            temp = temp -> next;
        }
        temp -> next = NULL;
        delete temp -> next;

    }

    void deleteAtPosition(int pos){
        if(pos == 1) deleteAtBeginning();
        else{
            LinkedList *temp  = head;
            for(int i = 2; i <= pos -1 ; i++){
                temp = temp -> next;
            }
            LinkedList *deletedNode = temp -> next;
            temp -> next = deletedNode -> next;
            delete deletedNode;
        }
    }
    void printList(){
        LinkedList *temp = head;
        while(temp){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }

    LinkedList *reverse(LinkedList * temp){
        if(temp == NULL or temp -> next == NULL){
            return temp;
        }

        LinkedList *smallHead = reverse(temp -> next);
        // cout << "SmallHead -> data " << smallHead ->  data << endl;
        // cout << "Temp -> data " << temp -> data << endl;
        LinkedList *sh = smallHead;
        // while(sh != NULL){
        //     // cout <<"SmallHead " << sh -> data << "";
        //     cout << "temp -> data " << temp-> data << "\n";
        //     sh = sh -> next;

        // }
        // cout << endl;

        // LinkedList *tail = temp -> next;
        // tail -> next = temp;
        // temp -> next = NULL;

        // Short Hand 
        temp -> next -> next = temp;
        temp -> next = NULL;
        return smallHead;
    }
    void reverseListRecursion(){
          head = reverse(head);
    }

    void reverseListIterative(LinkedList *head){
        if(head == NULL or head -> next == NULL){
            this -> head = head;
        } 
        LinkedList *current = head;
        LinkedList *prev = NULL;
        LinkedList *next = NULL;


        while(current){
            next = current -> next;
            current -> next = prev;
            prev  = current;
            current = next;
        }

        this -> head = prev;
    }
    void reverseListIteration(){
        reverseListIterative(head);
    }
    ~LinkedList(){
        LinkedList *current = head;
        while(head != NULL){
            LinkedList *next  = current -> next;
            delete current;
            current = next;
        }
        head = NULL;
        
    }

};



int main(){

	LinkedList *head = NULL;
    LinkedList obj;

	int arr[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
	for(int i = 0; i < 10; i++)
		obj.insert(arr[i]);
    obj.printList();

    cout << endl << endl;
	
    // cout << "Insertion At Beginning " << endl;
    // obj.printList();

    // cout << "Insertion At End " << endl;
    // obj.insertAtEnd(112);
    // obj.printList();

    // cout << "Insertion At Position " << endl;
    // obj.insertAtPosition(3, 1234);
    // obj.printList();


    // obj.deleteAtBeginning();
    // obj.printList();

    // obj.deleteAtEnd();
    // obj.printList();

    // cout << "Deletion At Position " << endl;

    // obj.deleteAtPosition(3);
    // obj.printList();


    obj.reverseListRecursion();
    obj.printList();


    obj.reverseListIteration();
    obj.printList();
	return 0;

}