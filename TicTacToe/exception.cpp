#include "exception.h"

const char* Exception::what() const noexcept
{
    return "exception";
}
