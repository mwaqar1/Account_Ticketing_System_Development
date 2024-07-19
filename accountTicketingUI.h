#ifndef ACCOUNTTIKETINGUI_H
#define ACCOUNTTIKETINGUI_H

#include "account.h"
#include "ticket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Debug prints */
// #define debug_print printf
#define debug_print

/**
 * @brief
 *
 * @param accounts is an array of accounts to be saved from the output file.
 * @return int is the number of accounts written in the file.
 */
int saveAccounts(struct Account *accounts, int nAccounts);

/**
 * @brief
 *
 * @param accounts is an array of accounts to be filled from the input file.
 * @param nAccounts is the size of the array.
 * @return int is the number of accounts read from the file.
 */
int loadAccounts(struct Account *accounts, int nAccounts);

/**
 * @brief
 *
 * @param tickets is the array of tickets to be saved int the output file.
 * @return int is the number of tickets written into the file.
 */
int saveTickets(struct Ticket *tickets, int nAccounts);

/**
 * @brief
 *
 * @param tickets is the array of tickets to be filled from the input file.
 * @param nTickets is the size of the array.
 * @return int is the number of tickets read from the file.
 */
int loadTickets(struct Ticket *tickets, int nTickets);

/**
 * @brief
 *
 * @param acctTicketPointer
 */
void applicationStartup(struct AccountTicketingData *acctTicketPointer);

void displayAccountDetailHeader(void); // a1m3
void displayAccountDetailRecord(
    const struct Account *displayAccountPointer); // a1m3
void displayAllAccountDetailRecords(const struct Account accountsArray[],
                                    int maxSizeAccountsArray); // a1m4
void displayTicketHeader(void);                                //***a2m2!!!
void displayTicketRecord(const struct Ticket *ticketPointer);  //***a2m2!!
int moreLoginValidation(const struct Account arrayAccounts[],
                        int maxAccountsArray);
void applicationStartup(
    struct AccountTicketingData *acctTicketPointer); //***a2m1!!!
int findAccountIndexByAcctNum(int userAccountNo,
                              const struct Account constAccounts[],
                              int max_constAccounts, int askAccountNo);
int findIndexByTicketNum(
    int userTicketNumber,
    const struct AccountTicketingData *acctTicketPointer); //***a2m2!!!
int addNewMessage(struct AccountTicketingData *acctTicketPointer,
                  int returnedTicketIndex);
int menuLogin(const struct Account arrayAccounts[],
              int maxAccountsArray); // a1m4
void menuAgent(
    struct AccountTicketingData *acctTicketPointer,
    const struct Account *validAgentAccount); // MODIFIED a2m1 *****!!!

#endif /* ACCOUNTTIKETINGUI_H */
