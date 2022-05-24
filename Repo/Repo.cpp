

#include "Repo.h"


Repo::Repo() = default;

void Repo::addTicket(Ticket &ticket) {
    this->tickets.push_back(ticket);
}

void Repo::deleteTicket(Ticket ticket) {
    for(int i=0; i<this->tickets.size(); i++) {
        if(tickets[i].getId() == ticket.getId()) {
            tickets.erase(tickets.begin() + i);
        }
    }
}

void Repo::updateTicket(Ticket oldTicket, Ticket newTicket) {
    for(Ticket &ticket: this->tickets) {
        if(ticket.getId() == oldTicket.getId()) {
            ticket = newTicket;
        }
    }
}

vector<Ticket> Repo::getAll() {
    return this->tickets;
}

Ticket Repo::getTicketByID(int id) {
    for(Ticket &ticket: this->tickets) {
        if(ticket.getId() == id) {
            return ticket;
        }
    }
    throw runtime_error("There is no ticket with given id!");
}

int Repo::getSize() {
    return this->tickets.size();
}

Repo::~Repo() = default;
