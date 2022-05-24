
#include "RepoMoney.h"

RepoMoney::RepoMoney() = default;

void RepoMoney::updateMoney(Money &moneey) {
    this->money = moneey;
}

Money RepoMoney::getMoney() {
    return this->money;
}

RepoMoney::~RepoMoney() = default;
