#include <iostream>
#include "Tests/Tests.h"
#include "Repo/RepoInFileTicket.h"
#include "Repo/RepoInFileMoney.h"
#include "Service/Service.h"
#include "UI/UI.h"

int main() {
    testAll();
    RepoInFileTicket repoInFileTicket(R"(C:\Users\User\Desktop\LAAAAB10\tickets.txt)");
    RepoInFileMoney repoInFileMoney(R"(C:\Users\User\Desktop\LAAAAB10\money.txt)");
    TicketValidator ticketValidator;
    MoneyValidator moneyValidator;
    Service service(repoInFileTicket, repoInFileMoney, ticketValidator, moneyValidator);
    UI ui(service);
    ui.runMenu();
    return 0;
}
