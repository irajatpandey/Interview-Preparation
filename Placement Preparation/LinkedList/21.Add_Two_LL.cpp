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

LinkedList *addTwoLinkedList(LinkedList *head1, LinkedList *head2){

        int carry = 0;
        LinkedList *finaleHead = NULL;
        LinkedList *curr = finaleHead;

        while(head1 or head2){
            int x = (head1 != NULL) ? head1 -> data : 0;
            int y = (head2 != NULL) ? head2 -> data : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            if(curr != NULL){
                curr -> next = new LinkedList(sum % 10);
                curr = curr -> next;
            }
            else{
                curr = new LinkedList(sum % 10);
                finaleHead = curr;
                // cout << finaleHead -> data << endl;
            }

            if(head1) head1 = head1 -> next;
            if(head2) head2 = head2 -> next;

            if(carry != 0){
                curr -> next = new LinkedList(carry);
                // curr = curr -> next;
            }


        }
        return finaleHead;

}

int main(){

	LinkedList *head1 = NULL;
    LinkedList *head2 = NULL;

	int arr1[] = {2, 3, 0, 7, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {0, 6, 6, 9, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);


	for(int i = n1 - 1; i >= 0; i--)
		insert(&head1, arr1[i]);
        printList(head1);

    for(int i = n2 - 1; i >= 0; i--)
		insert(&head2, arr2[i]);
        printList(head2);

    LinkedList *ans = addTwoLinkedList(head1, head2);
	printList(ans);

    return 0;

}