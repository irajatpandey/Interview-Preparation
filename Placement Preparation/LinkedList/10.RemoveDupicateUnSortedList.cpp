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
LinkedList *removeDuplicateFromUnSortedList2(LinkedList *head){
    set<int> s;
    LinkedList *prev = NULL;
    LinkedList *temp = head;

    while(head){
        if(s.find(head -> data) != s.end()){
            prev -> next = head -> next;
            delete head;
        }
        else{
            s.insert(head -> data);
            prev = head;
        }
        head = prev -> next;
    }
    return temp;
}
LinkedList *removeDuplicateFromUnSortedList(LinkedList *head){
    if(!head) return NULL;

    LinkedList *t1 = head;

    while(t1 and t1 -> next){
        LinkedList *t2 = t1;

        while(t2 -> next != NULL){
            if(t1 -> data  ==  t2 -> next -> data){
                LinkedList *temp = t2 -> next;
                t2 -> next = t2 -> next -> next;
                delete temp;
            }
            else
            t2 = t2 -> next;
            
        }
        t1 = t1 -> next;

    }
    return head;
}


int main(){

	LinkedList *head = NULL;

	int arr[] = {11, 21, 11, 43, 21, 43};
    int n = sizeof(arr) / sizeof(arr[0]);
	for(int i = n - 1; i >= 0; i--)
		insert(&head, arr[i]);

    head = removeDuplicateFromUnSortedList2(head);
	printList(head);

   
	

}