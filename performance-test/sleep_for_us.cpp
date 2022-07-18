/* Idlestate test result:
 * sleep_for(1 us) real sleep:60
 * sleep_for(100 us) real sleep:160
 */
#include <iostream>
#include <thread>
#include <chrono>


int main() {
        auto start = std::chrono::high_resolution_clock::now();
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        auto end = std::chrono::high_resolution_clock::now();

        std::cout << "sleep_for(100 us) real sleep:" <<
                std::chrono::duration_cast<std::chrono::microseconds>( end - start).count();
        std::cout << std::endl;
        return 0;
}

