#include "formula.hh"

#include <iostream>

bool intersect_bound(std::vector<std::set<int>*> &varia){
    unsigned int checksum=0;

    for (unsigned int i = 0; i < varia.size(); ++i) {
        checksum += varia.at(i)->size();
    }


    std::set<int> mel;
    for(unsigned int i=1;i<varia.size();i++){
         mel.insert(varia.at(i)->begin(),varia.at(i)->end());
    }

    std::vector<int> sup;
    bool valide=true;
    for (auto j:mel){
        valide=true;
        for (unsigned int i=1;i<varia.size();i++){
            valide = valide && !(varia.at(i)->find(j)==varia.at(i)->end());
        }
        if(!valide){
            sup.push_back(j);
        }
    }

    /*std::set<int> trol;
    for (auto j:mel){
        valide = true;
        for (int i=1;i<varia.size();i++){
            valide = valide && (varia.at(i)->find(j)!=varia.at(i)->end());
        }
        if(valide){
            trol.insert(j);
        }
    }


    for (auto i:trol) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;*/

    for(unsigned int i=0;i<sup.size();i++){
        mel.erase(sup.at(i));
    }


    for (auto j: mel){

        if(varia.at(0)->find(j)==varia.at(0)->end()){
            for (unsigned int i = 2; i < varia.size(); ++i) {
                    varia.at(i)->erase(j);
            }
        }
    }

    unsigned int cheksumc = 0;
    for (unsigned int i = 0; i < varia.size(); ++i) {
        cheksumc += varia.at(i)->size();
    }

    if (checksum-cheksumc ==0){
        return 0;

    }
    else{
        return 1;
    }
}//FinFonction

//==============================

bool supprime_in_bound(std::vector<std::set<int>*> &varia){

    for (unsigned int i=1;i<varia.size();i++){
        for (auto j:*varia.at(0)) {
            varia.at(i)->erase(j);
        }
    }

    return true;

}

//==============================

bool union_bound(std::vector<std::set<int>> &varia){
    unsigned int checksum=0;
    for (unsigned int i = 0; i < varia.size(); ++i) {
        checksum += varia.at(i).size();
    }


    std::set<int> mel;
    for(unsigned int i=1;i<varia.size();i++){
         mel.insert(varia.at(i).begin(),varia.at(i).end());
    }
    std::vector<int> sup;
    bool valide=true;
    for (auto j:mel){
        valide=true;
        for (unsigned int i=1;i<varia.size();i++){
            valide = valide && !(varia.at(i).find(j)==varia.at(i).end());
        }
        if(!valide){
            sup.push_back(j);
        }
    }
    for(unsigned int i=0;i<sup.size();i++){
        mel.erase(sup.at(i));
    }

    for (auto j: mel){

        if(varia.at(0).find(j)==varia.at(0).end()){
            for (unsigned int i = 2; i < varia.size(); ++i) {
                    varia.at(i).erase(j);
            }
        }
    }

    unsigned int cheksumc = 0;
    for (unsigned int i = 0; i < varia.size(); ++i) {
        cheksumc += varia.at(i).size();
    }

    if (checksum-cheksumc ==0){
        return 0;

    }
    else{
        return 1;
    }
}

//========================

bool insere_in_bound(std::vector<std::set<int>*> &varia){
    for (unsigned int  i=1;i<varia.size();i++)
        for(auto j : *varia.at(0)){
            varia.at(i)->insert(j);
        }
    return true;
}

//========================

bool present_bound(std::vector<std::set<int>*> &varia){

    for(auto j:*varia.at(1)){
        if(*varia.at(0)->find(j)){
            return false;
        }
    }

    return true;
}
