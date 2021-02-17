#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <cstdarg>
#include <iterator>
#include "calculatrice.cpp"
#include "variable.cpp"

using namespace std;

std::vector<Variable> _variables;

Variable getVar(std::vector<Variable> variables, string varName){
  for(Variable v : variables){
    if(v._varName == varName){
      return v;
    }
  }
}

static bool readVariable(string ligne){
  string variableType = ligne.substr(0, ligne.find(" "));

  string varName;
  string varValue;
  if(variableType == "var"){ //type variable (int)
    varName = ligne.substr(ligne.find(" ")+1, ligne.find("=")-ligne.find(" ")-1);
    varValue = ligne.substr(ligne.find("=")+1, ligne.find(";")-ligne.find("=")-1);

    int f; // valeur a affecter
    if(varValue.find("*") != string::npos){ //cas calcul sur des variable
      Variable v1 = getVar(_variables, varValue.substr(0, varValue.find("*")));
      int a = static_cast<const IntValue&>(*v1._value)._value;
      Variable v2 = getVar(_variables, varValue.substr(varValue.find("*")+1,
      varValue.length() - varValue.find("*")));
      int b = static_cast<const IntValue&>(*v2._value)._value;

      f = calculate(a,b,'*');
    }
    else if(!(isdigit(varValue[0]))){//cas d'affectation avec une autre variable
      Variable v = getVar(_variables, varValue);
      auto a = static_cast<const IntValue&>(*v._value)._value;
      f = a;
    }
    else { //cas d'une valeur int
      f = stoi(varValue);
    }
    _variables.push_back(Variable(1, varName, 1, f));
  } else if(variableType == "set"){
    
  } else if(variableType == "array"){

  }
  return true;
}

static bool readConstraint(string ligne){
  // std::cout << ligne << '\n';
  return true;
}

static bool read(string fileName)
{
    ifstream fichier(fileName, ios::in);
    if (!fichier.good())
    {
        cout << "le fichier renseigné en paramètre n'existe pas" << endl;
        throw runtime_error("Could not open file");
        return false;
    }
    string ligne;
    while (getline(fichier, ligne))
    {
        size_t isVariable = ligne.find("var");
        if (ligne.find("var") != string::npos ||
         ligne.find("set") != string::npos ||
        ligne.find("array") != string::npos)
        {
            if(!readVariable(ligne))
                return false;
        }
        else readConstraint(ligne);
    }
    fichier.close();
    for(Variable v : _variables){
      std::cout << v << '\n';
    }
    return true;
}
