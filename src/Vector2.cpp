#include "Vector2.h"
#include <cmath>

using namespace std;

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(float nx, float ny) {
	x = nx;
	y = ny;
}

float Vector2::distanceFrom(Vector2 v) {
    return sqrt( (x - v.x)*(x - v.x) + (y - v.y)*(y - v.y) ); 
}

ostream& operator << (ostream& os, Vector2 v) {
	return os << "(" << v.x << "," << v.y << ")";
}
