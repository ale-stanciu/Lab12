#include "Tests.h"
#include "../Ticket/Ticket.h"
#include "../Repo/Repo.h"
#include "../Repo/RepoInFileTicket.h"
#include "../Repo/RepoMoney.h"
#include "../Service/Service.h"
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;



void testConstructorTicket1() {
    Ticket ticket;
    assert(ticket.getId() == 0);
    assert(ticket.getCode().empty());
    assert(ticket.getDay().empty());
    assert(ticket.getPrice() == 0.0);
    assert(ticket.getStock() == 0);
}

void testConstructorTicket2() {
    Ticket ticket(1, "BV-CJ", "vineri", 70, 180);
    assert(ticket.getId() == 1);
    assert(ticket.getCode() == "BV-CJ");
    assert(ticket.getDay() == "vineri");
    assert(ticket.getPrice() == 70);
    assert(ticket.getStock() == 180);
}

void testSetterGetter() {
    Ticket ticket;
    ticket.setId(1);
    ticket.setCode("BV-CJ");
    ticket.setDay("vineri");
    ticket.setPrice(70);
    ticket.setStock(180);
    assert(ticket.getId() == 1);
    assert(ticket.getCode() == "BV-CJ");
    assert(ticket.getDay() == "vineri");
    assert(ticket.getPrice() == 70);
    assert(ticket.getStock() == 180);
}

void testAddTicketRepo() {
    Repo repo;
    Ticket ticket1, ticket2, ticket3, ticket4;

    ticket1.setId(1);
    ticket1.setCode("BV-CJ");
    ticket1.setDay("vineri");
    ticket1.setPrice(70);
    ticket1.setStock(180);

    ticket2.setId(2);
    ticket2.setCode("SB-CJ");
    ticket2.setDay("miercuri");
    ticket2.setPrice(50);
    ticket2.setStock(150);

    ticket3.setId(3);
    ticket3.setCode("MM-SV");
    ticket3.setDay("duminica");
    ticket3.setPrice(30);
    ticket3.setStock(100);

    ticket4.setId(4);
    ticket4.setCode("GL-BV");
    ticket4.setDay("luni");
    ticket4.setPrice(100);
    ticket4.setStock(200);

    repo.addTicket(ticket1);
    repo.addTicket(ticket2);
    repo.addTicket(ticket3);
    repo.addTicket(ticket4);

    assert(repo.getSize() == 4);
}

void testDeleteTicketRepo() {
    Repo repo;
    Ticket ticket1, ticket2, ticket3, ticket4;

    ticket1.setId(1);
    ticket1.setCode("BV-CJ");
    ticket1.setDay("vineri");
    ticket1.setPrice(70);
    ticket1.setStock(180);

    ticket2.setId(2);
    ticket2.setCode("SB-CJ");
    ticket2.setDay("miercuri");
    ticket2.setPrice(50);
    ticket2.setStock(150);

    ticket3.setId(3);
    ticket3.setCode("MM-SV");
    ticket3.setDay("duminica");
    ticket3.setPrice(30);
    ticket3.setStock(100);

    ticket4.setId(4);
    ticket4.setCode("GL-BV");
    ticket4.setDay("luni");
    ticket4.setPrice(100);
    ticket4.setStock(200);

    repo.addTicket(ticket1);
    repo.addTicket(ticket2);
    repo.addTicket(ticket3);
    repo.addTicket(ticket4);

    repo.deleteTicket(ticket2);

    assert(repo.getSize() == 3);
}

void testUpdateTicketRepo() {
    Repo repo;
    Ticket ticket1, ticket2, ticket3, ticket4;

    ticket1.setId(1);
    ticket1.setCode("BV-CJ");
    ticket1.setDay("vineri");
    ticket1.setPrice(70);
    ticket1.setStock(180);

    ticket2.setId(2);
    ticket2.setCode("SB-CJ");
    ticket2.setDay("miercuri");
    ticket2.setPrice(50);
    ticket2.setStock(150);

    ticket3.setId(3);
    ticket3.setCode("MM-SV");
    ticket3.setDay("duminica");
    ticket3.setPrice(30);
    ticket3.setStock(100);

    ticket4.setId(4);
    ticket4.setCode("GL-BV");
    ticket4.setDay("luni");
    ticket4.setPrice(100);
    ticket4.setStock(200);

    repo.addTicket(ticket1);
    repo.addTicket(ticket2);
    repo.addTicket(ticket3);

    repo.updateTicket(ticket1,ticket4);

    assert(repo.getSize() == 3);
}

void testUpdateMoneyRepo() {
    RepoMoney repoMoney;
    Money money(5,5,5,5,5,5,5,5);
    repoMoney.updateMoney(money);

    //assert(repoMoney.getMoney() == money);

    Money moneey(20,5,5,5,5,5,5,5);
    repoMoney.updateMoney(moneey);

    //assert(repoMoney.getMoney() == moneey);
}

void testCreateService() {
    Service service;

    Ticket ticket1, ticket2, ticket3, ticket4;

    ticket1.setId(1);
    ticket1.setCode("BV-CJ");
    ticket1.setDay("vineri");
    ticket1.setPrice(70);
    ticket1.setStock(180);

    ticket2.setId(2);
    ticket2.setCode("SB-CJ");
    ticket2.setDay("miercuri");
    ticket2.setPrice(50);
    ticket2.setStock(150);

    ticket3.setId(3);
    ticket3.setCode("MM-SV");
    ticket3.setDay("duminica");
    ticket3.setPrice(30);
    ticket3.setStock(100);

    ticket4.setId(4);
    ticket4.setCode("GL-BV");
    ticket4.setDay("luni");
    ticket4.setPrice(100);
    ticket4.setStock(200);

    service.create(ticket1);
    service.create(ticket2);
    service.create(ticket3);

    assert(service.getAll().size() == 3);
}

void testDeleteService() {
    Service service;

    Ticket ticket1, ticket2, ticket3, ticket4;

    ticket1.setId(1);
    ticket1.setCode("BV-CJ");
    ticket1.setDay("vineri");
    ticket1.setPrice(70);
    ticket1.setStock(180);

    ticket2.setId(2);
    ticket2.setCode("SB-CJ");
    ticket2.setDay("miercuri");
    ticket2.setPrice(50);
    ticket2.setStock(150);

    ticket3.setId(3);
    ticket3.setCode("MM-SV");
    ticket3.setDay("duminica");
    ticket3.setPrice(30);
    ticket3.setStock(100);

    ticket4.setId(4);
    ticket4.setCode("GL-BV");
    ticket4.setDay("luni");
    ticket4.setPrice(100);
    ticket4.setStock(200);

    service.create(ticket1);
    service.create(ticket2);
    service.create(ticket3);

    service.deletee(ticket2);

    assert(service.getAll().size() == 2);
}

void testUpdateService() {
    Service service;

    Ticket ticket1, ticket2, ticket3, ticket4;

    ticket1.setId(1);
    ticket1.setCode("BV-CJ");
    ticket1.setDay("vineri");
    ticket1.setPrice(70);
    ticket1.setStock(180);

    ticket2.setId(2);
    ticket2.setCode("SB-CJ");
    ticket2.setDay("miercuri");
    ticket2.setPrice(50);
    ticket2.setStock(150);

    ticket3.setId(3);
    ticket3.setCode("MM-SV");
    ticket3.setDay("duminica");
    ticket3.setPrice(30);
    ticket3.setStock(100);

    service.create(ticket1);
    service.create(ticket2);

    service.update(ticket2, ticket3);

    assert(service.getAll().size() == 2);
}

void testBuyTicket() {
    remove("ticketsTest.txt");
    remove("moneyTests.txt");

    fstream f;

    f.open("ticketsTest.txt", ios::in);
    f.open("ticketsTest.txt", ios::out);
    f.open("moneyTests.txt", ios::in);
    f.open("moneyTests.txt", ios::out);

    RepoInFileTicket repoInFileTicket("ticketsTest.txt");
    RepoInFileMoney repoInFileMoney("moneyTests.txt");
    TicketValidator ticketValidator;
    MoneyValidator moneyValidator;

    Money money(5,5,5,5,5,5,5,5);
    repoInFileMoney.updateMoneyFromFile(money);

    Service service(repoInFileTicket, repoInFileMoney, ticketValidator, moneyValidator);

    Ticket ticket1, ticket2, ticket3;

    ticket1.setId(1);
    ticket1.setCode("BV-CJ");
    ticket1.setDay("vineri");
    ticket1.setPrice(70);
    ticket1.setStock(180);

    ticket2.setId(2);
    ticket2.setCode("SB-CJ");
    ticket2.setDay("miercuri");
    ticket2.setPrice(50);
    ticket2.setStock(150);

    ticket3.setId(3);
    ticket3.setCode("MM-SV");
    ticket3.setDay("duminica");
    ticket3.setPrice(30);
    ticket3.setStock(100);

    service.create(ticket1);
    service.create(ticket2);
    service.create(ticket3);

    Money money1(2,2,2,2,2,2,2,2);
    float change = service.buyTicket(1,1,3,3,3,3,3,3,3,3);
    assert(change == 0);

    money1 = Money(4,4,4,4,4,4,4,4);
    change = service.buyTicket(2,1,7,7,7,7,7,7,7,7);

}

void testRepoInFileTicketAdd() {
    remove("Tickets.txt");
    fstream file;
    file.open("Tickets.txt", ios::in);
    file.open("Tickets.txt", ios::out);
    RepoInFileTicket repoInFileTicket("Tickets.txt");

    Ticket ticket(1, "BV-CJ", "vineri", 70, 180);

    repoInFileTicket.addTicketInFile(ticket);

    assert(repoInFileTicket.getAllFromFile().size() == 1);
}

void testRepoInFileTicketDelete() {
    remove("Tickets.txt");
    fstream file;
    file.open("Tickets.txt", ios::in);
    file.open("Tickets.txt", ios::out);
    RepoInFileTicket repoInFileTicket("Tickets.txt");

    Ticket ticket(1, "BV-CJ", "vineri", 70, 180);

    repoInFileTicket.addTicketInFile(ticket);
    repoInFileTicket.deleteTicketFromFile(ticket);

    assert(repoInFileTicket.sizeOfFile() == 0);
}

void testRepoInFileTicketUpdate() {
    remove("Tickets.txt");
    fstream file;
    file.open("Tickets.txt", ios::in);
    file.open("Tickets.txt", ios::out);
    RepoInFileTicket repoInFileTicket("Tickets.txt");

    Ticket ticket1(1, "BV-CJ", "vineri", 70, 180);
    Ticket ticket2(1, "BV-SB", "joi", 20, 90);

    repoInFileTicket.addTicketInFile(ticket1);
    repoInFileTicket.updateTicketFromFile(ticket1, ticket2);

    assert(repoInFileTicket.sizeOfFile() == 1);
}

void testAll() {
    testConstructorTicket1();
    testConstructorTicket2();
    testSetterGetter();
    testAddTicketRepo();
    testDeleteTicketRepo();
    testUpdateTicketRepo();
    testUpdateMoneyRepo();
    testCreateService();
    testDeleteService();
    testUpdateService();
    testRepoInFileTicketAdd();
    testRepoInFileTicketDelete();
    testRepoInFileTicketUpdate();
}