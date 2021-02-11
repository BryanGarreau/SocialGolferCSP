#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

static bool readVariable(string ligne){
  std::cout << ligne << '\n';
  return true;
}

static bool readConstraint(string ligne){
  std::cout << ligne << '\n';
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
        size_t isVariable = ligne.find(":");
        if (isVariable != string::npos)
        {
            if(!readVariable(ligne))
                return false;
        }
        else readConstraint(ligne);
    }
    fichier.close();
    return true;
}
