#pragma once

#include <cstddef>
#include <iostream>
using namespace std;

template <typename Object>
class Collection {
    // TODO(student): the rest of the template
    public:
        size_t cap;
        size_t siz;
        Object* list;
        bool empty;

        Collection():cap(10),siz(0),list(nullptr),empty(false){list = new Object[cap];}
        
        void insert(const Object& obj){
            if(empty == true){
                cap = 10;
            }
            if(siz == cap){
                cap *= 2;
                Object *temp = new Object[cap];
                for(size_t i = 0; i < siz; i++){
                    temp[i] = list[i];
                }
                delete[] list;
                list = temp;
            }
            list[siz] = obj;
            siz++;
        }

        void print(){
            for(size_t i=0;i<cap;i++){
                cout << list[i] << " ";
            }
        }

        bool is_empty() const{
            if(siz==0){
                return true;
            }
            return false;
        };
        void make_empty(){
            if(siz==0){
                return;
            }
            for(size_t i=0;i<cap;i++){
                list[i] =0;
            }
            siz =0;
            cap = 0;
            empty = true;
        };

        void remove(const Object& obj){
            int i;
            bool val = false;
            for(size_t j = 0; j < siz; j++){
                if(list[j] == obj){
                    val = true;
                    i = j;
                    break;
                }
            }
            if(val){
                for(size_t j = i; j < siz - 1; j++){
                    list[j] = list[j + 1];
                }
                siz--;
            }
            else cout << "Object doesn't exist" << endl;
        };

        bool contains(const Object& obj) const{
            for(size_t i=0;i<cap;i++){
                if(list[i] == obj){
                    return true;
                }
            }
            return false;
        };
        size_t size() const{
            return siz;
        };

        ~Collection(){
            delete[] list;
            list = NULL;
            cap =0;
            siz =0;
        }

        Collection(const Collection &obj):list(nullptr),siz(0),cap(0),empty(false){
            cap = obj.cap;
            siz = obj.siz;
            empty = obj.empty;
            list = new int[cap];
            for(size_t i=0;i<siz;i++){
                list[i] = obj.list[i];
            }
        }

        Collection& operator=(const Collection &obj){
            if(this == &obj){
                return *this;
            }
            siz = obj.siz;
            for(size_t i=0;i<siz;i++){
                list[i] = obj.list[i];
            }
            return *this;
        }
};