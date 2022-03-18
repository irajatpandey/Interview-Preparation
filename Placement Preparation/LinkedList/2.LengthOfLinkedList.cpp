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
    int cnt = 0;
    while(head){
        cnt++;
        head = head -> next;
    }

    return cnt;
}

int main(){

	LinkedList *head = NULL;

	int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

	for(int i = n - 1; i >= 0; i--)
		insert(&head, arr[i]);
	printList(head);

    cout << "Length of the Linked List " << length(head) << endl;
	

}