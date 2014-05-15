#include "constants.h"
#include "vectors.h"
#ifndef CHARGE_H
#define CHARGE_H


class Charge{      //A FIXED CHARGE 
    long double charge; //for accuracy, microcouloumbs
    double pos_x; 
    double pos_y;
    public: 
        Charge(); 
        Charge(const Charge& c);
        Charge(double pos_X, double pos_Y, long double charge) ; 
        Charge(double pos_X, double pos_Y);
        Charge (double Sharge); 
 
        Vector fAtPoint(Vector relLocation); 
        double fAtPoint(double distance); 

        Vector fOnCharge(Charge c, Vector relPosition); /*This gives the \
                                                       magnitude and angle \
                                                       of the force on charge.*/ 
        long double fOnCharge(Charge c, double distance);  //Just Magnitude 
        static long double conv_to_uc(Charge c); 
        static long double conv_to_c(Charge c); 
        Vector getP();  
        long double getC(); 
};

#endif
