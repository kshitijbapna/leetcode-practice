// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    map<int,int> m;
    Node *help(int in[],int preo[],int ins,int ine,int prs,int pre){
        if(ins>ine)return NULL;
        if(prs>pre)return NULL;
        Node* root=new Node(preo[prs]);
        int index=m[preo[prs]];
        int k=index-ins;
        // cout<<root->data<<" "<<ins+1<<" "<<ins+1+k<<" "<<prs<<" "<<index-1<<"\n";
        root->left=help(in,preo,ins,index-1,prs+1,prs+k);
        root->right=help(in,preo,index+1,ine,prs+1+k,pre);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        for(int i=0;i<n;i++)m[in[i]]=i;
        return help(in,pre,0,n-1,0,n-1);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends