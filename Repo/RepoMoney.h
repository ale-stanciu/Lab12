
#ifndef LAAAAB10_REPOMONEY_H
#define LAAAAB10_REPOMONEY_H


#include "../Money/Money.h"

class RepoMoney {
protected:
    Money money;
public:
    RepoMoney();

    void updateMoney(Money& moneey);
    Money getMoney();

    ~RepoMoney();
};


#endif //LAAAAB10_REPOMONEY_H
