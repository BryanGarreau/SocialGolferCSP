#pragma once

#include "formula.hh"
#include "arrayAccessor.hh"
#include <set>

class Intersection : public Formula {
private:

    ArrayAccessor* _left;
    ArrayAccessor* _right;

public:

    Intersection(ArrayAccessor* l, ArrayAccessor* r): _left(l), _right(r) {}
    int value() const;

    int filtre(Formula* e){
        std::set<int> vide;
        /*if (e->value()==0){
            std::set<int> vide;
        }*/
        std::vector<std::set<int>*> varia;
        varia.push_back(&vide);
        if(_left->value() == _right->value()){
           return 0;
        }
        varia.push_back(&_left->value()->get_lower_bound());
        varia.push_back(&_right->value()->get_lower_bound());


        intersect_bound(varia);
        _right->value()->vide_parcours(_left->value()->get_lower_bound());

        std::vector<std::set<int>*> supp;
        supp.push_back(&_left->value()->get_lower_bound());
        supp.push_back(&_right->value()->get_uper_bound());


        supprime_in_bound(supp);

        return  0;
    }

    ~Intersection(){
        delete _left;
        delete _right;
    }
};
