#include <iostream>

template <typename Comparable>
struct BinaryNode{
    Comparable val;
    BinaryNode<Comparable>* left;
    BinaryNode<Comparable>* right;
};

template <typename Comparable>
class BinarySearchTree {
private:
    BinaryNode<Comparable>* root;

public:

    void destroy(BinaryNode<Comparable>*& temp){
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

    void copy(BinaryNode<Comparable>*& curr, BinaryNode<Comparable>* to_copy){
        if(to_copy==nullptr){
            return;
        }
        curr = new BinaryNode<Comparable>{to_copy->val,nullptr,nullptr};
        if(to_copy->right!=nullptr){
            copy(curr->right,to_copy->right);
        }
        if(to_copy->left!=nullptr){
            copy(curr->left,to_copy->left);
        }
    }

    BinarySearchTree():root(nullptr){}
    
    ~BinarySearchTree(){
        destroy(root);
    }

    BinarySearchTree(const BinarySearchTree& rhs):root(nullptr){
        copy(root,rhs.root);
    }  

    BinarySearchTree& operator=(const BinarySearchTree& rhs){
        if(this!=&rhs){
            copy(root,rhs.root);
        }
        return *this;
    }

    bool contains(const Comparable& obj){
        BinaryNode<Comparable>* temp = root;
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

    void remove_it(BinaryNode<Comparable>*& curr,const Comparable& rhs){
        if(curr==nullptr){
            return;
        }
        if(curr->val > rhs){
            remove_it(curr->left,rhs);
        }else if(curr->val < rhs){
            remove_it(curr->right,rhs);
        }else{
            if(curr->left!=nullptr && curr->right!=nullptr){
                BinaryNode<Comparable>* temp = curr->right;
                while(temp->left!=nullptr){
                    temp = temp->left;
                }
                curr->val = temp->val;
                remove_it(curr->right,curr->val); 
            }else{
                BinaryNode<Comparable>* temp = curr;
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

    void Inorder(BinaryNode<Comparable>*& curr){
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

    int get_height(BinaryNode<Comparable>*& temp,const Comparable& obj){
        int i=0;
        if(temp->val == obj){
            return i;
        }
        while(temp!=nullptr){
            if(obj>temp->val){
                temp = temp->right;
                i++;
            }else if(obj<temp->val){
                temp = temp->left;
                i++;
            }else if(obj==temp->val){
                return i;
            }
        }
        return i;
        // int i=0;
        // int j=0;
        // BinaryNode<Comparable>* test = temp;
        // BinaryNode<Comparable>* test2 = temp;
        // while(test->left != nullptr){
        //     test = test->left;
        //     i++;
        // }
        // while(test2->right != nullptr){
        //     test2 = test2->right;
        //     j++;
        // }
        // if(i>j){
        //     return i;
        // }else{
        //     return j;
        // }
    }
    void Postorder(BinaryNode<Comparable>*& temp){
        if(temp){
            Postorder(temp->right);
            std::cout << temp->val << " : ";
            std::cout << get_height(root,temp->val) << std::endl;
            Postorder(temp->left);
        }
    }



    void print_tree(){
        Postorder(root);
    }
};
