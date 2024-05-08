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

// Zig-zag traversal
void zigZagTraversal(Node* root) {
    if(root == NULL){
        return;
    }
    queue < Node* > q;
    q.push(root);
    q.push(NULL);
    bool leftToRight = false;
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
            if(leftToRight){
                if(temp -> left){
                    q.push(temp -> left);
                }
                if(temp -> right){
                    q.push(temp -> right);
                }
            }else{
                if(temp -> right){
                    q.push(temp -> right);
                }
                if(temp -> left){
                    q.push(temp -> left);
                }
            }
        }
        leftToRight = !leftToRight;
    }
}



vector < int >  zigZagTraversalCorrect(Node* root){
    vector < int > v1;
    if(root == NULL){
        return v1;
    }

    queue < Node* > q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int size = q.size();
        vector < int > v2(size);
        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            q.pop();

            int ind = leftToRight ? i : size - 1 - i;
            v2[ind] = temp -> data;

            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }

        for(auto i : v2){
            v1.push_back(i);
        }
        leftToRight = !leftToRight;
    }
    return v1;
}


// Boundary Traversal : 
void TraverseLeft(Node* root){
    if(root == NULL || (root -> left == NULL && root -> right ==NULL)){
        return;
    }
    cout << root -> data << " ";
    if(root -> left){
        TraverseLeft(root -> left);
    }else{
        TraverseLeft(root -> right);
    }
}

void printLeaf(Node* root){
    if(root == NULL){
        return;
    }
    printLeaf(root -> left);
    if(root -> left == NULL && root -> right == NULL){
        cout << root -> data << " ";
    }
    printLeaf(root -> right);
}

void TraverseRight(Node* root){
    if(root == NULL || (root -> left == NULL && root -> right == NULL)){
        return;
    }
    if(root -> right){
        TraverseRight(root -> right);
    }
    else{
        TraverseRight(root -> left);
    }
    cout << root -> data << " ";

}
void BoundaryTraversal(Node* root){
    if(root == NULL){
        return;
    }

    TraverseLeft(root);
    printLeaf(root);
    TraverseRight(root -> right);
}



// Vertical Order Traversal : 


// TopView of Binary Tree : 
vector < int > topView(Node* root){
    vector < int > ans;
    if(root == NULL){
        return ans;
    }

    map < int, int > topNode;
    queue < pair < Node*, int > > q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair < Node*, int > temp = q.front();

        Node* frontNode = temp.first;
        int hd = temp.second;
        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode -> data;
        }
        if(frontNode -> left){
            q.push(make_pair(frontNode -> left, hd -1));
        }
        if(frontNode -> right){
            q.push(make_pair(frontNode -> right, hd +1));
        }
    }
    for(auto i : topNode){
        ans.push_back(i.second);
    }
    return ans;
}



// Construct a tree from InOrder and PreOrder :

// InOrder : 1,6,8,7
// PreOrder : 1,6,7,8

void createMap(int in[], map < int, int > & nodetoIndex, int n){
    for(int i = 0; i < n; i++){
        nodetoIndex[in[i]] = i;
    }

}

Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map < int, int > &nodeToIndex){
    if(index >= n || inOrderStart > inOrderEnd){
        return NULL;
    }

    int element = pre[index];
    Node* temp = new Node(element);
    int position = nodeToIndex[element];
    // Recursive calls

    temp -> left = solve(in, pre, index, inOrderStart, position - 1, n, nodeToIndex);
    temp -> right = solve(in, pre, index, position + 1, inOrderEnd, n, nodeToIndex);
    return temp;
}


Node* buildFromOrder(Node* root, int inOrder[], int preOrder[], int n){
    map < int, int > nodeToIndex;
    createMap(inOrder, nodeToIndex, n);
    // Take index as root element
    // Find root element position in inorder
    int preOrderIndex = 0;
    Node* realBinaryTree = solve(inOrder, preOrder, preOrderIndex, 0, n-1, n, nodeToIndex);
    return realBinaryTree;
}



// Morris Traversal (Iterative InOrder Traversal) : 

void MorrisTraversal(Node* root){
    if(root == NULL){
        return;
    }
    Node* current = root;
    Node* pre;
    while(current != NULL){
        if(current -> left == NULL){
            cout << current -> data << " ";
            current = current -> right;
        }else{
            pre = current -> left;
            while(pre -> right != NULL && pre -> right != current){
                pre = pre -> right;
            }
            if(pre -> right == NULL){
                pre -> right  = current;
                current = current -> left;
            }else{
                pre -> right = NULL;
                cout << current -> data << " ";
                current = current -> right;
            }
        }
    }
}

// Flatten a binary tree to Linked List : 

void flatten(Node* root){
    Node* curr = root;
    while(curr != NULL){
        if(curr -> left){
            Node* pred = curr -> left;
            while(pred -> right){
                pred = pred -> right;
            }
            pred -> right = curr -> right;
            curr -> right = curr -> left;
            curr -> left = NULL;
        }
        curr = curr -> right;
    }
    // Alternative :
    // curr = root;
    // while(curr != NULL){
    //     curr -> left = NULL;
    //     curr = curr -> right;
    // }
}


// Minimum time to Burn Tree:
// create mapping and return target node:
Node* createParentMapping( Node* root, int target, map < Node*, Node* > &nodeToParent){
    Node* result = NULL;
    queue< Node* > q;
    q.push(root);
    nodeToParent[root] = NULL;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp -> data == target){
            result = temp;
        }
        if(temp -> left){
            nodeToParent[temp -> left] = temp;
            q.push(temp -> left);
        }
        if(temp -> right){
            nodeToParent[temp -> right] = temp;
            q.push(temp -> right);
        }

    }
    return result;
}





int burntree(Node* root, map < Node*, Node* > nodeToParent){
    map < Node*, bool > visited;
    queue < Node* > q;
    q.push(root);
    visited[root] = true;
    int ans = 0;
    while(!q.empty()){
        bool flag = 0;
        int size = q.size();
        for(int i = 0; i < size; i++) {
            // process neighbouring node : 
            Node* front = q.front();
            q.pop();
            if(front -> left && visited[front -> left]){
                q.push(front -> left);
                visited[front -> left] = true;
                flag = true;
            }
            if(front -> right && visited[front -> right]){
                flag = true;
                q.push(front -> right);
                visited[front -> right] = true;
            }
            if(nodeToParent[front] && visited[nodeToParent[front]]){
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true; 
            }
        }
        if(flag == 1){
            ans ++;
        }
    }
    return ans;
}


int MinTime( Node* root, int target ){
    // algo :
    // step 1 : Create nodeToParent mapping
    // step 2 : Find target node
    // step 3 : Burn the tree in min time
    

    map < Node*, Node* > nodetoParent;
    Node* targetNode = createParentMapping(root, target, nodetoParent);
    int ans = burntree(targetNode, nodetoParent);
    return ans;
}



int main(){
    Node* root = NULL;
    root = buildtree(root);
    cout << "Printing the level order traversal of binary tree : " << endl;
    LevelOrderTraversal(root);
    cout << " Zig Zag Order Traversal : " << endl;
    zigZagTraversal(root);
    // vector < int > ans = zigZagTraversalCorrect(root);
    // for(auto i : ans){
    //     cout << i << " ";
    // }
    // cout << endl;

    // BoundaryTraversal(root);
    return 0;
}


