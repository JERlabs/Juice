#ifndef POINT_H
#define POINT_H

#include "vectors.h"
/** DON'T use this class as a vector.
 * Please. This is meant for a static point.
 * That is literally the only way this makes sense.
 * There are a LOT of similarities, but when you think about it,
 * YOU would rather have a dedicated point than using vectors.
 * Stuff could get a LITTLE confusing otherwise.
 */
class Point: public Vector{
	double pos_x; /**< X-Position */
	double pos_y; /**< Y-Position */

	double angle; /**< Radian angle*/
	double scale; /**< Mag when using Polar coordinates*/

	public:
		Point(Vector v);
		Point(double x, double y);
		Point(const Point& p); 

		Point operator+(Point p);
		Point operator-(Point p);
		Point operator*(Point p);
		Point operator/(Point p);
		void operator+=(Point p);
		void operator-=(Point p);
		void operator*=(Point p);
		void operator/=(Point p);

		double getDistBetween(Point p);
		Vector getVectBetween(Point p); //This makes sense. You find a vector that points from point a to point b.

		//Access functions
		double getXPosition();
		double getYPosition();
		double getPolarAngle();
		double getPolarMagnitude();

};

#endif
