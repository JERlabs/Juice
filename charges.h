#include "constants.h"
#include "vectors.h"
#ifndef CHARGE_H
#define CHARGE_H

/** 
     * Charge provides a comprehensive simulation of charges, defined in couloumbs. 
     * It is the main class which is simulated. 
     * this only provides the functionality, another class is going to provide the graphics. 
     */ 
class Charge{      //A FIXED CHARGE 
    
    protected:
        long double charge; //for accuracy, microcouloumbs
        double pos_x; //!< Holds the X-Coordinate
        double pos_y; //!< Holds the Y-Coordinate
        double mass;  //!< Holds the mass
        int dynamic ; /**< This is the state; either 1 or 0 depending on if its static or dynamic. */
    public: 
        Charge(); 
        Charge(const Charge& c);
        Charge(double pos_X, double pos_Y, long double charge) ; 
        Charge(double pos_X, double pos_Y);
        Charge (double Sharge); 
        Charge(double pos_X, double pos_Y, long double Sharge, double mass);  
        Vector fAtPoint(Vector relLocation); 
        double fAtPoint(double distance); 

        Vector fOnCharge(Charge c); /*This gives the \
                                                       magnitude and angle \
                                                       of the force on charge.*/ 
        long double fOnCharge(Charge c, double distance);  //Just Magnitude 
        static long double conv_to_uc(Charge c); 
        static long double conv_to_c(Charge c); 
        Vector getP();  
        long double getC();
        void changeMode(); 
        int getMode();
        void update(double timelapse); 
        Vector force; /**< Holds the temporary force and is used by void update(double) */ 
        void setMass(double m);
        double getMass();  
};

#endif
