#pragma once
#include "utility.hpp"

class POINT3D
{
private:
    char PointName;
    double x_coordinate;
    double y_coordinate;
    double z_coordinate;

public:
    POINT3D();
    POINT3D(char PointName);
    POINT3D(double x_coordinate, double y_coordinate, double z_coordinate);
    POINT3D(char PointName, double x_coordinate, double y_coordinate, double z_coordinate);
    POINT3D(const POINT3D &other);

    ~POINT3D();

    inline char GetPointName() const { return this->PointName; }
    inline double GetXCoordinate() const { return this->x_coordinate; }
    inline double GetYCoordinate() const { return this->y_coordinate; }
    inline double GetZCoordinate() const { return this->z_coordinate; }

    inline void SetPointName(char name) { this->PointName = name; }
    inline void SetXCoordinate(double x_coordinate) { this->x_coordinate = x_coordinate; }
    inline void SetYCoordinate(double y_coordinate) { this->y_coordinate = y_coordinate; }
    inline void SetZCoordinate(double z_coordinate) { this->z_coordinate = z_coordinate; }

    inline void PrintPoint() const;

    double GetDistanceFromOrigin() const;
    POINT3D normalized() const;
};

POINT3D::POINT3D() : PointName('A'), x_coordinate(0.0000), y_coordinate(0.0000), z_coordinate(0.0000) {}

POINT3D::POINT3D(char PointName) : PointName(PointName), x_coordinate(0.0000), y_coordinate(0.0000), z_coordinate(0.0000) {}

POINT3D::POINT3D(double x_coordinate, double y_coordinate, double z_coordinate) : PointName('A'), x_coordinate(x_coordinate), y_coordinate(y_coordinate), z_coordinate(z_coordinate) {}

POINT3D::POINT3D(char PointName, double x_coordinate, double y_coordinate, double z_coordinate) : PointName(PointName), x_coordinate(x_coordinate), y_coordinate(y_coordinate), z_coordinate(z_coordinate) {}

POINT3D::POINT3D(const POINT3D &other) = default;

POINT3D::~POINT3D() {}

void POINT3D::PrintPoint() const
{
    std::cout << std::fixed << std::setprecision(4) << std::showpos;
    std::cout << std::endl
              << std::endl;
    std::cout << this->PointName << "(" << this->x_coordinate << ", " << this->y_coordinate << ", " << this->z_coordinate << ")" << std::endl;

    std::cout << "[PointName : " << this->PointName << ", x = " << this->x_coordinate << ", y = " << this->y_coordinate << ", z = " << this->z_coordinate << "]" << std::endl
              << std::endl;
}

double POINT3D::GetDistanceFromOrigin() const
{
    return std::sqrt(x_coordinate * x_coordinate + y_coordinate * y_coordinate + z_coordinate * z_coordinate);
}

POINT3D POINT3D::normalized() const
{
    double magnitude = this->GetDistanceFromOrigin();

    if (COMPARE_DOUBLE::IS_ZERO(magnitude))
    {
        return POINT3D(this->PointName, 0.0000, 0.0000, 0.0000);
    }

    return POINT3D(PointName, (x_coordinate / magnitude), (y_coordinate / magnitude), (z_coordinate / magnitude));
}
