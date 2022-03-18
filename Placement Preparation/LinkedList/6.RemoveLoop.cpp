#include<bits/stdc++.h>
using namespace std;

class LinkedList{
	public:
		int data;
		LinkedList *next;
	LinkedList(int x){
		data = x;
	}	
};

void insert(LinkedList **head, int x){
	 LinkedList *newNode = new LinkedList(x);
	 newNode -> next = (*head);
	 (*head) = newNode;
}

void printList(LinkedList *head){
	while(head){
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}


void removeLoopLinkedList(LinkedList *head){
    if(head == NULL or head -> next == NULL) return;

    LinkedList *slow = head;
    LinkedList *fast = head;

    while(fast and fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast)
            break;
    }

    if(slow != fast) return;


    slow = head;
    while(slow -> next != fast -> next){
        slow = slow -> next;
        fast = fast -> next;
        
    }
    fast -> next = NULL;
}

int main(){

	LinkedList *head = NULL;

	int arr[] = {10, 4, 15, 20, 50};
	for(int i = 0; i < 5; i++)
		insert(&head, arr[i]);
    head->next->next->next->next->next = head->next->next; 


	removeLoopLinkedList(head);

	printList(head);

	
	

}