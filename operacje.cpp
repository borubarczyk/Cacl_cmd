#include <math.h>


long double dod(double w1, double w2, char o)
{
    switch (o)
    {
    case '+':
        return w1 + w2;
    case '-':
        return w1 - w2;
    case '*':
        return w1 * w2;
    case '/':
        return w1 / w2;
    case '^':
        return pow(w1, w2);
    }
    return 0;
}