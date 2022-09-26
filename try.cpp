#include <iostream>
#include <vector>
using namespace std;

int main(){

    int a[5];
    for(int i=0;i<5;i++){
        cout << "Enter ";
        cin >> a[i];
    }
    for(int i=0;i<5;i++){
        int b = a[i];
        int c=0;
        for(int j=0;j<5;j++){
            if(b != a[j] || i==j){
                c++;
            }
            if(c==5){
                cout << b << " ";
            }
        }
    }
    return 0;
}