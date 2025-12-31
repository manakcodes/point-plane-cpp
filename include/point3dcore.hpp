#pragma once
#include "utility.hpp"
#include "point3d.hpp"

inline bool ArePointsEqual(const POINT3D &a, const POINT3D &b);
inline bool ArePointsNotEqual(const POINT3D &a, const POINT3D &b);
double GetDistance(const POINT3D &a, const POINT3D &b);
POINT3D AddPoint(const POINT3D &a, const POINT3D &b);
POINT3D SubtractPoint(const POINT3D &a, const POINT3D &b);
POINT3D MultiplyPointByAScalar(const POINT3D &a, double scalar);
POINT3D DividePointByAScalar(const POINT3D &a, double scalar);
double DotProduct(const POINT3D &a, const POINT3D &b);
POINT3D CrossProduct(const POINT3D &a, const POINT3D &b);
bool ArePointsCollinear(const POINT3D &a, const POINT3D &b, const POINT3D &c);
double GetAreaOfTriangle(const POINT3D &a, const POINT3D &b, const POINT3D &c);

POINT3D AddPoint(const POINT3D &a, const POINT3D &b)
{
    return POINT3D(
        a.GetXCoordinate() + b.GetXCoordinate(),
        a.GetYCoordinate() + b.GetYCoordinate(),
        a.GetZCoordinate() + b.GetZCoordinate());
}

POINT3D SubtractPoint(const POINT3D &a, const POINT3D &b)
{
    return POINT3D(
        a.GetXCoordinate() - b.GetXCoordinate(),
        a.GetYCoordinate() - b.GetYCoordinate(),
        a.GetZCoordinate() - b.GetZCoordinate());
}

POINT3D MultiplyPointByAScalar(const POINT3D &a, double scalar)
{
    if (COMPARE_DOUBLE::IS_NAN(scalar))
    {
        return POINT3D(NAN, NAN, NAN);
    }

    return POINT3D(
        a.GetXCoordinate() * scalar,
        a.GetYCoordinate() * scalar,
        a.GetZCoordinate() * scalar);
}

POINT3D DividePointByAScalar(const POINT3D &a, double scalar)
{
    if (COMPARE_DOUBLE::IS_ZERO(scalar) || COMPARE_DOUBLE::IS_NAN(scalar))
    {
        return POINT3D(NAN, NAN, NAN);
    }

    return POINT3D((a.GetXCoordinate() / scalar),
                   (a.GetYCoordinate() / scalar),
                   (a.GetZCoordinate() / scalar));
}

inline bool ArePointsEqual(const POINT3D &a, const POINT3D &b)
{
    return COMPARE_DOUBLE::IS_EQUAL(a.GetXCoordinate(), b.GetXCoordinate()) &&
           COMPARE_DOUBLE::IS_EQUAL(a.GetYCoordinate(), b.GetYCoordinate()) &&
           COMPARE_DOUBLE::IS_EQUAL(a.GetZCoordinate(), b.GetZCoordinate());
}

inline bool ArePointsNotEqual(const POINT3D &a, const POINT3D &b)
{
    return !COMPARE_DOUBLE::IS_EQUAL(a.GetXCoordinate(), b.GetXCoordinate()) &&
           !COMPARE_DOUBLE::IS_EQUAL(a.GetYCoordinate(), b.GetYCoordinate()) &&
           !COMPARE_DOUBLE::IS_EQUAL(a.GetZCoordinate(), b.GetZCoordinate());
}

double GetDistance(const POINT3D &a, const POINT3D &b)
{
    double dx = b.GetXCoordinate() - a.GetXCoordinate();
    double dy = b.GetYCoordinate() - a.GetYCoordinate();
    double dz = b.GetZCoordinate() - a.GetZCoordinate();

    double distance = std::sqrt(dx * dx + dy * dy + dz * dz);
    return distance;
}

double DotProduct(const POINT3D &a, const POINT3D &b)
{
    return a.GetXCoordinate() * b.GetXCoordinate() +
           a.GetYCoordinate() * b.GetYCoordinate() +
           a.GetZCoordinate() * b.GetZCoordinate();
}

POINT3D CrossProduct(const POINT3D &a, const POINT3D &b)
{
    return POINT3D(
        a.GetYCoordinate() * b.GetZCoordinate() - a.GetZCoordinate() * b.GetYCoordinate(),
        a.GetZCoordinate() * b.GetXCoordinate() - a.GetXCoordinate() * b.GetZCoordinate(),
        a.GetXCoordinate() * b.GetYCoordinate() - a.GetYCoordinate() * b.GetXCoordinate());
}

bool ArePointsCollinear(const POINT3D &a, const POINT3D &b, const POINT3D &c)
{
    POINT3D AB = SubtractPoint(b, a);
    POINT3D AC = SubtractPoint(c, a);
    POINT3D cross = CrossProduct(AB, AC);

    return COMPARE_DOUBLE::IS_ZERO(cross.GetXCoordinate()) &&
           COMPARE_DOUBLE::IS_ZERO(cross.GetYCoordinate()) &&
           COMPARE_DOUBLE::IS_ZERO(cross.GetZCoordinate());
}

double GetAreaOfTriangle(const POINT3D &a, const POINT3D &b, const POINT3D &c)
{
    POINT3D AB = POINT3D(b.GetXCoordinate() - a.GetXCoordinate(),
                         b.GetYCoordinate() - a.GetYCoordinate(),
                         b.GetZCoordinate() - a.GetZCoordinate());

    POINT3D AC = POINT3D(c.GetXCoordinate() - a.GetXCoordinate(),
                         c.GetYCoordinate() - a.GetYCoordinate(),
                         c.GetZCoordinate() - a.GetZCoordinate());

    POINT3D CrossProd = CrossProduct(AB, AC);

    return std::abs((0.5 * CrossProd.GetDistanceFromOrigin()));
}
