#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isPowerOfTwo(int n) {
    if(n==1){return true;}
    while(true){
        if(n%2==0){
            n/=2;
            if(n==1){
                return true;
            }
        }else{
            return false;
        }
    }
    return false;
}
int main(){
    int n =6;
    cout << isPowerOfTwo(n);
    return 0;
}