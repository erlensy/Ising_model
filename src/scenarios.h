#pragma once
#include "ising.h"

// writes many lattices to lattice.txt
void many_states(int n, double J, double B, int iters, 
                 int states);
/*
n = (n*n) size of lattice, 
J = interaction strength,
B = beta,
states = total number of lattices
iters = iterations between states */

// writes average magnetization for many betas to magnetization.txt
void magnetization(int n, double J, double B_min, double B_max, int B_n,
                   int iters_equilibrium, int iters_avg,
                   int iters_new_state);
/*
n = (n*n) size of lattice, 
J = interaction strength,
B_min, B_max = beta range (includes B_min and B_max),
B_n = number of beta values in beta range,
iters_equilibrium = iterations from initial state to first state,
iters_avg = number of states to average over for one beta value,
iters_new_state = iterations between states */
