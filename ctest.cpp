#include "constants.h"
#include <iostream>
#include "charges.h"
#include "vectors.h"

int main(int argc, char * argv[]){ 
    Charge c = Charge(1.0); 
    Charge b = Charge(1.0, 1.0, 1.0); 

    long double f  = c.fOnCharge(b, b.getP()- c.getP()).getM(); 
    std::cout << f << std::endl; 
}
