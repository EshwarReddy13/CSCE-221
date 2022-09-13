
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

    ArrayList():siz(0),cap(10),list(nullptr){list = new Object[cap];};
    ArrayList(size_t capacity){
        cap = capacity;
        siz = 0;
        list = nullptr;
        list = new Object[cap];
    };

    size_t size() const {
        return siz;
    }

    Object& operator[](size_t s){
        if(s>siz-1){
            throw std::out_of_range("Index out of bounds");
        }
        return list[s];
    }

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

    void remove(size_t index){
        if(index>cap){
            throw std::out_of_range("Index out of range");
        }
        for(int i=0;i<cap;i++){
            if(i==index){
                list[i] = 0;
            }
        }
    }

    void print(){
        for(size_t i=0;i<cap;i++){
            cout << list[i] << " ";
        }
    }

    ~ArrayList(){
        delete[] list;
    }

    ArrayList(const ArrayList& other):{list(nullptr),siz(other.siz),cap(other.cap){
        list = new int[cap];
        for(int i=0;i<siz;i++){
            list[i] = other.list[i];
        }
    }

    ArrayList& operator=(const ArrayList& other){
        if(this != &other){
            delete[] list;
            siz = other.siz;
            cap = other.cap;
            list = new Object[cap];
            for(int i=0;i<siz;i++){
                list[i] = other.list[i];
            }
        }
        return *this;
    }
};

// class Fox(){
//     int* a;
//     fox(){a = new int();}
// }

// class s(){
//     Fox* f;

// }
