#include <iostream>
#include "collection.h"
using namespace std;

int main(){

	Collection<int> test;
	//Collection<int> test1;
	
	test.insert(1);
	test.insert(2);
	test.insert(3);
	test.insert(4);
	test.insert(5);
	test.insert(6);
	test.insert(7);
	test.insert(8);
	test.insert(9);
	test.insert(10);
	test.insert(11);
	test.insert(12);
	cout << test.is_empty() << endl;
	test.print();
	cout << endl;

	test.make_empty();
	test.insert(123);
	test.print();
	cout << endl;
	//insert done

	test.make_empty();
	cout << test.is_empty()<<endl;
	test.make_empty();
	//make_empty done
	//is_empty done

	test.insert(1);
	test.insert(2);
	cout << test.contains(1) << endl;
	cout << test.contains(10) << endl;
	//contains done

	cout << test.size() << endl;
	//size done

	test.remove(2);
	//test.remove(1);
	test.print();

	return 0;
}