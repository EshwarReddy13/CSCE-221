#include <iostream>
#include "doubly_linked_list.h"

void testinsert(){
    DoublyLinkedList<int> test;
    //test.make();  
    test.insert(0,1);
    test.insert(1,2);
    test.insert(2,3);
    test.insert(0,10);
    test.insert(1,20);
    try{test.insert(10,2);}catch(std::out_of_range const&){};
    test.print();
    cout << endl;
    return;
}

void testop(){
    DoublyLinkedList<int> test1;
    test1.make();
    cout << test1[1] << endl;
    try{test1[19];}catch(std::out_of_range const&){};
    return;
}

void testremove(){
    DoublyLinkedList<int> test2;
    test2.insert(0,1);
    test2.insert(1,2);
    test2.insert(2,3);
    test2.insert(3,4);
    test2.insert(4,5);

    test2.remove(0);
    test2.remove(1);
    test2.remove(2);
    //test2.remove(0);
    //test2.remove(0);
    //test.remove();
    try{test2.remove(10);}catch(std::out_of_range const&){};
    test2.print();
    cout << endl;
    //test2.printr();
    return;
}

void testrule(){
    DoublyLinkedList<int> test3;
    test3.insert(0,1);
    test3.insert(1,2);
    test3.insert(2,3);
    test3.insert(3,4);
    test3.insert(4,5);
    DoublyLinkedList<int> test4(test3);
    test4.get_head();
    cout << endl;
    test4.get_tail();
    cout << endl;
    test4.print();
    cout << endl;
    test4.printr();
    cout << endl;
    cout << test4.size();
    return;
}

int main() {
    // TODO(student): test your code
    testinsert();
    testop();
    testremove();
    testrule();
    return 0;
}