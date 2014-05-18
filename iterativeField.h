#ifndef ITERATVE_H
#define ITERATIVE_H

#include "charges.h"
#include "vectors.h"
#include "constants.h"

class IterativeField{
    Charge ** cList;  
    int size; 
    void instantiate_vectors(); 
    int ** operating_stack; 
    public: 
        IterativeField(Charge charges[], int Size, int accuracy); 
        void nextIteration();  
        Vector getTotalForce(int c); 
}; 

#endif 
