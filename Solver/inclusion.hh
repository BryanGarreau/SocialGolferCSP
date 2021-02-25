#pragma once

#include "formula.hh"
#include "arrayAccessor.hh"
#include <set>

class Inclusion : public Formula {
private:

    ArrayAccessor* _left;
    ArrayAccessor* _right;

public:

    Inclusion(ArrayAccessor* l, ArrayAccessor* r): _left(l), _right(r) {}
    int value() const;

    int filtre(Formula* e){
        std::set<int> vide;

        std::vector<std::set<int>*> varia;
        if(_left->value() == _right->value()){
           return 0;
        }
        varia.push_back(&_right->value()->get_lower_bound());
        varia.push_back(&_left->value()->get_lower_bound());


        int result = insere_in_bound(varia);
        //_right->value()->vide_parcours(_left->value()->get_lower_bound());

        /*std::vector<std::set<int>*> supp;
        supp.push_back(&_left->value()->get_uper_bound());
        supp.push_back(&_right->value()->get_uper_bound());


        int result = supprime_in_bound(supp);*/
        if (_left->value()->get_lower_bound().size()>_right->value()->get_lower_bound().size()){
            return 2;
        }

        if (!present_bound(varia)){
            return 2;
        }
        return  result;
    }

    ~Inclusion(){
        delete _left;
        delete _right;
    }
};
