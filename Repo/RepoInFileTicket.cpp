#include <fstream>
#include "RepoInFileTicket.h"


RepoInFileTicket::RepoInFileTicket() = default;

RepoInFileTicket::RepoInFileTicket(const string &filename) {
    this->filename = filename;
    ifstream f(filename);
    while(!f.eof()) {
        int id, price, stock;
        string code, day;
        f >> id >> code >> day >> price >> stock;
        if(!code.empty() and !day.empty()) {
            Ticket ticket(id, code, day, price, stock);
            this->tickets.push_back(ticket);
        }
    }
    f.close();
}

RepoInFileTicket::~RepoInFileTicket() {

}

void RepoInFileTicket::addTicketInFile(Ticket &ticket) {
    this->tickets.push_back(ticket);
    this->saveToFile();
}

vector<Ticket> RepoInFileTicket::getAllFromFile() {
    return this->tickets;
}

void RepoInFileTicket::deleteTicketFromFile(Ticket ticket) {
    for(int i=0; i<this->tickets.size(); i++) {
        if(tickets[i].getId() == ticket.getId()) {
            tickets.erase(tickets.begin() + i);
        }
    }
    this->saveToFile();
}

void RepoInFileTicket::updateTicketFromFile(Ticket oldTicket, Ticket newTicket) {
    for(Ticket &ticket: this->tickets) {
        if(ticket.getId() == oldTicket.getId()) {
            ticket = newTicket;
        }
    }
    this->saveToFile();
}

Ticket RepoInFileTicket::getTicketByIdFromFile(int id) {
    for(Ticket &ticket: this->tickets) {
        if(ticket.getId() == id) {
            return ticket;
        }
    }
    throw runtime_error("There is no ticket with given id!");
}

void RepoInFileTicket::saveToFile() {
    ofstream g(this->filename);
    for(Ticket &ticket: this->tickets) {
        g << ticket.getId() << " " << ticket.getCode() << " " << ticket.getDay() << " " << ticket.getPrice() << " " << ticket.getStock() << endl;
    }
    g.close();
}

bool RepoInFileTicket::find(Ticket ticket) {
    for(Ticket &tickeet: this->tickets) {
        if (tickeet == ticket) {
            return true;
        }
    }
    return false;
}

int RepoInFileTicket::sizeOfFile() {
    return (int)tickets.size();
}
