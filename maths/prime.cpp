#include<iostream>
#include<string>
using namespace std;

string prime(int n){
    if(n <= 1) return "non-prime";   // edge case

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return "non-prime";
        }
    }
    return "prime";
}

int main(){
    cout << prime(42);
}