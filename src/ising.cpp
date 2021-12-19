#include "ising.h"

// constructor initializing lattice, J and B
Ising::Ising(int n, double J, double B) : J{J}, B{B}, lattice{Lattice(n)} {} 

// algorithm to resemble the canonical ensemble
void Ising::metropolis(int iterations) {
    for (int i = 0; i < iterations; i++) {
        // choose random spin
        tuple<int, int> random_spin = lattice.choose_random_spin();

        // calculate change in energy if random_spin is flipped
        double delta_energy = 2.0 * J * lattice.calculate_energy(random_spin);
        // flip chosen spin
        lattice.flip_spin(random_spin);

        // accept flip if delta energy < 0
        if (delta_energy >= 0) {
            // accept spin with probability exp(-B*dE)
            if (lattice.double_distr(lattice.generator) >= exp(-B * delta_energy)) {
                lattice.flip_spin(random_spin);
            }
        }
    }
}

void Ising::write_lattice_to_file() {
    // create output stream
    ofstream lattice_file;
    // open file with "append" mode
    lattice_file.open("../data/raw/lattices.txt", std::ios_base::app);
    // use overloaded operator << to print state to file
    lattice_file << *get_lattice();
    // print ,\n to seperate different states 
    lattice_file << ",\n";
    lattice_file.close();
}

Lattice* Ising::get_lattice() {
    return &lattice;
}
