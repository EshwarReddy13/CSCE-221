#include <iostream>
using namespace std;


template <typename Object>
class ArrayList {
    // TODO(student): implement ArrayList
    private:

    size_t siz;
    size_t cap;
    Object* list;
    bool set_cap;

    public:

    ArrayList():siz(0),cap(1),list(nullptr),set_cap(false){
        list = new Object[cap];
    }
    explicit ArrayList(size_t capacity):siz(0),cap(capacity),list(nullptr),set_cap(false){
        list = new Object[capacity];
    }

    ~ArrayList(){
        delete[] list;
    }

    ArrayList(const ArrayList& other):siz(0),cap(0),list(nullptr),set_cap(false){
        siz = other.siz;
        cap = other.cap;
        set_cap = other.set_cap;
        list = new Object[other.cap];
        for(size_t i=0;i<cap;i++){
            list[i] = other.list[i];
        }
    }

    ArrayList& operator=(const ArrayList& other){
        if(this != &other){
            delete[] list;
            siz = other.siz;
            cap = other.cap;
            set_cap = other.set_cap;
            list = new Object[other.cap];
            for(size_t i=0;i<cap;i++){
                list[i] = other.list[i];
            }
        }
        return *this;
    }

    size_t size() const {
        return siz;
    }

    Object& operator[](size_t s){
        if(s>=siz){
            throw std::out_of_range("Index out of bounds");
        }
        return list[s];
    }

    void insert(size_t index,const Object& obj){
        if(index>siz || (index==cap && set_cap)){
            throw std::out_of_range("Index out of bounds");
        }
        if(siz==cap && !set_cap){
            cap*=2;
        }   
        if(index==0 && siz==0){
            list[0] = obj;
            siz++;
            return;
        }
        // 1 2 3 4 5 0 0 0
        // 1 2 3 8 4 5 0 0 
        Object* temp = new Object[cap];
        for(size_t i=0;i<cap;i++){
            if(index == i){
                temp[i] = obj;
            }else if(index > i){
                temp[i] = list[i];
            }else if(index < i){
                if(i>siz){
                    break;
                }
                temp[i] = list[i-1];
            }
        }
        delete[] list;
        list = temp;
        siz++;
    }

    void remove(size_t index){
        if(index>=siz){
            throw std::out_of_range("Index out of bounds");
        }
        Object* temp = new Object[cap];
        size_t j=0;
        for(size_t i=0;i<cap;i++){
            if(index == i){
                i++;
            }
            temp[j] = list[i];
            j++;
        }
        delete[] list;
        list = temp;
        siz--;
    }

    void print(){
        for(size_t i=0;i<siz;i++){
            cout << list[i] << " ";
        }
    }
};