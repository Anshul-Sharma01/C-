// #include <iostream>
// #include <array>
// using namespace std;
// int main(){
//     cout<<"Hello World"<<endl;
//     array<int,4> a={1,2,3,4};
//     cout<<"Size of array->"<<a.size()<<endl;
//     cout<<"Element at 2nd index->"<<a.at(2)<<endl;
//     cout<<"Empty or not->"<<a.empty()<<endl;
//     cout<<"First Element->"<<a.front()<<endl;
//     cout<<"Last Elmenet->"<<a.back()<<endl;
    
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//     vector<int> v;
//     cout<<"Capacity->"<<v.capacity()<<endl;   // Capacity is total memory allocated to this vector
//     cout<<"Size->"<<v.size()<<endl; // size is total elements present at the instant
//     v.push_back(1); //insertion
//     v.push_back(2); //insertion
//     v.push_back(2); //insertion
//     v.pop_back(); //deletion(last element only)
//     cout<<"Element at 2nd index->"<<v.at(2)<<endl;
//     v.clear(); //clear 
//     // v.begin() , v.end()
//     cout<<"Front->"<<v.front()<<endl;
//     cout<<"Back->"<<v.back()<<endl;
//     return 0;
// }


// #include <iostream>
// #include <deque>
// // Both insertions and deletions can be performed at the both ends 
// // Not contiguous like arrays and vectors
// // Dynamic
// // Random access possible
// using namespace std;
// int main(){
//     deque<int> d;
//     d.push_back(1);  // Insertion at last;
//     d.push_front(2); // Insertion at front;
//     for(auto i:d){
//         cout<<i<<endl;
//     }
//     // d.pop_back(); //Deletion at last;
//     // d.pop_front(); //Deletion at first 
//     cout<<"Element at 2nd Index"<<d.at(2)<<endl;
//     cout<<"Front->"<<d.front()<<endl;
//     cout<<"Back->"<<d.back()<<endl;
//     cout<<"Empty or not"<<d.empty()<<endl;
//     d.erase(d.begin(),d.begin()+1);
//     return 0;
// }


// #include <iostream>
// #include <list>
// // List implementation is done by doubly linked list
// // Accessing can be done only Traversing
// using namespace std;
// int main(){
//     list<int> l;
//     list<int> n(5,100);
//     l.push_back(1);  // Insertion at back;
//     l.push_front(2); // Insertion at front;
//     for(auto i:l){
//         cout<<i<<" ";
//     }
//     // l.erase(l.begin()) // deletes the element present at the iterator
//     return 0;
// }


// #include <iostream>
// #include <stack>
// // LIFO
// using namespace std;
// int main(){
//     stack<string> s;
//     s.push("Love");
//     s.push("Anshul");
//     s.push("Sharma");
//     cout<<"Top Element->"<<s.top()<<endl; //returns last element i.e. last entered
//     s.pop();
//     s.empty();
//     s.size();

//     return 0;
// }


// #include <iostream>
// #include <queue>
// using namespace std;
// int main(){
//     queue<string> q;
//     q.push("Love");
//     q.push("Anshul");
//     q.push("Sharma");
//     cout<<"Size before popping->"<<q.size()<<endl;
//     cout<<"First Element->"<<q.front()<<endl;
//     q.pop();
//     cout<<"First Element after popping->"<<q.front()<<endl;
//     cout<<"Size after pop->"<<q.size()<<endl;
//     return 0;
// }

// #include <iostream>
// #include <queue>
// // First element will be always greatest
// using namespace std;
// int main(){
//     // maxheap
//     priority_queue<int> maxi;
//     // minheap
//     priority_queue<int,vector<int>,greater<int>> mini;
//     maxi.push(1);
//     maxi.push(3);
//     maxi.push(2);
//     maxi.push(0);
//     cout<<"Size->"<<maxi.size()<<endl;
//     int n=maxi.size();
//     for(int i=0;i<n;i++){
//         cout<<maxi.top()<<" ";
//         maxi.pop();
//     }cout<<endl;

//     mini.push(5);
//     mini.push(1);
//     mini.push(0);
//     mini.push(4);
//     mini.push(3);
//     int m=mini.size();
//     for(int i=0;i<m;i++){
//         cout<<mini.top()<<" ";
//         mini.pop();
//     }
//     cout<<endl;
//     cout<<"Khali h ky bhai->"<<mini.empty()<<endl;
//     return 0;
// }


// #include <iostream>
// #include <set>
// // Stores only unique elements
// // Implementation by BST
// // Always sorted except than unorederd_set
// using namespace std;
// int main(){
//     set<int> s;

//     s.insert(5);
//     s.insert(5);
//     s.insert(5);
//     s.insert(1);
//     s.insert(6);
//     s.insert(6);
//     s.insert(0);
//     s.insert(0);
//     s.insert(0);

//     for(auto i:s){
//         cout<<i<<" "<<endl;
//     }
//     cout<<endl;
//     set<int>::iterator it=s.begin();
//     it++;
//     s.erase(it);
//     for(auto i:s){
//         cout<<i<<endl;
//     }
//     cout<<s.count(5)<<endl; //Tells if the element is present or not (returns bool ans)
//     set<int>::iterator itr=s.find(5); //returns the iterator of s.find(5);
//     for(auto it=itr;it!=s.end();it++){
//         cout<<*it<<" ";
//     }cout<<endl;
//     return 0;
// }


#include <iostream>
#include <map>
using namespace std;
int main(){
    map<int,string> m;
    m[1]="Anshul";
    m[2]="Sharma";
    m[3]="Ansh";
    m.insert({5,"bheem"});
    cout<<"Before erase->"<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<"Finding 13->"<<m.count(13)<<endl;
    m.erase(13);
    cout<<"After Erase->"<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}