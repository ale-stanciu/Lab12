
#ifndef LAAAAB10_TICKETVALIDATOR_H
#define LAAAAB10_TICKETVALIDATOR_H


#include "../Ticket/Ticket.h"
#include "../Repo/RepoInFileTicket.h"

class TicketValidator {
private:
    Ticket ticket;
    RepoInFileTicket repoInFileTicket;
public:
    TicketValidator();
    TicketValidator(RepoInFileTicket &repoInFileTicket1) : repoInFileTicket(repoInFileTicket1) {};
    void validate(Ticket &ticket1);
};


#endif //LAAAAB10_TICKETVALIDATOR_H
