// #include <iostream>
// #include <stack>
// using namespace std;
// int main(){
//     stack<int> my_stack;
//     my_stack.push(10);
//     my_stack.push(20);
//     my_stack.pop();
//     my_stack.pop();
//     cout<<my_stack.empty()<<endl;
//     cout<<my_stack.size()<<endl;
//     cout<<"Hello World!!"<<endl;
//     my_stack.push(29);
//     cout<<my_stack.top()<<endl;
//     return 0;
// }


#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    int frontelement=q.front();
    cout<<frontelement<<endl;
    int backelement=q.back();
    cout<<backelement<<endl;

    int queuesize=q.size();
    cout<<queuesize<<endl;
    
    return 0;
}