#pragma once
#include "math.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

class Lattice{
    private:
        // n*n gridsize
        int n;

        // 2d matrix holding spins
        vector<vector<int>> grid;

        // probability distributions
        bernoulli_distribution bool_distr{0.5};
        uniform_int_distribution<int> int_distr{0, n-1};

    public:
        // mersenne twister random number generator
        mt19937 generator;

        // probability distribution used by ising class
        uniform_real_distribution<double> double_distr{0.0, 1.0};

        // constructor 
        Lattice(int n);

        // calculate energy with row_col as center spin
        double calculate_energy(tuple<int, int> row_col);

        // get spin methods
        int get_spin(int row, int col);
        int get_spin(tuple<int, int> row_col);

        // flip spin at site (row, col)
        void flip_spin(tuple<int, int> row_col);

        // returns random spin pos (row, col) 
        tuple<int, int> choose_random_spin();

        // overloading << operator for printing grid
        friend ostream& operator<<(ostream& out, Lattice& l);
};
