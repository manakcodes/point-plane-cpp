#pragma once
#include "../include/point2d.hpp"
#include "../include/point2dcore.hpp"
#include "../include/point3d.hpp"
#include "../include/point3d.hpp"

void ClearInputBuffer();
void PrintMenu();
int InputPointChoice();
void InputPointFor2DOperation(POINT2D *a, POINT2D *b = nullptr, POINT2D *c = nullptr);
void InputPointFor3DOperation(POINT3D *a, POINT3D *b = nullptr, POINT3D *c = nullptr);

void ClearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void PrintMenu()
{
    std::cout << std::endl
              << std::endl
              << "MAIN - MENU" << std::endl;
    std::cout << "1. [POINT2D (x, y)] operations" << std::endl;
    std::cout << "2. [POINT3D (x, y, z)] operations" << std::endl;
    std::cout << "3. EXIT" << std::endl
              << std::endl;
}

int InputPointChoice()
{
    int choice = 0;

    while (true)
    {
        PrintMenu();
        std::cout << "enter choice [1/2/3] : ";
        std::cin >> choice;
        ClearInputBuffer();

        if (choice == 1)
        {
            std::cout << "you chose : [POINT2D(x, y)]" << std::endl;
            return choice;
        }

        else if (choice == 2)
        {
            std::cout << "you chose : [POINT3D(x, y, z)]" << std::endl;
            return choice;
        }

        if (choice == 3)
        {
            std::cout << "you chose : -> [EXIT]" << std::endl;
            return choice;
        }

        std::cout << std::endl
                  << std::endl;
        std::cout << "[ERROR ->INVALID CHOICE !!]" << std::endl;
        std::cout << "[USER ENTERED -> " << choice << "]" << std::endl;
        std::cout << "[VALID CHOICE -> [1/2/3]]" << std::endl;
        std::cout << std::endl
                  << std::endl;
        continue;
    }
}

void InputPointFor2DOperation(POINT2D *a, POINT2D *b, POINT2D *c)
{
    if (a && !b && !c)
    {
        std::cout << "enter the details for POINT2D below" << std::endl
                  << std::endl;

        char PointName = 'x';
        std::cout << "enter the name of the point : ";
        std::cin >> PointName;
        ClearInputBuffer();

        double x = 0.0000;
        std::cout << "enter the value of x coordinate of the point : ";
        std::cin >> x;
        ClearInputBuffer();

        double y = 0.0000;
        std::cout << "enter the value of y coordinate of the point : ";
        std::cin >> y;
        ClearInputBuffer();

        a->SetPointName(PointName);
        a->SetXCoordinate(x);
        a->SetYCoordinate(y);

        std::cout << "POINT2D -> " << PointName << " completed" << std::endl
                  << std::endl;
        return;
    }

    else if (a && b && !c)
    {
        std::cout << "enter the details for point 1 below" << std::endl
                  << std::endl;

        char PointName1 = 'x';
        std::cout << "enter the name of the point : ";
        std::cin >> PointName1;
        ClearInputBuffer();

        double x1 = 0.0000;
        std::cout << "enter the value of x coordinate of the point : ";
        std::cin >> x1;
        ClearInputBuffer();

        double y1 = 0.0000;
        std::cout << "enter the value of y coordinate of the point : ";
        std::cin >> y1;
        ClearInputBuffer();

        a->SetPointName(PointName1);
        a->SetXCoordinate(x1);
        a->SetYCoordinate(y1);

        std::cout << "first point :: POINT2D -> " << PointName1 << " completed" << std::endl
                  << std::endl;

        std::cout << "enter the details for point 2 below" << std::endl
                  << std::endl;

        char PointName2 = 'x';
        std::cout << "enter the name of the point : ";
        std::cin >> PointName2;
        ClearInputBuffer();

        double x2 = 0.0000;
        std::cout << "enter the value of x coordinate of the point : ";
        std::cin >> x2;
        ClearInputBuffer();

        double y2 = 0.0000;
        std::cout << "enter the value of y coordinate of the point : ";
        std::cin >> y2;
        ClearInputBuffer();

        std::cout << "POINT2D -> " << PointName2 << " completed" << std::endl
                  << std::endl;

        b->SetPointName(PointName2);
        b->SetXCoordinate(x2);
        b->SetYCoordinate(y2);

        std::cout << "second point :: POINT2D -> " << PointName2 << " completed" << std::endl
                  << std::endl;
        return;
    }

    else if (a && b && c)
    {
        std::cout << "enter the details for point 1 below" << std::endl
                  << std::endl;

        char PointName1 = 'x';
        std::cout << "enter the name of the point 1 : ";
        std::cin >> PointName1;
        ClearInputBuffer();

        double x1 = 0.0000;
        std::cout << "enter the value of x coordinate of the point 1 : ";
        std::cin >> x1;
        ClearInputBuffer();

        double y1 = 0.0000;
        std::cout << "enter the value of y coordinate of the point 1 : ";
        std::cin >> y1;
        ClearInputBuffer();

        a->SetPointName(PointName1);
        a->SetXCoordinate(x1);
        a->SetYCoordinate(y1);

        std::cout << "first point :: POINT2D -> " << PointName1 << " completed" << std::endl
                  << std::endl;

        std::cout << "enter the details for point 2 below" << std::endl
                  << std::endl;

        char PointName2 = 'x';
        std::cout << "enter the name of the point 2 : ";
        std::cin >> PointName2;
        ClearInputBuffer();

        double x2 = 0.0000;
        std::cout << "enter the value of x coordinate of the point 2 : ";
        std::cin >> x2;
        ClearInputBuffer();

        double y2 = 0.0000;
        std::cout << "enter the value of y coordinate of the point 2 : ";
        std::cin >> y2;
        ClearInputBuffer();

        b->SetPointName(PointName2);
        b->SetXCoordinate(x2);
        b->SetYCoordinate(y2);

        std::cout << "second point :: POINT2D -> " << PointName2 << " completed" << std::endl
                  << std::endl;

        std::cout << "enter the details for point 3 below" << std::endl
                  << std::endl;

        char PointName3 = 'x';
        std::cout << "enter the name of the point 3 : ";
        std::cin >> PointName3;

        double x3 = 0.0000;
        std::cout << "enter the value of x coordinate of the point 3 : ";
        std::cin >> x3;

        double y3 = 0.0000;
        std::cout << "enter the value of y coordinate of the point 3 : ";
        std::cin >> y3;

        std::cout << "POINT2D -> " << PointName3 << " completed" << std::endl
                  << std::endl;

        c->SetPointName(PointName3);
        c->SetXCoordinate(x3);
        c->SetYCoordinate(y3);

        std::cout << "third point :: POINT2D -> " << PointName3 << " completed" << std::endl
                  << std::endl;
    }
}

void InputPointFor3DOperation(POINT3D *a, POINT3D *b, POINT3D *c)
{
    if (a && !b && !c)
    {
        std::cout << "enter the details for POINT2D below" << std::endl
                  << std::endl;

        char PointName = 'x';
        std::cout << "enter the name of the point : ";
        std::cin >> PointName;
        ClearInputBuffer();

        double x = 0.0000;
        std::cout << "enter the value of x coordinate of the point : ";
        std::cin >> x;
        ClearInputBuffer();

        double y = 0.0000;
        std::cout << "enter the value of y coordinate of the point : ";
        std::cin >> y;
        ClearInputBuffer();

        double z = 0.0000;
        std::cout << "enter the value of z coordinate of the point : ";
        std::cin >> z;
        ClearInputBuffer();

        a->SetPointName(PointName);
        a->SetXCoordinate(x);
        a->SetYCoordinate(y);
        a->SetZCoordinate(z);

        std::cout << "POINT3D -> " << PointName << " completed" << std::endl
                  << std::endl;
        return;
    }

    else if (a && b && !c)
    {
        std::cout << "enter the details for point 1 below" << std::endl
                  << std::endl;

        char PointName1 = 'x';
        std::cout << "enter the name of the point : ";
        std::cin >> PointName1;
        ClearInputBuffer();

        double x1 = 0.0000;
        std::cout << "enter the value of x coordinate of the point 1 : ";
        std::cin >> x1;
        ClearInputBuffer();

        double y1 = 0.0000;
        std::cout << "enter the value of y coordinate of the point 1 : ";
        std::cin >> y1;

        double z1 = 0.0000;
        std::cout << "enter the value of z coordinate of the point 1 : ";
        std::cin >> z1;

        a->SetPointName(PointName1);
        a->SetXCoordinate(x1);
        a->SetYCoordinate(y1);
        a->SetZCoordinate(z1);

        std::cout << "first point :: POINT3D -> " << PointName1 << " completed" << std::endl
                  << std::endl;

        std::cout << "enter the details for point 2 below" << std::endl
                  << std::endl;

        char PointName2 = 'x';
        std::cout << "enter the name of the point : ";
        std::cin >> PointName2;

        double x2 = 0.0000;
        std::cout << "enter the value of x coordinate of the point 2 :";
        std::cin >> x2;

        double y2 = 0.0000;
        std::cout << "enter the value of y coordinate of the point 2 : ";
        std::cin >> y2;

        double z2 = 0.0000;
        std::cout << "enter the value of z coordinate of the point 2 : ";
        std::cin >> z2;

        std::cout << "POINT2D -> " << PointName2 << " completed" << std::endl
                  << std::endl;

        b->SetPointName(PointName2);
        b->SetXCoordinate(x2);
        b->SetYCoordinate(y2);
        b->SetZCoordinate(z2);

        std::cout << "second point :: POINT3D -> " << PointName2 << " completed" << std::endl
                  << std::endl;
        return;
    }

    else if (a && b && c)
    {
        std::cout << "enter the details for point 1 below" << std::endl
                  << std::endl;

        char PointName1 = 'x';
        std::cout << "enter the name of the point 1 : ";
        std::cin >> PointName1;
        ClearInputBuffer();

        double x1 = 0.0000;
        std::cout << "enter the value of x coordinate of the point 1 : ";
        std::cin >> x1;
        ClearInputBuffer();

        double y1 = 0.0000;
        std::cout << "enter the value of y coordinate of the point 1 : ";
        std::cin >> y1;
        ClearInputBuffer();

        double z1 = 0.0000;
        std::cout << "enter the value of z coordinate of the point 1 : ";
        std::cin >> z1;
        ClearInputBuffer();

        a->SetPointName(PointName1);
        a->SetXCoordinate(x1);
        a->SetYCoordinate(y1);
        a->SetZCoordinate(z1);

        std::cout << "first point :: POINT3D -> " << PointName1 << " completed" << std::endl
                  << std::endl;

        std::cout << "enter the details for point 2 below" << std::endl
                  << std::endl;

        char PointName2 = 'x';
        std::cout << "enter the name of the point 2 : ";
        std::cin >> PointName2;
        ClearInputBuffer();

        double x2 = 0.0000;
        std::cout << "enter the value of x coordinate of the point 2 : ";
        std::cin >> x2;
        ClearInputBuffer();

        double y2 = 0.0000;
        std::cout << "enter the value of y coordinate of the point 2 : ";
        std::cin >> y2;
        ClearInputBuffer();

        double z2 = 0.0000;
        std::cout << "enter the value of z coordinate of the point 2 : ";
        std::cin >> z2;
        ClearInputBuffer();

        b->SetPointName(PointName2);
        b->SetXCoordinate(x2);
        b->SetYCoordinate(y2);
        b->SetZCoordinate(z2);

        std::cout << "second point :: POINT3D -> " << PointName2 << " completed" << std::endl
                  << std::endl;

        std::cout << "enter the details for point 3 below" << std::endl
                  << std::endl;

        char PointName3 = 'x';
        std::cout << "enter the name of the point 3 : ";
        std::cin >> PointName3;
        ClearInputBuffer();

        double x3 = 0.0000;
        std::cout << "enter the value of x coordinate of the point 3 : ";
        std::cin >> x3;
        ClearInputBuffer();

        double y3 = 0.0000;
        std::cout << "enter the value of y coordinate of the point 3 : ";
        std::cin >> y3;
        ClearInputBuffer();

        double z3 = 0.0000;
        std::cout << "enter the value of z coordinate of the point 3 : ";
        std::cin >> z3;
        ClearInputBuffer();

        std::cout << "POINT3D -> " << PointName3 << " completed" << std::endl
                  << std::endl;

        c->SetPointName(PointName3);
        c->SetXCoordinate(x3);
        c->SetYCoordinate(y3);
        c->SetZCoordinate(z3);

        std::cout << "third point :: POINT3D -> " << PointName3 << " completed" << std::endl
                  << std::endl;
    }
}
