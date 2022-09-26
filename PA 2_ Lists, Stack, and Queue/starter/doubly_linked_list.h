// #pragma once
#include <iostream>
using namespace std;


//Node<Object>* new = new Node<Object>{obj,nullptr,nullptr}; 
template <typename Object>
struct Node{
    Object val;
    Node<Object>* next;  
    Node<Object>* prev;
};

template <typename Object>
class DoublyLinkedList {
    // TODO(student): implement DoublyLinkedList
    private:
        size_t sz;
        Node<Object>* head;
        Node<Object>* tail;

    public:
    DoublyLinkedList():sz(0),head(nullptr),tail(nullptr){};

    size_t size() const{
        return sz;
    }

    void make(){
        Node<Object>* my1 = new Node<Object>;
        Node<Object>* my2 = new Node<Object>;
        Node<Object>* my3 = new Node<Object>;
        Node<Object>* my4 = new Node<Object>;
        Node<Object>* my5 = new Node<Object>;
        my1->val = 1;
        my2->val = 2;
        my3->val = 3;
        my4->val = 4;
        my5->val = 5;
        head = my1;
        head->next = my2;
        head->next->next = my3;
        head->next->next->next = my4;
        head->next->next->next->next = my5;
        tail = my5;
        tail->next =nullptr;
        sz=5;
    }

    Object& operator[](size_t index){
        if(index>=sz){
            throw std::out_of_range("Index out of bounds");
        }
        size_t i=0;
        while(head!=nullptr){
            if(i==index){
                break;
            }
            head = head->next;
            i++;
        }
        return head->val;
    }

    void insert(size_t index,const Object& value){
        if(index>sz){
            throw std::out_of_range("Index out of bounds");
        }
        Node<Object>* add = new Node<Object>{value,nullptr,nullptr}; 
        if(sz==0){
            add->next = nullptr;
            add->prev = nullptr;
            head = add;
            tail = add;
            sz++;
            return;
        }
        if(index==0){
            add->next = head;
            add->prev = nullptr;
            head = add;
            sz++;
            return;
        }
        if(index==sz){
            Node<Object>* curr = head;
            while(curr->next!=nullptr){
                curr = curr->next;
            }
            add->next = nullptr;
            add->prev = curr;
            curr->next = add;
            tail = add;
            sz++;
            return;
        }
        // 1 2 3 4 5
        // 1 2 10 3 4 5
        size_t i=0;
        Node<Object>* curr = head;
        while(curr!=nullptr){
            if(index-1 == i){
                add->next = curr->next;
                curr->next = add;
                add->prev = curr;
                break;
            }
            i++;
            curr = curr->next;
        }
        sz++;
    }

    void remove(size_t index){
        // if(index>sz){
        //     throw std::out_of_range("Index out of bounds");
        // }
        // if(index==0){
            
        // }
    }

    void print() const{
        Node<Object>* curr =head;
        while(curr!=nullptr){
            cout << curr->val << " ";
            curr = curr->next;
        }
    }

    ~DoublyLinkedList(){
        while(head!=nullptr){
            Node<Object>* temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    DoublyLinkedList(const DoublyLinkedList& rhs):sz(0),head(nullptr),tail(nullptr){
        if(rhs.head == nullptr){
            return;
        }
        // 1 2 3
        Node<Object>* temp = rhs.head;
        while(temp->next!=nullptr){
            head = temp;
            temp = temp->next;
            head = head->next;
        }
        head = temp;
        head->next = nullptr;
        tail = temp;
    }

    DoublyLinkedList& operator=(const DoublyLinkedList& rhs){
        return *this;
    }
};
