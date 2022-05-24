
#ifndef LAAAAB10_MONEY_H
#define LAAAAB10_MONEY_H


class Money {
private:
    int RON1, RON5, RON10, RON20, RON50, RON100, RON200, RON500;
public:
    Money();

    Money(int RON1, int RON5, int RON10, int RON20, int RON50, int RON100, int RON200, int RON500);

    int getRON1();
    int getRON5();
    int getRON10();
    int getRON20();
    int getRON50();
    int getRON100();
    int getRON200();
    int getRON500();

    void setRON1 (int RON1);
    void setRON5 (int RON5);
    void setRON10 (int RON10);
    void setRON20 (int RON20);
    void setRON50 (int RON50);
    void setRON100 (int RON100);
    void setRON200 (int RON200);
    void setRON500 (int RON500);

    Money &operator=(const Money& money);
    bool operator==(const Money& money);

    ~Money();

};


#endif //LAAAAB10_MONEY_H
