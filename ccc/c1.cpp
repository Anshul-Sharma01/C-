#include <iostream>
using namespace std;
int main(){
  long long int n;
  cin>>n;
  long long int ln=n-1;
  long long int ele=0;
  long long int sum1=0;
  for(int i=1;i<=ln;i++){
    cin>>ele;
    sum1+=ele;
  }
  
  long long int sum2=n*(n+1)/2;
  // cout<<sum1<<" "<<sum2<<endl;
  cout<<sum2-sum1<<endl;
  return 0;
}