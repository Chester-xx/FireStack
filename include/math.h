/* ---------------- Linker Map ---------------- */
#ifndef MATH_H
#define MATH_H

/* ---------------- File Inclusions ---------------- */
#include <stdexcept>
#include <cmath>

/* ---------------- Defines ---------------- */


/* ---------------- Function Prototype Signatures ---------------- */

// private methods

namespace {

    template<typename t>
    static t power(t base, int exp) {

        if (exp == 0) return 1;
        if (exp == 1) return base;
        
        t temp = 1;
        
        for (int i = 0; i < exp; ++i) {
            temp *= base;
        }

        return temp;
    }

} // namespace

// public methods

namespace math {

    // add
    template<typename A, typename B>
    auto add(const A a, const B b) -> decltype(a + b) {
        static_assert(std::is_arithmetic<A>::value && std::is_arithmetic<B>::value, "Source file function 'math::add()' only supports arithmetic types.");
        return a + b;
    }

    // subtract
    template<typename A, typename B>
    auto subtract(const A a, const B b) -> decltype(a - b) {
        static_assert(std::is_arithmetic<A>::value && std::is_arithmetic<B>::value, "Source file function 'math::add()' only supports arithmetic types.");
        return a - b;
    }

    // multiply
    template<typename A, typename B>
    auto multiply(const A a, const B b) -> decltype(a * b) {
        static_assert(std::is_arithmetic<A>::value && std::is_arithmetic<B>::value, "Source file function 'math::multiply()' only supports arithmetic types.");
        return a * b;
    }

    // divide
    template<typename A, typename B>
    auto divide(const A a, const B b) -> decltype(a / b) {
        static_assert(std::is_arithmetic<A>::value && std::is_arithmetic<B>::value, "Source file function 'math::divide()' only supports arithmetic types.");
        if (b == 0) {
            throw std::invalid_argument("Error in source file function 'math::divide()', division by 0.");
        }
        return a / b;
    }

    // square
    template<typename t>
    t sqr(const t value) {
        static_assert(std::is_arithmetic<t>::value, "Source file function 'math::sqr()' only supports arithmetic types.");
        return value * value;
    }

    // sqrt
    template<typename t>
    t sqrt(const t value) {
        return std::sqrt(value);
    }

    //power
    template<typename B, typename E>
    auto pow(const B base, const E exponent) -> decltype(power(base, exponent)) {
        static_assert(std::is_arithmetic<B>::value && std::is_arithmetic<E>::value, "Source file function 'math::pow()' only supports arithmetic types.");
        return power(base, exponent);
    }

} // namespace math

/* ---------------- Class Definitions + Function Prototype Signatures ---------------- */

#endif