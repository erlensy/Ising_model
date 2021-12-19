#pragma once
#include "ising.h"

// n = 100, J = 0, Beta = 1, two states, 1 million iterations 
void no_interaction();

// n = 100, J = 1, Beta = 0, two states, 1 million iterations
void infinite_temperature();

// n = 100, j = 1, Beta = 1/0.4, 10 thousand states, 10 thousand iterations
void ferromagnetic_phase_transition_small_lattice();

// n = 100, j = -1, Beta = 1/0.4, 10 thousand states, 10 thousand iterations
void antiferromagnetic_phase_transition_small_lattice();

// n = 500, j = 1, Beta = 1/0.4, 10 thousand states, 10 thousand iterations
void ferromagnetic_phase_transition_large_lattice();

// n = 500, j = -1, Beta = 1/0.4, 10 thousand states, 10 thousand iterations
void antiferromagnetic_phase_transition_large_lattice();
