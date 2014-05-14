#include "vectors.h"

#include <iostream>
int main(int argc, char * argv[]){
    Vector v = Vector(1.0, 1.0); 
    Vector w = v; 
    Vector c = v + w; 
    std::cout << c.getX() <<std::endl;
    std::cout << c.getY() <<std::endl;
}
