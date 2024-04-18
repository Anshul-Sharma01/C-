#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(){
        data=0;
        next=nullptr;  //can also use NULL    
    }

    Node(int data){
        this->data=data;
        this->next=next;
    }

};

class LinkedList{
    public:
    Node *head;
    LinkedList(){
        head=NULL;
    }
    void insertEnd(int);
    void forwardPrint();
    
};

void LinkedList::insertEnd(int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void LinkedList::forwardPrint(){
    
}

//If head==NULL then linkedlist is empty;

int main(){
    cout<<"Linked List"<<endl;
    int tc,n,m;
    cin>>tc;
    while(tc--){
        LinkedList lt;
        cin>>n;
        while(n--){
            cin>>m;
            lt.insertEnd(m);
        }
        lt.forwardPrint();
    }

    return 0;
}