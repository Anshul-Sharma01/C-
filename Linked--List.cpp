#include <iostream>
using namespace std;

// Linked list is a type of data structure which is a collection of nodes
// Node consists of data and the next node address
// Insetion and Deletion is easy as compared to arrays
// Types : 
// Singly Linked List
// Doubly Linked List
// Circular Linked List
// Circular Doubly Linked List

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};

void InsertAtBeg(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"-";
        temp=temp->next;
    }
    cout<<endl;
}

void InsertAtEnd(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
    
}

void InsertAtPos(Node* &head,Node* &tail,int position,int d){
    Node* temp = head;
    Node* curr=new Node(d);
    if(position==1){
        InsertAtBeg(head,d);
        return;
    }
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        InsertAtEnd(tail,d);
        return;
    }
    curr->next=temp->next;
    temp->next=curr;

}

void deleteNode(int position,Node* &head){
    if(position==1){
        Node* temp = head;
        head=head->next;
        delete temp;
    }else{
        // Deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt=1;
        while(cnt<=position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        delete curr;
    }
}

int main(){

    // cout<<"Linked--List"<<endl;
    Node* node1=new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    // Head pointed to newnode now
    Node* head=node1;
    Node* tail=node1;
    print(head);
    InsertAtEnd(tail,12);
    print(head);
    InsertAtEnd(tail,15);
    print(head);
    InsertAtPos(head,tail,2,22);
    InsertAtPos(head,tail,1,21);
    InsertAtPos(head,tail,5,23);
    print(head);

    return 0;
}