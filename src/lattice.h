#pragma once
#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Lattice{
    private:
        // n*n size of matrix
        int n;

        // mersenne twister random number generator
        mt19937 generator;

    public:
        // constructor 
        Lattice(int n);

        // 2d matrix holding spins
        vector<vector<bool>> lattice;

        // overloading operator
        friend ostream& operator<<(ostream& out, Lattice& l);
};
