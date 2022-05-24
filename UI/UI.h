
#ifndef LAAAAB10_UI_H
#define LAAAAB10_UI_H


#include "../Service/Service.h"

class UI {
private:
    Service service;
public:
    UI();
    UI(Service &service1);
    ~UI();
    void runMenu();
    void addTicket();
    void showAllTickets();
    void updateTicket();
    void deleteTicket();
    void buyTicket();
    void showAllTicketsFromAGivenDay();
    void showAllBills();
    void updateMoney();


};


#endif //LAAAAB10_UI_H
