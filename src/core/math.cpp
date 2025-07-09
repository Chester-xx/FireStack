/* ---------------- File Inclusions ---------------- */
#include "math.h"
#include <cmath>

/* ---------------- Defines ---------------- */

/* ---------------- Constructor ---------------- */
math::math() {

}
/* ---------------- Destructor ---------------- */
math::~math() {

}

/* ---------------- Functions ---------------- */

// pow - relies on power within header file - template reliant itself as for the decleration
int math::pow(const int base, const int exp) {
    return math::power(base, exp);
}
float math::pow(const float base, const int exp) {
    return math::power(base, exp);
}
double math::pow(const double base, const int exp) {
    return math::power(base, exp);
}

// abs, factorial, mod, sin, cos, tan, cot, sec, csc, degtorad, radtodeg, log, logbase10, e to the x, floor, ceil, round, random(range min max), max, min