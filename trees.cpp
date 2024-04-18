#include <iostream>
#include <queue>

using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildtree(node* root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin >> data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for inserting in left of : "<<data<<endl;
    root -> left = buildtree(root -> left);
    cout<<"Enter the data for inserting in right of : "<<data<<endl;
    root -> right = buildtree(root -> right);
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            // Previous level complete traversed;
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp -> data <<" ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }

        }
    }
}

void inorder(node* root){
    // base case
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout<<root -> data << " ";
    inorder(root -> right);
}

void preorder(node* root){
    // base case
    if(root == NULL){
        return;
    }

    cout<<root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node* root){
    // base case
    if(root == NULL){
        return;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout<<root -> data << " ";
}

node* buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter the data for root : "<<endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for : "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for : "<<temp -> data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
}


int main(){
    node* root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // Creating a tree;

    // root = buildtree(root);
    // // Level order Traversal;
    // cout<<"Printing the level order Traversal :-- "<<endl;
    // levelOrderTraversal(root);

    // Inorder traversal
    cout<<"InOrder Traversal :--"<<endl;
    inorder(root);
    cout<<endl;

    // Preorder Traversal
    cout<<"PreOrder Traversal :--"<<endl;
    preorder(root);
    cout<<endl;

    // PostOrder Traversal
    cout<<"PostOrder Traversal :--"<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

// Types of Traversal in Tree : 
// 1. Level Order Traversal
// 2. InOrder Traversal
// 3. PreOrder Traversal
// 4. PostOrder Traversal
// 5. Iteration Traversal (without using recursion)


// Build Fro LevelOrder
// InOrder : LNR
// PreOrder : NLR
// PostOrder : LRN