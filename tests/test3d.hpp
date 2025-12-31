#pragma once
#include "../include/pointplanecpp.hpp"
#include <assert.h>

namespace TESTS3D
{
    void TestDistanceBetweenPointsMethod();
    void TestAdditionAndSubtractionMethods();
    void TestMultiplyAndDivideByScalarMethods();
};

void Run3DTests()
{
    std::cout << "\nrunning tests on 3D point...\n\n";
    TESTS3D::TestDistanceBetweenPointsMethod();
    TESTS3D::TestAdditionAndSubtractionMethods();
    TESTS3D::TestMultiplyAndDivideByScalarMethods();
}

void TESTS3D::TestDistanceBetweenPointsMethod()
{
    {
        POINT3D a = POINT3D(0, 0, 0);
        POINT3D b = POINT3D(1, 1, 1);

        assert(COMPARE_DOUBLE::IS_EQUAL(GetDistance(a, b), 1.732));

        std::cout << "POINT3D test : distance between 2 points test passed" << std::endl;
    }

    {
        POINT3D a = POINT3D(1, 1, 1);

        assert(COMPARE_DOUBLE::IS_EQUAL(a.GetDistanceFromOrigin(), 1.732));

        std::cout << "POINT3D test : distance from origin test passed" << std::endl;
    }
}

void TESTS3D::TestAdditionAndSubtractionMethods()
{
    POINT3D a = POINT3D(2, 4, 6);
    POINT3D b = POINT3D(1, 3, 5);

    {
        POINT3D sum = AddPoint(a, b);

        assert(COMPARE_DOUBLE::IS_EQUAL(sum.GetXCoordinate() == 3 && sum.GetYCoordinate() == 7 && sum.GetZCoordinate() == 11, true));

        std::cout << "POINT3D test : addition of 3D points" << std::endl;
    }

    {
        POINT3D diff = SubtractPoint(b, a);

        assert(COMPARE_DOUBLE::IS_EQUAL(diff.GetXCoordinate() == -1 && diff.GetYCoordinate() == -1 && diff.GetZCoordinate() == -1, true));

        std::cout << "POINT3D test : subtraction of 3D points" << std::endl;
    }
}

void TESTS3D::TestMultiplyAndDivideByScalarMethods()
{
    POINT3D a = POINT3D(2, 2, 2);

    {
        POINT3D mul = MultiplyPointByAScalar(a, 5.0000);

        assert(COMPARE_DOUBLE::IS_EQUAL(mul.GetXCoordinate() == 10 && mul.GetYCoordinate() == 10 && mul.GetZCoordinate() == 10, true));

        std::cout << "POINT3D test : multiply 3D point by a scalar" << std::endl;
    }

    {
        POINT3D div = DividePointByAScalar(a, 0.5000);

        assert(COMPARE_DOUBLE::IS_EQUAL(div.GetXCoordinate() == 4 && div.GetYCoordinate() == 4 && div.GetZCoordinate() == 4, true));

        std::cout << "POINT3D test : divide 3D point by a scalar" << std::endl;
    }
}