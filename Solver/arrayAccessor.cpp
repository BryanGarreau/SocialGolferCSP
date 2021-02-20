#include "arrayAccessor.hh"
#include <iostream>

set<int>* ArrayAccessor::value() const {
    std::cout << "Accessor : on essaye d'accéder  à : " << _itX->getVal()-1 << " " << _itY->getVal()-1 << std::endl;
    return _array->get(_itX->getVal()-1,_itY->getVal()-1);    
}

int ArrayAccessor::size() const {
    //on retourne la taille de l'ensemble à la case itx ity du tableau
    return _array->get(_itX->getVal()-1,_itY->getVal()-1)->size();

}
