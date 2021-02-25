#pragma once
#include <set>
#include <vector>

class Formula {
private:
    
public:
    virtual int value() const = 0;
     virtual int filtre(Formula* e)=0;
    virtual ~Formula(){}
};


//=========================

bool intersect_bound(std::vector<std::set<int>*> &varia);

//=========================

bool supprime_in_bound(std::vector<std::set<int>*> &varia);

//=========================

bool union_bound(std::vector<std::set<int>*> &varia);

//========================

bool insere_in_bound(std::vector<std::set<int>*> &varia);

//========================

bool present_bound(std::vector<std::set<int>*> &varia);


