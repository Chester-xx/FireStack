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


namespace {

} // namespace


// public methods


namespace logging {

    // const expression for each arg value
    template<typename t>
    constexpr bool type = std::is_arithmetic<t>::value || std::is_same<t, char>::value || std::is_same<t, const char *>::value || std::is_same<t, std::string>::value || std::is_pointer_v<t>;


    /*
    * @brief Helper function to print argument to console.
    *
    * @param value The value to be printed.
    * @return void
    */
    template<typename t>
    void print_arg(const t value) {
            std::cout << value;
    } // template<typename t> void print_arg(const t value)


    /*
    * @brief Log content to the current line of console.
    *
    * @param args Varying range of arguments that will be logged.
    * @return void
    */
    template<typename... arguments>
    void print(const arguments... args) {
        static_assert((type<arguments> && ...), "Source file function 'log::print()' only supports standard arithmetic and text based types.");
        (print_arg(args), ...);
    } // template<typename... arguments> void print(const arguments... args)


    /*
    * @brief Log content to current line of console and then create a newline.
    *
    * @param args Varying range of arguments that will be logged.
    * @return void
    */
    template<typename... arguments>
    void println(const arguments... args) {
        static_assert((type<arguments> && ...), "Source file function 'log::printf()' only supports standard arithmetic and text based types.");
        (print_arg(args), ...);
        std::cout << "\n";
    } // template<typename... arguments> void println(const arguments... args)


    /*
    * @brief Log content as error "c++ cerr" to the console.
    *
    * @param message Varying range of arguments that will be logged.
    * @return void
    */
    template<typename... arguments>
    void error(const arguments... message) {
        static_assert((type<arguments> && ...), "Source file function 'log::error()' only supports standard arithmetic and text based types.");
        (std::cerr << ... << message);
        println();
    } // template<typename... arguments> void error(const arguments... message)


    /* ---------------- Class Definitions + Function Prototype Signatures ---------------- */


} // namespace logging

#endif // LOGGING_H