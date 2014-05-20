#include "vectors.h"
#include <cmath>
#include "constants.h"
/** Basic Vector, holder. 
 *  Empty constructor, idk why this would be used at all 
 */ 
Vector::Vector(): 
    mag_x(0.0), 
    mag_y(0.0), 
    angle(0.0) {}; 
/** Copy Constructor.
 *  All Attributes are transferred over. Isn't the most efficient, but works. '
 */
Vector::Vector(Vector * copy /**< Vector to get valuse from. */ ): 
    mag_x(copy->mag_x), 
    mag_y(copy->mag_y), 
    angle(copy->angle) {}; 

/** Cartesian Constructor
 * cartesian constructor; given an X mangitude and Y magnitude, this creates a vector with those magnitudes.
 * It will not instantiate total magnitudes, but will instantiate the angle of the vector. 
 * A raw magnitude is available. 
 */ 
Vector::Vector(double magX /**< The X Magnitude */ , double magY /**< The Y magnitude*/): 
    mag_x(magX), 
    mag_y(magY) {
    
    angle = magY == 0 ? 0 : atan(magY/ magX); 
}; 
/** Full construcotr. 
 * This has no advantage over the privous construcotr, Vector(double, double). 
 * There is no reason why you shoould use this as opposed to the other one, the other one is easier. 
 */ 
Vector::Vector(double magX /**< X magnitude */ , double magY /**< Y mangitude */ , double Angle /**< Angle. Please, don't use this. */ : 
    mag_x(magX), 
    mag_y(magY), 
    angle(Angle) { 

};
/** Radian Construcotr.  
 * Constructs Vector as a Radian. Magnitude is the total magnitude of the Vector, and the angle is given in Radians. 
 * The third variable doesn't do ANYTHING yet, butwill eventually allow for more complicated codes, such as 1 = radian constructor,
 * 2 = x_mag given + angle, 3 = y_mag given + angle. 
 * But not supported yet. 
 * Use 1 or 0 for now. 
 */ 
Vector::Vector(double mag /**< Total magnitude of the vector. */ , double Angle /**< Angle, in Radians, of the vector. */ , int is_magnitude /**indicator code. */ ): 
    angle(Angle)
    {
    if(angle == 0){
        mag_x = mag;
        mag_y = 0; 
    }
    else{
        mag_x = mag * cos(angle); 
        mag_y = mag * sin(angle); 
    }
};
/** updates the angle of the vecotr. 
 * this is an internal function. 
 */ 
void Vector::calcNewAngle(){
    if(this->mag_y == 0){
        this-> angle = 0; 
    }
    else{ 
        this-> angle =atan(mag_y/ mag_x); 
    }
};

/** Addition for Vectors
 * simply adds the x and y values of the vectors, so its relatively efficient. 
 */ 
Vector Vector::operator+(Vector v){ 
    Vector w(this -> mag_x + v.mag_x , this-> mag_y + v.mag_y);  
    return w;  
};

/** Vector Subtraction 
 * Subtracts the x and y magnitudes. 
 */ 
Vector Vector::operator-(Vector v){ 
    Vector w(this -> mag_x - v.mag_x, this-> mag_y - v.mag_y);
    return w; 
};

/** access function for x magnitude */ 
double Vector::getX(){
    return this->mag_x; 
}; 
/** access function for y magnitude */ 
double Vector::getY(){ 
    return this->mag_y; 
}; 
/** access function for angle, in radians */ 
double Vector::getA(){ 
    this->calcNewAngle(); 
    return this-> angle; 
}
/** access function for magnitude, ad a double */ 
double Vector::getM(){
    return sqrt(this->mag_x * this->mag_x + this-> mag_y * this-> mag_y); 
}
