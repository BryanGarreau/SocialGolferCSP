#include "solveur.hh"
#include "parser.hh"

//=================================

bool Solveur::lauch(){

std::cout<<"Lancement"<<std::endl;
//lire le fichier
//parser lefichier

std::set<int> * nb_semaine = new std::set<int>();
std::set<int> * nb_groupe = new std::set<int>();

for (int i = 0; i < 10; ++i) {
   nb_semaine->insert(i);
}

for (int i = 0; i < 5; ++i) {
   nb_groupe->insert(i);
}

//Construire les ensembles
std::vector<std::vector<Ensemble>> solution;
std::vector<Ensemble*> ensemble;

std::set<int>* titi = new std::set<int>;
for(int i=0;i<5;i++){
    titi->insert(i);
}
Ensemble* ens1 = new Ensemble(titi,"e1");
Ensemble* ens2 = new Ensemble(titi,"e2");
ens1->set_name("ens1");
ens2->set_name("ens2");
titi->insert(777);
Ensemble* ens3 = new Ensemble(titi,"e3");
ensemble.push_back(ens1);
ensemble.push_back(ens2);

_maximum = 0;
for (u32 i=0;i<ensemble.size();i++){
_maximum += ensemble.at(i)->get_uper_bound().size();
}
//std::cout<<"taille = "<<_maximum<<std::endl;

ensemble.push_back(ens3);

//construire les cointrantes

std::vector<Constraint *> tt;

/*Formula* c1 = new Intersection(ens1,ens2);
Constante* con1=new Constante(0);

Constraint* eq1 = new Equal(c1,con1);
_constrainte.push_back(eq1);

Formula* card1= new Card(ens1);
Formula* card2= new Card(ens2);

Constante* con2=new Constante(2);

Constraint* equ2 = new Equal(card1,con2);
Constraint* equ3 = new Equal(card2,con2);

_constrainte.push_back(equ2);
_constrainte.push_back(equ3);


Formula* c2 = new Intersection(ens1,ens3);

Constraint* eq2 = new Equal(c2,con1);
_constrainte.push_back(eq2);*/

//F != G
//F c G
sum=0;
//std::cout<<_constrainte.at(0)<<std::endl;
//Fonctionnement MAC consitantte recalculer
//std::cout<<_ensemble.at(0)->get(0,0)<<std::endl;
//endroit =0;
std::vector<Ensemble*> ens;
for (u32 j = 0; j < _ensemble.at(0)->sizeX(); ++j) {
    for (u32 i=0 ;i<_ensemble.at(0)->sizeY();++i){
        ens.push_back(_ensemble.at(0)->get(static_cast<int>(j),static_cast<int>(i)));
    }

}

//std::cout<<_arraysDecision.at(0)->get(0,0)<<std::endl;
/*int g=3;
int t=3;
int s=3;
int nb=g*t;

std::vector<Ensemble *> ens_cata;

std::set<int>* varia=new std::set<int>;
for(int i=0;i<nb;i++){
    varia->insert(i+1);
}

for(int i=0;i<nb;i++){

    Ensemble* nw_ens= new Ensemble(varia,"ens"+std::to_string(i));
    ens_cata.push_back(nw_ens);
}

//Contrainte
Formula* cons1=new Constante(0);
Formula* cons2=new Constante(t);
Formula* cons3=new Constante(1);

for (int k;k<s;k++){
    for (int i=0;i<g;i++) {
        for(int j=i;j<g;j++){



        }
    }
}*/

bool valide = propagation(ens,solution,0,0);

if(valide or solution.size()!=0){
    std::cout<<"Solution trouvé"<<std::endl;
}
else{
    std::cout<<"Pas de solution"<<std::endl;
}


return  true;
}//FinMethode

//=========================

bool Solveur::arc_consistance(){
   bool filtre=false;
   int etat=-1;
   while(!filtre){
       filtre = true;
       for (auto constrainte :_constrainte){
           //0 aucun changement sur les domaines
           //1 Changemenet sur un domaine
           //2 Domaine inconstitant

           etat = constrainte->filtre();
           if(etat == 1){filtre = false;}
           else if (etat == 2) {return false;}

       }
   }
    return true;

}//FinMethode

//=========================

bool Solveur::verification_contrainte(std::vector<Ensemble*> &ensemble){
    bool valide = true;
   /* for (u32 i =0;i<ensemble.size();i++){
        valide = valide && ensemble.at(i)->get_lower_bound().size() ==3;
    }*/

    for (auto constrainte :_constrainte){
        valide = valide && constrainte->isValid();
        if( !valide){
            return valide;
        }
    }
    return valide;

}//FinMethode

//=========================

bool Solveur::look_ahead(std::vector<Ensemble*> &ensemble,std::vector<std::vector<Ensemble>> &solution,int pronfondeur,u32 endroit){
    //if(static_cast<u32>(pronfondeur)>_maximum){return true;}

    sum++;
   // std::cout<<"sum : "<<sum<<std::endl;

   //std::cout<<"look ahead"<< " endroit : "<<endroit<<std::endl;
    std::vector<Ensemble*> copy_ensemble;
    for (u32 i=0;i<ensemble.size();i++){
        Ensemble* re = new Ensemble();
        *re = *ensemble.at(i);
        copy_ensemble.push_back(re);
    }

    _pile.push_back(copy_ensemble);

        //std::cout<<"pile : "<<_pile.size()<<" "<<pronfondeur<<std::endl;
    //std::cout<<"nommme : "<<ensemble.at(endroit)<<std::endl;
            create_branch(ensemble.at(endroit),ensemble,solution,endroit,true,pronfondeur+1,endroit);
            for (u32 i = 0; i < ensemble.size(); ++i) {
                 //ensemble[i] = _pile[static_cast<u32>(_pile.size()-1)][i];
                *ensemble[i] = *_pile[static_cast<u32>(pronfondeur)][i];
            }
            create_branch(ensemble.at(endroit),ensemble,solution,endroit,false,pronfondeur+1,endroit);
             /*for (u32 i=0;i< _pile.at(_pile.size()-1).size();i++){
                  delete _pile.at(_pile.size()-1).at(i);
             }*/
             _pile.pop_back();

    return true;
}//FinMethode

//=========================

bool Solveur::create_branch(Ensemble* &e,std::vector<Ensemble*> &ensemble,std::vector<std::vector<Ensemble>> &solution,u32 k,bool t,int profondeur,u32 endroit){

   // Ensemble* re = new Ensemble();
   // *re = *e;
     //std::cout<<"at "<<std::endl;
    e->change_lower_bound(t);
    return propagation(ensemble,solution,profondeur,endroit);
}//FinMethode

//=========================

bool Solveur::propagation(std::vector<Ensemble*> &ensemble,std::vector<std::vector<Ensemble>> &solution,int pronfondeur,u32 endroit){

    //filtrage(ensemble,_constrainte);
    if (!arc_consistance()){
        return false;
    }
   /* std::cout<<"taille : "<<ensemble.size()<<" "<<std::endl;
    std::cout<<"========"<<std::endl;
    for (u32 i = 0; i < ensemble.size(); ++i) {
       //for(auto j:y){
        //std::cout<<"valeur parcours  : "<<ensemble.at(i)->get_valeur_parcours()<<std::endl;

       for(auto j:ensemble[i]->get_lower_bound()){
           std::cout<<" "<<j;
       }
       std::cout<<std::endl;
    }*/
    if (verification_contrainte(ensemble)){
        //solution.push_back(ensemble);
        std::cout<<"========"<<std::endl;
        for (u32 i = 0; i < ensemble.size  (); ++i) {
           //std::set<int> y=ensemble[i].give_parccours();
           std::set<int> y=ensemble[i]->get_lower_bound();
           for(auto j:y){
               std::cout<<" "<<j;
           }
           std::cout<<std::endl;
        }

    }
      //if(static_cast<u32>(pronfondeur)>_maximum){return true;}

    if (ensemble.at(endroit)->atteint_maximum()){endroit++;}
    if(endroit>=ensemble.size()){return true;}
      return look_ahead(ensemble,solution,pronfondeur,endroit);

}//FinMethode

//=========================

