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

LinkedList *mergeTwoSortedLinkedList(LinkedList *head1, LinkedList *head2){
    if(head1 == NULL and head2 == NULL){
        return head1;
    }
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    int i = 0, j = 0;
    int length_firstLinkedList = length(head1);
    int length_secondLinkedList = length(head2);

    LinkedList * finalHead = NULL;
    LinkedList * finalTail = NULL;
    


    while(head1 and head2){
       if(head1 -> data < head2 -> data){
           if(finalHead == NULL){
            finalHead = head1;   
            finalTail = head1;
           }
        
        else{
            finalTail -> next = head1;
            finalTail = head1;
        }
        head1 = head1 -> next;
       }  

       else if(head1 -> data > head2 -> data ){
           if(finalHead == NULL){
               finalHead = head2;
               finalTail = head2;
           }
           else{
               finalTail -> next = head2;
               finalTail = head2;
           }
           head2 = head2 -> next;
       }     
    }

    while(head1){

        finalTail -> next = head1;
        finalTail = head1;
        head1 = head1 -> next;
    }

    while(head2){
        finalTail -> next = head2;
        finalTail = head2;
        head2 = head2 -> next;
    }

    return finalHead;
}

LinkedList *mergeTwoSortedLinkedListRecursive(LinkedList *head1, LinkedList *head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    if(head1-> data < head2 -> data){
        head1 -> next = mergeTwoSortedLinkedListRecursive(head1 -> next, head2);
        cout << "Head1 -> next " << head1-> next -> data << endl;
        cout << head1 -> data << endl;
        return head1;
    }
    else{
        head2 -> next = mergeTwoSortedLinkedListRecursive(head1, head2 -> next);
        return head2;
    }
}
int main(){

	LinkedList *head1 = NULL;
	LinkedList *head2 = NULL;


	int arr1[] = {1, 3};
	int arr2[] = {2, 4};

    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);


	for(int i = n1 - 1; i >= 0; i--)
		insert(&head1, arr1[i]);

    for(int i = n2 - 1; i >= 0; i--)
		insert(&head2, arr2[i]);

	printList(head1);
	printList(head2);

    LinkedList *smallHead = mergeTwoSortedLinkedListRecursive(head1, head2);
    printList(smallHead);


	

}