#include <iostream>
#include "array_list.h"

int main() {
    // TODO(student): test your code
    ArrayList<int> test(10);
    test.insert(0, 1);
    test.insert(1, 2);
    test.insert(2, 3);
    test.insert(3, 4);
    test.insert(4, 5);
    test.insert(5, 6);
    test.insert(6, 7);
    test.insert(7, 8);
    test.insert(8, 9);
    test.insert(9, 10);
    test.remove(1);
    test.print();
    int a = test[9];
    cout << endl;
    cout << "Lets goo " << a << endl;
    ArrayList<int> test1(test);
    test1.print();
}
