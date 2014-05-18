#include "iterativeField.h"
/* TODO: 
 * Make an Operating Stack which will hold vector values
 * that correspond to the indexes of clist. So, when updating, 
 * the program can access the new positions. 
 */  
IterativeField::IterativeField(Charge * charges, int Size, int accuracy){ 
    cList = &charges;
    size = Size; 
    instantiate_vectors(); 
}; 

void IterativeField::nextIteration(){
    for(int i= 0; i < size ; i++ ){ 
        if((*(this->cList))[i].getMode() != 0){
          (*(this->cList))[i].force  = this -> getTotalForce(i) ; 
        };
    };
}; 

Vector IterativeField::getTotalForce(int c){ 
    Vector v = Vector(); 
    for(int i = 0; i < size; i++){ 
        if(i == c){ 
        }
        else { 
            v = v +Vector(((*(this->cList))[i]).fOnCharge(((*(this->cList)))[c],
             ((*(this->cList)))[c].getP() - ((*(this->cList)))[i].getP())); 
        }
    }
    return v; 
}
