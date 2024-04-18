// A Linear Data Structure which is a collection of Nodes
// Node consists of Data and the address of next node
// It is a Dynamic Data Structure which can grow and shrink on runtime
// Insertion and Deletion is easy as no shift needed
// Types of Linked List:--
// 1) Singly Linked List
// 2) Doubly Linked List
// 3) Circular Linked List
// 4) Circular Doubly Linked List

// Data can be integer point value and the address will be of pointer type value

// Singly Linked List:
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    ~Node(){
        int val=this->data;
        // memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data "<<val<<endl;
    }

};

void InsertAtHead(Node *&head,int d){
    Node *temp=new Node(d);
    temp->next=head;
    head=temp;
}

void InsertAtEnd(Node *&tail,int d){
    Node *temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
}
void InsertAtPosition(Node *&head,Node *&tail,int position,int d){
    if(position==1){
        InsertAtHead(head,d);
        return;
    }
    Node *temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        InsertAtEnd(tail,d);
    }
    Node *nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
    
}

void deleteNode(int position, Node*&head){
    if(position==1){
        // deleting first node
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }else{
        // deleting any middle or last node
        Node *curr=head;
        Node *prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}


void print(Node *&head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    Node *node1=new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    Node *head=node1;
    Node *tail=node1;
    print(head);
    InsertAtEnd(tail,12);
    print(head);
    InsertAtEnd(tail,15);
    print(head);
    InsertAtPosition(head,tail,1,22);
    print(head);
    InsertAtPosition(head,tail,4,23);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deleteNode(4,head);
    print(head);
    return 0;
}