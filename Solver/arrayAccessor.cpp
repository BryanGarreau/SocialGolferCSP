#include "arrayAccessor.hh"

set<int>* ArrayAccessor::value() const {

    return _array->get(_itX->getVal(),_itY->getVal());    
}

int ArrayAccessor::size() const {
    //on retourne la taille de l'ensemble à la case itx ity du tableau
    return _array->get(_itX->getVal(),_itY->getVal())->size();

}
