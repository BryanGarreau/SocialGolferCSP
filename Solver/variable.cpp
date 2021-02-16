#pragma once
#include <iostream>
#include <string>
#include <set>
#include <cstdarg>
#include <iterator>


struct SuperType{

  friend ostream& operator<<(ostream &out,const SuperType &v) {
    return out;
  }

};

struct IntValue : public SuperType{
  int _value;
  IntValue(int value):_value(value){}

  friend ostream& operator<<(ostream &out,const IntValue &v) {
    out << "Int " <<(int)v._value;
    return out;
  }
};

struct SetValue : public SuperType{
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

struct Array1D : public SuperType{
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

struct Array2D : public SuperType{
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
  SuperType *_value;
  Variable(int varType, string varName, int n, ...):_varType(varType), _varName(varName){
    vector<int> v_values;
    va_list values;
    va_start(values, n); //la liste des constantes commence apres n
      switch (_varType) {
        case 1:
          for(int i=0; i<n; ++i){
            int v = (int) va_arg(values, int);
            v_values.push_back(v);
          }
          _value = new IntValue(v_values[0]);
          break;
        case 2:
          for(int i=0; i<n; ++i){
            int v = (int) va_arg(values, int);
            v_values.push_back(v);
          }
          _value = new SetValue(v_values[0], v_values[1]);
          break;
        case 3:
          for(int i=0; i<n; ++i){
            int v = (int) va_arg(values, int);
            v_values.push_back(v);
          }
          _value = new Array2D(v_values[0], v_values[1]);
          break;
      }
    va_end(values);
  }

  friend ostream& operator<<(ostream &out,const Variable &v) {
    out << v._varName << " : ";
    switch (v._varType) {
      case 1:
      {
        auto value = static_cast<const IntValue&>(*v._value);
        out << value << "\n";
        break;
      }
      case 2:
      {
        auto value = static_cast<const SetValue&>(*v._value);
        out << value << "\n";
        break;
      }
      case 3:
      {
        auto value = static_cast<const Array2D&>(*v._value);
        out << value << "\n";
        break;
      }
    }
    return out;
  }
};
