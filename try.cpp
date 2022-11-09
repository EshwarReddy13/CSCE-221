#include <bits/stdc++.h>
using namespace std;

set<int> inter(set<int>& a, set<int>& b){
    set<int> ans;
    for(auto x:a){
        for(auto y:b){
            if(x==y){
                ans.insert(x);
            }
        }
    }
    return ans;
}

for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr << " ";

set<int> uni(set<int>& a, set<int>& b){
    set<int> ans;
    for(auto x:a){
        ans.insert(x);
    }
    for(auto x:b){
        ans.insert(x);
    }
    return ans;
}

int main(){ 
    set<int> a;
    set<int> b;
    a.insert(10);
    a.insert(20);
    a.insert(30);
    a.insert(40);
    b.insert(10);
    b.insert(20);
    b.insert(40);
    set<int> c = inter(a,b);
    set<int> d = uni(a,b);
    for(auto x:c){
        cout << x << " ";
    }cout << endl;
    for(auto x:d){
        cout << x << " ";
    }
    return 0;
}