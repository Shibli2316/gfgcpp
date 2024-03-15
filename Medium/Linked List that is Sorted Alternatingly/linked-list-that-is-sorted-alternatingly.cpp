//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    void sort(Node **head) {
    if (*head == nullptr || (*head)->next == nullptr)
        return;

    Node *ascending_head = nullptr;
    Node *ascending_tail = nullptr;
    Node *descending_head = nullptr;
    Node *descending_tail = nullptr;

    Node *current = *head;
    while (current != nullptr) {
        Node *next_node = current->next;
        current->next = nullptr;
        
        if (ascending_head == nullptr) {
            ascending_head = current;
            ascending_tail = current;
        } else if (ascending_tail->data <= current->data) {
            ascending_tail->next = current;
            ascending_tail = current;
        } else {
            current->next = ascending_head;
            ascending_head = current;
        }

        current = next_node;
        
        if (current != nullptr) {
            next_node = current->next;
            current->next = nullptr;
        
            if (descending_head == nullptr) {
                descending_head = current;
                descending_tail = current;
            } else if (descending_tail->data >= current->data) {
                descending_tail->next = current;
                descending_tail = current;
            } else {
                current->next = descending_head;
                descending_head = current;
            }

            current = next_node;
        }
    }

    // Reverse the descending segment
    Node *prev = nullptr;
    Node *temp = descending_head;
    while (temp != nullptr) {
        Node *next_node = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next_node;
    }
    descending_head = prev;

    // Merge the two segments
    Node *sorted_head = nullptr;
    Node *sorted_tail = nullptr;
    while (ascending_head && descending_head) {
        if (ascending_head->data <= descending_head->data) {
            if (sorted_head == nullptr) {
                sorted_head = ascending_head;
                sorted_tail = ascending_head;
            } else {
                sorted_tail->next = ascending_head;
                sorted_tail = ascending_head;
            }
            ascending_head = ascending_head->next;
        } else {
            if (sorted_head == nullptr) {
                sorted_head = descending_head;
                sorted_tail = descending_head;
            } else {
                sorted_tail->next = descending_head;
                sorted_tail = descending_head;
            }
            descending_head = descending_head->next;
        }
    }
    if (ascending_head)
        sorted_tail->next = ascending_head;
    else
        sorted_tail->next = descending_head;

    *head = sorted_head;
}

};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends