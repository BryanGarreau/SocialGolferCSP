#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <cstdarg>
#include <iterator>

using namespace std;

struct SuperType{
  friend ostream& operator<<(ostream &out,const SuperType &v) {
    out << "SuperType";
    return out;
  }
};

struct IntValue : SuperType{
  int _value;
  IntValue(int value):_value(value){}

  friend ostream& operator<<(ostream &out,const IntValue &v) {
    out << v._value;
    return out;
  }
};

struct SetValue : SuperType{
  set<int> _values;
  SetValue(int start, int end){
    for(int i = start; i<=end; i++){
      _values.insert(i);
    }
  }

  friend ostream& operator<<(ostream &out,const SetValue &v) {
    out << "[";
    for (auto elem : v._values)
    {
      out << elem << ", ";
    }
    out << "]";
    return out;
  }
};

struct Array1D : SuperType{
  size_t _size;
  int * _values;
  // iterator iterator;
  Array1D(size_t size, int * values):_size(size){
    _values = new int[size];
    // iterator = begin(values);
  }

  friend ostream& operator<<(ostream &out,const Array1D &v) {
    out << "tableau 1D pas implémenté";
    return out;
  }
};

struct Array2D : SuperType{
  size_t _size1;
  size_t _size2;
  int ** _values;
  Array2D(size_t size1, size_t size2)
  :_size1(size1), _size2(size2){
    // values = new int[size1][size2];
  }

  friend ostream& operator<<(ostream &out,const Array2D &v) {
    out << "{ ";
    for(int i=0; i<v._size1; i++){
      out << "{ ";
      for(int j=0; j<v._size2; j++){
        out << v._values[i][j] << " ";
      }
      out << "} ";
    }
    out << "} ";
    return out;
  }
};

struct Variable{
  int _varType;
  string _varName;
  SuperType _value;
  Variable(int varType, string varName, int n, ...):_varType(varType), _varName(varName){
    vector<int> v_values;
    va_list values;
    va_start(values, n); //la liste des constantes commence apres n
      switch (varType) {
        case 1:
          for(int i=0; i<n; ++i){
            int v = (int) va_arg(values, int );
            v_values.push_back(v);
          }
          _value = IntValue(v_values[0]);
          break;
        case 2:
          for(int i=0; i<n; ++i){
            int v = (int) va_arg(values, int );
            v_values.push_back(v);
          }
          _value = SetValue(v_values[0], v_values[1]);
          break;
        case 3:
          for(int i=0; i<n; ++i){
            int v = (int) va_arg(values, int );
            v_values.push_back(v);
          }
          _value = Array2D(v_values[0], v_values[1]);
          break;
      }
    va_end(values);
  }

  friend ostream& operator<<(ostream &out,const Variable &v) {
    out << v._varName << " : ";
    out << v._value << "\n";
    return out;
  }
};

std::vector<Variable> variables;

static bool readVariable(string ligne){
  string variableType = ligne.substr(0, ligne.find(" "));
  std::cout << variableType << '\n';

  string varName = /*a lire*/"v1";
  if(variableType == "var"){
    // variables.push_back(Object(1));
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
    return true;
}
