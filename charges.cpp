#include "charges.h"

Charge::Charge(): 
    charge(0.0), 
    pos_x(0.0), 
    pos_y(0.0),
    mass(0.0), 
    dynamic(0) {}; 

Charge::Charge(const Charge& c):
    charge(c.charge), 
    pos_x(c.pos_x), 
    dynamic(0), pos_y(c.pos_y), 
    mass(c.mass)
{}; 

Charge::Charge(double pos_X, double pos_Y, long double Sharge, double Mass): 
    charge(Sharge), 
    pos_x(pos_X), 
     dynamic(0),pos_y(pos_Y),
     mass(Mass) {
}; 
Charge::Charge(double pos_X, double pos_Y, long double Sharge ): 
    charge(Sharge), 
    pos_x(pos_X), 
     dynamic(0),pos_y(pos_Y),
     mass(0.0) {
}; 
Charge::Charge(double pos_X, double pos_Y):
    charge(0.0), 
    pos_x(pos_X),  dynamic(0),
    pos_y(pos_Y), 
    mass(0.0) 
    {

};

Charge::Charge(double Sharge): mass(0.0), dynamic(0),pos_x(0.0), pos_y(0.0), charge(Sharge) {}; 

Vector Charge::fAtPoint(Vector relLocation){
    double magnitude = relLocation.getM(); 
    double strength = K * this->charge /(magnitude * magnitude); 
    return Vector(strength, relLocation.getA(), 1 ); 
};

double Charge::fAtPoint(double distance){
    return K * (this-> charge) / (distance * distance); 
};

Vector Charge::fOnCharge(Charge c){
    Vector r = (c.getP() - this -> getP() ); 
    double f = K * (c.charge) * (this -> charge) / 
        (r.getM()* r.getM()); 
    return Vector(f, r.getA(), 1 ); 
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

void Charge::changeMode(){ 
    (this->dynamic )= (this->dynamic == 0) ? 1 : 0; 
}

int Charge::getMode(){ 
    return this->dynamic; 
}

void Charge::update(double timelapse ){ 
    if(!( this -> dynamic > 0)){
    }else{
        this-> pos_x += ((this->force).getX() / mass * timelapse)/2 ; 
        this-> pos_y += ((this->force).getY() / mass * timelapse)/2 ; 
    }
}
 
void Charge::setMass(double m) { 
    this -> mass = m; 
}

double Charge::getMass() { 
    return this->mass;  
}
