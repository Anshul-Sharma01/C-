// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// bool isUniqueChars(string str){
//     for(int i=0;str[i]!='\0';i++){
//         for(int j=i+1;str[j]!='\0';j++){
//             if(str[i]==str[j]){
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }
// int main(){
//     int tc;
//     cout<<"No of testcases:";
//     cin>>tc;
//     while(tc--){
//         string str;
//         cin>>str;
//         if(isUniqueChars(str)){
//             cout<<"YES";
//         }else{
//             cout<<"NO";
//         }
//         cout<<endl;
//     }
//     // for(int i=0;i<size;i++){
//     //     if(arr[i]>=0){
//     //         for(int j=0;j>0;j--){
//     //             if(arr[j-1]<0){
//     //                 int temp=arr[j-1];
//     //                 arr[j-1]=arr[j];
//     //                 arr[j]=temp; 
//     //             }
//     //             else{
//     //                 break;
//     //             }
//     //         }
//     //     }
//     // }
//     return 0;
// }
#include<iostream>
using namespace std;
int totalWays(int n){
    int a=1,b=1,c=2,d;
    if(n==0||n==1){
        return a;
    }
    if(n==2){
        return c;
    }

    for(int i=3;i<=n;i++){
        d=a+b+c;
        a=b;
        b=c;
        c=d;
    }
    return d;
}
int main(){
    cout<<totalWays(5)<<endl;
    cout<<totalWays(6);
    return 0;
}

