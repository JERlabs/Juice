#include "charges.h"

Charge::Charge(): 
    charge(0.0), 
    pos_x(0.0), 
    pos_y(0.0) {}; 

Charge::Charge(const Charge& c):
    charge(c.charge), 
    pos_x(c.pos_x), 
    pos_y(c.pos_y) 
{}; 

Charge::Charge(double pos_X, double pos_Y, long double Sharge): 
    charge(Sharge), 
    pos_x(pos_X), 
    pos_y(pos_Y) {
}; 

Charge::Charge(double pos_X, double pos_Y):
    charge(0.0), 
    pos_x(pos_X), 
    pos_y(pos_Y) 
    {

};

Charge::Charge(double Sharge): pos_x(0.0), pos_y(0.0), charge(Sharge) {}; 

Vector Charge::fAtPoint(Vector relLocation){
    double magnitude = relLocation.getM(); 
    double strength = K * this->charge /(magnitude * magnitude); 
    return Vector(strength, relLocation.getA(), 1 ); 
};

double Charge::fAtPoint(double distance){
    return K * (this-> charge) / (distance * distance); 
};

Vector Charge::fOnCharge(Charge c, Vector relPosition){ 
    double f = K * (c.charge) * (this -> charge) / 
        (relPosition.getM()* relPosition.getM()); 
    double angle = relPosition.getA(); 
    return Vector(f, angle, 1 ); 
}; 

long double Charge::fOnCharge(Charge c, double distance){ 
    return K * (this->charge) * (c.charge) / (distance * distance); 
}; 

static long double conv_to_uc(Charge c){
    return c.getC() * UC_IN_C;
}; 

static long double conv_to_c(Charge c){
    return c.getC()  / UC_IN_C; 
}; 
Vector Charge::getP(){ 
    Vector v = Vector(this -> pos_x, this -> pos_y); 
    return v; 
}

long double Charge::getC() {
    return this->charge; 
};


