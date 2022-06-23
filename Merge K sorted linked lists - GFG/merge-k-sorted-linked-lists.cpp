// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           Node *dum=new Node(-1),*curr=NULL;
           priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
           for(int i=0;i<K;i++){
               if(arr[i]!=NULL)
               pq.push({arr[i]->data,i});
           }
           while(pq.size()>0){
               if(curr==NULL){
                    pair<int,int> x=pq.top();
                    pq.pop();
                    curr=arr[x.second];
                    arr[x.second]=arr[x.second]->next;
                    if(arr[x.second]!=NULL)pq.push({arr[x.second]->data,x.second});
                    dum->next=curr;
                    continue;
               }
               pair<int,int> x=pq.top();
                pq.pop();
                curr->next=arr[x.second];
                arr[x.second]=arr[x.second]->next;
                if(arr[x.second]!=NULL)pq.push({arr[x.second]->data,x.second});
                curr=curr->next;
           }
           return dum->next;
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends