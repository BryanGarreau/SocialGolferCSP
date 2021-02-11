#include <iostream>
#include <string>
#include "parser.cpp"
using namespace std;

int main(int argc, char **argv)
{
	string fileName;
	if (argv[1] == nullptr)
	{
		cout << "paramètre non renseigné" << endl;
		return 0;
	}
	else
	{
		fileName = argv[1];
	}

	if(read(fileName))
    std::cout << "lecture bonne" << '\n';

	return 0;
}
