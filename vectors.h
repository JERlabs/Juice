#ifndef VECTOR_H
#define VECTOR_H


#include "constants.h"
class Vector{
    double mag_x; 
    double mag_y; 
    double angle; 
    void calcNewAngle(); 
    public:  
        Vector(); 
        Vector(Vector * copy); 
        Vector(double magX, double magY); 
        explicit Vector(double magX, double magY, double Angle); 
        explicit Vector(double mag, double Angle, int is_magnitude); 
        
        Vector operator+(Vector v); 
        Vector operator-(Vector v); 
        double getX();
        double getY(); 
        double getA(); 
        double getM(); 
};
#endif
