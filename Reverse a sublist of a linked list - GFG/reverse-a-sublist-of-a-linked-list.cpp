// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverse(Node* head){
        Node* prev=NULL,*curr=head;
        while(curr){
            Node* ne=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ne;
        }
        return prev;
    }
    Node* reverseBetween(Node* head, int m, int n)
    {
        if(m==n)return head;
        int i=1;
        Node* revs=NULL,*revs_prev=NULL;
        Node *reve=NULL,*reve_next=NULL;
        Node* curr=head;
        while(curr&&i<=n){
            if(i<m){
                revs_prev=curr;
            }
            if(i==m)revs=curr;
            if(i==n){
                reve=curr;
                reve_next=curr->next;
            }
            curr=curr->next;
            i++;
        }
        reve->next=NULL;
        reve=reverse(revs);
        if(revs_prev)revs_prev->next=reve;
        else head=reve;
        revs->next=reve_next;
        return head;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends