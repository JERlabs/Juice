#include "vectors.h"
#include <cmath>
#include "constants.h"
Vector::Vector(): 
    mag_x(0.0), 
    mag_y(0.0), 
    angle(0.0) {}; 

Vector::Vector(Vector * copy): 
    mag_x(copy->mag_x), 
    mag_y(copy->mag_y), 
    angle(copy->angle) {}; 

Vector::Vector(double magX, double magY): 
    mag_x(magX), 
    mag_y(magY) {
    
    angle = magY == 0 ? 0 : atan(magY/ magX); 
}; 

Vector::Vector(double magX, double magY, double Angle): 
    mag_x(magX), 
    mag_y(magY), 
    angle(Angle) { 

};

Vector::Vector(double mag, double Angle, int is_magnitude): 
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

void Vector::calcNewAngle(){
    if(this->mag_y == 0){
        this-> angle = 0; 
    }
    else{ 
        this-> angle =atan(mag_y/ mag_x); 
    }
};

Vector Vector::operator+(Vector v){ 
    Vector w(this -> mag_x + v.mag_x , this-> mag_y + v.mag_y);  
    return w;  
};

Vector Vector::operator-(Vector v){ 
    Vector w(this -> mag_x - v.mag_x, this-> mag_y - v.mag_y);
    return w; 
};

double Vector::getX(){
    return this->mag_x; 
}; 

double Vector::getY(){ 
    return this->mag_y; 
}; 

double Vector::getA(){ 
    return this-> angle; 
}

double Vector::getM(){
    return sqrt(this->mag_x * this->mag_x + this-> mag_y + this-> mag_y); 
}
