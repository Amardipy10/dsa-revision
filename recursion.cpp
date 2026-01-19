#include<iostream>
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

int factorial(int n){
    if(n==0){
        return 1;
    }
    else{
    return (n*factorial(n-1));
    }
}
int main(){
    int ans=factorial(5);
    cout<<ans;
}