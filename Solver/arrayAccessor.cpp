#include "arrayAccessor.hh"

set<int>* ArrayAccessor::value() const {

    return _array->get(_itX->getVal()-1,_itY->getVal()-1);    
}

int ArrayAccessor::size() const {
    //on retourne la taille de l'ensemble à la case itx ity du tableau
    return _array->get(_itX->getVal()-1,_itY->getVal()-1)->size();

}
