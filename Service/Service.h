
#ifndef LAAAAB10_SERVICE_H
#define LAAAAB10_SERVICE_H


#include "../Repo/RepoInFileTicket.h"
#include "../Repo/RepoInFileMoney.h"
#include "../Validator/TicketValidator.h"
#include "../Validator/MoneyValidator.h"

class Service {
private:
    RepoInFileTicket repoInFileTicket;
    RepoInFileMoney repoInFileMoney;
    TicketValidator ticketValidator;
    MoneyValidator moneyValidator;

public:
    Service();
    Service(RepoInFileTicket &repoInFileTicket1, RepoInFileMoney &repoInFileMoney1,
            TicketValidator &ticketValidator1, MoneyValidator &moneyValidator1);
    void create(Ticket ticket);
    void deletee(Ticket ticket);
    void update(Ticket oldTicket, Ticket newTicket);
    Ticket getTicketById(int id);
    vector<Ticket> getAll();
    Money getAllMoney();
    int buyTicket(int id, int nrTickets, int bills1, int bills5, int bills10, int bills20, int bills50, int bills100, int bills200, int bills500);
    vector<Ticket> getAllTicketsFromGivenDay(string day);
    void updateMoney(Money money);
    ~Service();
};


#endif //LAAAAB10_SERVICE_H
