
#include <iostream>
using namespace std;

#include <cstddef>
#include <stdexcept>
template <typename Object>
class ArrayList {
    // TODO(student): implement ArrayList
    private:

    size_t siz;
    size_t cap;
    Object* list;

    public:

    ArrayList():siz(0),cap(10),list(nullptr){};
    explicit ArrayList(size_t capacity){
        cap = capacity;
    };

    size_t size() const {
        return siz;
    }

    // Object& operator[](size_t s){
    //     if(s>siz-1){
    //         throw std::out_of_range("Index out of bounds");
    //     }
    //     return list[s];
    // }

    void insert(size_t s,const Object& obj){
        if(s>cap){
            throw std::out_of_range("Index out of range");
        }
        for(size_t i=0;i<cap;i++){
            if(i==s){
                list[i] = obj;
            }
        }
        siz+=1;
    }

    void print(){
        for(size_t i=0;i<cap;i++){
            cout << list[i] << " ";
        }
    }

};
