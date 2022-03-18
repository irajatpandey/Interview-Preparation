#include<bits/stdc++.h>
using namespace std;

class LinkedList{
	public:
		int data;
		LinkedList *next;
	LinkedList(int x){
		data = x;
        next = NULL;
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

LinkedList *reverse(LinkedList *head){
    if(!head || !head -> next){
        return head;
    }

    LinkedList *smallHead = reverse(head -> next);
    LinkedList *tail = head -> next;
    tail -> next = head ;
    head -> next = NULL;

    return smallHead;
}

LinkedList *add1ToLinkedList1(LinkedList *head){
    head = reverse(head);

    LinkedList *temp, *prev = NULL;
    LinkedList *res = head;
    int sum = 0, carry = 1;

    while(head){
        sum = carry + (head ? head -> data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        head -> data = sum;
        temp = head;
        head = head -> next;
    }

    if(carry > 0){
        temp -> next = new LinkedList(carry);
    }
    
    return reverse(res);
}

int main(){

	LinkedList *head = NULL;

	int arr[] = {9 , 9, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

	for(int i = n - 1; i >= 0; i--)
		insert(&head, arr[i]);

    head = add1ToLinkedList1(head);
	printList(head);

    return 0;

}