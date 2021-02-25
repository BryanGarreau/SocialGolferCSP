#include "ensemble.hh"


bool Ensemble::element(int var){

    if ( _set->end()==_set->find(var)){
        return false;
    }
    return true;
}//FinMethode


int Ensemble::give_item(){

}//FinMethode
