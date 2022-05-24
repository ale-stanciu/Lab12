#ifndef LAAAAB10_IREPOTICKET_H
#define LAAAAB10_IREPOTICKET_H

#include <iostream>
#include <vector>
#include "../Ticket/Ticket.h"

using namespace std;


class IRepoTicket{
protected:
    vector<Ticket> tickets;
public:

    virtual void addTicketInFile(Ticket &ticket) = 0;
    virtual vector<Ticket> getAllFromFile() = 0;
    virtual void deleteTicketFromFile(Ticket ticket) = 0;
    virtual void updateTicketFromFile(Ticket oldTicket, Ticket newTicket) = 0;
    virtual Ticket getTicketByIdFromFile(int id) = 0;
};

#endif //LAAAAB10_IREPOTICKET_H
