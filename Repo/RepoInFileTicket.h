
#ifndef LAAAAB10_REPOINFILETICKET_H
#define LAAAAB10_REPOINFILETICKET_H


#include "IRepoTicket.h"
#include <iostream>
using namespace std;

class RepoInFileTicket : public IRepoTicket {
private:
    string filename;

public:
    RepoInFileTicket();
    RepoInFileTicket(const string &filename);
    ~RepoInFileTicket();
    void addTicketInFile(Ticket &ticket) override;
    vector<Ticket> getAllFromFile() override;
    void deleteTicketFromFile(Ticket ticket) override;
    void updateTicketFromFile(Ticket oldTicket, Ticket newTicket) override;
    Ticket getTicketByIdFromFile(int id) override;
    void saveToFile();
    bool find(Ticket ticket);
    int sizeOfFile();
};

#endif //LAAAAB10_REPOINFILETICKET_H
