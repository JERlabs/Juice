#include "charges.h"
/** An empty constructor. 
 *  An empty constructor. Don't know why you would use this
 *  It initializes ALL values as 0. So, if you wanted a placeholder, 
 *  this would work fabulously. 
 */ 
Charge::Charge(): 
    charge(0.0), 
    pos_x(0.0), 
    pos_y(0.0),
    mass(0.0), 
    dynamic(0) {}; 
/** A copy Constructor.  
 *  All values EXCEPT THE FORCE are copied over. 
 */ 
Charge::Charge(const Charge& c /**< Charge to copy over */):
    charge(c.charge), 
    pos_x(c.pos_x), 
    dynamic(0), pos_y(c.pos_y), 
    mass(c.mass)
{}; 
/** Complete and recommended construcotr. 
 * Complete constructor which instantiates all private values.
 * Defaults state to dynamic  
 */ 
Charge::Charge(double pos_X /**< x location of the charge */ , double pos_Y/**< y location of the charge */ , long double Sharge/**< actual charge of the charge */ , double Mass/**< mass of the charge (only needed if you are working with a dynamic charge) */ ): 
    charge(Sharge), 
    pos_x(pos_X), 
     dynamic(1),pos_y(pos_Y),
     mass(Mass) {
};
/** Constructor for static objects, no mass required. 
 *  This is useful if you just want a held-in-place charge. 
 */ 
Charge::Charge(double pos_X/**< x position of the charge */ , double pos_Y /**< y position fo the charge */ , long double Sharge /**< actual charge of the charge */ ): 
    charge(Sharge), 
    pos_x(pos_X), 
     dynamic(0),pos_y(pos_Y),
     mass(0.0) {
}; 
/** A placeholding charge. 
 *  placeholding charge. No Valid use imaginable.
 */ 
Charge::Charge(double pos_X /**< x position of the charge */ , double pos_Y/**< y position of the charge */ ):
    charge(0.0), 
    pos_x(pos_X),  dynamic(0),
    pos_y(pos_Y), 
    mass(0.0) 
    {

};
/** Nothing except for a charge.  
 * just a charge, no position, no mass. Used for conversions most likely.  
 */ 
Charge::Charge(double Sharge /**< Charge of the particle */ ): mass(0.0), dynamic(0),pos_x(0.0), pos_y(0.0), charge(Sharge) {}; 

/** Gives Vector of field strength at relative location. 
 * returns a Vector, with the force at a relative location to this one. 
 * The relative location is given by the reLocation parameter. 
 */ 
Vector Charge::fAtPoint(Vector relLocation /**< The location of the point relative to the charge. */){
    double magnitude = relLocation.getM(); 
    double strength = K * this->charge /(magnitude * magnitude); 
    return Vector(strength, relLocation.getA(), 1 ); 
};
/** Returns field strength at a distance away. 
 * Returns the field strength at a point a certain distance away. 
 */ 
double Charge::fAtPoint(double distance /**< The net distance of the charge. If the Vector relLocation for this is 3,4, the distance should be 5. */){
    return K * (this-> charge) / (distance * distance); 
};
/** Force felt by Charge c because of this charge. 
 * Returns the force exerted by this charge on charge c. Perhaps the most important function in this program. 
 */ 

Vector Charge::fOnCharge(Charge c /** Charge to determine force on. This charge MUST have a position. this is not error handled yet. */){
    Vector r = (c.getP() - this -> getP() ); 
    double f = K * (c.charge) * (this -> charge) / 
        (r.getM()* r.getM()); 
    return Vector(f, r.getA(), 1 ); 
}; 

/** 
 * Same as above, but more retarded. very redundant. 
 * This is used in the off-chance that the charge doesn't have a location or the location is set to (0,0). 
 * This could be used in hypotheticals, in the calculator. 
 */ 

long double Charge::fOnCharge(Charge c /**< Same as the other fOnCharge */ , double distance /** Give this for less work, and to get a double instead of vector as return value */ ){ 
    return K * (this->charge) * (c.charge) / (distance * distance); 
}; 
/** 
 *  convert from couloumbs to microcouloumbs. 
 */ 

static long double conv_to_uc(Charge c /**< The charge you want to be converted. Should be instantiated by Charge(double) */ ){
    return c.getC() * UC_IN_C;
}; 
/** 
 * convert from microcouloumbs to coulombs 
 */ 
static long double conv_to_c(Charge c /**< The charge you want converted. Should be instantiated by Charge(double) */ ){
    return c.getC()  / UC_IN_C; 
}; 

/** 
 * get the position of the charge
 */ 
Vector Charge::getP(){ 
    Vector v = Vector(this -> pos_x, this -> pos_y); 
    return v; 
}
/** 
 * get the charge itself 
 */ 
long double Charge::getC() {
    return this->charge; 
};

/** 
 * toggle from dynamic to static mode 
 */ 
void Charge::changeMode(){ 
    (this->dynamic )= (this->dynamic == 0) ? 1 : 0; 
}

/** 
 * determine the mode 
 */ 
int Charge::getMode(){ 
    return this->dynamic; 
}

/** 
 * update the position of the charge IF mode is dynamic. 
 * this is very important as well. 
 * The paramater timelapse gives the time over which the force acts
 * uses the formula s = .5at^2, a = f/m 
 */
void Charge::update(double timelapse /**< The timelapse you want to update teh charge over. Larger timelapse = less accuracy. */  ){ 
    if(this -> getMode() == 0){
    }else{
        this-> pos_x += ((this->force).getX() / mass * timelapse*timelapse)/2 ; 
        this-> pos_y += ((this->force).getY() / mass * timelapse*timelapse)/2 ; 
    }
}
/** 
 * set the mass 
 */ 
void Charge::setMass(double m /**< The new mass of the charge */ ) { 
    this -> mass = m; 
}
/** 
 * get the mass 
 */ 
double Charge::getMass() { 
    return this->mass;  
}
