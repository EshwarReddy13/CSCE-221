#include <iostream>
#include "stack.h"
using namespace std;

void testpush(){
    Stack<int> test;
    test.push(10);
    test.push(20);
    test.push(30);
    test.push(40);
    test.print();
    cout << endl;
    return;
}

void testtop(){
    Stack<int> test1;
    try{test1.top();}catch(std::out_of_range const&){};
    test1.push(10);
    test1.push(20);
    cout << test1.top() << endl;
    test1.push(30);
    cout << test1.top() << endl;
    return;
}

void testpop(){
    Stack<int> test2;
    try{test2.pop();}catch(std::out_of_range const&){}
    test2.push(10);
    test2.push(20);
    test2.push(30);
    test2.push(40);
    test2.print();
    cout << endl;
    test2.pop();
    test2.print();
    test2.pop();
    test2.pop();
    cout << endl;
    test2.print();
    return;
}

void testrule(){
    Stack<int> test3;
    test3.push(1);
    test3.push(2);
    test3.push(3);
    test3.push(4);
    test3.push(5);
    Stack<int> test4(test3);
    cout << endl;
    test4.print();
    cout << endl;
    Stack<int> test5 = test3;
    test5.print();
    return;
}

int main() {
    // TODO(student): test your code
    testpush();
    testtop();
    testpop();
    testrule();
}
