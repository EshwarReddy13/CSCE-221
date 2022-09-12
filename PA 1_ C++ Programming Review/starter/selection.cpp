#include <stdexcept>
#include "selection.h"

int select(size_t k, const int* list, size_t N) {
    // TODO(student): solve the selection problem
    if(list==NULL){
        throw std::invalid_argument("Wrong");
    }
    if(N==1&&k==1){
        return list[0];
    }
    if(k<=0||k>N){
        throw std::invalid_argument("Wrong");
    }
    int *sortedList = new int[N];
    for(size_t i=0;i<N;i++){
        sortedList[i] = list[i];
    }
    int max,temp;
    for (size_t i = 0; i < N - 1; i++) {
      max = i;
      for (size_t j = i + 1; j < N; j++)
      if (sortedList[j] > sortedList[max])
      max = j;
      temp = sortedList[i];
      sortedList[i] = sortedList[max];
      sortedList[max] = temp;
   }
   int ans = sortedList[k-1];
    delete[] sortedList; 
    return ans;
    // sort(list,list+N);
    // return list[k-1];
}