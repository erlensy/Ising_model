#include "scenarios.h"

void many_states(int n, double J, double B, int iters, int states) {
    Ising model{n, J, B};
    for (int i = 0; i < states; i++) {
        model.write_lattice_to_file();
        model.metropolis(iters);
    }
}

void magnetization(int n, double J, double B_min, double B_max, int B_n,
                   int iters_equilibrium, int iters_avg,
                   int iters_new_state) {

    for (int i = 0; i <= B_n; i++) {
        Ising model{n, J, B_min + i * (B_max - B_min) / (B_n + 1)};
        model.metropolis(iters_equilibrium);
        double avg_magnetization = 0;
        for (int j = 0; j < iters_avg; j++) {
            avg_magnetization += model.get_magnetization();
            model.metropolis(iters_new_state);
        }
        model.write_magnetization_to_file(avg_magnetization / iters_avg);
    }
}
