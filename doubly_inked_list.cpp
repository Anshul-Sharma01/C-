// #include <iostream>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node* prev;
//     Node* next;

//     Node(int d){
//         data=d;
//         prev=nullptr;
//         next=nullptr;
//     }


// };

// // forward traversal{
// // Node *curr=head;
// // while(curr!=nullptr){
// //     curr=curr->next;
// //  }
// // }

// // Backward Traversal
// // Node *curr=last;
// // while(curr!=nullptr){
// //     curr=curr->prev;
// // }

// // Insertion:->

// // InsertAtBeginning(){
// // First step is to create a node in every round'
// // Node* newnode=new Node(data);
// // newnode->next=head;
// // head->prev=newnode;
// // head=newnode;
// // }

// // Node search(int data){
// //     Node* curr=head;
// //     while(curr!=nullptr){
// //         if(curr->data=data){
// //             return curr;
// //         }
// //         curr=curr->next;

// //     }
// //     return nullptr;
// // }

// void deleteNodeAtStart(){
//     head=head->next;
//     head->prev=nullptr;

// }

// void deleteNodeAtEnd(){
//     tail->prev->next=nullptr;
//     tail=tail->prev;
// }

// void pos(int position){
//     pos->prev->next=pos->next;
//     pos->next->prev=pos->prev;

// }

// // InsertAtEnd(){
// // Node* newnode=new Node(data);
// // last->next=newnode;
// // newnode->prev=last;
// // last=newnode;
// // }

// // Node* curr=head;
// // while(curr->next!=NULL){
// //     curr=curr->next;
// // }

// // InsertAtMiddle(){
// // Node* newnode=new Node(data);
// // newnode->prev=n1;
// // newnode->next=n1->next;
// // n1->next->prev=newnode;
// // n1->next=newnode;
// // }


// // void InsertAtEnd(){

// // }

// int main(){
//     cout<<"Hello World"<<endl;
//     Node* node1=new Node(10);
//     cout<<node1->data<<" "<<node1->prev<<" "<<node1->next<<endl;
//     return 0;
// }