
// FILE: set.h (part of the namespace main_savitch_11)
// TEMPLATE CLASS PROVIDED: set<Item>
//   (a container template class for a set of items)
//
// TYPEDEFS for the set<Item> class:
//   set<Item>::value_type
//     set<Item>::value_type is the data type of the items in the set. It may be
//     any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, a copy constructor, an assignment operator, and a
//     less-than operator forming a strict weak ordering.
//
// CONSTRUCTOR for the set<Item> class:
//   set( )
//     Postcondition: The set is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the set<Item> class:
//   void clear( )
//     Postcondition: The set is empty.
//
//   bool insert(const Item& entry)
//     Postcondition: If an equal entry was already in the set, the set is
//     unchanged and the return value is false. Otherwise, entry was added
//     to the set and the return value is true. This is slightly different than
//     the C++ Standard Library set (see Appendix H).
//
//   size_t erase(const Item& target)
//     Postcondition: If target was in the set, then it has been removed from
//     the set and the return value is 1. Otherwise the set is unchanged and the
//     return value is zero.
//
// CONSTANT MEMBER FUNCTIONS for the Set<Item> class:
//   size_t count(const Item& target) const
//     Postcondition: Returns the number of items equal to the target
//     (either 0 or 1 for a set).
//
//  bool empty( ) const
//     Postcondition: Returns true if the set is empty; otherwise returns false.
//
// VALUE SEMANTICS for the set<Item> class:
//   Assignments and the copy constructor may be used with set<Item> objects.
//
// DYNAMIC MEMORY USAGE by the set<Item> class:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc:
//   The constructors, insert, and the assignment operator.


//Assignment: Use a B-tree to implement the set.h class

#ifndef MAIN_SAVITCH_SET_H
#define MAIN_SAVITCH_SET_H
#include <cstdlib>   // Provides size_t
#include <iostream>
#include <set>
namespace main_savitch_11
{
    template <class Item>
    class set
    {
    public:
        // TYPEDEFS
        typedef Item value_type;
        // CONSTRUCTORS and DESTRUCTOR
        set( );
        set(const set& source);
        ~set( ) { clear( ); }
        // MODIFICATION MEMBER FUNCTIONS
        void operator =(const set& source);
        void clear( );
        bool insert(const Item& entry);
        bool erase(const Item& target);
        // CONSTANT MEMBER FUNCTIONS
        std::size_t count(const Item& target) const;
        bool empty( ) const { return (data_count == 0); }
        // SUGGESTED FUNCTION FOR DEBUGGING
        void print(int indent) const;
        std::size_t getData_count() { return data_count; }
        Item get_data(int index) { return data[index]; }
        std::size_t getChild_count() { return child_count; }
        set get_subset(int i) { return subset[i]; }
    private:
        // MEMBER CONSTANTS
        static const std::size_t MINIMUM = 200;
        static const std::size_t MAXIMUM = 2 * MINIMUM;
        // MEMBER VARIABLES
        std::size_t data_count;
        Item data[MAXIMUM+1];
        std::size_t child_count;
        set *subset[MAXIMUM+2];
        // HELPER MEMBER FUNCTIONS
        bool is_leaf( ) const { return (child_count == 0); }
        bool loose_insert(const Item& entry);
        bool loose_erase(const Item& target);
        void remove_biggest(Item& removed_entry);
        void fix_excess(std::size_t i);
        void fix_shortage(std::size_t i);
        // NOTE: The implementor may want to have additional helper functions
    };
}
//#include "set.template" // Include the implementation.

#endif

using namespace main_savitch_11;

class BtreeNode{
public:
    BtreeNode(int range, bool isLeaf){
        range_ = range;
        leaf_ = isLeaf;
        keys_ = new int[2*range-1];
        child_ = new BtreeNode *[2*range];
        currentKeys_ = 0;
    }
    void traverse();
    int getRange() { return range_; }
    BtreeNode getChild();
    int getKey (int index) { return keys_[index]; }
    
private:
    int *keys_;
    BtreeNode **child_;
    int currentKeys_;
    bool leaf_;
    int range_;
};



/////////   FUNCTIONS   /////////
template<class BtreeNode>
set<BtreeNode>::set(){
    data_count = 2;
    child_count = 0;
    for (int i=0; i<data_count; i++){
        data[i] = i;
    }
}

template<class Item>
set<Item>::set(const set<Item>& source){
    data_count = source.getData_count();
    for (int i=0; i<data_count; i++){
        data[i] = source.get_data(i);
    }
}

template<class Item>
void set<Item>::operator=(const set<Item>& source){
    data_count = source.getData_count();
    child_count = source.getChild_count();
    for (int i=0; i<data_count; i++){
        data[i] = source.get_data(i);
    }
    for (int j=0; j<child_count; j++){
        std::set<Item> pat = source.get_subset(j);
        for (int y=0; y<pat.getData_count; y++){
            subset[j] = pat.get_data(y);
        }
    }
}

template<class Item>
void set<Item>::clear(){
    data_count = 0;
    child_count = 0;
    
}

template<class Item>
bool set<Item>::insert(const Item& entry){
    if (!loose_insert(entry)){
        return false;
    }
    if (data_count > MAXIMUM){
        for (int i=0; i<child_count; i++){
            if (subset[i].getData_count < MAXIMUM - 1){
                int index = subset[i].data_count;
                int index2 = data.data_count;
                subset[i][index+1] = data[index2-1];
                data_count = data_count - 1;
                subset[i].data_count = subset[i].data_count + 1;
                return true;

            }
        }
    }
}

template<class Item>
bool set<Item>::erase(const Item& target){
    if (!loose_erase(target)){
        return false;
    }
    if((data_count == 0) && (child_count == 1)){
        if (subset[0].getData_count > 2){
            int index = subset[0].data_count-1;
            data[0] = subset[0][index];
            subset[0].data_count = subset[0].data_count-1;
            return true;
        }
        
    }
}

template<class Item>
std::size_t set<Item>::count(const Item& target) const {
    
}

template<class Item>
void set<Item>::print(int indent) const {
    
}







int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}
