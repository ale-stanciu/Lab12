
#ifndef LAAAAB10_REPO_H
#define LAAAAB10_REPO_H

#include "IRepoTicket.h"

class Repo {
protected:
    vector<Ticket> tickets;
public:
    Repo();
    void addTicket(Ticket &ticket);
    void deleteTicket(Ticket ticket);
    void updateTicket(Ticket oldTicket, Ticket newTicket);
    vector<Ticket> getAll();
    Ticket getTicketByID(int id);
    int getSize();
    ~Repo();
};

#endif //LAAAAB10_REPO_H
