#include <iostream>
using namespace std;

template <typename Object>
class Queue {
    // TODO(student): implement Queue
    private:
    size_t sz;
    Object* que;

    public:
    Queue():sz(0),que(nullptr){que = new Object[sz];};

    ~Queue(){
        delete[] que;
    }

    Queue(const Queue& rhs):sz(0),que(nullptr){
        sz = rhs.sz;
        que = new Object[sz];
        for(size_t i=0;i<sz;i++){
            que[i] = rhs.que[i];
        }
    }

    Queue& operator=(const Queue& rhs){
        if(this!=&rhs){
            delete[] que;
            sz = rhs.sz;
            que = new Object[sz];
            for(size_t i=0;i<sz;i++){
                que[i] = rhs.que[i];
            }
        }
        return *this;
    }

    void enqueue(const Object& obj){
        if(sz==0){
            sz=1;
            delete[] que;
            que = new Object[sz];
            que[0] = obj;
            return;
        }
        sz++;
        Object* temp = new Object[sz];
        for(size_t i = 0; i < sz-1; i++){
            temp[i] = que[i];
        }
        delete[] que;
        que = temp;
        que[sz-1] = obj;
    }

    Object& front(){
        if(sz==0){throw std::out_of_range("Queue empty");}
        return que[0];
    }

    Object dequeue(){
        if(sz==0){throw std::out_of_range("Queue empty");}
        int to_return = que[0];
        sz--;
        Object* temp = new Object[sz];
        for(size_t i=0 ;i<sz;i++){
            temp[i] = que[i+1];
        }
        delete[] que;
        que = temp;
        return to_return;
    }

    void print(){
        for(size_t i=0;i<sz;i++){
            cout << que[i] << " ";
        }
        cout << endl;
    }
};
