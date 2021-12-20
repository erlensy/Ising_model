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

void Ising::write_magnetization_to_file(double magnetization) {
    ofstream magnetization_file;
    magnetization_file.open("../data/raw/magnetization.txt", std::ios_base::app);
    magnetization_file << B << "," << magnetization << "\n";
    magnetization_file.close();
}


void Ising::write_lattice_to_file() {
    ofstream lattice_file;
    lattice_file.open("../data/raw/lattice.txt", std::ios_base::app);
    lattice_file << *get_lattice();
    // print ,\n to seperate different states 
    lattice_file << ",\n";
    lattice_file.close();
}

Lattice* Ising::get_lattice() {
    return &lattice;
}

double Ising::get_magnetization() {
    return lattice.total_magnetization();
}
