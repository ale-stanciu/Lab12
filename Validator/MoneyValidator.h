
#ifndef LAAAAB10_MONEYVALIDATOR_H
#define LAAAAB10_MONEYVALIDATOR_H


#include "../Money/Money.h"
#include "../Repo/RepoInFileMoney.h"

class MoneyValidator {
private:
    Money money;
    RepoInFileMoney repoInFileMoney;
public:
    MoneyValidator();
    MoneyValidator(RepoInFileMoney &repoInFileMoney1) : repoInFileMoney(repoInFileMoney1) {};
    void validate(Money &money1);
};


#endif //LAAAAB10_MONEYVALIDATOR_H
