#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>
using std::ostream;

/*!
\brief A two dimensional vector for testing libneljas library.
*/
class Vector2
{
public:
    /*!
    \details Default constructor.
    */
	Vector2();

	/*!
    \details Constructs a vector from given coordinates.
    \param nx X coordinate.
    \param ny Y coordinate.
    */
	Vector2(float nx, float ny);

	/*!
    \details Returns the distance between this vector and another vector.
    \param v Another vector.
    \returns The distance between this vector and another vector.
    */
	float distanceFrom(Vector2 v);

    /*!
    \details X coordinate.
    */
	float x;

    /*!
    \details Y coordinate.
    */
	float y;
};

ostream& operator << (ostream& valja, Vector2 v); /*!< Kirjutab v?ljundvoogu punkti koordinaadid kujul (nx, ny).*/

#endif
