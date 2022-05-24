
#include "MoneyValidator.h"
#include "../Exceptions/Exception.h"
#include <iostream>

using namespace std;

MoneyValidator::MoneyValidator() = default;

void MoneyValidator::validate(Money &money1) {

    if (money1.getRON1() < 0) {
        Exception exception("RON1 bills must be a positive integer !");
        throw exception;
    }

    if (money1.getRON5() < 0) {
        Exception exception("RON5 bills must be a positive integer !");
        throw exception;
    }

    if (money1.getRON10() < 0) {
        Exception exception("RON10 bills must be a positive integer !");
        throw exception;
    }

    if (money1.getRON20() < 0) {
        Exception exception("RON20 bills must be a positive integer !");
        throw exception;
    }

    if (money1.getRON50() < 0) {
        Exception exception("RON50 bills must be a positive integer !");
        throw exception;
    }

    if (money1.getRON100() < 0) {
        Exception exception("RON100 bills must be a positive integer !");
        throw exception;
    }

    if (money1.getRON200() < 0) {
        Exception exception("RON200 bills must be a positive integer !");
        throw exception;
    }

    if (money1.getRON500() < 0) {
        Exception exception("RON500 bills must be a positive integer !");
        throw exception;
    }
}