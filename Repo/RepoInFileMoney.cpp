
#include <fstream>
#include "RepoInFileMoney.h"


RepoInFileMoney::RepoInFileMoney() = default;

RepoInFileMoney::RepoInFileMoney(const string &filename) {
    this->filename = filename;
    ifstream f(filename);
    if(!f.eof()) {
        int bills1, bills5, bills10, bills20, bills50, bills100, bills200, bills500;
        f >> bills1 >> bills5 >> bills10 >> bills20 >> bills50 >> bills100 >> bills200 >> bills500;
        Money moneeey(bills1, bills5, bills10, bills20, bills50, bills100, bills200, bills500);
        this->money = moneeey;
    }
    f.close();
}

void RepoInFileMoney::updateMoneyFromFile(Money &moneey) {
    this->money = moneey;
    this->saveToFile();
}

Money RepoInFileMoney::getMoneyFromFile() {
    return this->money;
}

void RepoInFileMoney::saveToFile() {
    ofstream g(this->filename);
    g << this->money.getRON1() << " " << this->money.getRON5() << " " << this->money.getRON10() << " " << this->money.getRON20() << " " << this->money.getRON50() << " " << this->money.getRON100() << " " << this->money.getRON200() << " " << this->money.getRON500() << endl;
    g.close();
}

RepoInFileMoney::~RepoInFileMoney() {
    fstream f(this->filename);
    if(f.is_open()) {
        f.close();
    }
}

