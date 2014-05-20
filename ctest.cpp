#include "constants.h"
#include <iostream>
#include "charges.h"
#include "vectors.h"

int main(int argc, char * argv[]){ 
    Charge c = Charge(1.0); 
    Charge b = Charge(1.0, 1.0, 1.0); 

    Vector f  = c.fOnCharge(b); 
    std::cout << f.getM() << std::endl; 
}
