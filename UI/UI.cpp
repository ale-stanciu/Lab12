
#include "UI.h"
#include "../Exceptions/Exception.h"
#include <iostream>

using namespace std;

UI::UI() = default;

UI::UI(Service &service1) {
    this->service = service1;
}

void UI::runMenu() {
    int ok = 1;
    char option;
    while (ok) {
        cout << endl;
        cout << "1. Add a ticket" << endl;
        cout << "2. Delete a ticket" << endl;
        cout << "3. Update a ticket" << endl;
        cout << "4. Buy a ticket" << endl;
        cout << "5. Show all tickets from a given day" << endl;
        cout << "t. Show all tickets" << endl;
        cout << "m. Show all money" << endl;
        cout << "x. Exit" << endl;
        cout << "Give option:" << " ";
        cin >> option;
        switch (option) {
            case '1': {
                this->addTicket();
                break;
            }
            case '2': {
                this->deleteTicket();
                break;
            }
            case '3': {
                this->updateTicket();
                break;
            }
            case '4': {
                this->buyTicket();
                break;
            }
            case '5': {
                this->showAllTicketsFromAGivenDay();
                break;
            }
            case 't': {
                this->showAllTickets();
                break;
            }
            case 'm': {
                this->showAllBills();
                break;
            }
            case 'x': {
                ok = 0;
                break;
            }
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}


void UI::addTicket() {
    try {
        int id, price, stock;
        string code, day;
        cout << "Give id: ";
        cin >> id;
        if(!cin >> id) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("Id must be a positive integer!");
        }

        cout << "Give code: ";
        cin >> code;

        cout << "Give day: ";
        cin >> day;

        cout << "Give price: ";
        cin >> price;
        if(!cin >> price) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("Price must be a positive integer!");
        }

        cout << "Give stock: ";
        cin >> stock;
        if(!cin >> stock) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("Stock must be a positive integer!");
        }

        for(auto& ticket: service.getAll()) {
            if(id == ticket.getId()) {
                throw Exception("A ticket with this id already exists!");
            }
        }

        Ticket ticket(id, code, day, price, stock);
        this->service.create(ticket);
    }

    catch(Exception &exception) {
        cout << "Error: " << exception.what() << endl;
    }
    catch(invalid_argument &exception) {
        cout << "Invalid argument: " << exception.what() << endl;
    }
    catch (exception &exception) {
        cout << "Error: " << exception.what() << endl;
    }
}

void UI::showAllTickets() {
    for(Ticket& ticket: this->service.getAll()) {
        cout << "Ticket nr. " << ticket.getId() << "; code: " << ticket.getCode() << "; day: " << ticket.getDay()
        << "; price: " << ticket.getPrice() << "; stock: " << ticket.getStock() << endl;
    }
}

void UI::updateTicket() {
    try {
        int id, id1, price1, stock1;
        string code1, day1;
        cout << "Give id to modify: ";
        cin >> id;
        if(!cin >> id) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("Id must be a positive integer!");
        }

        if(id <= 0) {
            throw Exception("Id is incorrect!");
        }

        cout << "Give new id: ";
        cin >> id1;
        if(!cin >> id1) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("Id must be a positive integer!");
        }

        cout << "Give new code: ";
        cin >> code1;

        cout << "Give day: ";
        cin >> day1;

        cout << "Give price: ";
        cin >> price1;
        if(!cin >> price1) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("Price must be a positive integer!");
        }

        cout << "Give stock: ";
        cin >> stock1;
        if(!cin >> price1) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("Stock must be a positive integer!");
        }

        int k = 0;
        Ticket ticket1(id1, code1, day1, price1, stock1);
        for (Ticket &ticket: this->service.getAll()) {
            if (ticket.getId() == id) {
                k = 1;
                this->service.update(ticket, ticket1);
            }
        }
        if(!k) {
            cout << "Given id is not in the list!";
        }
    }
    catch(Exception &exception) {
        cout << "Error: " << exception.what() << endl;
    }
    catch (exception &exception) {
        cout << "Error: " << exception.what() << endl;
    }

}

void UI::deleteTicket() {
    try {
        int id;
        cout << "Give id: ";
        cin >> id;
        if (!cin >> id) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("Id must be a positive integer.");
        }
        if (id <= 0) {
            throw Exception("Id is incorrect.");
        }
        int size_before_delete = this->service.getAll().size();
        for (Ticket &ticket: this->service.getAll()) {
            if (ticket.getId() == id) {
                this->service.deletee(ticket);
            }
        }
        if (this->service.getAll().size() == size_before_delete) {
            cout << "There is no ticket with given id! ";
        }
    }
    catch (Exception &exception) {
        cout << "Error: " << exception.what() << endl;
    }
    catch (exception &exception) {
        cout << "Error: " << exception.what() << endl;
    }

}

void UI::buyTicket() {
    try {
        int id, nrTickets, bills1RON, bills5RON, bills10RON, bills20RON, bills50RON, bills100RON, bills200RON, bills500RON;
        cout << "Give id for the ticket to be bought: ";
        cin >> id;
        if (!cin >> id) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("Id must be a positive integer.");
        }
        Ticket ticket = this->service.getTicketById(id);
        cout << "Give the number of tickets wanted: ";
        cin >> nrTickets;
        if (!cin >> nrTickets) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("Number of tickets must be a positive integer.");
        }
        cout << "Enter the amount of bills " << endl;
        cout << "1RON bills: ";
        cin >> bills1RON;
        if (!cin >> bills1RON) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("1RON bills must be a positive integer.");
        }
        cout << "5RON bills: ";
        cin >> bills5RON;
        if (!cin >> bills5RON) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("5RON bills must be a positive integer.");
        }
        cout << "10RON bills: ";
        cin >> bills10RON;
        if (!cin >> bills10RON) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("10RON bills must be a positive integer.");
        }
        cout << "20RON bills: ";
        cin >> bills20RON;
        if (!cin >> bills20RON) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("20RON bills must be a positive integer.");
        }
        cout << "50RON bills: ";
        cin >> bills50RON;
        if (!cin >> bills50RON) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("50RON bills must be a positive integer.");
        }
        cout << "100RON bills: ";
        cin >> bills100RON;
        if (!cin >> bills100RON) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("100RON bills must be a positive integer.");
        }
        cout << "200RON bills: ";
        cin >> bills200RON;
        if (!cin >> bills200RON) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("200RON bills must be a positive integer.");
        }
        cout << "500RON bills: ";
        cin >> bills500RON;
        if (!cin >> bills500RON) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("500RON bills must be a positive integer.");
        }
        cout << this->service.buyTicket(id, nrTickets, bills1RON, bills5RON, bills10RON, bills20RON,
                                        bills50RON, bills100RON, bills200RON, bills500RON);
    }
    catch (Exception &exception) {
        cout << "Error: " << exception.what() << endl;
    }
    catch (exception &exception) {
        cout << "Error: " << exception.what() << endl;
    }
}

void UI::showAllTicketsFromAGivenDay() {
    try {
        string day;
        cout << "Give day: ";
        cin >> day;
        vector<Ticket> tickets = this->service.getAllTicketsFromGivenDay(day);
        for (Ticket &ticket: tickets) {
            cout << "Ticket nr. " << ticket.getId() << "; code: " << ticket.getCode() << "; day: " << ticket.getDay()
                 << "; price: " << ticket.getPrice() << "; stock: " << ticket.getStock() << endl;
        }
    }
    catch (Exception &exception) {
        cout << "Error: " << exception.what() << endl;
    }
    catch (exception &exception) {
        cout << "Error: " << exception.what() << endl;
    }
}

void UI::showAllBills() {
    cout << "The existing money: " << endl;
    Money money = this->service.getAllMoney();
    cout << "1RON bills: " << money.getRON1() << endl;
    cout << "5RON bills: " << money.getRON5() << endl;
    cout << "10RON bills: " << money.getRON10() << endl;
    cout << "20RON bills: " << money.getRON20() << endl;
    cout << "50RON bills: " << money.getRON50() << endl;
    cout << "100RON bills: " << money.getRON100() << endl;
    cout << "200RON bills: " << money.getRON200() << endl;
    cout << "500RON bills: " << money.getRON500() << endl;
}

void UI::updateMoney() {
    try {
        int bills1RON, bills5RON, bills10RON, bills20RON, bills50RON, bills100RON, bills200RON, bills500RON;

        cout << "1RON bills: ";
        cin >> bills1RON;
        cout << "5RON bills: ";
        cin >> bills5RON;
        cout << "10RON bills: ";
        cin >> bills10RON;
        cout << "20RON bills: ";
        cin >> bills20RON;
        cout << "50RON bills: ";
        cin >> bills50RON;
        cout << "100RON bills: ";
        cin >> bills100RON;
        cout << "200RON bills: ";
        cin >> bills200RON;
        cout << "500RON bills: ";
        cin >> bills500RON;

        Money money(bills1RON, bills5RON, bills10RON, bills20RON, bills50RON,
                    bills100RON, bills200RON, bills500RON);
        this->service.updateMoney(money);
    }
    catch (Exception &exception) {
        cout << "Error: " << exception.what() << endl;
    }
    catch (exception &exception) {
        cout << "Error: " << exception.what() << endl;
    }
}

UI::~UI() = default;

