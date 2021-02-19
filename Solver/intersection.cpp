#include "intersection.hh"

int Intersection::value() const{

    int n = 0;

    for(auto i = _left->begin(); i != _left->end(); i++){
        n += _right->count(*i);
    }

    return n;
}
