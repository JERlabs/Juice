#include "Point.h"
#include <cmath>

/** Vector constructor
 * Basically puts all values in :P
 */
Point::Point(Vector v): Vector(v), pos_x(v.getX()), pos_y(v.getY()), angle(v.getA()), scale(v.getM()){

};
//
// some text
// some more text
/** Double, Double constructor
 * Should initiate everything, i think
 */
Point::Point(double x, double y): Vector(x,y), pos_x(x), pos_y(y){
	this -> angle = this->pos_y == 0 ? 0 : atan(this-> pos_y / this -> pos_x);
	this -> scale = this -> getM(); 
}
