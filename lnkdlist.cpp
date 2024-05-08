#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        this -> data = 0;
        this -> next = nullptr;
    }
    Node(int d){
        this -> data = d;
        this -> next = nullptr;
    }
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void insertEnd(int);
    void forwardPrint();
};

void LinkedList::forwardPrint(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << "-";
        temp = temp -> next;
    }
}

void LinkedList::insertEnd(int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

Node* reverseKnodes(Node* head, int k){
    Node* curr = head;
    int count = 0;
    Node* nextNode;
    Node* prev = nullptr;
    while(curr != NULL && count < k){
        nextNode = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }
    if(head != NULL){
        head -> next = curr;
    }
    count = 0;
    while(count < k - 1 && curr != NULL){
        curr = curr -> next;
        count++;
    }

    if(curr != NULL){
        curr -> next = reverseKnodes(curr -> next, k);
    }
    return prev;

}


int main(){
    cout << "Linked List" << endl;
    int tc, n, m;
    cin >> tc;
    while(tc--){
        LinkedList lt;
        cin >> n;
        while(n--){
            cin >> m;
            lt.insertEnd(m);
        }
        lt.forwardPrint();
    }
    return 0;
}


// #include <iostream>
// #include <map>

// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;
//     Node(int d = 0) {
//         data = d;
//         next = nullptr;
//     }
// };

// class LinkedList {
// public:
//     Node* head;
//     LinkedList() {
//         head = nullptr;
//     }

//     void insertEnd(int);
//     void forwardPrint();
// };

// void LinkedList::forwardPrint() {
//     Node* temp = head;
//     while (temp != nullptr) {
//         cout << temp->data << "-";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void LinkedList::insertEnd(int data) {
//     Node* newNode = new Node(data);
//     if (head == nullptr) {
//         head = newNode;
//         return;
//     }
//     Node* temp = head;
//     while (temp->next != nullptr) {
//         temp = temp->next;
//     }
//     temp->next = newNode;
// }

// LinkedList intersection(Node* head1, Node* head2) {
//     map<int, int> m;
//     Node* curr = head1;
//     while (curr != nullptr) {
//         m[curr->data]++;
//         curr = curr->next;
//     }

//     curr = head2;
//     while (curr != nullptr) {
//         m[curr->data]++;
//         curr = curr->next;
//     }

//     LinkedList result;
//     Node* temp = nullptr;

//     for ( auto ch : m) {
//         if (ch.second > 1) {
//             Node* newNode = new Node(ch.first);
//             if (result.head == nullptr) {
//                 result.head = newNode;
//                 temp = newNode;
                
//             } else {
//                 temp->next = newNode;
//                 temp = temp->next;
//             }
//         }
//     }

//     return result;
// }

// int main() {
//     cout << "Linked List Intersection" << endl;
//     int tc, n, m, n1;
//     cin >> tc;

//     while (tc--) {
//         LinkedList lt1;
//         LinkedList lt2;
//         cin >> n;
//         while (n--) {
//             cin >> m;
//             lt1.insertEnd(m);
//         }

//         cin >> n1;
//         while (n1--) {
//             cin >> m;
//             lt2.insertEnd(m);
//         }

//         LinkedList result = intersection(lt1.head, lt2.head);
//         result.forwardPrint();
//     }

//     return 0;
// }
