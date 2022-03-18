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

LinkedList *pairWiseSwap(LinkedList *head){
    if(head == NULL or head -> next == NULL){return head;}
    LinkedList *curr = head;
    LinkedList *next = NULL;
    LinkedList *prev = NULL;

    // head = head -> next;
    // prev -> next = curr -> next;

    while(curr and curr -> next){
         LinkedList *check = head;
            while(check){
                cout << check -> data << " ";
                check = check -> next;
            }
            cout << endl;
         next = curr -> next;
         curr->next = next->next;
         next->next = curr;

 
        if (prev == NULL) {
            head = next; // head will point to the second node of the linked list
        }
        else {
            prev->next = next;
        }
 
        prev = curr;
        curr = curr->next;

    }
    return head;
}


int main(){

	LinkedList *head = NULL;

	int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	for(int i = 9; i >= 0; i--)
		insert(&head, arr[i]);

    head = pairWiseSwap(head);
	printList(head);

   
	

}