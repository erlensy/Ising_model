#pragma once
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
        // constructor
        Ising(int n, double J, double B);

        // metropolis algorithm
        void metropolis(int iterations);

        // function that writes current state to ../data/lattice.txt
        void write_lattice_to_file();

        // get current lattice state
        Lattice* get_lattice();
};
