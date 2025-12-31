#include "utility.hpp"
#pragma once

class POINT2D
{
private:
    char PointName;
    double x_coordinate;
    double y_coordinate;

public:
    POINT2D();
    POINT2D(char PointName);
    POINT2D(double x_coordinate, double y_coordinate);
    POINT2D(char PointName, double x_coordinate, double y_coordinate);
    POINT2D(const POINT2D &other);

    ~POINT2D();

    inline  char GetPointName() const { return this->PointName; }
    inline double GetXCoordinate() const { return this->x_coordinate; }
    inline double GetYCoordinate() const { return this->y_coordinate; }

    inline void SetPointName(char PointName) { this->PointName = PointName; }
    inline void SetXCoordinate(double x_coordinate) { this->x_coordinate = x_coordinate; }
    inline void SetYCoordinate(double y_coordinate) { this->y_coordinate = y_coordinate; }

    inline void PrintPoint() const;

    double GetDistanceFromOrigin() const;
    POINT2D normalize() const;
};

POINT2D::POINT2D() : PointName('A'), x_coordinate(0.0000), y_coordinate(0.0000) {}

POINT2D::POINT2D(char PointName) : PointName(PointName), x_coordinate(0.0000), y_coordinate(0.0000) {}

POINT2D::POINT2D(double x_coordinate, double y_coordinate) : PointName('A'), x_coordinate(x_coordinate), y_coordinate(y_coordinate) {}

POINT2D::POINT2D(char PointName, double x_coordinate, double y_coordinate) : PointName(PointName), x_coordinate(x_coordinate), y_coordinate(y_coordinate) {}

POINT2D::POINT2D(const POINT2D &other) = default;

POINT2D::~POINT2D() {}

inline void POINT2D::PrintPoint() const
{
    std::cout << std::fixed << std::setprecision(4) << std::showpos;
    std::cout << std::endl
              << std::endl;
    std::cout << this->PointName << "(" << this->x_coordinate << ", " << this->y_coordinate << ")" << std::endl;

    std::cout << "[PointName : " << this->PointName << ", x = " << this->x_coordinate << ", y = " << this->y_coordinate << "]" << std::endl
              << std::endl;
}

double POINT2D::GetDistanceFromOrigin() const
{
    double distance = std::sqrt((this->x_coordinate * this->x_coordinate) + (this->GetYCoordinate() * this->GetYCoordinate()));
    return distance;
}

POINT2D POINT2D::normalize() const
{
    double magnitude = std::sqrt((this->x_coordinate * this->x_coordinate) + (this->y_coordinate * this->y_coordinate));

    if (COMPARE_DOUBLE::IS_ZERO(magnitude))
    {
        return POINT2D(PointName, NAN, NAN);
    }

    return POINT2D(PointName, (this->x_coordinate / magnitude), (this->y_coordinate / magnitude));
}
