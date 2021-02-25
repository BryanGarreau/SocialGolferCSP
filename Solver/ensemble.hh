#pragma once
#include <set>
#include <iostream>
#include <vector>
using u32=unsigned int;



class Ensemble {
private:

    std::set<int>* _set;
    int _min_card;
    int _max_card;
    std::string _nom;
    std::set<int> _lower_bound;
    std::set<int> _upper_bound;

    std::vector<int> _valeur;
    int valeur_parcours;

public:

    Ensemble(){ valeur_parcours = 0;}//FinMethode

//======================

    Ensemble(std::set<int>* s,std::string n): _set(s),_nom(n){
        _min_card = 0;
        _max_card = static_cast<int>(_set->size());

        for (auto i:*_set) {
            _valeur.push_back(i);
        }

        _upper_bound = *_set;
        valeur_parcours = 0;
    }//FinMethode

//======================

    std::set<int>* get(){return _set;}//FinMethode
    std::string getNom(){return _nom;}//FinMethode
    bool isEmpty(){return _set->empty();}//FinMethode
    void setValue(std::set<int>* s) {_set = s;}//FinMethode

//======================

    Ensemble (const Ensemble &source){
        _min_card = source._min_card;
        _max_card = source._max_card;
        _set = source._set;
        _valeur = source._valeur;
        valeur_parcours = source.valeur_parcours;
        _upper_bound= source._upper_bound;
        _lower_bound= source._lower_bound;

    }//FinMethode

//======================

    bool element(int var);
    int give_item();

//======================

    std::set<int>&  get_lower_bound  (){
            return _lower_bound;
    }//FinMethode

//======================

    std::set<int>&  get_uper_bound  (){
            return _upper_bound;
    }//FinMethode

//======================

    void set_name(std::string n){
        _nom = n;
    }//FinMethode

//======================

    std::string get_name(){
        return _nom;
    }//FinMethode

//======================

    void change_lower_bound(bool t){
        if (t){
            if(_valeur.size() > static_cast<u32>(valeur_parcours)){
                //std::cout<<"bugguer"<<std::endl;
            _lower_bound.insert(_valeur.at(static_cast<u32>(valeur_parcours)));
            }
        }
        valeur_parcours++;
    }//FinMethode

//======================

    int size(){
        return static_cast<int>(_lower_bound.size());
    }//FinMethode

//======================

    bool is_vide(){
        return _valeur.size()==static_cast<u32>(valeur_parcours+1);
    }//FinMethode

//======================

    void grow_lowerbound(int var){
        _lower_bound.insert(var);
    }//FinMethode

//======================

    int filtre(std::set<int> upper,std::set<int> lower,int mincard,int maxcard){

        _upper_bound = upper;
       // _lower_bound = lower;
        _min_card = mincard;
        _max_card = maxcard;

        std::vector<int> tmp;
        for(auto j:upper){
            tmp.push_back(j);
        }
        if(tmp.size()<_valeur.size()){
            _valeur = tmp;
            //valeur_parcours--;
        }

        return 0;
    }//FinMethode
//======================

    void vide_parcours(std::set<int> tt){
       std::vector<int> tmp;
         for(u32 i=0;i<_valeur.size();i++){
             bool valide=true;
           for (auto j:tt){
                if(_valeur.at(i)==j){
                    valide = false;
                }
            }
            if(valide){
                tmp.push_back(_valeur[i]);
            }
        }
         _valeur=tmp;
    }

//======================

    bool atteint_maximum(){
        return static_cast<u32>(valeur_parcours) >= _valeur.size();
    }//FinMethode

//======================

    ~Ensemble(){
        delete _set;
    }//FinMethode

//======================

    int get_valeur_parcours(){
        return valeur_parcours;
    }//FinMethode

//===============================================

    //Ensemble(int a,int b) {min=a;max=b;for (int i=a;i<=b;i++){valeur.push_back(i);}}
    
  //  std::set<int>::iterator upperBound(){return _set.upperBound();}
//std::set<int>::iterator lowerBound(){return _set.lowerBound();}

    
};
