#include<bits/stdc++.h>
using namespace std;

class LinkedList{
	public:
		int data;
		LinkedList *next;
        bool visited;
	LinkedList(int x){
		data = x;
        visited = false;
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

//  If Modification to Linked List Structre is Allowed
bool detectLoop1(LinkedList *head){
    if(head == NULL or head -> next == NULL){
        return false;
    }
    while(head){
        if(head -> visited == false){
            head -> visited = true;
        }
        else
            return true;
        head = head -> next;
    }

    return false;

}

bool detectLoopHash(LinkedList *head){
    set<LinkedList *> container;

    while(head){
        if(container.find(head) != container.end()){
            return true;
        }
       container.insert(head);
       head = head -> next;
    }
    return false;

}

bool detectLoop2(LinkedList *head){
    if(head == NULL || head -> next == NULL) return false;
    LinkedList *slow = head;
    LinkedList *fast = head;

    while(fast and fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
            return true;
      
    }
    return false;
}



int main(){

	LinkedList *head = NULL;

	int arr[] = {20, 4, 15, 10};
	for(int i = 0; i < 10; i++)
		insert(&head, arr[i]);
	head->next->next->next->next = head; 

	if(detectLoop1(head)) cout << "true\n";
	else cout << "false\n";
	

	if(detectLoopHash(head)) cout << "true\n";
	else cout << "false\n";
	
    if(detectLoop2(head)) cout << "true\n";
	else cout << "false\n";

}