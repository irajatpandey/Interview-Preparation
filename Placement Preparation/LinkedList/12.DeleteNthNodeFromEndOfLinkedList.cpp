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

int length(LinkedList *head){
    if(!head) return 0;

    return 1 + length(head -> next);
    
}
LinkedList* deleteNthFromLast2(LinkedList *head, int n){
    LinkedList *first = head;
    LinkedList *second = head;

    for(int i = 1; i <= n && second ; i++){
        second = second -> next;
    }

    if(second == NULL){
        return NULL;
    }
    while(second -> next != NULL){
        first = first -> next;
        second = second -> next;
    }
    LinkedList *temp = first -> next;
  
    first -> next = first -> next -> next;
    delete temp;

    return head;
}


int main(){

	LinkedList *head = NULL;

	int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	for(int i = 9; i >= 0; i--)
		insert(&head, arr[i]);

    head = deleteNthFromLast2(head, 4);
	printList(head);

	return 0;
}