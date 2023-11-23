#pragma once
#ifndef TICKET_H
#define TICKET_H

#include <string>

class Ticket {
private:
    char* type;
    int* ticketID;
    int validityDuration;
    static int validTickets;

public:
    Ticket(const std::string& type, const int* ticketID);

    ~Ticket();

    std::string getType() const;
    int getTicketID(int index) const;
    int getValidityDuration() const;

    static bool validateTicket(const Ticket& ticket);
};

#endif // TICKET_H