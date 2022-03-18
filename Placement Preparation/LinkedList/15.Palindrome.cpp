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

bool isPalindrome1(LinkedList *head){
    vector<int> v;
    while(head){
        v.push_back(head->data);
        head = head -> next;
    }
    int j = v.size() - 1;

    for(int i = 0; i < v.size(); i++, j--){
        if(v[i] != v[j]){
            return false;
        }

    }
    return true;
}

LinkedList *middle(LinkedList *head){
    if(!head) return head;

    LinkedList *slow = head;
    LinkedList *fast = head;

    while(fast -> next and fast -> next -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
    
}
LinkedList *reverse(LinkedList *head){
    if(!head or !head -> next) return head;
    LinkedList *smallHead = reverse(head -> next);

    LinkedList *next = head -> next;
    next -> next = head;
    head -> next = NULL;

    return smallHead;
}
bool isPalindrome2(LinkedList *head){
    if(!head) return false;

    LinkedList *mid = middle(head);
    cout << mid -> data << endl;

    LinkedList *h1 = head;
    LinkedList *h2 = mid -> next;
    mid -> next = NULL;

    h2 = reverse(h2);

    while(h1 and h2){
        if(h1 -> data != h2 -> data)
            return false;
        h1 = h1 -> next;
        h2 = h2 -> next;

    }

    return true;
}
int main(){

	LinkedList *head = NULL;

	int arr[] = {10, 20, 30, 40, 30, 20 , 10};
    int n = sizeof(arr) / sizeof(arr[0]);

	for(int i = n - 1; i >= 0; i--)
		insert(&head, arr[i]);
	printList(head);

   if(isPalindrome2(head)){
       cout << "Yes\n";
   }
   else{
       cout << "No\n";
   }
	

}