#include "test2d.hpp"
#include "test3d.hpp"
#include <thread>
#include <chrono>

void RunTests();

int main()
{
    RunTests();
    return 0;
}

void RunTests()
{
    std::cout << "..........\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "\nrunning tests...\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    Run2DTests();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Run3DTests();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "\nall tests competed successfully\nsystem ok\n";
    std::cout << "\n..........\n";
}