
#include "Service.h"
#include "../Exceptions/Exception.h"
#include <iostream>

Service::Service() = default;

Service::Service(RepoInFileTicket &repoInFileTicket1, RepoInFileMoney &repoInFileMoney1,
                 TicketValidator &ticketValidator1, MoneyValidator &moneyValidator1) {
    this->repoInFileTicket = repoInFileTicket1;
    this->repoInFileMoney = repoInFileMoney1;
    this->ticketValidator = ticketValidator1;
    this->moneyValidator = moneyValidator1;
}

void Service::create(Ticket ticket) {
    this->ticketValidator.validate(ticket);
    this->repoInFileTicket.addTicketInFile(ticket);
}

void Service::deletee(Ticket ticket) {
    this->repoInFileTicket.deleteTicketFromFile(ticket);
}

void Service::update(Ticket oldTicket, Ticket newTicket) {
    this->ticketValidator.validate(newTicket);
    this->repoInFileTicket.updateTicketFromFile(oldTicket, newTicket);
}

Ticket Service::getTicketById(int id) {
    return this->repoInFileTicket.getTicketByIdFromFile(id);
}

vector<Ticket> Service::getAll() {
    return this->repoInFileTicket.getAllFromFile();
}

Money Service::getAllMoney() {
    return this->repoInFileMoney.getMoneyFromFile();
}

int Service::buyTicket(int id, int nrTickets, int bills1, int bills5, int bills10, int bills20, int bills50,
                       int bills100, int bills200, int bills500) {

    Money money1(bills1,bills5, bills10, bills20, bills50,
             bills100, bills200, bills500);
    if(id <= 0) {
        Exception exception("Id is incorrect!");
        throw exception;
    }

    if(nrTickets <= 0) {
        Exception exception("The number of tickets is incorrect!");
        throw exception;
    }

    this->moneyValidator.validate(money1);

    int price = nrTickets * this->repoInFileTicket.getTicketByIdFromFile(id).getPrice();
    int sum = bills1 + (5 * bills5) + (10 * bills10) + (20 * bills20) + (50 * bills50) + (100 * bills100) + (200 * bills200) + (500 * bills500);
    int change = sum - price;
    int changee = change;

    if(this->repoInFileTicket.find(this->repoInFileTicket.getTicketByIdFromFile(id))) {
        if(sum < price) {
            cout << "The amount of money you introduced is not enough!";
            return 0;
        }

        int change500RON = min(changee / 500, this->repoInFileMoney.getMoneyFromFile().getRON500());
        int new500bills = this->repoInFileMoney.getMoneyFromFile().getRON500() - change500RON + bills500;
        changee -= 500 * change500RON;

        int change200RON = min(changee / 200, this->repoInFileMoney.getMoneyFromFile().getRON200());
        int new200bills = this->repoInFileMoney.getMoneyFromFile().getRON200() - change200RON + bills200;
        changee -= 200 * change200RON;

        int change100RON = min(changee / 100, this->repoInFileMoney.getMoneyFromFile().getRON100());
        int new100bills = this->repoInFileMoney.getMoneyFromFile().getRON100() - change100RON + bills100;
        changee -= 100 * change100RON;

        int change50RON = min(changee / 50, this->repoInFileMoney.getMoneyFromFile().getRON50());
        int new50bills = this->repoInFileMoney.getMoneyFromFile().getRON50() - change50RON + bills50;
        changee -= 50 * change50RON;

        int change20RON = min(changee / 20, this->repoInFileMoney.getMoneyFromFile().getRON20());
        int new20bills = this->repoInFileMoney.getMoneyFromFile().getRON20() - change20RON + bills20;
        changee -= 20 * change20RON;

        int change10RON = min(changee / 10, this->repoInFileMoney.getMoneyFromFile().getRON10());
        int new10bills = this->repoInFileMoney.getMoneyFromFile().getRON10() - change10RON + bills10;
        changee -= 10 * change10RON;

        int change5RON = min(changee / 5, this->repoInFileMoney.getMoneyFromFile().getRON5());
        int new5bills = this->repoInFileMoney.getMoneyFromFile().getRON5() - change5RON + bills5;
        changee -= 5 * change5RON;

        int change1RON = min(changee, this->repoInFileMoney.getMoneyFromFile().getRON1());
        int new1bills = this->repoInFileMoney.getMoneyFromFile().getRON1() - change1RON + bills1;
        changee -= 1 * change1RON;


        if(changee == 0) {
            Ticket ticket = this->repoInFileTicket.getTicketByIdFromFile(id);
            Ticket newTicket = ticket;
            newTicket.setStock(newTicket.getStock() - nrTickets);
            Money money(new1bills, new5bills, new10bills, new20bills, new50bills,
                        new100bills, new200bills, new500bills);
            this->repoInFileTicket.updateTicketFromFile(ticket, newTicket);
            this->repoInFileMoney.updateMoneyFromFile(money);
            return change;
        } else {
            Exception exception("The bank does not have enough money for the change to be done!");
            throw exception;
        }
    } else {
        Exception exception("The id is not in the list");
        throw exception;
    }
}

vector<Ticket> Service::getAllTicketsFromGivenDay(string day) {
    if(day != "luni" && day != "marti" && day != "miercuri" && day != "joi" && day != "vineri" &&
    day != "sambata" && day != "duminica") {
        Exception exception("Day is incorrect!");
        throw exception;
    }

    vector<Ticket> tickets;
    for(Ticket &ticket: this->repoInFileTicket.getAllFromFile()) {
        if(ticket.getDay() == day) {
            tickets.push_back(ticket);
        }
    }
    return tickets;
}

void Service::updateMoney(Money money) {
    this->repoInFileMoney.updateMoneyFromFile(money);
}

Service::~Service() = default;
