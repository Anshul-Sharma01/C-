#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int insertionSort(int *arr,int n){
    cout<<"This is an Insertion Sort Function!!";
    int j=0;
    int temp;
    for(int i=0;i<n-1;i++){
        temp=arr[i];
        for(j=i-1;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }else{
                break;
            }
        }
    }
    arr[j+1]=temp;
    
}
int main(){
    cout<<"!!Insertion Sort!!"<<endl;
    int arr[11]={20,46,24,2,77,67,21,1,9,55,0};
    int n=11;
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}