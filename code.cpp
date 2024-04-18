#include <iostream>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int sum1=0,sum2=0;
        int m,n;
        cin>>m;
        cin>>n;
        sum1=m*(m+1)/2;
        sum2=n*(n+1)/2;
        cout<<sum2-sum1<<endl;

    }
    return 0;
}