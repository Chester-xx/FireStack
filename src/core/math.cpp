/* ---------------- File Inclusions ---------------- */
#include "math.h"

/* ---------------- Defines ---------------- */

/* ---------------- Constructor ---------------- */
math::math() {

}
/* ---------------- Destructor ---------------- */
math::~math() {

}

/* ---------------- Functions ---------------- */

// sqr
int math::sqr(int value) {
    return value * value;
}
float math::sqr(float value) {
    return value * value;
}
double math::sqr(double value) {
    return value * value;
}

// pow - relies on power within header file - template reliant itself as for the decleration
int math::pow(int base, int exp) {
    return math::power(base, exp);
}
float math::pow(float base, int exp) {
    return math::power(base, exp);
}
double math::pow(double base, int exp) {
    return math::power(base, exp);
}