#include <iostream>
#include "selection.h"
using namespace std;

void unitTesting(){
	const int list[7] = {8, 6, 7, 5, 3, 0, 9};
	size_t k = 0;
	size_t N = 7;
	int pass =0;
	try{
		select(k,list,N);
	}catch (std::invalid_argument const&){
		pass++;
	}catch(...){
		cout << "[FAIL] k " << k << " threw an error but not an invalid_argument" << endl;
	}
	k++;
	if(select(k,list,N) == 9){
		pass++;
	}else{
		cout << "[FAIL] got" << select(k,list,N) << endl;
	}
	k++;
	if(select(k,list,N) == 8){
		pass++;
	}else{
		cout << "[FAIL] got" << select(k,list,N) << endl;
	}
	k++;
	if(select(k,list,N) == 7){
		pass++;
	}else{
		cout << "[FAIL] got" << select(k,list,N) << endl;
	}
	k++;
	if(select(k,list,N) == 6){
		pass++;
	}else{
		cout << "[FAIL] got" << select(k,list,N) << endl;
	}
	k++;
	if(select(k,list,N) == 5){
		pass++;
	}else{
		cout << "[FAIL] got" << select(k,list,N) << endl;
	}
	k++;
	if(select(k,list,N) == 3){
		pass++;
	}else{
		cout << "[FAIL] got" << select(k,list,N) << endl;
	}
	k++;
	if(select(k,list,N) == 0){
		pass++;
	}else{
		cout << "[FAIL] got" << select(k,list,N) << endl;
	}
	k++;
	try{
		select(k,list,N);
	}catch (std::invalid_argument const&){
		pass++;
	}catch(...){
		cout << "[FAIL] k " << k << " threw an error but not an invalid_argument" << endl;
	}

	k=-10212002;
	try{
		select(k,list,N);
	}catch (std::invalid_argument const&){
		pass++;
	}catch(...){
		cout << "[FAIL] k " << k << " threw an error but not an invalid_argument" << endl;
	}

	k=10212002;
	try{
		select(k,list,N);
	}catch (std::invalid_argument const&){
		pass++;
	}catch(...){
		cout << "[FAIL] k " << k << " threw an error but not an invalid_argument" << endl;
	}

	k=1;
	const int list2[1]= {0};
	N=1;
	if(select(k,list2,N)==0){
		pass++;
	}else{
		cout << "[FAIL] got" << select(k,list,N) << endl;
	}

	k = 1;
	const int* list3 = NULL;
	N = 1;
	try{
		select(k,list3,N);
	}catch(std::invalid_argument const&){
		pass++;
	}catch(...){
		cout << "[FAIL] got" << select(k,list,N) << endl;		
	}

	cout << pass << "/" << 13 << " passed" << endl;
	if(pass ==13){
		cout << "All tests passed" << endl;
	}else{
		cout << "Some tests failed" << endl;
	}
}

int main(){
	unitTesting();
	return 0;
}