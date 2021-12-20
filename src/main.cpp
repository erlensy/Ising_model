#include "scenarios.h"
#include <thread>

void print(int n) {
    cout << n;
}

int main() {

    vector<std::thread> threads;

    threads.push_back(thread(many_states,
                100, 1.0, 1.0, 100000, 100));

    threads.push_back(thread(magnetization, 
                10, 1.0, 0.33, 0.66, 100,
                500000, 100, 1000));

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
