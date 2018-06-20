#ifndef IO_STREAM
#define IO_STREAM

#include "wrap-hwlib.hpp"

/**
 * @brief Interface inheriting hwlib::istream and hwlib::ostream
 *
 * @details
 * The purpose of this interface is to merge the istream and ostream.
 */
class IOStream : public hwlib::istream, public hwlib::ostream {
    virtual void putc(char c) = 0;

    virtual bool char_available() = 0;

    virtual char getc() = 0;
};

#endif // IO_STREAM
