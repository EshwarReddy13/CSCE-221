#include <iostream>

template <typename Comparable>
struct BinaryNode{
    Comparable val;
    BinaryNode<Comparable>* left;
    BinaryNode<Comparable>* right;

    void PostOrder(BinaryNode<Comparable>* temp){
        if(temp == nullptr){
            return;
        }else{
            PostOrder(temp->left);
            PostOrder(temp->right);
            std::cout << temp->val << " ";
        }
    }
    
    void destroy(BinaryNode<Comparable>* temp){
        if(temp){
            destroy(temp->left);
            destroy(temp->right);
            delete temp;
        }   
    }
};

template <typename Comparable>
class BinarySearchTree {
private:
    BinaryNode<Comparable>* root;

public:
    BinarySearchTree():root(nullptr){}
    
    ~BinarySearchTree(){
        root->destroy(root);
    }

    // BinarySearchTree(const BinarySearchTree& rhs):root(rhs.root){}  

    // BinarySearchTree& operator=(const BinarySearchTree& rhs){
    //     return *this;
    // }

    bool contains(const Comparable& obj){
        BinaryNode<Comparable>* temp = root;
        BinaryNode<Comparable>* curr = nullptr;
        while(temp!=nullptr){
            curr = temp;
            if(obj>temp->val){
                temp = temp->right;
            }else if(obj<temp->val){
                temp = temp->left;
            }else if(obj==temp->val){
                return true;
            }
        }
        return false;
    }

    void insert(const Comparable& obj){
        BinaryNode<Comparable>* temp = root;
        BinaryNode<Comparable>* curr = nullptr;
        while(temp!=nullptr){
            curr = temp;
            if(obj>temp->val){
                temp = temp->right;
            }else if(obj<temp->val){
                temp = temp->left;
            }else if(obj==temp->val){
                return; 
            }
        }
        if(curr==nullptr){
            root = new BinaryNode<Comparable>{obj,nullptr,nullptr};
        }else if(obj > curr->val){
            curr->right = new BinaryNode<Comparable>{obj,nullptr,nullptr};
        }else if(obj<curr->val){
            curr->left = new BinaryNode<Comparable>{obj,nullptr,nullptr};
        }
    }

    void remove(const Comparable& rhs){

    }

    const Comparable& find_min() const{
        if(root==nullptr){
            throw std::invalid_argument("Invalid");
        }
        BinaryNode<Comparable>* temp = root;
        while(temp->left!=nullptr){
            temp = temp->left;
        }
        return temp->val;
    }

    const Comparable& find_max() const{
        if(root==nullptr){
            throw std::invalid_argument("Invalid");
        }   
        BinaryNode<Comparable>* temp = root;
        while(temp->right!=nullptr){
            temp = temp->right;
        }
        return temp->val;
    }

    void print(){
        std::cout << root->val << " ";
        std::cout << root->right->val << " ";
        std::cout << root->left->val << std::endl;
    }

    void print_tree()const{
        root->PostOrder(root);    
    }
};
