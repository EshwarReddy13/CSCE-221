#include <iostream>
#include "queue.h"
using namespace std;

void testenqueue(){
    Queue<int> test;
    test.enqueue(1);
    test.enqueue(2);
    test.enqueue(3);
    test.enqueue(4);
    test.print();
    return;
}

void testdequeue(){
    Queue<int> test1;
    try{test1.dequeue();}catch(std::out_of_range const&){}
    test1.enqueue(1);
    test1.enqueue(2);
    test1.enqueue(3);
    test1.enqueue(4);
    cout << test1.dequeue() << endl;
    test1.print();
    cout << test1.dequeue() << endl;
    test1.print();
}

void testrule(){
    Queue<int> test2;
    test2.enqueue(1);
    test2.enqueue(2);
    test2.enqueue(3);
    test2.enqueue(4);
    Queue<int> test3(test2);
    test2.print();
    Queue<int> test4 = test2;
    test4.print();
}

void testfront(){
    Queue<int> test5;
    test5.enqueue(1);
    test5.enqueue(2);
    test5.enqueue(3);
    test5.enqueue(4);
    cout << test5.front() << endl;
}

int main() {
    // TODO(student): test your code
    testenqueue();
    testdequeue();
    testrule();
    testfront();
}
