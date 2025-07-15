/* ---------------- Linker Map ---------------- */
#ifndef LOGGING_H
#define LOGGING_H

/* ---------------- File Inclusions ---------------- */
#include <iostream>
#include <string>
#include <type_traits>

/* ---------------- Defines ---------------- */

/* ---------------- Function Prototype Signatures ---------------- */

// private methods

// public methods

namespace logging {

    // const expression for each arg value
    template<typename t>
    constexpr bool type = std::is_arithmetic<t>::value || std::is_same<t, char>::value || std::is_same<t, const char *>::value || std::is_same<t, std::string>::value;

    // print - log content to current line of console
    template<typename... arguments>
    void print(const arguments... args) {
        static_assert((type<arguments> && ...), "Source file function 'log::print()' only supports standard arithmetic and text based types.");
        (std::cout << ... << args);
    }

    // printf - log a new line of content to console
    template<typename... arguments>
    void printf(const arguments... args) {
        static_assert((type<arguments> && ...), "Source file function 'log::printf()' only supports standard arithmetic and text based types.");
        std::cout << std::endl;
        (std::cout << ... << args);
    }

    // log error to console
    template<typename... arguments>
    void error(const arguments... message) {
        static_assert((type<arguments> && ...), "Source file function 'log::error()' only supports standard arithmetic and text based types.");
        (std::cerr << ... << message);
    }

    /* ---------------- Class Definitions + Function Prototype Signatures ---------------- */



} // namespace logging

#endif // LOGGING_H