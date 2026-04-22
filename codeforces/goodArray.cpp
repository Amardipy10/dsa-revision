#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
    int n;
    cin >> n;
    int single=0;
    for(int i=1;i<=n;i++){
        if(i%10<11){
            single++;
        }
    }
    cout<<single<<endl;
    }
    
    return 0;
}