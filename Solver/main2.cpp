#include <iostream>
#include <set>

#include "forAll.hh"
#include "equal.hh"
#include "variable.hh"
#include "card.hh"



int main(){

    int* taille_groupe = new int(3);
    std::set<int> * nb_semaine = new std::set<int>();
    std::set<int> * nb_groupe = new std::set<int>();

    //constraint forall(i in 1..nb_semaine)(forall(j in 1..nb_groupe)(card(ladder[i,j])==taille_groupe ));

    for(int i = 1; i <= *taille_groupe; i++){
        nb_semaine->insert(i);
        nb_groupe->insert(i);
    }

    Variable* left = new Variable(new int(3));
    Variable* right = new Variable(taille_groupe);

    Equal* contrainteInterne =  new Equal(left, right);

    int* it2 = new int(0);
    ForAll* deuxiemeForall = new ForAll(it2, nb_groupe, contrainteInterne);

    int* it1 = new int(0);
    ForAll* premierForall = new ForAll(it1, nb_semaine, deuxiemeForall);

    std::cout << "val left  : " << left->value() << std::endl;
    std::cout << "val right : " << right->value() << std::endl;
    std::cout << "res left == right : " << contrainteInterne->isValid() << std::endl;
    std::cout << "res Forall 2 : " << deuxiemeForall->isValid() << std::endl;
    std::cout << "res Forall 1 : " << premierForall->isValid() << std::endl;

    Card ca(nb_semaine);

    std::cout << "card : " << ca.value() << std::endl;


//constraint forall(i in 1..nb_semaine)(forall(j in 1..nb_groupe)(card(ladder[i,j])==taille_groupe ));

//constraint forall(i in 1..nb_semaine)(forall(k,l in 1..nb_groupe where k!=l)(ladder[i,k] intersect ladder[i,l] == {}));
//ForAll(i in nb_semaine)(forall(k in nb_groupe)(forall(l in nb_groupe)) disjonction(l==k,conjonction(k!=l,intersect(ladder[i,k],ladder[i,l]))))

//constraint forall(i,j in 1..nb_semaine where i!=j)(forall(k,l in 1..nb_groupe where k!=l)(card(ladder[i,l] intersect ladder[j,k]) == 1));
//ForAll(i in nb_semaine)(forall(j in nb_semaine)(forall(j in nb_semaine)(forall(l in nb_groupe) disjonction(l==k,conjonction(k!=l,intersect(ladder[i,k],ladder[i,l]))))))

    return 0;
}
