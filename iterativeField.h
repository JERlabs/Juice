#ifndef ITERATVE_H
#define ITERATIVE_H

#include "charges.h"
#include "vectors.h"
#include "constants.h"

class IterativeField{
    Charge ** cList;  /**< A double pointer to a list of charges. This means its actually a Charge * cList[]. This is very important, as it will hold ALL the charges. */ 
    int size; /**< the size of cList, for convinience */
    double tlapse; /**< provides the timelapse/ accuracy for each frame. */ 
    public: 
        IterativeField(Charge charges[], int Size, int accuracy); 
        void nextIteration();  
        Vector getTotalForce(int c); 
}; 

#endif 
