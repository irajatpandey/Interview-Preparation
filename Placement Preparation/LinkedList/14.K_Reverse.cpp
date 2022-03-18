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

    int cnt = 0;
    while(head){
        cnt ++;
        head = head -> next;
    }

    return cnt;
}

LinkedList *kReverse(LinkedList *head, int k){
    LinkedList *finalHead = NULL;
    LinkedList *prev = NULL, *curr = head;
    LinkedList *tail1 = NULL;
    LinkedList *tail2 = head;
    LinkedList *next = head;

    int n = length(head);
    cout << n << endl;
    while(n >= k){
        for(int i = 0; i < k; i++){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        if(finalHead == NULL){
            finalHead = prev;
        }

        if(tail1) tail1 -> next = prev;

        tail2 -> next = curr;
        tail1 = tail2;
        tail2 = curr;
        prev = NULL;
        n -= k;

    }

     return finalHead;

}

LinkedList *kReverse2(LinkedList *head, int k){
    int cnt = 0;

    LinkedList *curr = head;
    LinkedList *next = NULL;
    LinkedList *prev = NULL;
    while(curr and cnt < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    if(next) head -> next = kReverse2(next, k);
    return prev;

}
int main(){

	LinkedList *head = NULL;

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

	for(int i = n - 1; i >= 0; i--)
		insert(&head, arr[i]);

    head = kReverse2(head, 3);
	printList(head);

    
	

}