#ifndef LAAAAB10_REPOINFILEMONEY_H
#define LAAAAB10_REPOINFILEMONEY_H

#include "IRepoMoney.h"
#include "../Money/Money.h"
#include <string>

using namespace std;

class RepoInFileMoney : public IRepoMoney {
private:
    string filename;
public:
    RepoInFileMoney();
    RepoInFileMoney(const string &filename);

    void updateMoneyFromFile(Money &moneeey) override;
    Money getMoneyFromFile() override;
    void saveToFile();

    ~RepoInFileMoney();
};


#endif //LAAAAB10_REPOINFILEMONEY_H
