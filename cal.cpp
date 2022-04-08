#include <iostream>
#include <fstream>
#include <string>
#include "quadratic.c"
#include "triples.c"
#include "sum.c"

using namespace std;


int main() {
    ifstream inFile, quadratic, triples, modSum;

    //open cal.in
    inFile.open("cal.in.txt");

    //if file does not open
    if (inFile.fail()){
        cerr << "Error opening file" << endl;
        exit(1);
    }

    //define values
    int numb, x, y;
    string value;

    //get the integer at the top of the file
    inFile >> numb;
    cout << "This file has " << numb + 1 << " lines" << endl;

    //get the file input
    while(inFile >> value >> x >> y){
        if (value == "quadratic"){
            quadratic_solution(1, x, y);
        }else if (value == "triples"){
            find_triples(x, y);
        } else if (value == "mod-sum"){
            modular_sum(x, y);
        }else{
            cout << "Invalid" << x << y<< endl;
        }


        }

    inFile.close();

    return 0;
}




