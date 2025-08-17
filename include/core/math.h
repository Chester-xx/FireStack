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


    /*
    * @brief Helper function that returns the power of a base and exponent.
    *
    * @param base The base component of the power calculation.
    * @param exponent The exponent component of the power calculation.
    * @return common arithmetic type as the result of decltype the power calculation.
    */
    template<typename t>
    static t power(t base, int exp) {
        if (exp == 0) return 1;
        if (exp == 1) return base;
        t temp = 1;
        for (int i = 0; i < exp; ++i) {
            temp *= base;
        }
        return temp;
    } // template<typename t> static t power(t base, int exp)


} // namespace


// public methods


namespace math {


    /*
    * @brief Return the sum of two arithmetic values.
    *
    * @param a First value "a".
    * @param b Second value "b".
    * @return common arithmetic type as the result of decltype of a and b's sum.
    */
    template<typename A, typename B>
    auto add(const A& a, const B& b) -> decltype(a + b) {
        static_assert(std::is_arithmetic<A>::value && std::is_arithmetic<B>::value, "Source file function 'math::add()' only supports arithmetic types.");
        return a + b;
    } // template<typename A, typename B> auto add(const A& a, const B& b) -> decltype(a + b)


    /*
    * @brief Return the subtraction of two arithmetic values.
    *
    * @param a First value "a".
    * @param b Second value "b".
    * @return common arithmetic type as the result of decltype of a and b's subtraction.
    */
    template<typename A, typename B>
    auto subtract(const A& a, const B& b) -> decltype(a - b) {
        static_assert(std::is_arithmetic<A>::value && std::is_arithmetic<B>::value, "Source file function 'math::add()' only supports arithmetic types.");
        return a - b;
    } // template<typename A, typename B> auto subtract(const A& a, const B& b) -> decltype(a - b)


    /*
    * @brief Return the multiplication of two arithmetic values.
    *
    * @param a First value "a".
    * @param b Second value "b".
    * @return common arithmetic type as the result of decltype of a and b's multiplication.
    */
    template<typename A, typename B>
    auto multiply(const A& a, const B& b) -> decltype(a * b) {
        static_assert(std::is_arithmetic<A>::value && std::is_arithmetic<B>::value, "Source file function 'math::multiply()' only supports arithmetic types.");
        return a * b;
    } // template<typename A, typename B> auto multiply(const A& a, const B& b) -> decltype(a * b)


    /*
    * @brief Return the division of two arithmetic values.
    *
    * @param a First value "a".
    * @param b Second value "b".
    * @return common arithmetic type as the result of decltype of a and b's division.
    */
    template<typename A, typename B>
    auto divide(const A& a, const B& b) -> decltype(a / b) {
        static_assert(std::is_arithmetic<A>::value && std::is_arithmetic<B>::value, "Source file function 'math::divide()' only supports arithmetic types.");
        if (b == 0) {
            throw std::invalid_argument("Error in source file function 'math::divide()', division by 0.");
        }
        return a / b;
    } // template<typename A, typename B> auto divide(const A& a, const B& b) -> decltype(a / b)


    /*
    * @brief Return the square of some value.
    *
    * @param value The value that will be squared.
    * @return common arithmetic type as the result of the decltype square calculation.
    */
    template<typename t>
    t sqr(const t& value) {
        static_assert(std::is_arithmetic<t>::value, "Source file function 'math::sqr()' only supports arithmetic types.");
        return value * value;
    } // template<typename t> t sqr(const t& value)


    /*
    * @brief Return the square root of some value.
    *
    * @param value The value that will be square rooted.
    * @return common arithmetic type as the result of the decltype square root calculation.
    */
    template<typename t>
    t sqrt(const t& value) {
        return std::sqrt(value);
    } // template<typename t> t sqrt(const t& value)


    /*
    * @brief Return the power of some value raised to an exponent.
    *
    * @param base The base component of the power calculation.
    * @param exponent The exponent component of the power calculation
    * @return common arithmetic type as the result of the decltype power calculation.
    */
    template<typename B, typename E>
    auto pow(const B& base, const E& exponent) -> decltype(power(base, exponent)) {
        static_assert(std::is_arithmetic<B>::value && std::is_arithmetic<E>::value, "Source file function 'math::pow()' only supports arithmetic types.");
        return power(base, exponent);
    } // template<typename B, typename E> auto pow(const B& base, const E& exponent) -> decltype(power(base, exponent))


} // namespace math


/* ---------------- Class Definitions + Function Prototype Signatures ---------------- */


#endif // #ifndef MATH_H