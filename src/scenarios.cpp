#include "scenarios.h"

void no_interaction() {
    Ising model{100, 0.0, 1.0}; 
    model.write_lattice_to_file();
    model.metropolis(1000000);
    model.write_lattice_to_file();
}

void infinite_temperature() {
    Ising model{100, 1.0, 0.0};
    model.write_lattice_to_file();
    model.metropolis(1000000);
    model.write_lattice_to_file();
}

void ferromagnetic_phase_transition_small_lattice() {
    Ising model{100, 1.0, 1.0/0.4};
    for (int i = 0; i < 100000; i++) {
        model.write_lattice_to_file();
        model.metropolis(10000);
    }
}

void antiferromagnetic_phase_transition_small_lattice() {
    Ising model{100, -1.0, 1.0/0.4};
    for (int i = 0; i < 10000; i++) {
        model.write_lattice_to_file();
        model.metropolis(10000);
    }
}
void ferromagnetic_phase_transition_large_lattice() {
    Ising model{500, 1.0, 1.0/0.4};
    for (int i = 0; i < 10000; i++) {
        model.write_lattice_to_file();
        model.metropolis(10000);
    }
}

void antiferromagnetic_phase_transition_large_lattice() {
    Ising model{500, -1.0, 1.0/0.4};
    for (int i = 0; i < 10000; i++) {
        model.write_lattice_to_file();
        model.metropolis(10000);
    }
}
