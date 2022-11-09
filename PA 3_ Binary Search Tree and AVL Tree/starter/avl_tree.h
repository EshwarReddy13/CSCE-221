#include <iostream>

template <typename Comparable>
struct AVLnode{
    Comparable val;
    AVLnode<Comparable>* left;
    AVLnode<Comparable>* right;
};

template <typename Comparable>
class AVLTree {
private:
    AVLnode<Comparable>* root;

public:
    // TODO(student): implement AVLTree
    void destroy(AVLnode<Comparable>*& temp){
        if (temp == nullptr){
            return;
        }
        if (temp-> left !=nullptr){ 
            destroy(temp -> left);
        }
        if (temp-> right !=nullptr){ 
            destroy(temp -> right);
        }
        delete temp;
    }

    void copy(AVLnode<Comparable>*& curr, AVLnode<Comparable>* to_copy){
        if(to_copy==nullptr){
            return;
        }
        curr = new AVLnode<Comparable>{to_copy->val,nullptr,nullptr};
        if(to_copy->right!=nullptr){
            copy(curr->right,to_copy->right);
        }
        if(to_copy->left!=nullptr){
            copy(curr->left,to_copy->left);
        }
    }

    AVLTree():root(nullptr){}
    
    ~AVLTree(){
        destroy(root);
    }

    AVLTree(const AVLTree& rhs):root(nullptr){
        copy(root,rhs.root);
    }  

    AVLTree& operator=(const AVLTree& rhs){
        if(this!=&rhs){
            copy(root,rhs.root);
        }
        return *this;
    }
    bool contains(const Comparable& obj){
        AVLnode<Comparable>* temp = root;
        while(temp!=nullptr){
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
        AVLnode<Comparable>* temp = root;
        AVLnode<Comparable>* curr = nullptr;
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
            root = new AVLnode<Comparable>{obj,nullptr,nullptr};
        }else if(obj > curr->val){
            curr->right = new AVLnode<Comparable>{obj,nullptr,nullptr};
        }else if(obj<curr->val){
            curr->left = new AVLnode<Comparable>{obj,nullptr,nullptr};
        }
    }

    void remove_it(AVLnode<Comparable>*& curr,const Comparable& rhs){
        if(curr==nullptr){
            return;
        }
        if(curr->val > rhs){
            remove_it(curr->left,rhs);
        }else if(curr->val < rhs){
            remove_it(curr->right,rhs);
        }else{
            if(curr->left!=nullptr && curr->right!=nullptr){
                AVLnode<Comparable>* temp = curr->right;
                while(temp->left!=nullptr){
                    temp = temp->left;
                }
                curr->val = temp->val;
                remove_it(curr->right,curr->val); 
            }else{
                AVLnode<Comparable>* temp = curr;
                if(curr->left!=nullptr){
                    curr = curr->left;
                }else if(curr->right!=nullptr){
                    curr = curr->right;
                }else{
                    curr = curr->left;
                }
                delete temp;
            }
        }
    }

    void remove(const Comparable& rhs){
        remove_it(root,rhs);
    }

    const Comparable& find_min() const{
        if(root==nullptr){
            throw std::invalid_argument("Invalid");
        }
        AVLnode<Comparable>* temp = root;
        while(temp->left!=nullptr){
            temp = temp->left;
        }
        return temp->val;
    }

    const Comparable& find_max() const{
        if(root==nullptr){
            throw std::invalid_argument("Invalid");
        }   
        AVLnode<Comparable>* temp = root;
        while(temp->right!=nullptr){
            temp = temp->right;
        }
        return temp->val;
    }

    void Inorder(AVLnode<Comparable>*& curr){
        if(curr){
            Inorder(curr->left);
            std::cout << curr->val << " ";
            Inorder(curr->right);
        }else{
            return;
        }
    }

    void print(){
        Inorder(root);
    }

    void print_tree(){
        if(root){
            std::cout << root->val;
        }else{
            std::cout << "<empty>\n";
        }
    }
};
