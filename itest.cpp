#include "vectors.h"
#include "iterativeField.h"
#include "charges.h"
#include "constants.h"

#include <iostream>
using std::string; 
using std::cout; 
using std::endl; 

void status(string a){ 
    cout << "[STATUS]\t" << a << endl; 
}
void info(string a = ""){ 
    cout << "[ INFO ]\t" << a << '\t'; 
}
void debug(string a){ 
    cout << "[DEBUG ]\t" << a << endl; 
}

int main(){ 
/*   //Vector Tests (Very Basic)
    cout << "Testing Vectors... " << endl; 
    status("CREATING NEW VECTOR... Vector(double, double)"); 
    Vector v = new Vector(3.0, 4.0); 
    cout << "\n" << v.getM() << endl; 
    Vector w = new Vector(5.0,0.927295218, 1);
    status("SUBTRACTING VECTORS"); 
    Vector sub = v - w; 
    info(); 
    cout <<sub.getX()<<sub.getY()<< sub.getA() << sub.getM() << endl; 
    cout<<"\nVector Tests Complete\n"; 
    cout<<"Testing Charges..." <<endl; 
    status("CREATING NEW CHARGE... Charge(double)"); 
    Charge * c =  new Charge(1.0); 
    status("CREATING NEW CHARGE... Charge(double, double, long double)"); 
    
    cout <<  new Charge(1.0,1.0, 1.0 ); 
    cout << endl; 
    Charge * d = new Charge(1.0, 1.0, 1.0); 
    cout << c << endl; 
    info(); 
    cout <<"C ORIGINAL POSITION: X" << c -> getP().getX() << " Y " << c->getP().getY() << endl; 
    cout <<"D ORIGINAL POSITION: X" << d -> getP().getX() << " Y " << d->getP().getY() << endl; 

    status("CALCULATING FORCES"); 
    info(); 
    cout<<"FORCE BETWEEN X" << (c->fOnCharge(*d)).getX() << " Y " << (c->fOnCharge(*d)).getY() << endl; 
    cout<<"FORCE BETWEEN M" << (c->fOnCharge(*d)).getM() << " A " << (c->fOnCharge(*d)).getA() << endl; 
    
    status("UPDATING POSITIONS"); 

    c-> changeMode();  
    c-> setMass(1.0); 
    info(); 
    cout << "Mode is: " << c->getMode() << endl; 
    
    c->force =  c->fOnCharge(*d); 

    cout <<"[DEBUG ] VALUE OF C->FORCE IS (" << c-> force .getM() << "@" << c->force.getA() << "R" << endl; 
    
    c->update(0.001); 
    
    cout << "[ INFO ] POSITIONS... "<< c->getP().getX() << " " << c->getP().getY() << endl; 

    c -> update(0.001); 

    cout << "[ INFO ] POSITIONS... "<< c->getP().getX() << " " << c->getP().getY() << endl; 

    cout <<"Charge Test Complete" <<endl; 
    delete c; 
    delete d; */
    //Begin iterative field test... challenging! 

    Charge * e = new Charge(0.0, 0.0, 1.0, 1.0); 
    Charge * f = new Charge(1.0, 0.0, -1.0, 1.0);
    
    info("Position of charge e");
    cout << (e ->getP()).getX() << "\t" << (e->getP()).getY() <<endl; 
    info("Position of charge f");
    cout << (f ->getP()).getX() << "\t" << (f->getP()).getY() <<endl; 

    info("Charge of Charge e"); 
    cout << e -> getC() << endl; 
    info("Charge of Charge f"); 
    cout << f -> getC() << endl; 

    info("State of Charge e");
    cout << e -> getMode() << endl; 
    info("State of Charge f"); 
    cout << f -> getMode() << endl; 
    //e -> changeMode(); 
   // f -> changeMode(); 
    info("State of Charge e, post-change");
    cout << e -> getMode() << endl; 
    info("State of Charge f, post-change"); 
    cout << f -> getMode() << endl; 
    Charge cList[2] = {*e, *f};     
   
    IterativeField * g = new IterativeField(cList, 2, 0.001); 

    g -> nextIteration(); 
    status("OMG DYING"); 
    e = g->getSpecificCharge(0);
    f = g->getSpecificCharge(1);
    info("State of Charge E, post iter"); 
    cout << e -> getMode() << endl; 
    info("State of Charge F, post iter"); 
    cout << e-> getMode() << endl; 
    info("Position of charge e");
    cout << (e ->getP()).getX() << "\t" << (e->getP()).getY() <<endl; 
    info("Position of charge f");
    cout << (f ->getP()).getX() << "\t" << (f->getP()).getY() <<endl; 

}
