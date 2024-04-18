#include <iostream>
using namespace std;
int main(){
  long int n;
  cin>>n;
  long int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  long int sum,cnt=0;
  for(int i=1;i<n;i++){
    if(arr[i]<arr[i-1]){
      sum=arr[i-1]-arr[i];
      cnt+=sum;
      arr[i]+=sum;
    }
  }
  cout<<cnt;
  return 0;
}