#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// // Node -> the single entity of the tree used to store data
// // Root -> The top node of the tree
// // Ancestor -> The previous nodes of the specified nodes
// // Descendant -> The successor nodes of the specified nodes

// // Sample tree :-> 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1



class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildtree(Node* root){
    cout << "Enter the data :" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout << "Enter the data for inserting in left : " << endl;
    root -> left = buildtree(root -> left);
    cout << "Enter the data for inserting in right : " << endl;
    root -> right = buildtree(root -> right);
    return root;
}

void LevelOrderTraversal(Node* root ){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

void InOrder( Node* root ){
    if(root == NULL){
        return;
    }

    InOrder(root -> left);
    cout << root -> data << " ";
    InOrder(root -> right);
}

void PreOrder(Node* root ){
    if(root == NULL){
        return ;
    }

    cout << root -> data << " ";
    PreOrder(root -> left);
    PreOrder(root -> right);
}

void PostOrder(Node* root){
    if(root == NULL){
        return;
    }

    PostOrder(root -> left);
    PostOrder(root -> right);
    cout << root -> data << " ";
}


Node* buildFromLevelOrder(Node* root ){

    queue<Node*> q;
    cout << "Enter the data for root " << endl;
    int data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node for : " << temp -> data << endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1){
            temp -> left = new Node(leftData);
        }

        cout << "Enter right node for : " << temp -> data << endl;
        int rightData;
        cin >> rightData;
        if(rightData != -1){
            temp -> right = new Node(rightData);
        }
    }
}

// Height of a binary tree
int maxHeight( Node* root ){
    if(root == NULL){
        return 0;
    }

    int left = maxHeight( root -> left );
    int right = maxHeight( root -> right);

    int ans = max(left,right) + 1;
    return ans;
}

// Diameter of a binary tree : Also called the width is the number of nodes on the longest path between two end node

pair<int,int> diameterFast( Node* root ){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> leftCall = diameterFast(root -> left);
    pair<int,int> rightCall = diameterFast(root -> right);

    int op1 = leftCall.first;
    int op2 = rightCall.first;
    int op3 = leftCall.second + rightCall.second + 1;

    pair<int,int> ans;
    ans.first = max(op1, max(op2,op3));
    ans.second = max(leftCall.second,rightCall.second) + 1;

    return ans;
    
}

int diameter(Node* root ){
    return diameterFast(root).first;
}


// isBalanced Tree:

pair < bool, int> isBalancedFast( Node* root ){
    if(root == NULL){
        pair < bool, int> p = make_pair(true, 0);
        return p;
    }

    pair < bool, int > leftCall = isBalancedFast( root -> left);
    pair < bool, int > rightCall = isBalancedFast( root -> right);

    bool leftAns = leftCall.first;
    bool rightAns = rightCall.second;

    bool height = abs( leftCall.second - rightCall.second ) <= 1;

    pair < bool, int > ans;
    ans.second = max( leftCall.second, rightCall.second ) + 1;

    if( leftAns && rightAns && height ){
        ans.first = true;
    }else{
        ans.second = false;
    }

    return ans;
}

bool isBalanced( Node* root ){
    return isBalancedFast( root ).first;
}


// Identical Trees :
bool isIdentical( Node* r1, Node* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 == NULL && r2 != NULL){
        return false;
    }
    if(r1 != NULL && r2 == NULL){
        return false;
    }

    bool leftCall = isIdentical(r1 -> left, r2 -> left);
    bool rightCall = isIdentical(r1 -> right, r2 -> right);

    bool value = r1 -> data == r2 -> data;

    return leftCall && rightCall && value;

}



// Sum tree:

pair < bool, int > isSumTree( Node* root ) {
    if(root == NULL){
        pair < bool, int > p = make_pair(true, 0);
        return p;
    }

    if(root -> left == NULL && root -> right == NULL){
        pair < bool, int > p = make_pair(true, root -> data);
        return p;
    }

    pair < bool, int > leftAns = isSumTree(root -> left);
    pair < bool, int > rightAns = isSumTree(root -> right);

    bool left = leftAns.first;
    bool right = rightAns.first;
    bool condn = root -> data == leftAns.second + rightAns.second;

    pair < bool, int > ans;

    if(left && right && condn){
        ans.first = true;
        ans.second = 2 * root -> data;
    }else{
        ans.first = false;
    }
    return ans;

}


// Largest sum of nodes in bloddline

void solve(Node* root, int sum, int &maxSum, int len, int &maxlen){
    if(root == NULL){
        if(len > maxlen){
            maxlen = len;
            maxSum = sum;
        }else if(len == maxlen){
            maxSum = max(sum,maxSum);
        }
        return;
    }
    sum = sum + root -> data;
    solve(root -> left, sum ,maxSum, len, maxlen);
    solve(root -> right, sum ,maxSum, len, maxlen);
}

int SumOfLongRootPath(Node* root){
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, sum, maxSum, len, maxLen);
    return maxSum;
}


// Lowest common Ancestor :
Node* LowestCommonAncestor(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root -> data == n1 || root -> data == n2){
        return root;
    }

    Node* leftAns = LowestCommonAncestor(root -> left, n1, n2);
    Node* rightAns = LowestCommonAncestor(root -> right, n1, n2);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        return NULL;
    }
    
}


// K Sum Paths : Find the number of Paths in the tree whcoh ave their sum equal to K

void solve(Node* root, int k, int &count, vector < int > path){
    if(root == NULL){
        return;
    }
    path.push_back(root -> data);
    solve(root -> left, k, count, path);
    solve(root -> right, k ,count, path);
    int sum = 0;
    for(int i = path.size() - 1; i >=0 ; i--){
        sum += path[i];
        if(sum == k){
            count ++;
        }
    }
    path.pop_back();
}

int sumK(Node* root, int k){
    vector < int > path;
    int count = 0;
    solve(root, k, count, path);
    return count; 
}

int main(){
    Node* root = NULL;
    root = buildtree(root);
    cout << "Printing the level order traversal of binary tree : " << endl;
    LevelOrderTraversal(root);
    cout << endl;
    return 0;
}


