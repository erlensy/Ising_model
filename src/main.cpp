#include "ising.h"

int main() {
    Ising model{100, 1000.0, 10000.0};

    for (int i = 0; i < 1000; i++) {
        model.write_lattice_to_file();
        model.metropolis(10000);
    }
}
