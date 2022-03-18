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

LinkedList *removeDuplicateFromSortedList(LinkedList *head){
    if(head == NULL) return head;
    LinkedList *curr = head -> next;
    LinkedList *prev = head;

    while(curr){
        if(curr -> data == prev -> data){
            LinkedList *temp = curr;
            prev -> next = curr -> next;
            curr = curr -> next;
            delete temp;
        }

        else{         
            prev = prev -> next;
            curr = curr -> next;
        }
    }
    return head;                        
}


int main(){

	LinkedList *head = NULL;

	int arr[] = {11, 11, 21, 43, 43, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
	for(int i = n - 1; i >= 0; i--)
		insert(&head, arr[i]);
	printList(head);


    head = removeDuplicateFromSortedList(head);
	printList(head);

   
	

}