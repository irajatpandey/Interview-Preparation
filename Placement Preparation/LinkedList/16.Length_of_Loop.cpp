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

int lengthOfLoop(LinkedList *head){
    if(!head) return 0;

    LinkedList *slow = head, *fast = head;
    while(fast -> next and fast -> next -> next){

        fast = fast -> next -> next;
        slow = slow -> next;
        if(slow == fast) break;
    }
    LinkedList *temp = slow;
    int cnt = 1;

    while(temp -> next != slow){
        temp = temp -> next;
        cnt++;
    }

    return cnt;
}

int main(){

	LinkedList *head = NULL;

	int arr[] = {20, 4, 15, 10};
	for(int i = 0; i < 10; i++)
		insert(&head, arr[i]);
	head->next->next->next->next = head; 

    cout << lengthOfLoop(head) << endl;


	

}