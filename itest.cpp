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
    std::cout << "\n" << v.getM() << std::endl; 
    std::cout <<"[STATUS] CREATING NEW VECTOR... Vector(double, double, int)\n"; 
    Vector w = new Vector(5.0,0.927295218, 1);
    std::cout <<"[STATUS] SUBTRACTING VECTORS\n" ;
    Vector sub = v - w; 
    std::cout <<"[ INFO ]"<<sub.getX()<<sub.getY()<< sub.getA() << sub.getM(); 
    std::cout<<"\nVector Tests Complete\n"; 
    std::cout<<"Testing Charges..." <<std::endl; 
    
    std::cout<<"[STATUS] CREATING NEW CHARGE... Charge(double)\n" ; 
    Charge * c =  new Charge(1.0); 
    std::cout<<"[STATUS] CREATING NEW CHARGE... Charge(double, double, long double) " << std::endl; 
    Charge * d = new Charge(1.0,1.0, 1.0 ); 
    std::cout <<"[ INFO ] C ORIGINAL POSITION: X" << c -> getP().getX() << " Y " << c->getP().getY() << std::endl; 
    std::cout <<"[ INFO ] D ORIGINAL POSITION: X" << d -> getP().getX() << " Y " << d->getP().getY() << std::endl; 

    std::cout<<"[STATUS] CALCULATING FORCES" <<std::endl; 

    std::cout<<"[ INFO ] FORCE BETWEEN X" << (c->fOnCharge(*d)).getX() << " Y " << (c->fOnCharge(*d)).getY() << std::endl; 
    std::cout<<"[ INFO ] FORCE BETWEEN M" << (c->fOnCharge(*d)).getM() << " A " << (c->fOnCharge(*d)).getA() << std::endl; 
    std::cout<<"[STATUS] UPDATING POSITIONS" << std::endl; 
    c-> changeMode();  
    c-> setMass(1.0); 
    std::cout << "[ INFO ] Mode is: " << c->getMode() << std::endl; 
    c->force =  c->fOnCharge(*d); 
    std::cout <<"[DEBUG ] VALUE OF C->FORCE IS (" << c-> force .getM() << "@" << c->force.getA() << "R" << std::endl; 
    c->update(0.000001); 
    
    std::cout << "[ INFO ] POSITIONS... "<< c->getP().getX() << " " << c->getP().getY() << std::endl; 

    std::cout <<"Charge Test Complete" <<std::endl; 

    //Begin iterative field test... challenging! 
    
    std::cout <<"Testing the Iterative Field... " <<std::endl; 
    
    Charge clist[2] = {*c, *d}; 
    if(c -> getMode() == 0)
        c->changeMode(); 
    if(d -> getMode() == 0)
        d->changeMode(); 
    if(c -> getMass() == 0)
        c -> setMass(1.0); 
    if(d -> getMass() == 0 )
        d -> setMass(1.0); 
    IterativeField * field = new IterativeField(clist, 2, 0.01);
    field->nextIteration(); 
    
    std::cout<< c -> getP().getX() <<" "<< c -> getP().getY() << std::endl; 
    std::cout<< d -> getP().getX() <<" "<< d -> getP().getY() << std::endl; 
    
    field -> nextIteration(); 
    std::cout<< c -> getP().getX() <<" "<< c -> getP().getY() << std::endl; 
    std::cout<< d -> getP().getX() <<" "<< d -> getP().getY() << std::endl; 

}
