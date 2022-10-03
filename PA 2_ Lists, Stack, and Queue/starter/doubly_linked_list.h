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
    
    ~DoublyLinkedList(){
        while(head!=nullptr){
            Node<Object>* temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    //DoublyLinkedList(const DoublyLinkedList<Object>& rhs):sz(0),head(nullptr),tail(nullptr){
    DoublyLinkedList(const DoublyLinkedList& other): sz(other.sz),head(nullptr), tail(nullptr){
        if(other.head == nullptr){
            head = nullptr;
            tail = nullptr;
            sz = 0;
        }
        else{
            size_t i = 0;
            sz = i;
            Node<Object>* temp = other.head;
            while(temp){
                insert(i, temp->val);
                temp = temp->next;
                i++;
            } 
        }
    }
    //    if(rhs.head == nullptr){
    //         return;
    //     }
    //     else{
    //         size_t i = 0;
    //         sz = rhs.sz;
    //         Node<Object>* temp = rhs.head;
    //         tail = rhs.tail;
    //         while(temp!=nullptr){
    //             insert(i, temp->val);
    //             temp = temp->next;
    //             i++;
    //         }     
    //     }
        // if(rhs.head == nullptr){
        //     head = nullptr;
        //     tail = nullptr;
        //     sz=0;
        //     return;
        // }
        // // 1 2 3
        // sz = rhs.sz;
        // //head = new Node<Object>{rhs.head->val,nullptr,nullptr};
        // tail = rhs.tail;
        // tail->prev = rhs.tail->prev;
        // Node<Object>* temp = rhs.head;
        // size_t i=0;
        // while(temp!=nullptr){
        //     insert(i, temp->val);
        //     temp = temp->next;
        //     i++;
        // }
        // //tail->prev = rhs.tail->prev;
        // // temp = rhs.tail->prev;
        // // curr = tail;
        // // while(temp!=nullptr){
        // //     Node<Object>* add = new Node<Object>{temp->val,nullptr,nullptr};
        // //     add->prev = nullptr;
        // //     add->next = curr;
        // //     curr->prev = add;
        // //     temp = temp->prev;
        // //     curr = curr->prev;
        // // }
        // delete temp;

    DoublyLinkedList& operator=(const DoublyLinkedList& rhs){
        return *this;
    }
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
        Node<Object>* temp = head;
        while(temp!=nullptr){
            if(i==index){
                break;
            }
            temp = temp->next;
            i++;
        }
        return temp->val;
    }

    void insert(size_t index,const Object& value){
        if(index>sz){
            throw std::out_of_range("Index out of bounds");
        }
        //Insert into empty list
        if(sz==0){
            head = new Node<Object>{value,nullptr,nullptr};
            head->prev = nullptr;
            head->next = nullptr;
            tail = head;
            sz=1;
            return;
        }
        Node<Object>* add = new Node<Object>{value,nullptr,nullptr}; 
        //Insert at head
        if(index==0){
            add->next = head;
            add->prev = nullptr;
            head = add;
            sz++;
            return;
        }
        //Insert at tail
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
                add->prev = curr;
                curr->next = add;
                break;
            }
            i++;
            curr = curr->next;
        }
        sz++;
    }

    void remove(size_t index){
        if(sz==0){return;}
        if(index>=sz){
            throw std::out_of_range("Index out of bounds");
        }
        if(index == 0){
            Node<Object>* temp = head;
            head = temp->next;
            //head->prev = nullptr;
            delete temp;
        }
        else{
            Node<Object>* temp = head;
            for(size_t i = 0; i < index; i++){
                temp = temp->next;
            }
            Node<Object>* curr = temp->prev;
            curr->next = temp->next;
            if(temp->next != nullptr){
                temp->next->prev = curr;
            }else{
                tail = curr;
            }
            temp->next = nullptr;
            temp->prev = nullptr;
            delete temp;
        }
        sz--;
        // if(sz==0){return;}
        // if(index>=sz){
        //     throw std::out_of_range("Index out of bounds");
        // }
        // if(index==0){
        //     Node<Object>* temp = head;
        //     head = temp->next;
        //     sz--;
        //     delete temp;
        //     head->prev = nullptr;
        //     return;
        // }
        // //1 2 3 4 5
        // if(index<sz){
        //     Node<Object>* temp = head;
        //     for(size_t i=0;i<index;i++){
        //         temp = temp->next;
        //     }
        //     if(index==sz-1){
        //         tail = temp->prev;
        //         tail->prev = temp->prev->prev;
        //     }
        //     if(temp->next != nullptr){
        //         temp->next->prev = temp->prev;
        //     }
        //     if(temp->prev != nullptr){
        //         temp->prev->next = temp->next;
        //     }
        //     delete temp;
        //     sz--;
        //     return;
        // }
        return;
    }

    void print() const{
        Node<Object>* curr =head;
        while(curr!=nullptr){
            cout << curr->val << " ";
            curr = curr->next;
        }
    }

    void printr(){
        Node<Object>* curr = tail;
        while(curr!=nullptr){
            cout << curr->val << " ";
            curr = curr->prev;
        }
        // Node<Object>* curr =head;
        // while(curr->next != nullptr){
        //     curr = curr->next;
        // }
        // while(curr != nullptr){
        //     cout << curr->val << " ";
        //     curr = curr->prev;
        // }
    }    

    void get_head(){
        cout << head->val;
    }

    void get_tail(){
        cout << tail->val;
    }
};