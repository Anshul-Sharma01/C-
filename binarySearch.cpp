// #include <iostream>
// using namespace std;
// int binarySearch(int* arr,int n,int k){
//     int low=0;
//     int high=n-1;
//     int mid=0;
//     while(low<=high){
//         mid=low+(high-low)/2;
//         if(arr[mid]==k){
//             return mid;
//         }else if(arr[mid]<k){
//             low=mid+1;
//         }else if(arr[mid]>k){
//             high=mid-1;
//         }
//     }
//     return -1;
// }
// int main(){
//     int arr[6]={2,4,6,8,12,16};
//     int k=16;
//     cout<<binarySearch(arr,6,k);
//     return 0;
// }


// #include <iostream>
// using namespace std;

// void occure(int *arr,int n,int k){
//     int low=0;
//     int high=n-1;
//     int mid=0;
//     int l=-1,h=-1;
//     while(low<=high){
//         mid=low+(high-low)/2;
//         if(arr[mid]==k){
//             l=mid;
//             low=mid+1;
//         }else if(arr[mid]<k){
//             low=mid+1;
//         }else if(arr[mid]>k){
//             high=mid-1;
//         }
//     }
//     low=0;
//     high=n-1;
//     while(low<=high){
//         mid=low+(high-low)/2;
//         if(arr[mid]==k){
//             h=mid;
//             high=mid-1;
//         }else if(arr[mid]<k){
//             low=mid+1;
//         }else if(arr[mid]>k){
//             high=mid-1;
//         }
//     }
//     cout<<h<<" "<<l;
// }

// int main(){
//     int arr[9]={0,5,5,6,6,6,8,8,8};
//     int k=5;
//     int ans[2];
//     occure(arr,9,k);
    
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int PeakElement{
    
// }

// int main(){
//     int arr[4]={0,10,5,2};
//     cout<<PeakElement(arr,4)<<endl;
//     return 0;
// }