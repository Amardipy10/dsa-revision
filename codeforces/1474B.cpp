#include<iostream>
using namespace std;
bool isPrime(int p){
    if (p < 2) return false;
    for(int i = 2; i * i <= p; i++){
        if(p % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int d;
        cin >> d;
        int p = d + 1;
        while (!isPrime(p)) {
            p++;
        }
        int q = p + d;
        while (!isPrime(q)) {
            q++;
        }
        long long a =p * q;
        cout << a <<endl;
    }
    return 0;
}