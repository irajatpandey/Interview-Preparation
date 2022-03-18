#include <iostream>
#include <unordered_map>
using namespace std;
 
// A linked list node with a random pointer
struct Node
{
    int data;
    Node* next;
    Node* random;
 
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->random = nullptr;
    }
 
    Node() {}
};
 
// Recursive function to print a linked list
void traverse(Node* head)
{
    // traverse the linked list
    while (head != nullptr)
    {
        // print current node data and random pointer data
        if (head->random) {
            cout << head->data << "(" << head->random->data << ") —> ";
        }
        else {
            cout << head->data << "(" << "X" << ") —> ";
        }
 
        // advance to the next node
        head = head->next;
    }
 
    cout << "null" << endl;
}
 
// Function to clone a linked list having random pointers
Node* cloneLinkedList(Node* head)
{
    /* 1. Create a duplicate of each node of the original linked list */
 
    // traverse the original linked list
    Node* curr = head;
    while (curr != nullptr)
    {
        // take a pointer to the next node in the original list
        Node* next = curr->next;
 
        // duplicate each node of the linked list
        Node* dup = new Node(curr->data);
 
        // associate each duplicate node with the next child of the original node
        curr->next = dup;
        dup->next = next;
 
        // advance to the next node in the original list
        curr = next;
    }
 
    /* 2. Update the random pointers of the duplicated nodes */
 
    // traverse the modified list
    curr = head;
    while (curr != nullptr)
    {
        // if a random pointer for the original node exists, set it for the clone
        if (curr->random != nullptr) {
            (curr->next)->random = (curr->random)->next;
        }
 
        // advance to the next node in the original list
        curr = (curr->next)->next;
    }
 
    /* 3. Extract the duplicate nodes from the modified list */
 
    // construct a dummy node whose next pointer points to the head
    // of the cloned linked list
    Node dummy;
 
    // maintain a tail node for the clone
    Node* tail = &dummy;
 
    // traverse the modified list
    curr = head;
    while (curr != nullptr)
    {
        // take a pointer to the next node in the original list
        Node* next = curr->next->next;
 
        // extract the duplicate
        Node* dup = curr->next;
        tail->next = dup;
        tail = dup;
 
        // restore the original linked list
        curr->next = next;
 
        // advance to the next node in the original list
        curr = next;
    }
 
    // return head node of the cloned list
    return dummy.next;
}
 
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
 
    head->random = head->next->next->next;
    head->next->next->random = head->next;
 
    cout << "Original linked list:\n";
    traverse(head);
 
    Node* clone = cloneLinkedList(head);
 
    cout << "\nCloned linked list:\n";
    traverse(clone);
 
    return 0;
}

