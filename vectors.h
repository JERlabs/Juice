#ifndef VECTOR_H
#define VECTOR_H


#include "constants.h"
/** Class for Vecotor Values
 * This is used for a variety of purposes. 
 * It is used for Points, Forces, magntidudes, etc. 
 * Relatively simple class, 
 * In some ways more like a point, 
 * but implementation should be limited to velocities, forces, and real vectgr values
 * Although this CAN be used as a point, you should use a special point class for point values.
 * Internally, it holds all Vectors as an X and Y magntiude. Also holds an angle, which is just used for calculating radian vectors. 
 * The magnitude is reccalculated whenever called. 
 */ 
class Vector{
    double mag_x; /**< hodls the x magnitude of all vectors */  
    double mag_y; /**< holds the x-magnitude of all vectors.*/ 
    double angle; /**< holds the angle for all vectors. This is semi-redundant. */ 
    void calcNewAngle(); 
    public:  
        Vector(); 
        Vector(Vector * copy); 
        Vector(double magX, double magY); 
        explicit Vector(double mag, double Angle, int is_magnitude); 
        
        Vector operator+(Vector v); 
        Vector operator-(Vector v); 
        double getX();
        double getY(); 
        double getA(); 
        double getM(); 
};
#endif
