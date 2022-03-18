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
int printNthFromLast2(LinkedList *head, int n){
    LinkedList *first = head;
    LinkedList *second = head;

    for(int i = 1; i <= n && second ; i++){
        second = second -> next;
    }

    if(second == NULL){
        return -1;
    }
    while(second  != NULL){
        first = first -> next;
        second = second -> next;
    }
    return first -> data;
}
int printNthFromLast(LinkedList *head, int n){
    int cnt = length(head);

    if(n > cnt) return -1;

    for(int i = 1; i < (cnt - n); i++)
        head = head -> next;
    return head -> data;

}

int main(){

	LinkedList *head = NULL;

	int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	for(int i = 9; i >= 0; i--)
		insert(&head, arr[i]);
	printList(head);

    cout << printNthFromLast2(head, 4);
	return 0;
}