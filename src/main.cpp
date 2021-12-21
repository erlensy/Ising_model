#include "scenarios.h"
#include <thread>

void print(int n) {
    cout << n;
}

int main() {

    vector<std::thread> threads;
    /*
    threads.push_back(thread(many_states,
                100, 1.0, 1.0, 1000, 10));
    */

    threads.push_back(thread(magnetization, 
                10, 1.0, 0.30, 0.66, 32,
                256, 502, 256));

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
