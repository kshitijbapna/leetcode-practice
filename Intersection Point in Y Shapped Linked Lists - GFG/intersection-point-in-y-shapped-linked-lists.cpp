// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    Node* cur1=head1,*cur2=head2;
    int cnt1=0,cnt2=0;
    while(cur1){
        cnt1++;
        cur1=cur1->next;
    }
    while(cur2){
        cnt2++;
        cur2=cur2->next;
    }
    int diff=abs(cnt1-cnt2);
    cur1=head1;
    cur2=head2;
    if(cnt1>cnt2)for(int i=0;i<diff;i++)cur1=cur1->next;
    else for(int i=0;i<diff;i++)cur2=cur2->next;
    while(cur1){
        // cout<<cur1->data<<" "<<cur2->data<<"\n";
        if(cur1==cur2)return cur1->data;
        cur1=cur1->next;
        cur2=cur2->next;
    }
    return -1;
}

