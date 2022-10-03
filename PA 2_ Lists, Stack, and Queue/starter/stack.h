#include <iostream>

template <typename Object>
class Stack {
   // TODO(student): implement Stack
   private:
   size_t sz;
   Object* slist;
   

   public:
   Stack():sz(0),slist(nullptr){slist = new Object[sz];}

   ~Stack(){
      delete[] slist;
   }

   Stack(const Stack& rhs):sz(0),slist(nullptr){
      sz = rhs.sz;
      slist = new Object[sz];
      for(size_t i=0;i<sz;i++){
         slist[i] = rhs.slist[i];
      }
   }

   Stack& operator=(const Stack& rhs){
      if(this!=&rhs){
         delete[] slist;
         sz = rhs.sz;
         slist = new Object[sz];
         for(size_t i=0;i<sz;i++){
            slist[i] = rhs.slist[i];
         }
      }
      return *this;
   }

   size_t size(){
      return sz;
   }

   void push(const Object& obj){
      if(sz==0){
         sz=1;
         delete[] slist;
         slist = new Object[sz];
         slist[0] = obj;
         return;
      }
      sz++;
      Object* temp = new Object[sz];
      for(size_t i = 0; i < sz-1; i++){
         temp[i] = slist[i];
      }
      delete[] slist;
      slist = temp;
      slist[sz-1] = obj;
   }

   void pop(){
      if(sz==0){
         throw std::out_of_range("Stack empty");
      }
      sz--;
      Object* temp = new Object[sz];
      for(size_t i=0;i<sz;i++){
         temp[i] = slist[i];
      }
      delete[] slist;
      slist = temp;
   }

   Object& top(){
      if(sz==0){
         throw std::out_of_range("Stack is empty");
      }
      return slist[sz-1];
   }

   void print(){
      for(size_t i=0;i<sz;i++){
         std::cout << slist[i] << " ";
      }
   }
};
