// #include <iostream>
// using namespace std;
// int main(){
//     // int a=2,b=4;
//     // cout<<"a&b:"<<(a&b)<<endl;
//     // cout<<"a|b:"<<(a|b)<<endl;
//     // cout<<"a^b:"<<(a^b)<<endl;
//     // cout<<"~a:"<<(~a)<<endl;
//     // cout<<"~b:"<<(~b)<<endl;
//     // cout<<(2<<4)<<endl;
//     // cout<<(4<<2)<<endl;
//     // cout<<(4>>2)<<endl;
//     // cout<<(2>>4)<<endl;
//     return 0;
    
// }


#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    int ans=0;
    int i=0;
    while(n!=0){
        int bit=n&1;
        ans=(bit*pow(10,i))+ans;
        n=n>>1;
        i++;
    }
    cout<<ans<<endl;


    return 0;
}