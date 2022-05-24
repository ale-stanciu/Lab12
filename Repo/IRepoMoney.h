
#ifndef LAAAAB10_IREPOMONEY_H
#define LAAAAB10_IREPOMONEY_H


#include "../Money/Money.h"

class IRepoMoney {
protected:
    Money money;
public:
    virtual void updateMoneyFromFile(Money &moneeey) = 0;
    virtual Money getMoneyFromFile() = 0;
};


#endif //LAAAAB10_IREPOMONEY_H
