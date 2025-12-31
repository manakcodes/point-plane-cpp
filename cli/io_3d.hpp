#pragma once
#include "../include/point3d.hpp"
#include "../include/point3dcore.hpp"
#include "io_utility.hpp"

void Print3DMenu();
int Get3DMenuChoice();
int Get3DOperationType(int choice);
void Perform3DUnaryOperation(const POINT3D &a, int choice);
void Perform3DBinaryOperation(const POINT3D &a, const POINT3D &b, int choice);
void Perform3DTernaryOperation(const POINT3D &a, const POINT3D &b, const POINT3D &c, int choice);
void Calculate3D();

void Print3DMenu()
{
    std::string menu = "\n\n===== POINT3D - MAIN - MENU =====\n\n1. distance from origin\n2. normalize point\n3. add 2 points\n4. subtract 2 points\n5. multiply point by a scalar\n6. divide point by a scalar\n7. distance between 2 points\n8. dot product\n9. cross product\n10. collinearity check \n11. area of triangle\n12. EXIT\n\n";

    std::cout << menu;
}

int Get3DMenuChoice()
{
    int choice = 0;
    while (true)
    {
        std::cout << "enter choice -> [1/2/3/4/5/6/7/8/9/10/11/12] : ";
        std::cin >> choice;
        ClearInputBuffer();

        if (choice >= 1 && choice <= 12)
        {
            return choice;
        }

        std::cout << "[ERROR -> INVALID CHOICE !!]\n[USER ENTERED -> " << choice
                  << "]\nvalid choice -> [1/2/3/4/5/6/7/8/9/10/11/12]\n\n";
    }
}

int Get3DOperationType(int choice)
{
    if (choice == 12)
    {
        return 0;
    }

    if (choice == 10 || choice == 11)
    {
        return 3;
    }

    if (choice == 1 || choice == 2 || choice == 5 || choice == 6)
    {
        return 1;
    }

    if (choice == 3 || choice == 4 || choice == 7 || choice == 8 || choice == 9)
    {
        return 2;
    }

    return -1;
}

void Perform3DUnaryOperation(const POINT3D &a, int choice)
{
    std::string OperationChoice = " ";
    std::string OperationType = "[UNARY OPERATION -> requires 1 operand]";
    std::string PointType = "[POINT3D (x, y, z)]";

    a.PrintPoint();

    if (choice == 1)
    {
        OperationChoice = "distance from origin";
        std::cout << "distance of " << a.GetPointName()
                  << " from origin is : " << a.GetDistanceFromOrigin() << " sqr units" << std::endl;
    }

    else if (choice == 2)
    {
        OperationChoice = "normalize point";
        POINT3D normalized = a.normalized();
        std::cout << "normalized point : " << std::endl;
        normalized.PrintPoint();
    }

    else if (choice == 5)
    {
        OperationChoice = "multiply point by a scalar";
        double scalar = 0.0000;
        std::cout << "enter the value of the scalar by which you want to multiply the point : ";
        std::cin >> scalar;
        std::cout << "after multiplying POINT3D " << a.GetPointName() << " by " << scalar << std::endl;
        MultiplyPointByAScalar(a, scalar).PrintPoint();
    }

    else if (choice == 6)
    {
        OperationChoice = "divide point by a scalar";
        double scalar = 0.0000;
        std::cout << "enter the value of the scalar by which you want to divide the point : ";
        std::cin >> scalar;
        std::cout << "after dividing POINT3D " << a.GetPointName() << " by " << scalar << std::endl;
        DividePointByAScalar(a, scalar).PrintPoint();
    }

    std::cout << std::endl;
    std::cout << "[OPERATION CHOICE -> " << OperationChoice << "]" << std::endl;
    std::cout << "[OPERATION CHOICE -> " << OperationType << "]" << std::endl;
    std::cout << "[POINT TYPE -> " << PointType << "]" << std::endl;
    std::cout << std::endl;
}

void Perform3DBinaryOperation(const POINT3D &a, const POINT3D &b, int choice)
{
    std::string OperationChoice = " ";
    std::string OperationType = "[BINARY OPERATION -> requires 2 operands]";
    std::string PointType = "[POINT3D (x, y, z)]";

    a.PrintPoint();
    b.PrintPoint();

    if (choice == 3)
    {
        OperationChoice = "add two points";
        std::cout << "sum of " << a.GetPointName() << ", " << b.GetPointName() << " is : " << std::endl;
        AddPoint(a, b).PrintPoint();
    }

    else if (choice == 4)
    {
        OperationChoice = "subtract two points";
        std::cout << "difference of " << a.GetPointName() << ", " << b.GetPointName() << " is : " << std::endl;
        SubtractPoint(a, b).PrintPoint();
    }

    else if (choice == 7)
    {
        OperationChoice = "distance between two points";
        std::cout << "distance between : " << a.GetPointName() << " and " << b.GetPointName()
                  << " is : " << GetDistance(a, b) << " sqr units" << std::endl;
    }

    else if (choice == 8)
    {
        OperationChoice = "dot product of two points";
        std::cout << "dot product of " << a.GetPointName() << ", " << b.GetPointName()
                  << " is : " << DotProduct(a, b) << std::endl;
    }

    else if (choice == 9)
    {
        OperationChoice = "cross product of two points";
        std::cout << "cross product of " << a.GetPointName() << ", " << b.GetPointName() << " is : " << std::endl;
        CrossProduct(a, b).PrintPoint();
    }

    std::cout << std::endl
              << std::endl;
    std::cout << "[OPERATION CHOICE -> " << OperationChoice << "]" << std::endl;
    std::cout << "[OPERATION CHOICE -> " << OperationType << "]" << std::endl;
    std::cout << "[POINT TYPE -> " << PointType << "]" << std::endl;
    std::cout << std::endl
              << std::endl;
}

void Perform3DTernaryOperation(const POINT3D &a, const POINT3D &b, const POINT3D &c, int choice)
{
    std::string OperationChoice = " ";
    std::string OperationType = "[TERNARY OPERATION -> requires 3 operand]";
    std::string PointType = "[POINT3D (x, y, z)]";

    a.PrintPoint();
    b.PrintPoint();
    c.PrintPoint();

    if (choice == 10)
    {
        OperationChoice = "are 3 points collinear";
        std::cout << "are points collinear -> ? "
                  << a.GetPointName() << ", " << b.GetPointName() << ", " << c.GetPointName()
                  << (ArePointsCollinear(a, b, c) ? "TRUE" : "FALSE") << std::endl;
    }

    else if (choice == 11)
    {
        OperationChoice = "area of triangle enclosed between 3 points";
        std::cout << "area of points " << a.GetPointName() << ", " << b.GetPointName() << ", "
                  << c.GetPointName() << " is : " << GetAreaOfTriangle(a, b, c)
                  << " sqr units" << std::endl;
    }

    std::cout << std::endl
              << std::endl;
    std::cout << "[OPERATION CHOICE -> " << OperationChoice << "]" << std::endl;
    std::cout << "[OPERATION CHOICE -> " << OperationType << "]" << std::endl;
    std::cout << "[POINT TYPE -> " << PointType << "]" << std::endl;
    std::cout << std::endl
              << std::endl;
}

void Calculate3D()
{
    Print3DMenu();

    POINT3D a, b, c;

    int choice = Get3DMenuChoice();
    int OperationType = Get3DOperationType(choice);

    if (OperationType == 0)
    {
        return;
    }

    else if (OperationType == 1)
    {
        InputPointFor3DOperation(&a);
        Perform3DUnaryOperation(a, choice);
    }

    else if (OperationType == 2)
    {
        InputPointFor3DOperation(&a, &b);
        Perform3DBinaryOperation(a, b, choice);
    }

    else if (OperationType == 3)
    {
        InputPointFor3DOperation(&a, &b, &c);
        Perform3DTernaryOperation(a, b, c, choice);
    }
}
