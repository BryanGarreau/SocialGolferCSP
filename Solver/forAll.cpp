#include "forAll.hh"
#include <iostream>

bool ForAll::isValid() const {
    //on affecte la valeur au symbole        
    //on teste la contrainte avec cette valeur
    
    for(auto i : (*_s->get())){//pour chaque élément de l'ensemble
        _iterator->setVal(i); //on modifie la table des symboles pour être sûr de propager l'information
        //si UNE valeur ne fonctionne pas, on retourne faux
        if(not _c->isValid()){
            return false;
        }
    }

    return true;
}