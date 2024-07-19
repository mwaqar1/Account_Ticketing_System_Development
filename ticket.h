#ifndef TICKET_H_
#define TICKET_H_

struct Message {
  char messageAccountType;
  char messageDisplayName[31];
  char messageDetails[151];
};

struct Ticket {
  int ticketNum;
  int customerAccountNum;
  int ticketStatusFlag;
  char subjectLine[31];
  int counterNumMessages;

  struct Message messages[20];
};

struct AccountTicketingData {
  struct Account *accounts;   // array of accounts
  const int ACCOUNT_MAX_SIZE; // maximum elements for account array
  struct Ticket *tickets;     // array of tickets
  const int TICKET_MAX_SIZE;  // maximum elements for ticket array
};

void getNewTicketMenu(struct AccountTicketingData *acctTicketPointer);

void getActiveTicketsMenu(struct AccountTicketingData *acctTicketPointer);

void getClosedTicketsMenu(struct AccountTicketingData *acctTicketPointer);

#endif
