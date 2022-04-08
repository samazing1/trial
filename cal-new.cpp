#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include "cmake-build-debug/quadratic.c"
#include "cmake-build-debug/triples.c"
#include "cmake-build-debug/sum.c"

using namespace std;
void calNew (char*, int, int){

    int numberLines, x, y;
    string calType;

    if (calType == "quadratic"){
        solve_quadratic(x, y);
    }else if (calType == "triples"){
        find_triples(x, y);
    } else if (calType == "mod-sum"){
        modular_sum(x, y);
    }else{
        cout << "Invalid option" << x << y<< endl;
    }

}