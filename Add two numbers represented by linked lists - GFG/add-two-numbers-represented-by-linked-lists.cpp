// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node* head)
    {
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    int size(Node *head){
        int s=0;
        while(head!=NULL){
            s++;
            head=head->next;
        }
        return s;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        if(first==NULL)return second;
        if(second==NULL)return first;
        Node* l1=reverse(first);
        Node* l2=reverse(second);
        
        
        int s1=size(l1),s2=size(l2);
        if(s1<s2)swap(l1,l2);
        Node* h1=l1;
        Node* h2=l2;
        int carry=0;
        while(l1!=NULL){
            int k;
             if(l2!=NULL)
             k=l1->data+l2->data+carry;
             else
             k=l1->data+carry;
             if(k>9)
              carry=1;
              else carry=0;
              
              k=k%10;
              l1->data=k;
              l1=l1->next;
              if(l2!=NULL)l2=l2->next;
        }
        Node* a=h1;
        while(carry){
            if(a->next==NULL){
                Node * xx=new Node(1);
                a->next=xx;
                break;
            }
            a=a->next;
        }
        
        l1=reverse(h1);
        return l1;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends