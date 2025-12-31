#pragma once
#include "../include/point2d.hpp"
#include "../include/point2dcore.hpp"
#include "io_utility.hpp"

void Print2DMenu();
int Get2DMenuChoice();
int Get2DOperationType(int choice);
void Perform2DUnaryOperation(const POINT2D &a, int choice);
void Perform2DBinaryOperation(const POINT2D &a, const POINT2D &b, int choice);
void Perform2DTernaryOperation(const POINT2D &a, const POINT2D &b, const POINT2D &c, int choice);
void Calculate2D();

void Print2DMenu()
{
    std::cout << "\n===== POINT2D - MAIN - MENU =====\n\n";
    std::cout << "1. distance from origin\n2. multiply  point by a scalar\n3. divide point by a constant\n4. normalize point\n5. distance between 2 points\n6. add points\n7. subtract points\n8.dot product\n9. cross product\n10. divide point in a ratio of (m : n)\n11. divide point into half (1 : 2)\n12. midpoint of a point\n13. get slope of points\n14. line equation of points\n15. area of triangle\n16. collinearity check\n17. EXIT\n\n";
}

int Get2DMenuChoice()
{
    int choice = 0;
    while (true)
    {
        std::cout << "enter choice -> [1/2/3/4/5/6/7/8/9/10/11/12/13/14/15/16/17] : ";

        std::cin >> choice;
        ClearInputBuffer();

        if (choice >= 1 && choice <= 17)
        {
            return choice;
        }

        std::cout << std::endl
                  << std::endl;
        std::cout << "[ERROR -> INVALID CHOICE !!]\n[USER ENTERED -> " << choice << "]\nvalid choice -> [1/2/3/4/5/6/7/8/9/10/11/12/13/14/15/16/17]\n\n";
        std::cout << std::endl
                  << std::endl;
        continue;
    }
}

int Get2DOperationType(int choice)
{
    if (choice == 17)
    {
        return 0;
    }

    if (choice >= 15 && choice <= 16)
    {
        return 3;
    }

    else if (choice >= 5 && choice <= 14)
    {
        return 2;
    }

    else if (choice >= 1 && choice <= 4)
    {
        return 1;
    }

    return -1;
}

void Perform2DUnaryOperation(const POINT2D &a, int choice)
{

    if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {
        return;
    }

    std::string OperationPerformed = " ";
    std::string OperationType = "[UNARY OPERATION -> requires 1 operand]";
    std::string PointType = "[POINT2D (x, y)]";

    a.PrintPoint();

    if (choice == 1)
    {
        OperationPerformed = "distance from origin";
        std::cout << "distance from origin : " << a.GetDistanceFromOrigin() << " sqr units" << std::endl;
    }

    else if (choice == 2)
    {
        OperationPerformed = "multiply point by a scalar";

        double constant = 0.000;
        std::cout << "enter the value of scalar by which you want to multiply the point : ";
        std::cin >> constant;

        POINT2D MulByScalar = MultiplyPointByAConstant(a, constant);
        MulByScalar.PrintPoint();
    }

    else if (choice == 3)
    {
        OperationPerformed = "divide point by a scalar";

        double constant = 0.000;
        std::cout << "enter the value of scalar by which you want to divide the point : ";
        std::cin >> constant;

        POINT2D MulByScalar = DividePointByAConstant(a, constant);
        MulByScalar.PrintPoint();
    }

    else if (choice == 4)
    {
        OperationPerformed = "normalize point";

        POINT2D norm = a.normalize();
        norm.PrintPoint();
    }

    std::cout << std::endl
              << std::endl;
    std::cout << "[OPERATION PERFORMED -> " << OperationPerformed << "]" << std::endl;
    std::cout << "[OPERATION CHOICE -> " << OperationType << "]" << std::endl;
    std::cout << "[POINT TYPE -> " << PointType << "]" << std::endl;
    std::cout << std::endl
              << std::endl;
}

void Perform2DBinaryOperation(const POINT2D &a, const POINT2D &b, int choice)
{

    if (choice < 5 || choice > 14)
    {
        return;
    }

    std::string OperationPerformed = " ";
    std::string OperationType = "[BINARY -> require 2 operands]";
    std::string PointType = "[POINT2D (x, y)]";

    a.PrintPoint();
    b.PrintPoint();

    if (choice == 5)
    {
        OperationPerformed = "distance between two points";

        std::cout << "distance between " << a.GetPointName() << " and " << b.GetPointName() << " is : " << GetDistance(a, b) << " sqr units" << std::endl;
    }

    else if (choice == 6)
    {
        OperationPerformed = "add two points";

        POINT2D sum = AddPoint(a, b);

        sum.PrintPoint();
    }

    else if (choice == 7)
    {
        OperationPerformed = "subtract two points";

        POINT2D diff = SubtractPoint(a, b);

        diff.PrintPoint();
    }

    else if (choice == 8)
    {
        OperationPerformed = "dot product of two points";

        double DProduct = DotProduct(a, b);
        std::cout << "dot product of " << a.GetPointName() << " and " << b.GetPointName() << " is " << DProduct << std::endl;
    }

    else if (choice == 9)
    {
        OperationPerformed = "cross product of two points";

        double CProduct = CrossProduct(a, b);
        std::cout << "cross product of " << a.GetPointName() << " and " << b.GetPointName() << " is " << CProduct << std::endl;
    }

    else if (choice == 10)
    {
        OperationPerformed = "divide point in ratio (m:n)";

        double m = 0.0000;
        std::cout << "enter the numerator of the ratio by which you want to divide the point : ";
        std::cin >> m;

        double n = 0.0000;
        std::cout << "enter the denominator of the ratio by which you want to divide the point : ";
        std::cin >> n;

        POINT2D DividedPoint = DividePointInRatio(a, b, m, n);

        std::cout << "divided point " << a.GetPointName() << " and " << b.GetPointName() << " in the ratio of " << m << ":" << n << std::endl;

        std::cout << "resultant divided point : " << std::endl;

        DividedPoint.PrintPoint();
    }

    else if (choice == 11)
    {

        OperationPerformed = "divide point in half (1:2)";

        POINT2D DividedPoint = DividePointInHalf(a, b);

        std::cout << "divided point " << a.GetPointName() << " and " << b.GetPointName() << " in half " << std::endl;

        std::cout << "resultant divided point : " << std::endl;

        DividedPoint.PrintPoint();
    }

    else if (choice == 12)
    {
        OperationPerformed = "midpoint of two points";

        POINT2D MidPoint = GetMidPoint(a, b);

        std::cout << "midpoint point of " << a.GetPointName() << " and " << b.GetPointName() << std::endl;

        std::cout << "resultant midpoint point : " << std::endl;

        MidPoint.PrintPoint();
    }

    else if (choice == 13)
    {
        OperationPerformed = "slope of two points";

        double slope = GetSlope(a, b);

        std::cout << "slope of " << a.GetPointName() << " and " << b.GetPointName() << " is " << slope << std::endl;
    }

    else if (choice == 14)
    {
        OperationPerformed = "line equation of two points";
        std::string LineEquation = GetLineEquation(a, b);

        std::cout << "line equation of " << a.GetPointName() << " and " << b.GetPointName() << " is " << LineEquation << std::endl;
    }

    std::cout << std::endl
              << std::endl;
    std::cout << "[OPERATION PERFORMED -> " << OperationPerformed << "]" << std::endl;
    std::cout << "[OPERATION CHOICE -> " << OperationType << "]" << std::endl;
    std::cout << "[POINT TYPE -> " << PointType << "]" << std::endl;
    std::cout << std::endl
              << std::endl;
}

void Perform2DTernaryOperation(const POINT2D &a, const POINT2D &b, const POINT2D &c, int choice)
{

    if (choice != 15 && choice != 16)
    {
        return;
    }

    std::string OperationPerformed = " ";
    std::string OperationType = "[TERNARY -> require 3 operands]";
    std::string PointType = "[POINT2D (x, y)]";

    a.PrintPoint();
    b.PrintPoint();
    c.PrintPoint();

    if (choice == 15)
    {

        OperationPerformed = "area of triangle";

        double area = GetAreaOfTriangle(a, b, c);

        std::cout << "area of triangle made by the points " << a.GetPointName() << ", " << b.GetPointName() << ", " << c.GetPointName() << " is " << area << " sqr units" << std::endl;
    }

    if (choice == 16)
    {

        OperationPerformed = "collinear check";

        bool collinear = ArePointsCollinear(a, b, c);

        std::cout << "are the points " << a.GetPointName() << ", " << b.GetPointName() << ", " << c.GetPointName() << " collinear ? -> " << (collinear == 1 ? "TRUE" : "FALSE") << std::endl;
    }

    std::cout << std::endl
              << std::endl;
    std::cout << "[OPERATION PERFORMED -> " << OperationPerformed << "]" << std::endl;
    std::cout << "[OPERATION CHOICE -> " << OperationType << "]" << std::endl;
    std::cout << "[POINT TYPE -> " << PointType << "]" << std::endl;
    std::cout << std::endl
              << std::endl;
}

void Calculate2D()
{
    POINT2D a;
    POINT2D b;
    POINT2D c;

    Print2DMenu();

    int TwoDOperationChoice = Get2DMenuChoice();

    int OperationType = Get2DOperationType(TwoDOperationChoice);

    if (OperationType == 0)
    {
        return;
    }

    if (OperationType == 1)
    {
        InputPointFor2DOperation(&a);
        Perform2DUnaryOperation(a, TwoDOperationChoice);
    }

    else if (OperationType == 2)
    {
        InputPointFor2DOperation(&a, &b);
        Perform2DBinaryOperation(a, b, TwoDOperationChoice);
    }

    else if (OperationType == 3)
    {
        InputPointFor2DOperation(&a, &b, &c);
        Perform2DTernaryOperation(a, b, c, TwoDOperationChoice);
    }
}
