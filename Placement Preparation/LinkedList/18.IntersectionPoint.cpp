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
int length(LinkedList *head){
    int cnt = 0;
    while(head){
        cnt++;
        head = head -> next;
    }

    return cnt;
}

LinkedList *intersectionPoint(LinkedList *head1, LinkedList *head2){

    int k = (length(head1) - length(head2));
    if (k < 0) {
        swap(head1, head2);
    }
    
    for (int i = 0; i < k && head1; i++) {
        head1 = head1->next;
    }
 
    // simultaneously move both lists at the same speed until they meet
    while (head1 && head2)
    {
        // if both lists meet any node, then that node is the intersection point
        if (head1 == head2) {
            return head1;
        }
 
        // advance both lists by one node
        head1 = head1->next;
        head2 = head2->next;
    }
 
    // return null if both lists don't meet
    return nullptr;
}

int main(){

	LinkedList *head1 = NULL;
	LinkedList *head2 = NULL;

    // construct the first linked list (1 —> 2 —> 3 —> 4 —> 5 —> null)
	LinkedList* first = nullptr;
    for (int i = 7; i > 0; i--) {
        insert(&first, i);
    }
 
    // construct the second linked list (1 —> 2 —> 3 —> null)
    LinkedList* second = nullptr;
    for (int i = 3; i > 0; i--) {
        insert(&second, i);
    }
 
    // link tail of the second list to the fourth node of the first list
    second->next->next->next = first->next->next->next;
 
    LinkedList* addr = intersectionPoint(first, second);
    if (addr) {
        cout << "The intersection point is " << addr->data << endl;
    }
    else {
        cout << "The lists do not intersect." << endl;
    }
 
	

}