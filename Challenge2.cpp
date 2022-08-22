#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments();

int main()
{
    Expression* expression;
    char paren, comma;
    string program;

    ifstream myfile("expressions.txt");

    if (myfile.is_open())
    {
        while (getline(myfile, program))
        {
            cout << program << '\n';   
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    cin.get(); 
    return 0;
}
