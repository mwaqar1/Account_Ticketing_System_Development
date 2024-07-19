#include "accountTicketingUI.h"
#include "commonHelpers.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LEN 2000

/**
 * @brief
 *
 * @param accounts is an array of accounts to be filled from the input file.
 * @param nAccounts is the size of the array.
 * @return int is the number of accounts read from the file.
 */
int loadAccounts(struct Account *accounts, int nAccounts) {
  int nAccountsRead = 0;
  char line[MAX_LINE_LEN];
  const char delimiters[3] = "~\n";
  char *token;
  FILE *fp;

#if 0  /* Allocate dymamic memory */
    /* Check if accounts array is pre-allocated. */
    if (accounts != NULL)
    {
      debug_print("Error: Accounts structure not empty.");
      return 0;
    }

    /* Allocate dynamic memory for accounts array. */
    accounts = (struct Account*)malloc(nAccounts * sizeof(struct Account));
    
    /* Check if memory was allocated successfully. */
    if (accounts == NULL)
    {
      debug_print("Error: Unable to allocate memory for accounts.");
      return 0;
    }
#endif /* Allocate dymamic memory */

  /* Open the accounts.txt file. */
  fp = fopen("accounts.txt", "r");

  if (fp == NULL) {
    debug_print("Error: Unable to load accounts.txt file.\n");
    return 0;
  }

  /* File opened successfully. */

  /* Now read each row and extract the individual fields. */
  while (!feof(fp)) {
    if (fgets(line, MAX_LINE_LEN, fp) == NULL) {
      break;
    }

    debug_print("[%d] %s", nAccountsRead + 1, line);

    /* Get first token from the line, that is, uAccountNo */
    token = strtok(line, delimiters);
    /* First convert token into an integer. Then, fill in uAccountNo */
    accounts[nAccountsRead].uAccountNo = atoi(token);

    /* Get second token from the line, that is, uAccountType */
    token = strtok(NULL, delimiters);
    /* Fill in uAccountType */
    if (token[0] == 'C') {
      accounts[nAccountsRead].uAccountType = 'C';
    } else if (token[0] == 'A') {
      accounts[nAccountsRead].uAccountType = 'A';
    }

    /* Get third token from the line, that is, persons's fullname */
    token = strtok(NULL, delimiters);
    /* Fill in persons's full name */
    strcpy(accounts[nAccountsRead].person.fullName, token);

    /* Get fourth token from the line, that is, persons's birth year */
    token = strtok(NULL, delimiters);
    /* First convert token into an integer. Then, fill in person's birth year */
    int tmpYear = atoi(token);
    accounts[nAccountsRead].person.birthYear = tmpYear;

    /* Get fifth token from the line, that is, persons's house income */
    token = strtok(NULL, delimiters);
    /* First convert token into an integer. Then, fill in person's house income
     */
    double tmpIncome = atof(token);
    accounts[nAccountsRead].person.houseIncome = tmpIncome;

    /* Get 6th token from the line, that is, persons's country */
    token = strtok(NULL, delimiters);
    /* Fill in persons's country */
    strcpy(accounts[nAccountsRead].person.customerCountry, token);

    /* If the customer type was agent, then extract two more tokens. */
    if (accounts[nAccountsRead].uAccountType == 'A') {
      /* Get 7th token from the line, that is, persons's login name */
      token = strtok(NULL, delimiters);
      /* Fill in persons's login name */
      strcpy(accounts[nAccountsRead].login.userLogName, token);

      /* Get 8th token from the line, that is, persons's password */
      token = strtok(NULL, delimiters);
      /* Fill in persons's password */
      strcpy(accounts[nAccountsRead].login.userPassw, token);
    }

    /* Flush remaining tokens, if any. */
    while (token != NULL) {
      token = strtok(NULL, delimiters);
    }

    /* Increment number of accounts read. */
    nAccountsRead++;

    if (nAccounts == nAccountsRead) {
      break;
    }
  }

  return nAccountsRead;
}

/**
 * @brief
 *
 * @param tickets is the array of tickets to be filled from the input file.
 * @param nTickets is the size of the array.
 * @return int is the number of tickets read from the file.
 */
int loadTickets(struct Ticket *tickets, int nTickets) {
  int nTicketsRead = 0;
  char line[MAX_LINE_LEN];
  const char delimiters[3] = "|\n";
  char *token;
  FILE *fp;

#if 0  /* Allocate dymamic memory */
    /* Check if tickets array is pre-allocated. */
    if (tickets != NULL)
    {
      debug_print("Error: tickets structure not empty.");
      return 0;
    }

    /* Allocate dynamic memory for tickets array. */
    tickets = (struct Ticket*)malloc(nTicket * sizeof(struct Ticket));
    
    /* Check if memory was allocated successfully. */
    if (tickets == NULL)
    {
      debug_print("Error: Unable to allocate memory for tickets.");
      return 0;
    }
#endif /* Allocate dymamic memory */

  /* Open the tickets.txt file. */
  fp = fopen("tickets.txt", "r");

  if (fp == NULL) {
    debug_print("Error: Unable to load tickets.txt file.\n");
    return 0;
  }

  /* File opened successfully. */

  /* Now read each row and extract the individual fields. */
  while (!feof(fp)) {
    if (fgets(line, MAX_LINE_LEN, fp) == NULL) {
      break;
    }

    debug_print("[%d] %s", nTicketsRead + 1, line);

    /* Get 1st token from the line, that is, ticketNum */
    token = strtok(line, delimiters);
    /* First convert token into an integer. Then, fill in uAccountNo */
    int tmpTicketNum = atoi(token);
    tickets[nTicketsRead].ticketNum = tmpTicketNum;

    /* Get 2nd token from the line, that is, customerAccountNum */
    token = strtok(NULL, delimiters);
    /* First convert token into an integer. Then, fill in customerAccountNum */
    int tmpCustomerAccountNum = atoi(token);
    tickets[nTicketsRead].customerAccountNum = tmpCustomerAccountNum;

    /* Get 3rd token from the line, that is, ticketStatusFlag */
    token = strtok(NULL, delimiters);
    /* First convert token into an integer. Then, fill in ticketStatusFlag */
    int tmpTicketStatusFlag = atoi(token);
    tickets[nTicketsRead].ticketStatusFlag = tmpTicketStatusFlag;

    /* Get 4th token from the line, that is, subjectLine */
    token = strtok(NULL, delimiters);
    /* Fill in subjectLine */
    strcpy(tickets[nTicketsRead].subjectLine, token);

    /* Get 5th token from the line, that is, counterNumMessages */
    token = strtok(NULL, delimiters);
    /* First convert token into an integer. Then, fill in counterNumMessages */
    int tmpCounterNumMessages = atoi(token);
    tickets[nTicketsRead].counterNumMessages = tmpCounterNumMessages;

    int i = 0;
    /* Fill in the message structure */
    while (i < tmpCounterNumMessages) {
      /* Get messageAccountType */
      token = strtok(NULL, delimiters);
      tickets[nTicketsRead].messages[i].messageAccountType = token[0];

      /* Get messageDisplayName */
      token = strtok(NULL, delimiters);
      strcpy(tickets[nTicketsRead].messages[i].messageDisplayName, token);

      /* Get messageDetails */
      token = strtok(NULL, delimiters);
      strcpy(tickets[nTicketsRead].messages[i].messageDetails, token);

      /* Increment i to index next message. */
      i++;
    }

    /* Flush remaining tokens, if any. */
    while (token != NULL) {
      token = strtok(NULL, delimiters);
    }

    /* Increment number of accounts read. */
    nTicketsRead++;

    if (nTickets == nTicketsRead) {
      break;
    }
  }

  return nTicketsRead;
}

#define _CRT_SECURE_NO_WARNINGS

void displayAccountDetailHeader(void) // a1m3
{
  printf("Acct# Acct.Type Full Name       Birth Income      Country    Login   "
         "   Password\n");
  printf("----- --------- --------------- ----- ----------- ---------- "
         "---------- --------\n");
}

void displayAccountDetailRecord(
    const struct Account *displayAccountPointer) // a1m3
{
  // Declare function variables
  char tempPassw[9] = {0}; // temp password string
  int i = 100;
  int j = 100;
  int countTempPasswChar =
      0; // count of characters in temp password without the null character

  // 1. copy temp password string element by element to
  // tempDisplayAccountPointer->login.userPassw
  for (i = 0; displayAccountPointer->login.userPassw[i] != '\0';
       i++) // displayAccountPointer->login.userPassw=
            // (*displayPointer).login.user
  {
    tempPassw[i] = displayAccountPointer->login.userPassw[i];
    countTempPasswChar++;
  }

  // 2. display password to print * for every other letter
  for (j = 0; j < countTempPasswChar; j++) {
    if (j % 2 != 0) {
      tempPassw[j] =
          '*'; // replace with * only when index no j is not even i.e j is odd
      // ex. need * in elements 1, 3 etc....for temp password string
    }
  }

  tempPassw[j] =
      '\0'; // adds null character at the end of temp password after changing

  if (displayAccountPointer->uAccountType == 'A') {

    printf("%05d ", displayAccountPointer->uAccountNo);
    printf("%-9s ",
           displayAccountPointer->uAccountType == 'A' ? "AGENT" : "CUSTOMER");
    printf("%-15s ", displayAccountPointer->person.fullName);
    printf("%5d ", displayAccountPointer->person.birthYear);
    printf("%11.2lf ", displayAccountPointer->person.houseIncome);
    printf("%-10s ", displayAccountPointer->person.customerCountry);
    printf("%-10s ", displayAccountPointer->login.userLogName);
    printf("%8s\n", tempPassw); // UPDATE a1m3

  }

  else {

    printf("%05d ", displayAccountPointer->uAccountNo);
    printf("%-9s ",
           displayAccountPointer->uAccountType == 'A' ? "AGENT" : "CUSTOMER");
    printf("%-15s ", displayAccountPointer->person.fullName);
    printf("%5d ", displayAccountPointer->person.birthYear);
    printf("%11.2lf ", displayAccountPointer->person.houseIncome);
    printf("%-10s\n ", displayAccountPointer->person.customerCountry);
  }

} // end of displayAccountDetailRecord

void displayAllAccountDetailRecords(const struct Account accountsArray[],
                                    int maxSizeAccountsArray) {

  int i = 100;

  displayAccountDetailHeader();

  for (i = 0; i < maxSizeAccountsArray; i++) {
    if (accountsArray[i].uAccountNo > 0) {

      displayAccountDetailRecord(&accountsArray[i]);
    }
  }

} // end of displayAllAccountDetailRecords
void displayTicketHeader(void) {
  printf("------ ----- --------------- ------ ------------------------------ "
         "--------\n");
  printf("Ticket Acct# Full Name       Status Subject                        "
         "Messages\n");
  printf("------ ----- --------------- ------ ------------------------------ "
         "--------\n");

} // end displayTicketHeader

void displayTicketRecord(const struct Ticket *ticketPointer) {

  char checkTicketStatus[10] = {0};

  if (ticketPointer->ticketStatusFlag != 1) {
    strcpy(checkTicketStatus, "CLOSED");

  }

  else {
    strcpy(checkTicketStatus, "ACTIVE");
  }

  printf("%06d %-5d %-15s %-6s %-30s %5d\n", ticketPointer->ticketNum,
         ticketPointer->customerAccountNum,
         ticketPointer->messages->messageDisplayName, checkTicketStatus,
         ticketPointer->subjectLine, ticketPointer->counterNumMessages);

} // end of displayTicketRecord

// void applicationStartup(struct Account accountsArray[], int maxSizeAccounts)
// //previous: a1m4

int moreLoginValidation(const struct Account arrayAccounts[],
                        int maxAccountsArray) {

  int attempt = 3;
  int returnedFindAcct = -500;
  char attemptLogName[100] = {0};
  char attemptPass[100] = {0};
  int flag = 0;
  int returnLoginValid = -5;
  int returnedAccountNo = 0;
  int askAccountNo = 0;

  do {

    attempt--;

    // 1. ask and scan for account No.

    printf("\n");
    printf("Enter the account#: ");
    returnedAccountNo = getPositiveInteger(); // promt user and validate input
                                              // is positive integer
    // store returned positive int value in userAccount

    returnedFindAcct = findAccountIndexByAcctNum(
        returnedAccountNo, arrayAccounts, maxAccountsArray,
        askAccountNo); // PREVIOUS  a1m4
    // returnedFindAcct=findAccountIndexByAcctNum(accountNum,acctTicketPointer->accounts,
    // acctTicketPointer->ACCOUNT_MAX_SIZE, askAccountNo);  //a2m1 UPDATE***!!!

    printf("User Login        : ");
    getCString(attemptLogName, 0, 100);

    printf("Password          : ");
    getCString(attemptPass, 0, 100);

    if (returnedFindAcct != -1) // returnedFindAcct not equal to -1, therefore,
                                // matching account no was FOUND
    {

      if (strcmp(attemptLogName,
                 arrayAccounts[returnedFindAcct].login.userLogName) == 0 &&
          strcmp(attemptPass,
                 arrayAccounts[returnedFindAcct].login.userPassw) == 0) {
        flag = 1; // valid login attempt break out of do while loop early
        returnLoginValid = returnedFindAcct;

      } else {

        flag = 0;
      }

    } // end of inner else
    else // invalid account number
    {
      flag = 0;

    } // end of outer else

    if (flag == 0) {

      printf(
          "INVALID user login/password combination! [attempts remaining:%d]\n",
          attempt);
      printf("\n");
    }

  } while (attempt > 0 && flag != 1);

  if (attempt <= 0) // 3 or more failed attempts
  {

    printf("ERROR:  Access Denied\n");
    printf("\n");
    returnLoginValid = -5;
  }

  return returnLoginValid;

} // end of loginValidation function

void applicationStartup(
    struct AccountTicketingData *acctTicketPointer) // a2m1 UPDATE**!!
{
  // declare function variables

  int returnedMenuLogin = -500; // test CHANGE after fixing MenuLogin
  int terminate = 0;

  do {

    returnedMenuLogin =
        menuLogin(acctTicketPointer->accounts,
                  acctTicketPointer->ACCOUNT_MAX_SIZE); // call menuLogin

    if (returnedMenuLogin == -1) // user wants to exit, terminate program
    {
      terminate = 1; // to exit do while loop

    } else // returnedMenuLogin contains the index number of the account array
           // for the user that is logged in
    {
      // Using the returned index number, you should check the logged in user
      // account type

      if (acctTicketPointer->accounts[returnedMenuLogin].uAccountType == 'A') {
        // If the logged in user is an "agent" account type, load the agent main
        // menu by calling the
        // function "menuAgent"

        printf("\n");

        menuAgent(acctTicketPointer,
                  &acctTicketPointer->accounts[returnedMenuLogin]);

      } else // logged in user account i.e.
             // accountsArray[returnedMenuLogin].uAccountType is NOT an agent
             // type
      {
        // printf("ERROR:  login failed!\n");      //only an agent type account
        // can login printf ("\n");  //any other login attempt gets an error
        // message
        pauseExecution();
      }
    }

  } while (terminate != 1);

  // terminate=1 after exiting do while loop so print out exit prompt and then
  // terminate the program

  printf("\n");
  printf("==============================================\n");
  printf("Account Ticketing System - Terminated\n");
  printf("==============================================");

} // end of application function

int findAccountIndexByAcctNum(int userAccountNo,
                              const struct Account constAccounts[],
                              int max_constAccounts, int askAccountNo) {
  // Declare local function variables

  int flag = 0;
  int flag2 = 0;
  int returnedAccountNo = -5;
  int finalReturn2 = 0;
  int i = 100;
  int j = 100;

  switch (askAccountNo) {
  case 0: //  means no we don't need to ask user to enter an account number
  {
    for (i = 0; i < max_constAccounts && flag != 1;
         i++) // loop continues when i becomes greater than max size of
              // arrayAccounts or if user enters valid account no and flag sets
              // to 1
    {
      if (userAccountNo ==
          constAccounts[i]
              .uAccountNo) // checks to see if userAccountno matches any of the
                           // uAccountNo's in the const Accounts array that was
                           // passed to the function
      {
        flag = 1; // matching accountno found, exit for loop and do while loop
      } else {
        flag = 0; // matching account  not found
      }
    } // end of for loop
    if (flag != 1) // flag2 not 1, userAccountno is invalid
    {
      // printf("ERROR:  Login failed!\n"); //invalid user intger input because
      // does not match any account number that was passed to the function
      // printf("\n");
      finalReturn2 = -1;
    }

    else // if flag2 ==1 and userAccountno is matched
    {
      // matched account found therefore can exit the function
      finalReturn2 = i - 1; // final return set to equal value of i which stores
                            // the element no where arrayAccounts[i].uAccountNo
                            // matched userAccountno user input
    }

    break;
  } // end of case 0 and exit switch

  case 1: // askAccountNo is a non zero value, therefore, yes, we do need to
          // prompt user to input an account number
  {
    printf("\n");
    printf("Enter the account#: ");
    returnedAccountNo = getPositiveInteger(); // promt user and validate input
                                              // is positive integer
    // store returned positive int value in userAccountno

    // check whether account no matches const struct Account constAccounts[]
    // array The function should return either -1 (no record match found) or the
    // index position where the matched record was found within the argument 2
    // array.

    for (j = 0; j < max_constAccounts && flag2 != 1;
         j++) // loop continues when i becomes greater than max size of
              // arrayAccounts or if user enters valid account no and flag sets
              // to 1
    {
      if (returnedAccountNo ==
          constAccounts[j]
              .uAccountNo) // checks to see if userAccountno matches any of the
                           // uAccountNo's in the Accounts array that was passed
                           // to the function
      {
        flag2 = 1; // matching accountno found, exit for loop and do while loop

      } else {
        flag2 = 0; // matching account no not found
      }

    } // end of for loop

    // after the search, check the flag status and determine whether the user
    // entered a matching account type
    if (flag2 != 1) // flag2 not 1, userAccountno is invalid
    {
      // printf("ERROR:  Login failed!\n"); //invalid user intger input because
      // does not match any account number that was passed to the function
      printf("\n");
      finalReturn2 = -1;
    } else // if flag2 ==1 and userAccountno is matched
    {
      // matched account found therefore can exit the function
      finalReturn2 = j - 1; // final return set to equal value of i which stores
                            // the element no where arrayAccounts[i].uAccountNo
                            // matched userAccountno user input
    }

    break;
  } // end case 1 and exit switch statement

  } // end of switch statement

  return finalReturn2;

} // end of findAccountIndexByAcctNum function

int findIndexByTicketNum(int userTicketNumber,
                         const struct AccountTicketingData *acctTicketPointer) {

  // Declare local function variables

  int returnInt = -7;
  int flag = 0;
  int flag2 = 0;
  int returnTicketIndex = -5;
  int i = 100;

  for (i = 0; i < acctTicketPointer->ACCOUNT_MAX_SIZE && flag != 1;
       ++i) // loop continues when i becomes greater than max size of
            // AccountTicketingData data array or if user enters valid ticket
            // number and flag sets to 1
  {
    if (userTicketNumber == acctTicketPointer->tickets[i].ticketNum) {
      flag = 1; // matching ticket number found, exit for loop and do while loop
    } else {
      flag = 0; // matching ticket number not found
    }
  } // end of for loop

  // after the search, check the flag status and determine whether the user
  // entered a matching account type
  if (flag != 1) // flag2 not 1, userTicketNumber is invalid
  {
    printf(
        "ERROR: Invalid ticket number.\n"); // invalid user input because does
                                            // not match any ticket number that
                                            // was passed to the function
    printf("\n");
    returnTicketIndex = -1;
  } else // if flag2 ==1 and userTicketNumber is matched
  {
    // matched account found therefore can exit the function
    returnTicketIndex =
        i - 1; // returnTicketNumberCheck set to equal value of i-1 which stores
               // the element no where acctTicketPointer->tickets[i].ticketNum
               // matched userTicketNumber user input
  }

  return returnTicketIndex;

} // end findIndexByTicketNum
// UPDATE a2m2 !!!
int addNewMessage(struct AccountTicketingData *acctTicketPointer,
                  int returnedTicketIndex) {

  int indexMessage = -5;

  indexMessage =
      acctTicketPointer->tickets[returnedTicketIndex]
          .counterNumMessages; // index for the message number is the same as
                               // the current count of the message

  printf("Enter the ticket message details (150 chars. maximum). Press the "
         "ENTER key to submit:\n");

  getCString(acctTicketPointer->tickets[returnedTicketIndex]
                 .messages[indexMessage]
                 .messageDetails,
             0, 151);
  printf("\n");

  // after message is added, increase the count of the message by 1
  acctTicketPointer->tickets[returnedTicketIndex].counterNumMessages++;

  return indexMessage;

} // end of addNewMessage function

int menuLogin(const struct Account arrayAccounts[], int maxAccountsArray) {
  // Declare local function variables

  int min = 0;
  int max = 1;
  int validgetIntRange; // store validIntFromRange
  const char constgetChar[] = {"yYnN"};
  int terminate = 0;
  int finalReturn = -500;
  int returnLoginValid = -5;
  char validgetChar = 'x';

  do {
    // Prompt user to pick a selection
    printf("==============================================\n");
    printf("Account Ticketing System - Login\n");
    printf("==============================================\n");
    printf("1) Login to the system\n");
    printf("0) Exit application\n");
    printf("----------------------------------------------\n");
    printf("\n");
    printf("Selection: ");

    validgetIntRange =
        getIntFromRange(min, max); // call getIntFromRange function to check if
                                   // valid int and is within 0 and 1 range
    // store return value in validgetIntRange
    // check user input
    switch (validgetIntRange) {
    case 0: {
      printf("\n");
      printf("Are you sure you want to exit? ([Y]es|[N]o): ");
      validgetChar = getCharOption(
          constgetChar); // call getCharOption to make sure user input includes
                         // has one constgetChar[] character
      // store return value in validgetChar

      if (validgetChar == 'Y' || validgetChar == 'y') {
        terminate = 1;
        finalReturn =
            -1; // user entered Y or y meaning exit selection was successful
                // therefore finalReturn value is -1 indicating valid early exit
      } else {

        terminate = 0; // when user enter N or n repeat print and promt process
                       // from the beginning
      }

      break;
    } // end of case 0

    case 1: {
      // call  moreLoginValidation to validate accout no, login name and
      // password login more strictly

      returnLoginValid = moreLoginValidation(arrayAccounts, maxAccountsArray);

      if (finalReturn == -1) // moreLoginValidation was invalid
      {
        // printf("ERROR:  Login failed!\n"); //invalid user intger input
        // because does not match any account number that was passed to the
        // function printf("\n");
        terminate = 0; // continue do while loop
        pauseExecution();

      } else // if finalReturn==1 and moreLoginValidations are  valid
      {
        terminate = 1; // matched account found therefore can exit the function
        finalReturn = returnLoginValid;
      }

      // printf("finalReturn=%d\n", finalReturn); //COMMENT out
      break; // break out of case 1  right after do while loop when valid
             // account no is entered
    } // end case 1
    } // end of switch

  } while (terminate != 1); // repeat until either the user selects 0 and wishes
                            // to exit the application
  // or the entered account number matched to an account in the account array.

  // selection based on whether validIntRange is 0 0r 1

  return finalReturn; // returns valid_i integer which stores the element number
                      // where arrayAccounts[i].uAccountNo matched userAccountno
                      // user input or -1 indicating user selected  0 and exited
                      // early

} // end of menuLogin function

void menuAgent(
    struct AccountTicketingData *acctTicketPointer,
    const struct Account *validAgentAccount) // MODIFIED a2m1 *****!!!
{
  // Declare local Function Variables
  int returnedIntRange = 0;
  int min = 0;
  int max = 9;
  int quitmenu = 0;
  int i = 100;

  int askAccountNo = -4;
  int returnedFindAcct = -500;
  int accountNum = 0;
  const char constgetChar[] = {"YN"};
  char validgetChar = 'x'; // declare to set to safe space

  const char aorC[] = {"AC"};
  int j = 100;
  int k = 100;
  int largestAccountNo = -5;
  int tempValidAccountNo = -5;
  int removeTicket = 0;
  int element = -1;

  struct Ticket nullTicketStruct[50] = {0};

  int returnedAccountNo = -500;
  int returnInt = -7;
  int flag2 = 0;
  int ticketIndex = -5;
  char validgetChar2 = 'x';
  int largestTicektNo = 0;
  int userTicketNumber = -5;
  int returnedTicketIndex = -5;
  int returnedTicketNo = -5;
  int exitMenu2 = 0;
  int flag4 = 0;
  int select = -5;

  int const maxMessageSize = 20;
  int indexMessage = -5;

  do {

    removeTicket = 0;

    printf("AGENT: %s (%d)\n", validAgentAccount->person.fullName,
           validAgentAccount->uAccountNo);
    printf("==============================================\n");
    printf("Account Ticketing System - Agent Menu\n");
    printf("==============================================\n");
    printf("1) Add a new account\n");
    printf("2) Modify an existing account\n");
    printf("3) Remove an account\n");
    printf("4) List accounts: detailed view\n");
    printf("----------------------------------------------\n");
    printf("5) List new tickets\n");
    printf("6) List active tickets\n");
    printf("7) List closed tickets\n");
    printf("8) Add a new ticket\n");
    printf("9) Manage a ticket\n");
    printf("----------------------------------------------\n");
    printf("0) Logout\n");
    printf("\n");

    printf("Selection: "); // prompt user for selection

    returnedIntRange = getIntFromRange(
        min,
        max); // ask for and make sure user inputs a valid menu item selection
    // store valid returned selection in returnedIntRange

    switch (returnedIntRange) // implement program based on the value of user
                              // menu selection stored in returnedIntRange
    {
    case 0: // exit menuAgent function and return to the login menu
    {
      printf("\n");
      printf("### LOGGED OUT ###\n");
      quitmenu = 1;

      // Save accounts and tickets files.
      printf("Saving session modifications...\n");
      printf("   %d account(s) saved.\n",
             saveAccounts(acctTicketPointer->accounts,
                          acctTicketPointer->ACCOUNT_MAX_SIZE));
      printf("   %d tickets(s) saved.\n",
             saveTickets(acctTicketPointer->tickets,
                         acctTicketPointer->TICKET_MAX_SIZE));
      break;
    }

      // Case 1: use the findAccountIndexByAcctNum function to find the index no
      // of our current account
      // which was passed to this function via validAgentAccount pointer that
      // stores the logged-in agent's account details

    case 1: {
      askAccountNo = 0; // set to 0 b/c we don't need to prompt the user for the
                        // account number
      accountNum = 0; // set account number to 0 to find the index number which
                      // has empty space(at account number 0)

      // returnedFindAcct holds the array index of the Account that matches the
      // desired account number or -1 if the record was not found.

      // returnedFindAcct=findAccountIndexByAcctNum(accountNum,accountsArray,
      // maxSizeAccountsArray, askAccountNo);   PREVIOUS

      returnedFindAcct =
          findAccountIndexByAcctNum(accountNum, acctTicketPointer->accounts,
                                    acctTicketPointer->ACCOUNT_MAX_SIZE,
                                    askAccountNo); // a2m1 UPDATE***!!!

      if (returnedFindAcct !=
          -1) // returnedFindAcct not equal to -1, therefore, matching accountno
              // 0 or i.e. empty account was found
      {       // and index value of the account is returned

        // Modification for a2m1: Find the largest account number in an array
        // and assign that value+1 to the array

        for (j = 0; j < acctTicketPointer->ACCOUNT_MAX_SIZE; j++) {
          if (acctTicketPointer->accounts[j].uAccountNo >
              largestAccountNo) // if acctTicketPointer[j]->uAccountNo is
                                // greater than largestAccountNo
          {
            largestAccountNo =
                acctTicketPointer->accounts[j]
                    .uAccountNo; // set largestAccountNo to hold the value of
                                 // acctTicketPointer[j]->uAccountNo
          }
        }
        // after exiting the for loop and finding the largestAccountNo, set it
        // as the value of acctTicketPointer[j]->uAccountNo +1
        largestAccountNo += 1;

        acctTicketPointer->accounts[returnedFindAcct].uAccountNo =
            largestAccountNo;

        printf("\n");
        printf("New Account Data (Account#:%d)\n",
               acctTicketPointer->accounts[returnedFindAcct].uAccountNo);
        printf("----------------------------------------\n");

        // getAccount(&acctTicketPointer->accounts[returnedFindAcct]); // call
        // getAccount function to prompt and let user add new account details
        // PREVIOUS A1m4
        // getAccount(&acctTicketPointer->accounts[returnedFindAcct]); //UPDATED
        // a2m1

        getNewAccount(&acctTicketPointer
                           ->accounts[returnedFindAcct]); // UPDATED final a2m1

      } else // returnedFindAcct=-1, therefore no matching accounts with account
             // number 0 i.e empty accounts were found
      {
        printf("\n");
        printf("ERROR: Account listing is FULL, call ITS Support!\n");
        printf("\n");
        pauseExecution();
      }

      break;
    } // end of case 1

    case 2: {
      askAccountNo = 1; // prompt the user to enter account number when calling
                        // findAccountIndexByAcctNum Function
      accountNum =
          0; // findAccountIndexByAcctNum will not use this value as
             // askAccountNo is set to 1, just setting it to a safe empty space

      returnedFindAcct =
          findAccountIndexByAcctNum(accountNum, acctTicketPointer->accounts,
                                    acctTicketPointer->ACCOUNT_MAX_SIZE,
                                    askAccountNo); // a2m1 UPDATE***!!!

      if (returnedFindAcct != -1) // returnedFindAcct not equal to -1,
                                  // therefore, matching accountno WAS found
      {                           // and index value of the account is returned

        updateAccount(
            &acctTicketPointer
                 ->accounts[returnedFindAcct]); // call updateAccountAccount
                                                // function to prompt and let
                                                // user add new account details

      } else // returnedFindAcct is equal to -1, therefore matching account not
             // found
      {
        printf("ERROR: Account not found\n");
      }

      break;
    } // end of case 2

    case 3: {

      accountNum =
          0; // findAccountIndexByAcctNum will not use this value as
             // askAccountNo is set to 1, just setting it to a safe empty space

      askAccountNo = 1; // prompt the user to enter account number when calling
                        // findAccountIndexByAcctNum Function

      // returnedFindAcct=findAccountIndexByAcctNum(accountNum,accountsArray,
      // maxSizeAccountsArray, askAccountNo);   PREVIOUS
      returnedFindAcct =
          findAccountIndexByAcctNum(accountNum, acctTicketPointer->accounts,
                                    acctTicketPointer->ACCOUNT_MAX_SIZE,
                                    askAccountNo); // a2m1 UPDATE***!!!

      // If the account number entered is the same as the logged-in user's
      // account, you
      // must deny the removal (see sample output for appropriate message)

      if (returnedFindAcct <
          0) // means account was not found i.e. returnedFindAcct=-1
      {

        printf("ERROR: Account not found\n");

      } else // means account was found and returnedFindAcct is greater than or
             // equal to 0
      {

        // if(accountsArray[returnedFindAcct].uAccountNo!=validAgentAccount->uAccountNo)
        // //if acount num entered is not the same as current account /PREVIOUs
        // A1m4

        if (acctTicketPointer->accounts[returnedFindAcct].uAccountNo !=
            validAgentAccount->uAccountNo) // if acount num entered is not the
                                           // same as current account
        {

          displayAccountDetailHeader();
          // displayAccountDetailRecord(&accountsArray[returnedFindAcct]);
          // previous a1m4
          displayAccountDetailRecord(
              &acctTicketPointer->accounts[returnedFindAcct]); // updated a2m1

          printf("\n");
          printf("Are you sure you want to remove this record? ([Y]es|[N]o): ");

          validgetChar = getCharOption(
              constgetChar); // call getCharOption to make sure user input has
                             // one constgetChar[] character store return value
                             // in validgetChar

          if (validgetChar == 'Y') // user confirms account removal
          {

            // Update a2m2 also remove all tickets associated with the account
            // number

            // Removal of an account should also remove any tickets (set to a
            // safe empty state) that are associated with the account The result
            // message should be updated to include the number of tickets
            // removed

            tempValidAccountNo =
                acctTicketPointer->accounts[returnedFindAcct].uAccountNo;

            /* Delete the account. */
            strcpy(
                acctTicketPointer->accounts[returnedFindAcct].login.userLogName,
                "");
            // acctTicketPointer->accounts[returnedFindAcct].person.birthYear =
            // 0;
            strcpy(acctTicketPointer->accounts[returnedFindAcct]
                       .person.customerCountry,
                   "");
            strcpy(
                acctTicketPointer->accounts[returnedFindAcct].person.fullName,
                "");
            acctTicketPointer->accounts[returnedFindAcct].person.houseIncome =
                0;
            acctTicketPointer->accounts[returnedFindAcct].uAccountNo = 0;
            acctTicketPointer->accounts[returnedFindAcct].uAccountType = 0;

            for (i = 0; i < acctTicketPointer->TICKET_MAX_SIZE; i++) {
              if (tempValidAccountNo ==
                  acctTicketPointer->tickets[i].customerAccountNum) {
                // TESTING
                // printf("before value of
                // acctTicketPointer->tickets[i].counterNumMessages is %d\n",
                // acctTicketPointer->tickets[i].counterNumMessages); //set all
                // tickets to 0; //set all tickets to 0 printf("before value of
                // acctTicketPointer->tickets[i].customerAccountNum is %d\n",
                // acctTicketPointer->tickets[i].customerAccountNum); //set all
                // tickets to 0; //set all tickets to 0

                //								acctTicketPointer->tickets[i]
                //= nullTicketStruct[i];

                // printf("after value of
                // acctTicketPointer->tickets[i].customerAccountNum is %d\n",
                // acctTicketPointer->tickets[i].customerAccountNum); //set all
                // tickets to 0; //set all tickets to 0
                //  printf("after value of
                //  acctTicketPointer->tickets[i].counterNumMessages is %d\n",
                //  acctTicketPointer->tickets[i].counterNumMessages); //set all
                //  tickets to 0; //set all tickets to 0

                acctTicketPointer->tickets[i].counterNumMessages = 0;
                acctTicketPointer->tickets[i].customerAccountNum = 0;
                strcpy(acctTicketPointer->tickets[i].subjectLine, "");
                acctTicketPointer->tickets[i].ticketNum = 0;
                acctTicketPointer->tickets[i].ticketStatusFlag = 2;
                removeTicket++;
              }

            } // end of for loop

            // printf("after loop value of
            // acctTicketPointer->tickets[i].customerAccountNum is %d\n",
            // acctTicketPointer->tickets[i].customerAccountNum); //set all
            // tickets to 0; //set all tickets to 0

            printf("\n");
            printf("*** Account Removed! (%d ticket(s) removed) ***\n",
                   removeTicket);
            printf("\n");
            pauseExecution();

            // accountsArray[returnedFindAcct].uAccountNo=0;//set account number
            // to 0 previous a1m4
            acctTicketPointer->accounts[returnedFindAcct].uAccountNo =
                0; // set account number to 0 Updated a2m1

          } // end of inner if

        } // end of outer if
        else { // the account number entered is the same as the logged-in user's
               // account, can't remove account

          printf("\n");
          printf("ERROR: You can't remove your own account!\n");
          printf("\n");
          pauseExecution();

        } // end of outer else

      } // end of outer else

      break;

    } // end of case 3

    case 4: {
      printf("\n");
      // displayAllAccountDetailRecords(accountsArray, maxSizeAccountsArray);
      // previous a1m4
      displayAllAccountDetailRecords(
          acctTicketPointer->accounts,
          acctTicketPointer->ACCOUNT_MAX_SIZE); // updated a2m1**!!1
      printf("\n");
      pauseExecution();

      break;
    } // end of case 4

    case 5: {
      // list new accounts

      // void getNewTicketMenu (struct AccountTicketingData* acctTicketPointer);
      // //***a2m2!!!
      getNewTicketMenu(acctTicketPointer);

      printf("\n");

      break;
    } // end of case 5

    case 6: {
      getActiveTicketsMenu(acctTicketPointer);
      printf("\n");
      // pauseExecution();

      break;
    } // end of case 6

    case 7: {
      getClosedTicketsMenu(acctTicketPointer);
      printf("\n");
      // pauseExecution();

      break;
    } // end of case 7

    case 8: {

      accountNum =
          0; // findAccountIndexByAcctNum will not use this value as
             // askAccountNo is set to 1, just setting it to a safe empty space

      askAccountNo = 1; // prompt the user to enter account number when calling
                        // findAccountIndexByAcctNum Function

      // returnedFindAcct=findAccountIndexByAcctNum(accountNum,accountsArray,
      // maxSizeAccountsArray, askAccountNo);   PREVIOUS
      returnedFindAcct =
          findAccountIndexByAcctNum(accountNum, acctTicketPointer->accounts,
                                    acctTicketPointer->ACCOUNT_MAX_SIZE,
                                    askAccountNo); // a2m1 UPDATE***!!!

      // If the account number entered is the same as the logged-in user's
      // account, you
      // must deny the removal (see sample output for appropriate message)

      if (returnedFindAcct <
          0) // means account was not found i.e. returnedFindAcct=-1
      {

        printf("ERROR: Account not found\n");

      } else // means account was found and returnedFindAcct is greater than or
             // equal to 0
      {

        // CHECK and make sure account type is customer
        if (acctTicketPointer->accounts[returnedFindAcct].uAccountType ==
            'A') // invalid if account type is agent
        {

          printf("\n");
          printf("ERROR: Agent accounts can't have tickets!\n");
          printf("\n");
          pauseExecution();

        } else // user account type entered is customer type and is valid //main
               // ticket logic entry
        {

          displayAccountDetailHeader();
          displayAccountDetailRecord(
              &acctTicketPointer->accounts[returnedFindAcct]); // updated a2m1

          printf("\n");
          printf("\n");
          printf("Add a new ticket for this customer? ([Y]es|[N]o): ");

          validgetChar2 = getCharOption(
              constgetChar); // call getCharOption to make sure user input has
                             // one constgetChar[] character

          // store return value in validgetChar

          // Validate validgetChar
          if (validgetChar2 == 'Y') // user confirms wants to create new ticket
          {                         // create a new ticket entry logic

            userTicketNumber =
                0; // set account number to 0 to find the index number which has
                   // empty space(at ticket number 0)

            for (k = 0; k < acctTicketPointer->ACCOUNT_MAX_SIZE && flag2 != 1;
                 k++) // loop continues when k becomes greater than max size of
                      // AccountTicketingData data array or if it matches
                      // userTicketNumber 0 (indicating empty) and flag sets to
                      // 1
            {

              if (userTicketNumber == acctTicketPointer->tickets[k].ticketNum) {
                flag2 = 1; // matching ticket number found, exit for loop and do
                           // while loop
              } else {
                flag2 = 0; // matching ticket number not found
              }
            } // end of for loop

            // After for loop validate if ticket number was matches 0 i.e.
            // ticket index has an empty space

            if (flag2 != 1) // userTicketNumber is not matched i.e. ticket
                            // number has no empty space
            {
              printf("\n");
              printf("ERROR: Ticket listing is FULL, call ITS Support!\n");
              // printf ("\n");
              pauseExecution();

            } else // userTicketNumber is matched i.e. ticket number has empty
                   // space and matched account found therefore can exit the
                   // function
            {
              ticketIndex = k - 1; // ticketNumberCheck set to equal value of
                                   // k-1 which stores the element no where
                                   // acctTicketPointer->tickets[i].ticketNum
                                   // matched userTicketNumber user input

              // Find the largest ticket number in an array +1 and assign it to
              // the tickes account

              for (i = 0; i < acctTicketPointer->ACCOUNT_MAX_SIZE; i++) {
                if (acctTicketPointer->tickets[i].ticketNum >
                    largestTicektNo) // if
                                     // acctTicketPointer->tickets[i].ticketNum
                                     // is greater than largestTicketNo
                {
                  largestTicektNo =
                      acctTicketPointer->tickets[i]
                          .ticketNum; // set largestTicketNo to hold the value
                                      // of
                                      // acctTicketPointer[j]->tickets[i].ticketNum
                }
              }
              // after exiting the for loop and finding the largestTicketNoNo,
              // set it as the value of
              // acctTicketPointer[i]->tickets[i].ticketNum  +1
              largestTicektNo += 1;
              acctTicketPointer->tickets[ticketIndex].ticketNum =
                  largestTicektNo;

              // display largest ticket number and header
              printf("\n");
              printf("New Ticket (Ticket:%0d)\n",
                     acctTicketPointer->tickets[ticketIndex].ticketNum);
              printf("----------------------------------------\n");

              // create new ticket

              // 1. All new tickets are immediately set to the "ACTIVE" status.

              acctTicketPointer->tickets[ticketIndex].ticketStatusFlag = 1;
              acctTicketPointer->tickets[ticketIndex].counterNumMessages = 1;

              // 2+3. prompt for ticket subject line and message details input

              printf("Enter the ticket SUBJECT (30 chars. maximum): ");

              getCString(acctTicketPointer->tickets[ticketIndex].subjectLine, 0,
                         31);

              printf("\n");

              printf("Enter the ticket message details (150 chars. maximum). "
                     "Press the ENTER key to submit:\n");

              getCString(acctTicketPointer->tickets[ticketIndex]
                             .messages->messageDetails,
                         0, 151);

              // 4. set the customer account number to be equal to the account
              // number we valididated
              acctTicketPointer->tickets[ticketIndex].customerAccountNum =
                  acctTicketPointer->accounts[returnedFindAcct].uAccountNo;

              // 5. set the accountType to Customer type to match the message
              // valid account type
              acctTicketPointer->tickets[ticketIndex]
                  .messages->messageAccountType =
                  acctTicketPointer->accounts[returnedFindAcct].uAccountType;

              // 6.  copy the name of the customer from the valid account type
              // entered above and set it to new ticket
              strncpy(
                  acctTicketPointer->tickets[ticketIndex]
                      .messages->messageDisplayName,
                  acctTicketPointer->accounts[returnedFindAcct].person.fullName,
                  31);

              printf("\n");
              printf("*** New ticket created! ***\n");
              printf("\n");

              // TESTING DELETE

              // printf("acctTicketPointer->tickets[ticketIndex].subjectLine is
              // %s\n", acctTicketPointer->tickets[ticketIndex].subjectLine);
              // TESTING DELETE
              // printf("acctTicketPointer->tickets[ticketIndex].messages->messageDetails
              // is %s\n", acctTicketPointer->tickets[ticketIndex].
              // messages->messageDetails);
              // printf("acctTicketPointer->tickets[ticketIndex is
              // %d]customerAccountNum=acctTicketPointer->accounts[returnedFindAcct].uAccountNo
              // is %d\n",
              // ticketIndex,acctTicketPointer->tickets[ticketIndex].customerAccountNum);

              // printf("
              // acctTicketPointer->tickets[ticketIndex].messages->messageAccountType=acctTicketPointer->accounts[returnedFindAcct].uAccountType
              // is %c\n",
              // acctTicketPointer->tickets[ticketIndex].messages->messageAccountType);
              // printf("
              // strncpopy(acctTicketPointer->tickets[ticketIndex].messages->messageDisplayName,
              // acctTicketPointer->accounts[returnedFindAcct].person.fullName,
              // 31) is %s\n",
              // acctTicketPointer->tickets[ticketIndex].messages->messageDisplayName);

              pauseExecution();

            } // end of inner else

          } // end of outer if

        } // end of outer else

      } // end of outmost if

      break;
    } // end of case 8

    case 9: {

      exitMenu2 = 0;

      printf("\n");
      printf("Enter ticket number: ");

      returnedTicketNo = getPositiveInteger(); // promt user and validate input
                                               // is positive integer

      returnedTicketIndex = findIndexByTicketNum(
          returnedTicketNo,
          acctTicketPointer); // index value of the ticket  number is returned

      // use do while loop until 0 is entered

      do {

        // printf("returnedTicketIndex: %d\n", returnedTicketIndex); //delete
        printf("\n");
        printf("----------------------------------------\n");
        printf("Ticket %06d - Update Options\n",
               acctTicketPointer->tickets[returnedTicketIndex].ticketNum);
        printf("----------------------------------------\n");
        printf(
            "Status  : %s\n",
            acctTicketPointer->tickets[returnedTicketIndex].ticketStatusFlag ==
                    1
                ? "ACTIVE"
                : "CLOSED");
        printf("Subject : %s\n",
               acctTicketPointer->tickets[returnedTicketIndex].subjectLine);
        printf(
            "Acct#   : %d\n",
            acctTicketPointer->tickets[returnedTicketIndex].customerAccountNum);
        printf("Customer: %s\n", acctTicketPointer->tickets[returnedTicketIndex]
                                     .messages->messageDisplayName);
        printf("----------------------------------------\n");
        printf("1) Add CUSTOMER message\n");
        printf("2) Add AGENT message\n");
        printf("3) Close ticket\n");
        printf("4) Re-activate ticket\n");
        printf("0) Done\n");
        printf("Selection: ");

        select =
            getIntFromRange(0, 4); // ask for and make sure user inputs a valid
                                   // menu item selection and store in select

        switch (select) // implement program based on the value of user menu
                        // selection stored in returnedIntRange
        {
        case 0: // exit menuAgent function and return to the login menu
        {
          printf("\n");
          exitMenu2 = 1;

          break;
        }
        case 1: {

          if (acctTicketPointer->tickets[returnedTicketIndex]
                  .ticketStatusFlag != 1) {
            printf("\n");
            printf(
                "ERROR: Ticket is closed - new messages are not permitted.\n");

          } else {
            if (acctTicketPointer->tickets[returnedTicketIndex]
                    .counterNumMessages >= maxMessageSize) {
              printf("\n");
              printf(
                  "ERROR: Message limit has been reached, call ITS Support!\n");
              printf("\n");

            } else {
              printf("\n");
              indexMessage =
                  addNewMessage(acctTicketPointer, returnedTicketIndex);

              acctTicketPointer->tickets[ticketIndex]
                  .messages[indexMessage]
                  .messageAccountType =
                  'C'; // set the message account type to customer
              strncpy(
                  acctTicketPointer->tickets[returnedTicketIndex]
                      .messages[indexMessage]
                      .messageDisplayName,
                  acctTicketPointer->accounts[returnedFindAcct].person.fullName,
                  31);
              // copy the name of the agent from the account type to the new
              // ticket

            } // end of inner else

          } // end of outer else

          break;
        } // end of case 1

        case 2: {

          if (acctTicketPointer->tickets[returnedTicketIndex]
                  .ticketStatusFlag != 1) {
            printf("\n");
            printf(
                "ERROR: Ticket is closed - new messages are not permitted.\n");

          } else {
            if (acctTicketPointer->tickets[returnedTicketIndex]
                    .counterNumMessages >= maxMessageSize) {
              printf("\n");
              printf(
                  "ERROR: Message limit has been reached, call ITS Support!\n");
              printf("\n");

            } else {
              printf("\n");
              indexMessage =
                  addNewMessage(acctTicketPointer, returnedTicketIndex);
              acctTicketPointer->tickets[ticketIndex]
                  .messages[indexMessage]
                  .messageAccountType =
                  'A'; // set the message account type to Agent
              strncpy(
                  acctTicketPointer->tickets[returnedTicketIndex]
                      .messages[indexMessage]
                      .messageDisplayName,
                  acctTicketPointer->accounts[returnedFindAcct].person.fullName,
                  31);
              // copy the name from the account to the new ticket
            } // end of inner else

          } // end of outer else

          break;
        } // end case 2
        case 3: {
          char validgetChar2 = 'x';

          if (acctTicketPointer->tickets[returnedTicketIndex]
                  .ticketStatusFlag == 1) {
            printf("\n");
            printf("Are you sure you CLOSE this ticket? ([Y]es|[N]o): ");

            validgetChar2 = getCharOption(
                constgetChar); // call getCharOption to make sure user input has
                               // one constgetChar[] character
            // store return value in validgetChar

            if (validgetChar2 == 'Y') {

              acctTicketPointer->tickets[returnedTicketIndex].ticketStatusFlag =
                  0; // set ticket status to close
              printf("\n");
              printf("*** Ticket closed! ***\n");
            }

          } else // invalid status because statusFlag ==0
          {

            printf("\n");
            printf("ERROR: Ticket is already closed!\n");
          }

          break;

        } // end case 3
        case 4: {
          char validgetChar3 = 'x';

          if (acctTicketPointer->tickets[returnedTicketIndex]
                  .ticketStatusFlag == 1) {

            printf("\n");
            printf("ERROR: Ticket is already active!\n");

          } else {

            printf("\n");
            printf("Are you sure you want to RE-ACTIVATE this closed ticket? "
                   "([Y]es|[N]o): ");

            validgetChar3 = getCharOption(
                constgetChar); // call getCharOption to make sure user input has
                               // one constgetChar[] character
            // store return value in validgetChar

            if (validgetChar3 == 'Y') {

              acctTicketPointer->tickets[returnedTicketIndex].ticketStatusFlag =
                  1; // set ticket status to open
              printf("\n");
              printf("*** Ticket re-activated! ***\n");
            }
          }

          break;
        } // end of case 4

        } // end of switch statement case 9

      } while (exitMenu2 != 1);

      break;

    } // end of case 9

    } // end of switch statement menuAgent
  } while (quitmenu != 1); // end of do while loop, only exit when user selects
                           // menu option 0 and quitMenu becomes 1
} // end of menuAgent function

int saveAccounts(struct Account *accounts, int nAccounts) {
  int nAccountsWritten = 0;
  FILE *fp;
  int i;
  /* Open the accounts.txt file. */
  fp = fopen("accounts.txt", "w+");

  if (fp == NULL) {
    debug_print("Error: Unable to create accounts.txt file.\n");
    return 0;
  }

  /* File opened successfully. */

  for (i = 0; i < nAccounts; i++) {
    if ((accounts[i].uAccountNo != 0)) {
      fprintf(fp, "%5d~", accounts[i].uAccountNo);
      fprintf(fp, "%c~", accounts[i].uAccountType);
      fprintf(fp, "%s~", accounts[i].person.fullName);
      fprintf(fp, "%d~", accounts[i].person.birthYear);
      fprintf(fp, "%0.2f~", accounts[i].person.houseIncome);
      fprintf(fp, "%s", accounts[i].person.customerCountry);

      if (accounts[i].uAccountType == 'A') {
        fprintf(fp, "%~s~", accounts[i].login.userLogName);
        fprintf(fp, "%s\n", accounts[i].login.userPassw);
      } else {
        fprintf(fp, "\n");
      }

      /* INcrement tickets written. */
      nAccountsWritten++;
    }
  }

  fclose(fp);

  return nAccountsWritten;
}

int saveTickets(struct Ticket *tickets, int nTickets) {
  int nTicketsWritten = 0;

  FILE *fp;
  int i;
  int j = 0;
  int tmpCounterNumMessages;

  /* Open the tickets.txt file. */
  fp = fopen("tickets.txt", "w+");

  if (fp == NULL) {
    debug_print("Error: Unable to create tickets.txt file.\n");
    return 0;
  }

  /* File opened successfully. */

  for (j = 0; j < nTickets; j++) {
    if (tickets[j].ticketNum != 0) {

      fprintf(fp, "%5d|", tickets[j].ticketNum);
      fprintf(fp, "%d|", tickets[j].customerAccountNum);
      fprintf(fp, "%d|", tickets[j].ticketStatusFlag);
      fprintf(fp, "%s|", tickets[j].subjectLine);
      fprintf(fp, "%d|", tickets[j].counterNumMessages);

      tmpCounterNumMessages = tickets[j].counterNumMessages;
      i = 0;

      while (i < tmpCounterNumMessages) {
        fprintf(fp, "%c|", tickets[j].messages[i].messageAccountType);
        fprintf(fp, "%s|", tickets[j].messages[i].messageDisplayName);
        fprintf(fp, "%s|", tickets[j].messages[i].messageDetails);

        /* Increment i to index next message. */
        i++;
      }

      fprintf(fp, "\n");

      /* Increment number of tickets written. */
      nTicketsWritten++;
    }
  }

  fclose(fp);

  return nTicketsWritten;
}
