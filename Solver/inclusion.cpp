#include "inclusion.hh"

#include <iostream>
#include <set>

int Inclusion::value() const{

    std::set<int>* l = &_left->value()->get_lower_bound();
    std::set<int>* r = &_right->value()->get_lower_bound();

    int count = 0;

    for(int i : *l){

        count += r->count(i);
    }

    //std::cout << "Debug intersction : " << l->size() << "  " << r->size() << std::endl;
    //std::cout << "count de l'intersection : " << count << std::endl;

    return count;
}
