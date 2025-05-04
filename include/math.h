/* ---------------- Linker Map ---------------- */
#ifndef MATH_H
#define MATH_H

/* ---------------- Defines ---------------- */
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/* ---------------- Function Prototype Signatures ---------------- */
// Non member functions only

/* ---------------- Class Definitions + Function Prototype Signatures ---------------- */
class math
{
    private:
        //pow wrapper
        template<typename t>
        static t power(t base, int exp) {
            if (exp == 0) return 1;
            if (exp == 1) return base;
            t temp = 1;
            for (t i = 0; i < exp; ++i) {
                temp *= base;
            }
            return temp;
        }
    public:
        // constr and destr
        math(/* args */);
        ~math();
        // sqr
        static int sqr(int value);
        static float sqr(float value);
        static double sqr(double value);
        //pow
        static int pow(int base, int exp);
        static float pow(float base, int exp);
        static double pow(double base, int exp);
    protected:
        /*  */

};

#endif