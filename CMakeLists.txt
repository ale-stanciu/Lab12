cmake_minimum_required(VERSION 3.21)
project(LAAAAB10)

set(CMAKE_CXX_STANDARD 14)

add_executable(LAAAAB10 main.cpp Money/Money.cpp Money/Money.h Ticket/Ticket.cpp Ticket/Ticket.h UI/UI.cpp UI/UI.h Service/Service.cpp Service/Service.h Tests/Tests.cpp Tests/Tests.h Repo/RepoInFileTicket.cpp Repo/RepoInFileTicket.h Repo/IRepoTicket.h Repo/Repo.cpp Repo/Repo.h Repo/RepoInFileMoney.cpp Repo/RepoInFileMoney.h Repo/IRepoMoney.h Repo/RepoMoney.cpp Repo/RepoMoney.h Validator/TicketValidator.cpp Validator/TicketValidator.h Validator/MoneyValidator.cpp Validator/MoneyValidator.h Exceptions/Exception.h)
