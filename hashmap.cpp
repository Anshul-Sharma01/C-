// #include <iostream>
// #include <unordered_map>
// using namespace std;
// int main(){
//     // Creation
//     unordered_map<string,int> m;
//     // Insertion
//     // 1
//     pair<string,int> p = make_pair("anshul",3);
//     m.insert(p);
//     // 2
//     pair<string,int> pair2("Love",2);
//     m.insert(pair2);
//     // 3
//     m["mera"]=1;
//     m["mera"]=2;  //Updation of previous key


//     // Searching
//     cout<<m["mera"]<<endl;
//     cout<<m.at("anshul")<<endl;
//     // cout<<m["unknownKey"]<<endl; //will give 0
//     // cout<<m.at("unknownkey")<<endl;  // ERROR
//     cout<<m.size()<<endl;

//     // To check Presence
//     cout<<m.count("anshul")<<endl;

//     // erase
//     // m.erase("Love");
//     // cout<<m.size()<<endl;

//     // Iteration
//     for(auto e:m){
//         cout<<e.first<<" "<<e.second<<endl;
//     }

//     // Iterators
//     unordered_map<string,int> :: iterator it=m.begin();
//     while(it!=m.end()){
//         cout<<it->first<<" "<<it->second<<endl;
//         it++;
//     }

//     // When we use unordered_map , elements are printed in random order and ordered of insertions is not maintained wheras when we use (ordered)map,order of insertion is preserved and the elements are printed in that order
//     return 0;
// }

// #include <iostream>
// #include <bits/stdc++.h>
// #include <unordered_map>

// using namespace std;
// int main(){
//     int arr[5]={1,2,3,1,2};
//     unordered_map<int,int> count;
//     for(int i=0;i<5;i++){
//         count[arr[i]]++;
//     }
//     int maxi=INT_MIN,ans=0;
//     for(auto i:count){
//         if(i.second>maxi){
//             maxi=i.second;
//             ans=i.first;
//         }
//     }

    
//     return 0;
// }



// Open hashing:--->Same place pr dal do,that place already contains linked ist known as Separate Chaining
// Closed Addressing:---> Element o next khali space pr daldo and that khali place is determined by a function
// hi(a)=h(a)+Fi(a)    {Linear Probbing}
// F(i)->i^2  {Quadratic probbing}
// Complexity Analysis:-->
// Hash Code: O(1)  {assuming n>>k} 
// n/b-->load factor {assuming n/b <0.7}
// If n/b -->n inc. than  inc.