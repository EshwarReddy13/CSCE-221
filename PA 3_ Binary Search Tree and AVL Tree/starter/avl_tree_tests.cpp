#include <iostream>
#include "avl_tree.h"

using std::cout, std::endl;

void testinsert(){
    std::cout << "Insert:" << std::endl;
    AVLTree<int> test;
    test.insert(10);
    test.insert(10);
    test.insert(12);
    test.insert(12);
    test.insert(8);
    test.insert(8);
    test.print();
    std::cout << std::endl;
}

void testmin(){
    std::cout << "Find_min:" << std::endl;
    AVLTree<int> test1;
    try{test1.find_min();}catch(std::invalid_argument const&){}
    test1.insert(10);
    test1.insert(12);
    test1.insert(8);
    test1.insert(2);
    test1.insert(5);
    std::cout << test1.find_min() << std::endl;
}

void testmax(){
    std::cout << "Find_max:" << std::endl;
    AVLTree<int> test2;
    try{test2.find_max();}catch(std::invalid_argument const&){}
    test2.insert(10);
    test2.insert(12);
    test2.insert(8);
    test2.insert(17);
    test2.insert(5);
    std::cout << test2.find_min() << std::endl;
}

void testprint(){
    std::cout << "Print:" << std::endl;
    AVLTree<int> test3;
    test3.print_tree();
    test3.insert(6);
    test3.insert(10);
    test3.insert(4);
    test3.insert(8);
    test3.insert(2);
    test3.print_tree();
    std::cout << std::endl;
}

void testcontains(){
    std::cout << "Contains:" << std::endl;
    AVLTree<int> test4;
    test4.insert(10);
    test4.insert(12);
    test4.insert(8);
    std::cout << test4.contains(8) << " ";
    std::cout << test4.contains(13) << " ";
    std::cout << test4.contains(12) << std::endl;
}

void testrule(){
    std::cout << "Rule of three:" << std::endl;
    AVLTree<int> test5;
    test5.insert(10);
    test5.insert(12);
    test5.insert(8);
    test5.print();std::cout << std::endl;
    AVLTree<int> test6 = test5;
    test6.print();
    std::cout << std::endl;
    test6.insert(25);
    AVLTree<int> testt(test6);
    testt.print();std::cout << std::endl;
}

void testremove(){
    std::cout << "Remove:" << std::endl;
    AVLTree<int> test6;
    test6.insert(10);   
    test6.insert(20);
    test6.insert(15);
    test6.insert(25);
    test6.insert(5);
    test6.insert(4);
    test6.insert(6);
    test6.print();std::cout << std::endl;
    test6.remove(10);
    test6.print(); 
    test6.remove(15);
    std::cout << std::endl;
    test6.print();
}
/*   15
   5   20
  4 6   25
*/
int main() {
    // TODO(student): write tests
    testinsert();
    testmin();
    testmax();
    testprint();
    testcontains();
    testrule();
    testremove();
    return 0;
}
