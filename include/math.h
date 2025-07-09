/* ---------------- Linker Map ---------------- */
#ifndef MATH_H
#define MATH_H

/* ---------------- File Inclusions ---------------- */
#include <stdexcept>
#include <cmath>

/* ---------------- Defines ---------------- */


/* ---------------- Function Prototype Signatures ---------------- */


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
        math();
        ~math();

        // add
        template<typename A, typename B>
        static auto add(const A a, const B b) -> decltype(a + b) {
            static_assert(std::is_arithmetic<A>::value && std::is_arithmetic<B>::value, "Source file function 'math::add()' only supports arithmetic types.");
            return a + b;
        }

        // subtract
        template<typename A, typename B>
        static auto subtract(const A a, const B b) -> decltype(a - b) {
            static_assert(std::is_arithmetic<A>::value && std::is_arithmetic<B>::value, "Source file function 'math::add()' only supports arithmetic types.");
            return a - b;
        }

        // multiply
        template<typename A, typename B>
        static auto multiply(const A a, const B b) -> decltype(a * b) {
            static_assert(std::is_arithmetic<A>::value && std::is_arithmetic<B>::value, "Source file function 'math::multiply()' only supports arithmetic types.");
            return a * b;
        }

        // divide
        template<typename A, typename B>
        static auto divide(const A a, const B b) -> decltype(a / b) {
            static_assert(std::is_arithmetic<A>::value && std::is_arithmetic<B>::value, "Source file function 'math::divide()' only supports arithmetic types.");
            if (b == 0) {
                throw std::invalid_argument("Error in source file function 'math::divide()', division by 0.");
            }
            return a / b;
        }

        // FOR LATER -- STATIC ASSERT arithmetic types using templates for below
        // sqr
        static int sqr(const int value);
        static float sqr(const float value);
        static double sqr(const double value);

        // sqrt - calls cmath std::sqrt() for safety
        template<typename t>
        static t sqrt(t value) {
            return std::sqrt(value);
        }

        //pow
        static int pow(const int base, const int exp);
        static float pow(const float base, const int exp);
        static double pow(const double base, const int exp);

    protected:
        /*  */

};

#endif