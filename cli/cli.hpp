#pragma once
#include "io_utility.hpp"
#include "io_2d.hpp"
#include "io_3d.hpp"

void IOEngine();

void IOEngine()
{
    while (true)
    {
        int choice = InputPointChoice();

        if (choice == 1)
        {
            Calculate2D();
        }

        else if (choice == 2)
        {
            Calculate3D();
        }

        else if (choice == 3)
        {
            break;
        }

        else
        {
            std::cout << "[ERROR -> [INVALID CHOICE !!]\n[USER ENTERED ->]" << choice << "[VALID CHOICE -> 1/2]\n\n";
            continue;
        }
    }
}