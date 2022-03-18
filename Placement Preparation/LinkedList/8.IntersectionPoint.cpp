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

// Time complexity O(n^2)
LinkedList *intersectionPoint1(LinkedList *head1, LinkedList *head2){
    LinkedList *temp = head2;
    while(head1){
        head2 = temp;
        while(head2){
            if(head1 -> data == head2 -> data){
                return head1;
            }
            head2 = head2 -> next;
        }
        head1 = head1 -> next;
    }
    return NULL;
}
int length(LinkedList *head){
    int cnt = 0;
    while(head){
        cnt++;
        head = head -> next;
    }

    return cnt;
}

LinkedList *intersectionPoint2(LinkedList *head1, LinkedList *head2){
    LinkedList *temp = head2;

    set<LinkedList *> s;
    while(head1){
        s.insert(head1);
        head1 = head1 -> next;
    }

    while(head2){
        if(s.find(head2) != s.end()){
            return head2;
        }
        head2 = head2 -> next;
    }
    return NULL;
    
}

LinkedList *intersectionPoint3(LinkedList *head1, LinkedList *head2){
    if(!head1 or !head2) return NULL;

    int cnt1 = length(head1);
    int cnt2 = length(head2);

    int d = abs(cnt1 - cnt2);

    if(cnt1 > cnt2){

        for(int i = 1; i <= d; i++){
            head1 = head1 -> next;
        }
    }
    else{
        for(int i = 1; i <= d; i++){
            head2 = head2 -> next;
        }

    }


    while(head1 -> next and head2 -> next){
        if(head1 == head2){
            return head1;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    return NULL;
}
int main(){
    LinkedList* head1 = new LinkedList(10); 
   
    LinkedList* newNode = NULL;
    LinkedList* head2 = new LinkedList(3); 
    
  
    newNode = new LinkedList(6); 
   
    head2->next = newNode; 
  
    newNode = new LinkedList(9); 
  
    head2->next->next = newNode; 
  
    newNode = new LinkedList(15); 
    
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = new LinkedList(30); 
    
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 
	
	cout << intersectionPoint1(head1, head2) -> data << endl; 
	cout << intersectionPoint2(head1, head2) -> data << endl;
    cout << intersectionPoint3(head1, head2) -> data << endl;


}