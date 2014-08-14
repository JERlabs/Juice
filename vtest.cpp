#include "vectors.h"
#include <string> 
#include <iostream>
using std::cout; 
using std::endl; 
using std::string; 

#define PI 3.141592
void status(string a){ 
    cout << "[STATUS]\t" << a << endl; 
};
void info(string a = ""){ 
    cout << "[ INFO ]\t" << a << '\t'; 
};
void debug(string a){ 
    cout << "[DEBUG ]\t" << a << endl; 
};

int main(int argc, char * argv[]){
	//Testing Vector Creation 
	status("Testing Vector Creation"); 
	status("Testing Constructor \t Vector()"); 
	Vector * a = new Vector(); 
	info("blank vector information: Position "); 
	cout << "X position: " << a -> getX() << "\t Y Position " << a -> getY() << endl; 
	info("blank vector information: Angle & Magnitude "); 
	cout << "Angle: " << a -> getA() << "\t Magnitude" << a -> getM() << endl; 

	status("Testing Constructor \t Vector(double, double)"); 
    Vector * v = new Vector(1.0, 1.0); 

    info("Vector(double, double) vector information: Position "); 
	cout << "X position: " << v -> getX() << "\t Y Position " << v -> getY() << endl; 
	info("Vector(double, double) information: Angle & Magnitude "); 
	cout << "Angle: " << v -> getA() << "\t Magnitude" << v -> getM() << endl; 
    
    status("Testing Constructor \t Vector(double, double, int)"); 
    Vector * w = new Vector(1, PI/4, 1); 

    info("Vector(double, double,int) vector information: Position "); 
	cout << "X position: " << w -> getX() << "\t Y Position " << w -> getY() << endl; 
	info("Vector(double, double) information: Angle & Magnitude "); 
	cout << "Angle: " << w -> getA() << "\t Magnitude" << w -> getM() << endl;

/*    Vector w = v; 
    Vector c = v + w; 
    std::cout << c.getX() <<std::endl;
    std::cout << c.getY() <<std::endl;
*/ 
}
