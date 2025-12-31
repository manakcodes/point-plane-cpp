#pragma once
#include "utility.hpp"
#include "point2d.hpp"

inline bool ArePointsEqual(const POINT2D &a, const POINT2D &b);
inline bool ArePointsNotEqual(const POINT2D &a, const POINT2D &b);
double GetDistance(const POINT2D &a, const POINT2D &b);
POINT2D AddPoint(const POINT2D &a, const POINT2D &b);
POINT2D SubtractPoint(const POINT2D &a, const POINT2D &b);
POINT2D MultiplyPointByAConstant(const POINT2D &a, double k);
POINT2D DividePointByAConstant(const POINT2D &a, double k);
double DotProduct(const POINT2D &a, const POINT2D &b);
inline double CrossProduct(const POINT2D &a, const POINT2D &b);
inline POINT2D DividePointInRatio(const POINT2D &a, const POINT2D &b, const double m, const double n);
inline POINT2D DividePointInHalf(const POINT2D &a, const POINT2D &b);
inline POINT2D GetMidPoint(const POINT2D &a, const POINT2D &b);
inline double GetSlope(const POINT2D &a, const POINT2D &b);
inline std::string GetLineEquation(POINT2D &a, POINT2D &b);
inline double GetAreaOfTriangle(const POINT2D &a, const POINT2D &b, const POINT2D &c);
inline bool ArePointsCollinear(const POINT2D &a, const POINT2D &b, const POINT2D &c);

double GetDistance(const POINT2D &a, const POINT2D &b)
{
    double dx = b.GetXCoordinate() - a.GetXCoordinate();
    double dy = b.GetYCoordinate() - a.GetYCoordinate();
    double distance = std::sqrt((dx * dx) + (dy * dy));
    return distance;
}

inline bool ArePointsEqual(const POINT2D &a, const POINT2D &b)
{
    return (COMPARE_DOUBLE::IS_EQUAL(a.GetXCoordinate(), b.GetXCoordinate()) &&
            COMPARE_DOUBLE::IS_EQUAL(a.GetYCoordinate(), b.GetYCoordinate()));
}

inline bool ArePointsNotEqual(const POINT2D &a, const POINT2D &b)
{
    return (!COMPARE_DOUBLE::IS_EQUAL(a.GetXCoordinate(), b.GetXCoordinate()) &&
            !COMPARE_DOUBLE::IS_EQUAL(a.GetYCoordinate(), b.GetYCoordinate()));
}

inline POINT2D AddPoint(const POINT2D &a, const POINT2D &b)
{
    return POINT2D(a.GetXCoordinate() + b.GetXCoordinate(), a.GetYCoordinate() + b.GetYCoordinate());
}

inline POINT2D SubtractPoint(const POINT2D &a, const POINT2D &b)
{
    return POINT2D(a.GetXCoordinate() - b.GetXCoordinate(), a.GetYCoordinate() - b.GetYCoordinate());
}

inline POINT2D MultiplyPointByAConstant(const POINT2D &a, const double k)
{
    return POINT2D(a.GetXCoordinate() * k, a.GetYCoordinate() * k);
}

inline POINT2D DividePointByAConstant(const POINT2D &a, const double k)
{
    if (COMPARE_DOUBLE::IS_ZERO(k) || COMPARE_DOUBLE::IS_NAN(k))
    {
        return POINT2D(NAN, NAN);
    }

    return POINT2D(a.GetXCoordinate() / k, a.GetYCoordinate() / k);
}

double DotProduct(const POINT2D &a, const POINT2D &b)
{
    return ((a.GetXCoordinate() * b.GetXCoordinate()) +
            (a.GetYCoordinate() * b.GetYCoordinate()));
}

inline double CrossProduct(const POINT2D &a, const POINT2D &b)
{
    return a.GetXCoordinate() * b.GetYCoordinate() - a.GetYCoordinate() * b.GetXCoordinate();
}

inline double GetAreaOfTriangle(const POINT2D &a, const POINT2D &b, const POINT2D &c)
{
    double area =
        a.GetXCoordinate() * (b.GetYCoordinate() - c.GetYCoordinate()) +
        b.GetXCoordinate() * (c.GetYCoordinate() - a.GetYCoordinate()) +
        c.GetXCoordinate() * (a.GetYCoordinate() - b.GetYCoordinate());

    return std::abs(area) * 0.5;
}

inline bool ArePointsCollinear(const POINT2D &A, const POINT2D &B, const POINT2D &C)
{
    return COMPARE_DOUBLE::IS_ZERO(GetAreaOfTriangle(A, B, C));
}

inline POINT2D DividePointInRatio(const POINT2D &a, const POINT2D &b, const double m, const double n)
{
    if (COMPARE_DOUBLE::IS_ZERO(m + n))
    {
        return POINT2D(NAN, NAN);
    }
    double x = (n * a.GetXCoordinate() + m * b.GetXCoordinate()) / (m + n);
    double y = (n * a.GetYCoordinate() + m * b.GetYCoordinate()) / (m + n);
    return POINT2D('/', x, y);
}

POINT2D DividePointInHalf(const POINT2D &a, const POINT2D &b)
{
    return DividePointInRatio(a, b, 1.0000, 2.0000);
}

inline POINT2D GetMidPoint(const POINT2D &a, const POINT2D &b)
{
    return POINT2D((a.GetXCoordinate() + b.GetXCoordinate()) / 2.0000, (a.GetYCoordinate() + b.GetYCoordinate()) / 2.0000);
}

double GetSlope(const POINT2D &a, const POINT2D &b)
{
    double dx = b.GetXCoordinate() - a.GetXCoordinate();
    double dy = b.GetYCoordinate() - a.GetYCoordinate();

    if (COMPARE_DOUBLE::IS_ZERO(dx))
    {
        return NAN;
    }

    return (dy / dx);
}

inline std::string GetLineEquation(const POINT2D &a, const POINT2D &b)
{
    double dx = b.GetXCoordinate() - a.GetXCoordinate();
    double dy = b.GetYCoordinate() - a.GetYCoordinate();

    if (COMPARE_DOUBLE::IS_ZERO(dx))
    {
        return "x = " + std::to_string(a.GetXCoordinate()); // vertical line
    }

    double m = dy / dx;
    double c = a.GetYCoordinate() - (m * a.GetXCoordinate());

    std::ostringstream oss;
    oss << "y = " << m << " x + " << c;
    return oss.str();
}