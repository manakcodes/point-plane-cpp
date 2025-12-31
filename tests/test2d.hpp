#pragma once
#include "../include/pointplanecpp.hpp"
#include <assert.h>

namespace TESTS2D
{
    void TestDistanceBetweenPointsMethod();
    void TestAdditionAndSubtractionMethods();
    void TestMultiplyAndDivideByScalarMethods();
};

void Run2DTests();

void Run2DTests()
{
    std::cout << "running tests on 2D point...\n\n";
    TESTS2D::TestDistanceBetweenPointsMethod();
    TESTS2D::TestAdditionAndSubtractionMethods();
    TESTS2D::TestMultiplyAndDivideByScalarMethods();
}

void TESTS2D::TestDistanceBetweenPointsMethod()
{
    {
        POINT2D a = POINT2D(3, 4);
        POINT2D b = POINT2D(1, 4);

        assert(COMPARE_DOUBLE::IS_EQUAL(GetDistance(a, b), 2.0000));

        std::cout << "POINT2D test : distance between 2 points test passed" << std::endl;
    }

    {
        POINT2D a = POINT2D(3, 4);

        assert(COMPARE_DOUBLE::IS_EQUAL(a.GetDistanceFromOrigin(), 5.0000));

        std::cout << "POINT2D test : distance from origin test passed" << std::endl;
    }
}

void TESTS2D::TestAdditionAndSubtractionMethods()
{
    POINT2D a = POINT2D(2, 2);
    POINT2D b = POINT2D(5, 5);

    {
        POINT2D sum = AddPoint(a, b);

        assert(COMPARE_DOUBLE::IS_EQUAL(sum.GetXCoordinate() == 7.0000 && sum.GetYCoordinate() == 7.0000, true));

        std::cout << "POINT2D test : addition of 2D points" << std::endl;
    }

    {
        POINT2D diff = SubtractPoint(b, a);

        assert(COMPARE_DOUBLE::IS_EQUAL(diff.GetXCoordinate() == 3.0000 && diff.GetYCoordinate() == 3.0000, true));

        std::cout << "POINT2D test : subtraction of 2D points" << std::endl;
    }
}

void TESTS2D::TestMultiplyAndDivideByScalarMethods()
{
    POINT2D a = POINT2D(2, 2);

    {
        POINT2D mul = MultiplyPointByAConstant(a, 5.0000);

        assert(COMPARE_DOUBLE::IS_EQUAL(mul.GetXCoordinate() == 10.0000 && mul.GetYCoordinate() == 10.0000, true));

        std::cout << "POINT2D test : multiply 2D point by a scalar" << std::endl;
    }

    {
        POINT2D div = DividePointByAConstant(a, 0.5000);

        assert(COMPARE_DOUBLE::IS_EQUAL(div.GetXCoordinate() == 4.0000 && div.GetYCoordinate() == 4.0000, true));

        std::cout << "POINT2D test : divide 2D point by a scalar" << std::endl;
    }
}