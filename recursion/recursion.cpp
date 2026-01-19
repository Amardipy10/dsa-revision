#include<iostream>
#include <vector>
using namespace std;
// int sum_of_n(int n){
//     if(n==0){
//         return 0;
//     }
//     return (n+sum_of_n(n-1));
// }

// int main(){
//     int ans=sum_of_n(5);
//     cout<<ans;
// }

// int factorial(int n){
//     if(n==0){
//         return 1;
//     }
//     else{
//     return (n*factorial(n-1));
//     }
// }
// int main(){
//     int ans=factorial(5);
//     cout<<ans;
// }

// int fibonacci(int n){
    // if(n==1 || n==0){
    //     return n;
    // }
    // else{
    //     return fibonacci(n-1)+fibonacci(n-2);
    // }
// }

// int main(){
//     int ans=fibonacci(2);
//     cout<<ans;
// }

// bool issorted(vector<int>& arr, int n){
//     if(n==0||n==1){
//         return true;
//     }
//     else if(arr[n-1]>arr[n-2]){
//             return issorted(arr,n-1);
//         }
//     else{
//         return false;
//     }
// }

// int binary_search(vector<int>& arr, int start, int end, int target){
//     // base case
//     if (start > end) {
//         return -1;  // not found
//     }

//     int mid = start + (end - start) / 2;

//     if (arr[mid] == target) {
//         return mid;
//     }
//     else if (arr[mid] < target) {
//         return binary_search(arr, mid + 1, end, target);
//     }
//     else {
//         return binary_search(arr, start, mid - 1, target);
//     }
// }