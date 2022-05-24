
#ifndef LAAAAB10_TICKET_H
#define LAAAAB10_TICKET_H
#include <cstring>
#include<iostream>

using namespace std;


class Ticket {
private:
    int id;
    string code;
    string day;
    int price;
    int stock;

public:
    Ticket();

    Ticket(const Ticket &ticket);

    Ticket(int id1, string code1, string day1, int price1, int stock1);

    int getId();
    string getCode();
    string getDay();
    int getPrice();
    int getStock();

    void setId(int id1);
    void setCode(string code1);
    void setDay(string day1);
    void setPrice(int price1);
    void setStock(int stock1);

    Ticket &operator=(const Ticket& ticket);
    bool operator==(const Ticket& ticket);

    ~Ticket();
};


#endif //LAAAAB10_TICKET_H
