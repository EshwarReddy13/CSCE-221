#include <iostream>
#include "array_list.h"

void testinsert(){
    ArrayList<int> test;
    test.insert(0,1);
    test.insert(1,2);
    test.insert(2,3);
    test.insert(3,4);
    test.insert(4,5);
    test.insert(5,6);
    test.insert(6,7);
    test.insert(7,8);
    test.insert(8,10);
    
    try{test.insert(10,10);}catch(std::out_of_range const&){};
    test.print();cout << endl;

    ArrayList<int> test1(3);
    test1.insert(0,1);
    test1.insert(1,2);
    test1.insert(2,3);
    try{test.insert(3,10);}catch(std::out_of_range const&){};
    test1.print();
    return;
}

void testremove(){
    ArrayList<int> test2;
    test2.insert(0,1);
    test2.insert(1,2);
    test2.insert(2,3);
    test2.insert(3,4);
    test2.insert(4,5);
    cout << endl;
    test2.print();
    cout << endl;
    test2.remove(3);
    test2.print();
    return;
}

int main() {
    testinsert();
    testremove();
    return 0;
}
