#include "forAll.hh"
#include <iostream>

bool ForAll::isValid() const {
    //on affecte la valeur au symbole        
    //on teste la contrainte avec cette valeur

    for(auto i : (*_s->get())){//pour chaque élément de l'ensemble
        //std::cout << "debug forall : "<< _iterator->getNom() << " value : "  << i << std::endl;
        _iterator->setVal(i); //on modifie la table des symboles pour être sûr de propager l'information
        //si UNE valeur ne fonctionne pas, on retourne faux
        //std::cout << "debug contrainte : "<< _c->isValid()  << std::endl;
        if(not _c->isValid()){
            return false;
        }
    }

    return true;
}
