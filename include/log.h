/* ---------------- Linker Map ---------------- */
#ifndef LOG_H
#define LOG_H

/* ---------------- File Inclusions ---------------- */
#include <iostream>
#include <string>
#include <type_traits>

/* ---------------- Defines ---------------- */

/* ---------------- Function Prototype Signatures ---------------- */

// const expression for each arg value
template<typename t>
constexpr bool type = std::is_arithmetic<t>::value || std::is_same<t, char>::value || std::is_same<t, const char *>::value || std::is_same<t, std::string>::value;

// print - log on current line
template<typename... arguments>
void print(const arguments... args) {
    static_assert((type<arguments> && ...), "Source file function 'log::print()' only supports standard arithmetic and text based types.");
    (std::cout << ... << args);
}

// printf - print a new line
template<typename... arguments>
void printf(const arguments... args) {
    static_assert((type<arguments> && ...), "Source file function 'log::printf()' only supports standard arithmetic and text based types.");
    std::cout << std::endl;
    (std::cout << ... << args);
}

/* ---------------- Class Definitions + Function Prototype Signatures ---------------- */

#endif