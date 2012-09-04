#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/*!
\file Functions.h
\brief This header file contains some functions.
*/

/*!
\details Swaps two values.
\param a A reference to value 1.
\param b A reference to value 2.
*/
template <class T>
void swap_ref (T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

/*!
\details Swaps two values.
\param a A pointer to value 1.
\param b A pointer to value 2.
*/
template <class T>
void swap_ptr (T* a, T* b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

/*!
\details Solves a quadratic equation that has a format of ax^2 + bx + c = 0.
\param a a.
\param b b.
\param c c.
\param x1 First solution.
\param x2 Second solution.
\returns true if the equation was solved, false otherwize.
*/
bool solve (double a, double b, double c, double& x1, double& x2);

#endif // FUNCTIONS_H_INCLUDED
