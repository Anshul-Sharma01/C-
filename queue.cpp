#include <iostream>
#include <queue>
using namespace std;

// Queue works on FIFO(First In,First Out) principle


int main(){
    // cout<<"!!HELLO WORLD!!"<<endl;
    // create a queue
    queue<int> q;
    q.push(11);
    cout<<"Front of q : "<<q.front()<<endl;
    q.push(15);
    q.push(13);
    cout<<"Size of queue is : "<<q.size()<<endl;
    q.pop();
    cout<<"Size of queue is : "<<q.size()<<endl;
    if(q.empty()){
        cout<<"Queue is empty!!"<<endl;
    }else{
        cout<<"Queue is full!!"<<endl;
    }

    return 0;
}