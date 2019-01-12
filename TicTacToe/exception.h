#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <stdexcept>


class Exception : public std::exception
{
public:
    virtual const char* what() const noexcept;
};

#endif // EXCEPTION_H
