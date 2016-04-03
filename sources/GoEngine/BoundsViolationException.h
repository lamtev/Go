#ifndef GO_BOUNDSVIOLATIONEXCEPTION_H
#define GO_BOUNDSVIOLATIONEXCEPTION_H

#include <exception>

class BoundsViolationException : public std::exception
{
public:
    const char* what() const noexcept
    {
        return "Array bounds violation";
    }

};

#endif //GO_BOUNDSVIOLATIONEXCEPTION_H
