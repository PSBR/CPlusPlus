
#include <iostream>
#ifndef BINTREE_H
#define BINTREE_H
#include <cstdlib>  // Provides NULL and size_t
#include <string>

/*
Assignment: Convert an arithmetic expression in prefix notation into a binary tree, such that
each operation is stored in a node whose left subtree stores the left operand and whose right subtree
stores the right operand
*/

template <class Item>
class binary_tree_node{
    public:
        // TYPEDEFtypedef
        Item value_type;
        // CONSTRUCTOR
        binary_tree_node(
                         const Item& init_data = Item( ),
                         binary_tree_node* init_left = NULL,
                         binary_tree_node* init_right = NULL)
        {
            data_field = init_data;
            left_field = init_left;
            right_field = init_right;
        }
        // MODIFICATION MEMBER FUNCTIONS
        Item& data( ) { return data_field; }
        binary_tree_node* left( ) { return left_field; }
        binary_tree_node* right( ) { return right_field; }
        void set_data(const Item& new_data) { data_field = new_data; }
        void set_left(binary_tree_node* new_left) { left_field = new_left; }
        void set_right(binary_tree_node* new_right) { right_field = new_right; }
        // CONST MEMBER FUNCTIONSconst
        Item& data( ) const { return data_field; }
        const binary_tree_node* left( ) const { return left_field; }
        const binary_tree_node* right( ) const { return right_field; }
        bool is_leaf( ) const    { return (left_field == NULL) && (right_field == NULL); }
        
    private:
        Item data_field;
        binary_tree_node *left_field;
        binary_tree_node *right_field;
    };

// NON-MEMBER FUNCTIONS for the binary_tree_node<Item>:

bool isOperator (char c){
    if (c == '+' || c == '-' || c == '/' || c == '*'){
        return true;
    }else{
        return false;
    }
}

bool isLetter (char c){
    if (c>='A' && c<='Z'){
        return true;
    }else{
        return false;
    }
}

template <class Process, class BTNode>
void inorder(Process f, BTNode* node_ptr);

template <class Process, class BTNode>
void preorder(Process f, BTNode* node_ptr);

template <class Process, class BTNode>
void postorder(Process f, BTNode* node_ptr);

template <class Item, class SizeType>
void print(binary_tree_node<Item>* node_ptr, SizeType depth){
    if (node_ptr != NULL){
        print(node_ptr->left(), depth);
        std::cout<<node_ptr->data()<<std::endl;
        print(node_ptr->right(), depth);
    }
}

template <class Item>
void tree_clear(binary_tree_node<Item>*& root_ptr);

template <class Item>
binary_tree_node<Item>* tree_copy(const binary_tree_node<Item>* root_ptr);

template <class Item>
std::size_t tree_size(const binary_tree_node<Item>* node_ptr);

void prefixToTree(std::string str){
    //(+A*BC)
    int index = 0;
    int count = 1;
    const int size = str.length();
    binary_tree_node<char> *prefix[size];
    prefix[0] -> set_data(NULL);
    for (int i=0; i<str.length(); i++){
        if (isOperator(str[i])){
            if (prefix[i]->data() == NULL){
                prefix[i]->set_data(str[i]);
                index++;
            }else if (isOperator(str[i-1]) && isLetter(str[i+1])){
                prefix[index]->set_data(str[i]);
                prefix[0]->set_left(prefix[index]);
                index++;
            }else if(isLetter(str[i-1])&&isLetter(str[i+1])){
                prefix[index]->set_data(str[i]);
                prefix[0]->set_right(prefix[index]);
                index++;
            }
        }else if (isLetter(str[i])){
            if (isOperator(str[i-1])&&isOperator(str[i+1])){
                prefix[index]->set_data(str[i]);
                prefix[0]->set_left(prefix[index]);
                index++;
            }else if(isOperator(str[i-1])&&isLetter(str[i+1])){
                prefix[index]->set_data(str[i]);
                prefix[count]->set_left(prefix[index]);
                index++;
            }else if (isLetter(str[i-1])&&isOperator(str[i+1])){
                prefix[index]->set_data(str[i]);
                prefix[count]->set_right(prefix[index]);
                index++;
                count++;
            }else{
                prefix[index]->set_data(str[i]);
                prefix[count]->set_right(prefix[index]);
                index++;
            }
        }
    }
    print(prefix[0], index);
}



int main(int argc, const char * argv[]) {
    std::string test;
    std::cout<<"Input prefix notation: "<<std::endl;
    std::cin>>test;
    prefixToTree(test);
    
    return 0;
}

#endif
