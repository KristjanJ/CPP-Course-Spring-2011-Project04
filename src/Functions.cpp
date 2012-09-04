#include "Functions.h"

#include <cmath>

bool solve (double a, double b, double c, double& x1, double& x2)
{
    bool result = false;

    if (a != 0)
    {
        double discriminant = pow(b, 2) - (4 * a * c);

        if (discriminant >= 0)
        {
            double dsqrt = sqrt(discriminant);
            x1 = (-b + dsqrt) / (2 * a);
            x2 = (-b - dsqrt) / (2 * a);

            result = true;
        }
    }
    else if (b != 0)
    {
        x1 = x2 = (-c/b);

        result = true;
    }

	return result;
}
