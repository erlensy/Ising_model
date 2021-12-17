#include "lattice.h"

using namespace std;

// constructor
Lattice::Lattice(int n) : n{n} {
    // seed random number generator with "true" randomness
    random_device rd;
    generator.seed(rd()); 

    // make uniform boolean distribution 
    bernoulli_distribution distr(0.5);

    // iterate through lattice and set random spin
    for (int i = 0; i < n; i++) {
        lattice.push_back(vector<bool>(n));
        for (int j = 0; j < n; j++) {
            lattice[i][j] = distr(generator);
        }
    }
}

// overloading << operator
ostream& operator<<(ostream& out, Lattice& l) {
    for (int i = 0; i < l.n; i++) {
        for (int j = 0; j < l.n; j++) {
            out << l.lattice[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}
