#include "vectors.h"
#include "iterativeField.h"
#include "charges.h"
#include "constants.h"

#include <iostream>

int main(){ 
   //Vector Tests (Very Basic)
    std::cout << "Testing Vectors... " << std::endl; 
    std::cout << "[STATUS] CREATING NEW VECTOR... Vector(double, double) \n"; 
    Vector v = new Vector(3.0, 4.0); 
    std::cout <<"[STATUS] CREATING NEW VECTOR... Vector(double, double, int)\n"; 
    Vector w = new Vector(5.0,0.927295218, 1);
    std::cout <<"[STATUS] SUBTRACTING VECTORS\n" ;
    Vector sub = v - w; 
    std::cout <<"[INFO]..."<<sub.getX()<<sub.getY()<< sub.getA() << sub.getM(); 
    std::cout<<"\nVector Tests Complete\n"; 
    std::cout<<"Testing Charges..." <<std::endl; 
    
    std::cout<<"[STATUS] CREATING NEW CHARGE... Charge(double)\n" ; 
    Charge * c =  new Charge(1.0); 
    std::cout<<"[STATUS] CREATING NEW CHARGE... Charge(double, double, long double) " << std::endl; 
    Charge * d = new Charge(1.0,1.0, 1.0 ); 
    std::cout<<"[STATUS] CALCULATING FORCES" <<std::endl; 
    std::cout<<"[INFO]: FORCE BETWEEN" << c->fOnCharge(*d, d->getP()- c->getP()).getM() <<std::endl; 
    
    std::cout<<"[STATUS]: UPDATING POSITIONS" << std::endl; 
    
    c->force = Vector(c->fOnCharge(*d, d->getP()- c->getP())); 
    c->update(0.01); 
    
    std::cout << "[INFO] POSITIONS... "<< c->getP().getX() << " " << c->getP().getY() << std::endl; 

    std::cout <<"Charge Test Complete" <<std::endl; 
}
