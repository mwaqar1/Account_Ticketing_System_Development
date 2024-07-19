
#define _CRT_SECURE_NO_WARNINGS
#include "account.h"
#include "accountTicketingUI.h"
#include "commonHelpers.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void getNewTicketMenu(struct AccountTicketingData *acctTicketPointer) {

  int uTicketNumber = -30;
  int terminate = 0;
  int flag = 0;
  int k = 100;
  int ticketIndex = 0;
  char checkTicketStatus[10] = {0};

  do // menu only quits when user enters 0
  {

    displayTicketHeader(); // call displayTicketHeader to display ticket header
                           // table

    for (k = 0; k < acctTicketPointer->TICKET_MAX_SIZE; k++) {
      if (acctTicketPointer->tickets[k].ticketStatusFlag == 1 &&
          (acctTicketPointer->tickets[k].counterNumMessages == 1)) {
        displayTicketRecord(&acctTicketPointer->tickets[k]);
      }

    } // end of for loop to display new tickets

    printf("------ ----- --------------- ------ ------------------------------ "
           "--------\n");

    // after displaying data prompt user to new ticket menu
    printf("\n");
    printf("Enter the ticket number to view the messages or\n");

    printf("0 to return to previous menu: ");

    uTicketNumber = getInteger();

    // returned value is validated by getInteger function

    if (uTicketNumber == 0) {

      terminate = 1;

    } else {
      for (k = 0; k < acctTicketPointer->TICKET_MAX_SIZE && flag != 1;
           ++k) // display messages if user account input is the same as the new
                // ticket listed
      {
        if (acctTicketPointer->tickets[k].ticketStatusFlag == 1 &&
            (acctTicketPointer->tickets[k].counterNumMessages == 1)) {
          if (acctTicketPointer->tickets[k].ticketNum == uTicketNumber &&
              uTicketNumber > 0) {
            flag = 1;
            ticketIndex = k;

          } else {
            ticketIndex = -4;
          }
        }
      }
      if (ticketIndex >=
          0) // matching ticket number was found after for loop display messages
      {
        if (acctTicketPointer->tickets[ticketIndex].ticketStatusFlag != 1) {
          strcpy(checkTicketStatus, "CLOSED");

        }

        else {

          strcpy(checkTicketStatus, "ACTIVE");
        }

        printf("\n");
        printf("==============================================================="
               "=================\n");
        printf("%06d (%-6s) Re: %s\n",
               acctTicketPointer->tickets[ticketIndex].ticketNum,
               checkTicketStatus,
               acctTicketPointer->tickets[ticketIndex].subjectLine);
        printf("==============================================================="
               "=================\n");

        for (k = 0;
             k < acctTicketPointer->tickets[ticketIndex].counterNumMessages;
             k++) {
          printf("%s (%s):\n",
                 acctTicketPointer->tickets[ticketIndex]
                             .messages[k]
                             .messageAccountType == 'A'
                     ? "AGENT"
                     : "CUSTOMER",
                 acctTicketPointer->tickets[ticketIndex]
                     .messages[k]
                     .messageDisplayName);

          printf("   %s\n\n", acctTicketPointer->tickets[ticketIndex]
                                  .messages[k]
                                  .messageDetails);
        }

        pauseExecution();

      } // end of outer if
      else {
        printf("\n");
        printf("ERROR: Invalid ticket number.\n"); // invalid user input because
                                                   // does not match any ticket
                                                   // number that was passed to
                                                   // the function
        printf("\n");

        pauseExecution();

      } // end of inner else

    } // end of outer else

  } while (terminate != 1);

} // end of getNewTicketMenu function

void getActiveTicketsMenu(struct AccountTicketingData *acctTicketPointer) {

  int uTicketNumber = -30;
  int terminate = 0;
  int flag = 0;
  int ticketIndex = 0;
  char checkTicketStatus[10] = {0};
  int k = 100;

  do // menu only quits when user enters 0
  {

    displayTicketHeader(); // call displayTicketHeader to display ticket header
                           // table

    for (k = 0; k < acctTicketPointer->TICKET_MAX_SIZE; k++) {
      if (acctTicketPointer->tickets[k].ticketStatusFlag == 1 &&
          (acctTicketPointer->tickets[k].counterNumMessages >= 1)) {
        displayTicketRecord(&acctTicketPointer->tickets[k]);
      }

    } // end of for loop to display new tickets

    printf("------ ----- --------------- ------ ------------------------------ "
           "--------\n");

    // after displaying data prompt user to new ticket menu
    printf("\n");
    printf("Enter the ticket number to view the messages or\n");
    printf("0 to return to previous menu: ");

    uTicketNumber = getInteger();

    // returned value is validated by getInteger function

    if (uTicketNumber == 0) {

      terminate = 1;

    } else {
      for (k = 0; k < acctTicketPointer->TICKET_MAX_SIZE && flag != 1;
           ++k) // display messages if user account input is the same as the
                // active ticket listed
      {
        if (acctTicketPointer->tickets[k].ticketStatusFlag == 1 &&
            (acctTicketPointer->tickets[k].counterNumMessages >= 1)) {
          if (acctTicketPointer->tickets[k].ticketNum == uTicketNumber &&
              uTicketNumber > 0) {
            flag = 1;
            ticketIndex = k;

          } else {
            ticketIndex = -4;
          }
        }
      }
      if (ticketIndex >=
          0) // matching ticket number was found after for loop display messages
      {
        if (acctTicketPointer->tickets[ticketIndex].ticketStatusFlag != 1) {
          strcpy(checkTicketStatus, "CLOSED");

        } else {
          strcpy(checkTicketStatus, "ACTIVE");
        }

        printf("\n");
        printf("==============================================================="
               "=================\n");
        printf("%06d (%-6s) Re: %s\n",
               acctTicketPointer->tickets[ticketIndex].ticketNum,
               checkTicketStatus,
               acctTicketPointer->tickets[ticketIndex].subjectLine);
        printf("==============================================================="
               "=================\n");

        for (k = 0;
             k < acctTicketPointer->tickets[ticketIndex].counterNumMessages;
             k++) {
          printf("%s (%s):\n",
                 acctTicketPointer->tickets[ticketIndex]
                             .messages[k]
                             .messageAccountType == 'A'
                     ? "AGENT"
                     : "CUSTOMER",
                 acctTicketPointer->tickets[ticketIndex]
                     .messages[k]
                     .messageDisplayName);

          printf("   %s\n\n", acctTicketPointer->tickets[ticketIndex]
                                  .messages[k]
                                  .messageDetails);
        }

        pauseExecution();

      } // end of outer if
      else {
        printf("\n");
        printf("ERROR: Invalid ticket number.\n"); // invalid user input because
                                                   // does not match any ticket
                                                   // number that was passed to
                                                   // the function
        printf("\n");

        pauseExecution();

      } // end of inner else

    } // end of outer else

  } while (terminate != 1);

} // end of getActiveTicketMenu function

void getClosedTicketsMenu(struct AccountTicketingData *acctTicketPointer) {

  int uTicketNumber = -30;
  int terminate = 0;
  int flag = 0;
  int k = 100;
  char checkTicketStatus[10] = {0};
  int ticketIndex = -5;

  do {

    displayTicketHeader(); // call displayTicketHeader to display ticket header
                           // table

    for (k = 0; k < acctTicketPointer->TICKET_MAX_SIZE; k++) {
      if (acctTicketPointer->tickets[k].ticketStatusFlag == 0 &&
          (acctTicketPointer->tickets[k].counterNumMessages >= 1)) {
        displayTicketRecord(&acctTicketPointer->tickets[k]);
      }

    } // end of for loop to display new tickets

    printf("------ ----- --------------- ------ ------------------------------ "
           "--------\n");

    // after displaying data prompt user to new ticket menu only quits when user
    // enters 0

    printf("\n");

    printf("Enter the ticket number to view the messages or\n");
    printf("0 to return to previous menu: ");

    uTicketNumber = getInteger();

    // returned value is validated by getInteger function

    if (uTicketNumber == 0) {

      terminate = 1;

    } else {
      for (k = 0; k < acctTicketPointer->TICKET_MAX_SIZE && flag != 1;
           ++k) // display messages if user account input is the same as the
                // closed ticket listed
      {
        if (acctTicketPointer->tickets[k].ticketStatusFlag == 0 &&
            (acctTicketPointer->tickets[k].counterNumMessages >= 1)) {
          if (acctTicketPointer->tickets[k].ticketNum == uTicketNumber &&
              uTicketNumber > 0) {
            flag = 1;
            ticketIndex = k;

          } else {
            ticketIndex = -4;
          }
        }
      }
      if (ticketIndex >=
          0) // matching ticket number was found after for loop display messages
      {
        if (acctTicketPointer->tickets[ticketIndex].ticketStatusFlag != 1) {
          strcpy(checkTicketStatus, "CLOSED");

        }

        else {

          strcpy(checkTicketStatus, "ACTIVE");
        }

        printf("\n");
        printf("==============================================================="
               "=================\n");
        printf("%06d (%-6s) Re: %s\n",
               acctTicketPointer->tickets[ticketIndex].ticketNum,
               checkTicketStatus,
               acctTicketPointer->tickets[ticketIndex].subjectLine);
        printf("==============================================================="
               "=================\n");

        for (k = 0;
             k < acctTicketPointer->tickets[ticketIndex].counterNumMessages;
             k++) {
          printf("%s (%s):\n",
                 acctTicketPointer->tickets[ticketIndex]
                             .messages[k]
                             .messageAccountType == 'A'
                     ? "AGENT"
                     : "CUSTOMER",
                 acctTicketPointer->tickets[ticketIndex]
                     .messages[k]
                     .messageDisplayName);

          printf("   %s\n\n", acctTicketPointer->tickets[ticketIndex]
                                  .messages[k]
                                  .messageDetails);
        }

        pauseExecution();

      } // end of outer if
      else {
        printf("\n");
        printf("ERROR: Invalid ticket number.\n"); // invalid user input because
                                                   // does not match any ticket
                                                   // number that was passed to
                                                   // the function
        printf("\n");

        pauseExecution();

      } // end of inner else

    } // end of outer else
  } while (terminate != 1);
} // end of getClosedTicketsMenu function
