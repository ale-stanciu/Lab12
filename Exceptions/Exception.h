

#ifndef LAAAAB10_EXCEPTION_H
#define LAAAAB10_EXCEPTION_H

#include <stdexcept>

using namespace std;

class Exception: public exception{
private:
    const char *message;
public:
    Exception(const char *message1) : message(message1) {}
    const char * what() const noexcept override {
        return this->message;
    }
};


#endif //LAAAAB10_EXCEPTION_H
