#include "iterativeField.h"
/** Creates the Iterative Field. 
 * There is only meant to be one of these objects at ANY TIME. 
 * Instantiates the chargesList (cList) and the size of the list (for convience)
 */ 
IterativeField::IterativeField(Charge * charges /**< list of all charges */ , int Size /**< number of all charges */  int accuracy /**< timelapse per frame */){ 
    cList = &charges;
    size = Size; 
}; 

/** Calculates the next iteration of all values. 
 *  Given that the iterative field has been constructed, this function calculates the next set of values. 
 *  It iterates through all the dynamic charges and gets the total force, and sets it in the force section. 
 *  It then runs an update for all forces.
 *  As of 5/19/2014, it does not provide any error handling, so be careful! 
 */ 
void IterativeField::nextIteration(){
    for(int i= 0; i < size ; i++ ){ 
        if((*(this->cList))[i].getMode() != 0){
          (*(this->cList))[i].force  = this -> getTotalForce(i) ; 
        };
    };
}; 
/** Calculates the total force a charge
 *  It uses the parameter as a base, and calculates total force based on the parameter. 
 *  It uses the fOnCharge function to calculate the force. 
 *  This does not provide any error handling as of 5/19/2014
 */ 
Vector IterativeField::getTotalForce(int c /**< The index of the charge in cList you want the total force of. */){ 
    Vector v = Vector(); 
    for(int i = 0; i < size; i++){ 
        if(i != c){
            v = v + (*(this -> cList))[i].fOnCharge((*(this->cList))[c]); 
        }
    }
    return v; 
}
