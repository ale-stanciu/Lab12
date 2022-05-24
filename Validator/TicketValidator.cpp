
#include "TicketValidator.h"
#include "../Exceptions/Exception.h"

TicketValidator::TicketValidator() = default;

void TicketValidator::validate(Ticket &ticket1) {
    if(ticket1.getId() <= 0) {
        Exception exception("Id is incorrect!");
        throw exception;
    }

    for(Ticket &ticket2: this->repoInFileTicket.getAllFromFile()) {
        if(ticket2.getId() == ticket1.getId()) {
            Exception exception("Id is already used!");
            throw exception;
        }
    }

    if(ticket1.getDay() != "luni" && ticket1.getDay() != "marti" && ticket1.getDay() != "miercuri" &&
    ticket1.getDay() != "joi" && ticket1.getDay() != "vineri" && ticket1.getDay() != "sambata" &&
    ticket1.getDay() != "duminica") {
        Exception exception("Day is incorrect!");
        throw exception;
    }

    if(ticket1.getPrice() <= 0) {
        Exception exception("Price must be positive and not null!");
        throw exception;
    }
}
