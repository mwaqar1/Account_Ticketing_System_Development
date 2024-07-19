#define _CRT_SECURE_NO_WARNINGS
#include "account.h"
#include "accountTicketingUI.h"
#include "commonHelpers.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Pause execution until user enters the enter key

void pauseExecution(void) {
  printf("<< ENTER key to Continue... >>");
  clearStandardInputBuffer();
  putchar('\n');

} // end of pauseExecution function

void getAccount(struct Account *accountPointer) {
  // Declare function variables
  const char aorC[] = {"AC"};
  int i = 100;

  printf("\n");
  printf("Account Data: New Record\n");
  printf("----------------------------------------\n");

  printf("Enter the account number: "); // 1. START of ACCOUNT DATA CODE  // 2.
                                        // CALL getInteger function to verify
                                        // user input is an integer

  accountPointer->uAccountNo =
      getInteger(); // 2b) prints out error message to enter integer and returns
                    // valid integer store value under struct
                    // accountPointer->uAccountNo aka
  //(*accountPointer).uAccountNo

  printf(
      "\nEnter the account type (A=Agent | C=Customer): "); // 3.ask for
                                                            // userinput for
                                                            // agent or customer

  accountPointer->uAccountType = getCharOption(
      aorC); // 3b) CALL getCharOption function to ake user input and validate
             // whether it matches the agentorCustomer string

  if (accountPointer->uAccountType == 'A') // UPDATE a1m4
  {
    getPerson(
        &accountPointer
             ->person); // if account type is agent also call getPerson function
    getUserLogin(
        &accountPointer
             ->login); // Modify so that it will prompt the user for the User
                       // Login info ONLY IF the new account is an "Agent" type
                       // by calling the updateAccount

    printf("\n");
    printf("*** New account added! ***\n");
    printf("\n");
    pauseExecution();
  } else // user account type entered is C
  {
    for (i = 0; i < 11; i++) // If the new account is a customer type, DO NOT
                             // prompt the user for the User Login
    // set the User Login member variable to a safe empty state
    {
      accountPointer->login.userLogName[i] = 0;

      if (i < 9) {
        accountPointer->login.userPassw[i] = 0;
      }

    } // end of for loop

    getPerson(&accountPointer->person); // if account type is customer only call
                                        // getPerson function

    printf("\n");
    printf("*** New account added! ***\n");
    printf("\n");
    pauseExecution();

  } // end of else

} // end of getAccount

void getNewAccount(struct Account *accountPointer) {

  // Declare function variables
  const char aorC[] = {"AC"};
  int i = 100;

  printf(
      "Enter the account type (A=Agent | C=Customer): "); // 3.ask for userinput
                                                          // for agent or
                                                          // customer

  accountPointer->uAccountType = getCharOption(
      aorC); // 3b) CALL getCharOption function to ake user input and validate
             // whether it matches the agentorCustomer string

  if (accountPointer->uAccountType == 'A') // UPDATE a1m4
  {
    getPerson(
        &accountPointer
             ->person); // if account type is agent also call getPerson function
    getUserLogin(
        &accountPointer
             ->login); // Modify so that it will prompt the user for the User
                       // Login info ONLY IF the new account is an "Agent" type
                       // by calling the updateAccount

    printf("\n");
    printf("*** New account added! ***\n");
    printf("\n");
    pauseExecution();
  } else // user account type entered is C
  {
    for (i = 0; i < 11; i++) // If the new account is a customer type, DO NOT
                             // prompt the user for the User Login
    // set the User Login member variable to a safe empty state
    {
      accountPointer->login.userLogName[i] = 0;

      if (i < 9) {
        accountPointer->login.userPassw[i] = 0;
      }

    } // end of for loop

    getPerson(&accountPointer->person); // if account type is customer only call
                                        // getPerson function

    printf("\n");
    printf("*** New account added! ***\n");
    printf("\n");
    pauseExecution();

  } // end of else

} // end of getNewAccount

void getPerson(struct Person *personPointer) {
  // Declare function variables
  int minYear = 0;
  int maxYear = 0;
  int newCurrentYear = 0;
  int minAge = 18;
  int maxAge = 110;
  int maxChar = 30;
  int minChar = 0;
  int i = 100;

  printf("\nPerson Data Input\n");
  printf("----------------------------------------\n");

  printf("Enter the person's full name (%d chars max): ",
         maxChar); // prompt for user input

  getCString(personPointer->fullName, minChar,
             maxChar + 1); // scanf and validate user input string length is
                           // valid by calling getCString function
  // passing Person pointer personPointer->fullName array on its own which is
  // also a pointer
  //  to return via pointer and minChar and maxChar to validate againt

  newCurrentYear = currentYear(); // call currentYear to get int current year
                                  // value and store it in newCurrentYear

  minYear =
      newCurrentYear - maxAge; // calculate min and max year by subtrating it
                               // with the minumum age given by the assignment

  maxYear = newCurrentYear - minAge;

  printf("Enter birth year (current age must be between %d and %d): ", minAge,
         maxAge); // prompt for user input

  personPointer->birthYear =
      getIntFromRange(minYear, maxYear); // call getIntFromRange to ask for user
                                         // birth year input and validate
  // that it falls between the minYear and minYear ranges that we provide as
  // arguments returned value stored in personPointer->birthYear aka
  //(*personPointer).birthYear

  printf("Enter the household Income: $"); // prompt for user input

  personPointer->houseIncome =
      getPositiveDouble(); // call getPositiveDouble to prompt the user to
                           // validate two
  // things 1. user input is type double and 2. also a positive double

  printf("Enter the country (%d chars max.): ",
         maxChar); // prompt for user input

  getCString(personPointer->customerCountry, minChar,
             maxChar + 1); // scanf and validate user input string length is
                           // valid by calling getCString function
  // person.customerCountry[] is an array but its name passed down as
  // person.customerCountry is a pointer personPointer->customerCountry value is
  // returned via pointer in the function and minChar and maxChar to validate
  // againt (person.customerCountry=&person.customerCountry[0] for example
  // UPDATE a1m3
  // (*personPointer).customerCountry=&(*personPointer).customerCountry[0

  // UPDATE a2m1 ***!!!
  // Enhance the Person data input processes (when adding new or updating) so
  // that entered values for the country member are stored as all UPPERCASE
  // characters (the user should be able to enter lowercase characters and you
  // will convert it to uppercase accordingly).

  for (i = 0; i < personPointer->customerCountry[i] != '\0'; ++i) {

    personPointer->customerCountry[i] =
        toupper(personPointer->customerCountry[i]);
  }

} // end of getPerson function

void getUserLogin(struct UserLogin *loginPointer) {
  // Declare function variables

  int maxCharLogin = 10;
  int maxPasswdLogin = 8;
  int i = 100;
  int j = 100;
  int stringLength = -5;
  int whiteSpaceCount = 0;
  int flag = 0;
  int flag2 = 0;
  int countDigit = 0;
  int countUpper = 0;
  int countLower = 0;
  int countSpecial = 0;
  int passwLength = 0;

  printf("\nUser Login Data Input\n");
  printf("----------------------------------------\n");

  do {

    whiteSpaceCount = 0;

    printf("Enter user login (%d chars max): ",
           maxCharLogin); // /prompt for user input

    getCString(loginPointer->userLogName, 0,
               11); // scanf and validate user input string length is valid by
                    // calling getCString function
    // login.userLogName[] is an array but its name passed down as
    // login.userLogName is a pointer login.userLogName=&login.userLogName[0]
    // for example login.userLogName value is returned via pointer in the
    // function and minCharLog and maxCharLogin to validate againt UPDATE a1m3
    // loginPointer=&login UPDATE a1m3
    // loginPointer->userLogName=(*userLoginPointer).userLogName UPDATE a1m3
    // (*loginPointer).customerCountry=&(*loginPointer).customerCountry[0]

    // UPDATE a2m1
    // Purpose: Enhance the validation for obtaining the UserLogin identifier
    // and do NOT allow any whitespace characters (spaces and tabs etc.).
    // 1. find number of characters in string without including null terminator

    stringLength = strlen(loginPointer->userLogName);

    // 2. loop through entire string element by element (null already not
    // included b/c of strlen) and count the number of whitespaces If character
    // is a white-space character, isspace function returns a non-zero integer.
    // If NO white spaces found, 0 is returned

    for (i = 0; i <= stringLength; i++) {

      if (isspace(
              loginPointer->userLogName[i])) // check if string character using
                                             // isspace is equal to 1 aka if
                                             // character IS a white space
      {

        whiteSpaceCount++; // add 1 each time a string character has a white
                           // space
      }
    } // end of for loop

    if (whiteSpaceCount ==
        0) // after for loop, check if whiteSpaceCount is equal to 0 aka a white
           // space charcater was not found
    {
      flag = 1; // condition to break out of do while loop

    } else // whitespaces WERE found and user login input is invalid
    {

      printf(
          "ERROR:  The user login must NOT contain whitespace characters.\n");
    }

  } while (flag != 1);

  // UPDATE validation of password a2m1**!!

  do {
    int countDigit = 0; // set to safe space incase loop needs to iterate
    int countUpper = 0;
    int countLower = 0;
    int countSpecial = 0;

    printf("Enter the password (must be %d chars in length): ",
           maxPasswdLogin); // previous a1m4

    getCString(loginPointer->userPassw, 8, 8); // previous a1m4

    // UPDATE a2m1
    // 1. After getting the proper string length from getCstring function , find
    // the number of characters in string without including null terminator

    passwLength = strlen(loginPointer->userPassw);

    for (j = 0; j <= passwLength; j++) {

      if (isdigit(loginPointer->userPassw[j])) // check if string character
                                               // using isdigit is equal to 1
                                               // aka if character IS a digit
      {

        countDigit++; // add 1 each time a string character has a digit
      }
      if (isupper(loginPointer
                      ->userPassw[j])) // check if string character using
                                       // isupper is equal to 1 aka if character
                                       // IS an upper case character
      {

        countUpper++; // add 1 each time a string character has an Upper case
                      // character
      }
      if (islower(loginPointer
                      ->userPassw[j])) // check if string character using
                                       // islower is equal to 1 aka if character
                                       // IS a lower case character
      {

        countLower++; // add 1 each time a string character has a lower case
                      // character
      }

      if (loginPointer->userPassw[j] == '!' ||
          loginPointer->userPassw[j] == '@' ||
          loginPointer->userPassw[j] == '#' ||
          loginPointer->userPassw[j] == '$' ||
          loginPointer->userPassw[j] == '%' ||
          loginPointer->userPassw[j] == '^' ||
          loginPointer->userPassw[j] == '&' ||
          loginPointer->userPassw[j] == '*') {

        countSpecial++; // add 1 each time a string character has one special
                        // character
      }

    } // end of for loop

    // validate counts of different characters in user password after for loop

    if (countDigit == 2 && countUpper == 2 && countLower == 2 &&
        countSpecial == 2) {
      flag2 = 1; // password is valid  therefore set flag to 1 to break out of
                 // do while loop

    } else // password invalid print out error messages and contine do while
           // loop until flag2 is 1 and password is valid
    {
      printf("SECURITY: Password must contain 2 of each:\n");
      printf("          Digit: 0-9\n");
      printf("          UPPERCASE character\n");
      printf("          lowercase character\n");
      printf("          symbol character: !@#$%%^&*\n");
    }

  } while (flag2 != 1);

} // end of getUserLogin Function

void updateUserLogin(struct UserLogin *loginPointer) {
  int exitUserLog = 0;
  int userSelect = -5;
  int maxPasswdLogin = 8;
  int flag2 = 0;
  int j = 100;
  int countDigit = 0;
  int countUpper = 0;
  int countLower = 0;
  int countSpecial = 0;
  int passwLength = 0;

  do {

    printf("\nUser Login: %s - Update Options\n", loginPointer->userLogName);
    printf("----------------------------------------\n");
    printf("1) Password\n");
    printf("0) Done\n");
    printf("Selection: ");

    userSelect = getIntFromRange(0, 2);

    switch (userSelect) {

    case 0: {
      exitUserLog = 1;
      break;
    }
    case 1: {
      // UPDATE validation of password a2m1**!!

      do {
        countDigit = 0; // set to safe space incase loop needs to iterate
        countUpper = 0;
        countLower = 0;
        countSpecial = 0;

        printf("Enter the password (must be %d chars in length): ",
               maxPasswdLogin); // previous a1m4

        getCString(loginPointer->userPassw, 8, 8); // previous a1m4

        // UPDATE a2m1
        // 1. After getting the proper string length from getCstring function ,
        // find the number of characters in string without including null
        // terminator

        passwLength = strlen(loginPointer->userPassw);

        for (j = 0; j <= passwLength; j++) {

          if (isdigit(
                  loginPointer->userPassw[j])) // check if string character
                                               // using isdigit is equal to 1
                                               // aka if character IS a digit
          {

            countDigit++; // add 1 each time a string character has a digit
          }

          if (isupper(loginPointer->userPassw[j])) // check if string character
                                                   // using isupper is equal to
                                                   // 1 aka if character IS an
                                                   // upper case character
          {

            countUpper++; // add 1 each time a string character has an Upper
                          // case character
          }

          if (islower(loginPointer->userPassw[j])) // check if string character
                                                   // using islower is equal to
                                                   // 1 aka if character IS a
                                                   // lower case character
          {

            countLower++; // add 1 each time a string character has a lower case
                          // character
          }

          if (loginPointer->userPassw[j] == '!' ||
              loginPointer->userPassw[j] == '@' ||
              loginPointer->userPassw[j] == '#' ||
              loginPointer->userPassw[j] == '$' ||
              loginPointer->userPassw[j] == '%' ||
              loginPointer->userPassw[j] == '^' ||
              loginPointer->userPassw[j] == '&' ||
              loginPointer->userPassw[j] == '*') {
            countSpecial++; // add 1 each time a string character has one
                            // special character
          }

        } // end of for loop

        // validate counts of different characters in user password after for
        // loop

        if (countDigit == 2 && countUpper == 2 && countLower == 2 &&
            countSpecial == 2) {
          flag2 = 1; // password is valid  therefore set flag to 1 to break out
                     // of do while loop

        } else // password invalid print out error messages and contine do while
               // loop until flag2 is 1 and password is valid
        {
          printf("SECURITY: Password must contain 2 of each:\n");
          printf("          Digit: 0-9\n");
          printf("          UPPERCASE character\n");
          printf("          lowercase character\n");
          printf("          symbol character: !@#$%%^&*\n");

        } // end of else

      } while (flag2 != 1); // end of do while

      break;
    } // end  of case 1

    } // end of switch statement

  } while (exitUserLog != 1);

} // end of updateUserLogin

void updatePerson(struct Person *personPointer) {
  int exitPerson = 0;
  int userSelect = -5;
  int maxChar = 30;
  int minChar = 0;

  int i = 100;

  do {

    printf("\nPerson Update Options\n");
    printf("----------------------------------------\n");
    printf("1) Full name (current value: %s)\n", personPointer->fullName);
    printf("2) Household Income (current value: $%.2lf)\n",
           personPointer->houseIncome);
    printf("3) Country (current value: %s)\n", personPointer->customerCountry);
    printf("0) Done\n");
    printf("Selection: ");

    userSelect = getIntFromRange(0, 3);

    switch (userSelect) {
    case 1: {
      printf("\n");
      printf("Enter the person's full name (%d chars max): ",
             maxChar); // prompt for user input

      getCString(personPointer->fullName, minChar,
                 maxChar + 1); // scanf and validate user input string length is
                               // valid by calling getCString function
      // passing Person pointer personPointer->fullName array on its own which
      // is also a pointer
      //  to return via pointer and minChar and maxChar to validate againt
      break;
    }
    case 2: {
      printf("\n");
      printf("Enter the household Income: $"); // prompt for user input
      personPointer->houseIncome =
          getPositiveDouble(); // call getPositiveDouble to prompt the user to
                               // validate two

      // things 1. user input is type double and 2. also a positive double
      break;
    }
    case 3: {
      printf("\n");
      printf("Enter the country (%d chars max.): ",
             maxChar); // prompt for user input

      getCString(personPointer->customerCountry, minChar,
                 maxChar + 1); // scanf and validate user input string length is
                               // valid by calling getCString function
      // person.customerCountry[] is an array but its name passed down as
      // person.customerCountry is a pointer personPointer->customerCountry
      // value is returned via pointer in the function and minChar and maxChar
      // to validate againt (person.customerCountry=&person.customerCountry[0]
      // for example UPDATE a1m3
      // (*personPointer).customerCountry=&(*personPointer).customerCountry[0]

      for (i = 0; i < personPointer->customerCountry[i] != '\0'; ++i) {

        personPointer->customerCountry[i] =
            toupper(personPointer->customerCountry[i]);
      }

      break;

    } // end of case 3

    case 0: {
      exitPerson = 1;
      break;
    }

    } // end of switch

  } while (exitPerson != 1);

} // end of updatePerson

void updateAccount(struct Account *accountPointer) {
  int quitMenu2 = 0;
  int validSelect = -50;
  int min = 0;
  int max = 3;
  char validgetChar = 'x';
  int i = 100;
  const char aorC[] = {"AC"};

  do {
    putchar('\n');
    printf("Update Account: %d (%s)\n", accountPointer->uAccountNo,
           accountPointer->person
               .fullName); // display's current account number being modified
                           // and full name of user
    printf("----------------------------------------\n");
    printf("1) Update account type (current value: %c)\n",
           accountPointer->uAccountType); // display A or C account type
    printf("2) Person\n");
    printf("3) Login\n");
    printf("0) Done\n");

    printf("Selection: ");
    validSelect = getIntFromRange(min, max);

    switch (validSelect) {
    case 0: {
      printf("\n");
      quitMenu2 = 1; // allows exit out of do while loop
      break;
    }
    case 1: {
      printf("\n");
      printf("Enter the account type (A=Agent | C=Customer): "); // ask for
                                                                 // userinput
                                                                 // for agent or
                                                                 // customer

      accountPointer->uAccountType = getCharOption(
          aorC); // CALL getCharOption function to ake user input and validate
                 // whether it matches the agentorCustomer string

      if (accountPointer->uAccountType == 'A') {
        printf("\n");
        printf("Agent type accounts require a user login. Please enter this "
               "information now:  \n");

        getUserLogin(
            &accountPointer->login); // only if account type is agent prompt the
                                     // user for the User Login only if the new
                                     // account is an "Agent" type
      }

      break;
    } // end of case 1

    case 2: {
      updatePerson(&accountPointer->person); // call updatePerson function
      break;
    } // end of case 2

    case 3: {
      if (accountPointer->uAccountType ==
          'C') // display an error message if the account is a "Customer" will
               // not have login information (and return to the menu):
      {
        printf("\n");
        printf("ERROR:  Customer account types don't have user logins!\n");

      } else // account type is agent
      {
        updateUserLogin(
            &accountPointer->login); // call the "updateUserLogin" function
      }
      break;

    } // end of case 3

    } // end of switch statement

  } while (quitMenu2 != 1); // exit when user enters 1 quit becomes 1

} // end of updateAccount
