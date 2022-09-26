#include <iostream>
#include "doubly_linked_list.h"

void testinsert(){
    DoublyLinkedList<int> test;
    //test.make();  
    test.insert(0,1);
    test.insert(1,3);
    test.insert(2,4);
    test.insert(1,2);
    test.print();
    cout << endl;

}

int main() {
    // TODO(student): test your code
    testinsert();
    return 0;
}