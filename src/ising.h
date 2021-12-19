#pragma once
#include <iostream>
#include <fstream>
#include "math.h"
#include "lattice.h"

class Ising {

    private:
        // coupling strength
        double J; 

        // beta = 1 / (kT)
        double B;

        // lattice
        Lattice lattice;

    public:
        Ising(int n, double J, double B);

        Lattice* get_lattice();

        void metropolis(int iterations);

        void write_lattice_to_file();
};
