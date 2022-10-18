#include <iostream>
#include "binary_search_tree.h"
using std::cout, std::endl;

void testinsert(){
    BinarySearchTree<int> test;
    test.insert(10);
    test.insert(10);
    test.insert(12);
    test.insert(12);
    test.insert(8);
    test.insert(8);
    test.print_tree();
    std::cout << std::endl;
}

void testmin(){
    BinarySearchTree<int> test1;
    try{test1.find_min();}catch(std::invalid_argument const&){}
    test1.insert(10);
    test1.insert(12);
    test1.insert(8);
    test1.insert(2);
    test1.insert(5);
    std::cout << test1.find_min() << std::endl;
}

void testmax(){
    BinarySearchTree<int> test2;
    try{test2.find_max();}catch(std::invalid_argument const&){}
    test2.insert(10);
    test2.insert(12);
    test2.insert(8);
    test2.insert(17);
    test2.insert(5);
    std::cout << test2.find_min() << std::endl;
}

void testprint(){
    BinarySearchTree<int> test3;
    test3.insert(10);
    test3.insert(3);
    test3.insert(12);
    test3.insert(8);
    test3.insert(9);
    test3.insert(15);
    test3.insert(1);
    test3.insert(2);
    test3.print_tree();
    std::cout << std::endl;
}

void testcontains(){
    BinarySearchTree<int> test4;
    test4.insert(10);
    test4.insert(12);
    test4.insert(8);
    std::cout << test4.contains(8) << " ";
    std::cout << test4.contains(13) << " ";
    std::cout << test4.contains(12) << std::endl;
}

void testrule(){
    BinarySearchTree<int> test5;
    test5.insert(10);
    test5.insert(12);
    test5.insert(8);
    BinarySearchTree<int> test6(test5);
    test6.print_tree();
    std::cout << std::endl;
}

int main() {
    // TODO(student): write tests
    testinsert();
    testmin();
    testmax();
    testprint();
    testcontains();
    //testrule();
    return 0;
}
