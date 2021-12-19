#include "ising.h"

Ising::Ising(int n, double J, double B) : J{J}, B{B}, lattice{Lattice(n)} {} 

Lattice* Ising::get_lattice() {
    return &lattice;
}

void Ising::metropolis(int iterations) {
    for (int i = 0; i < iterations; i++) {
        // choose random spin
        tuple<int, int> random_spin = lattice.choose_random_spin();

        // calculate energy before flipping chosen spin
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
    ofstream lattice_file;
    lattice_file.open("../data/lattice.txt", std::ios_base::app);
    lattice_file << *get_lattice();
    lattice_file << ",\n";
    lattice_file.close();
}
