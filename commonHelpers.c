
#define _CRT_SECURE_NO_WARNINGS

#include "commonHelpers.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Uses the time.h library to obtain current year information // Get the current
// 4-digit year from the system
int currentYear(void) {
  time_t currentTime = time(NULL);
  return localtime(&currentTime)->tm_year + 1900;
}

// Included function to empty the standard input buffer
void clearStandardInputBuffer(void) {
  while (getchar() != '\n') {
    ; // On purpose: do nothing
  }
}

// define getInteger

int getInteger(void) { // integer definition to make validate user enters
                       // integer value and return if user input is valid

  // declare variables to use for user input
  int user_getInt = 0;
  char user_newline = 'x'; // declared to make sure that when user press's enter
                           // after integer, it is still valid

  do {
    // ask user for int input
    scanf("%d%c", &user_getInt, &user_newline);

    // validate user input make sure that when user press's enter after integer,
    // it is still valid
    if (user_newline != '\n') {
      // make sure to invoke included clear buffer funciton so user can enter
      // input again without a problem
      clearStandardInputBuffer(); // NOTE: see if you need to switch the order
                                  // of clear and printf error around
      printf("ERROR: Value must be an integer: ");
    }

  } while (user_newline != '\n'); // end of do while loop in getInteger function

  return user_getInt; // return user integer value

} // end of getInteger

int getPositiveInteger(void) {
  int returnedInt = 0;
  int flag = 0;
  do {
    // ask user for int input by calling returnedInt Function
    returnedInt = getInteger();

    // validate user input make sure that when user press's enter after integer,
    // it is still valid
    if (returnedInt <= 0) // invalid input
    {
      printf("ERROR: Value must be a positive integer greater than zero: ");
      flag = 0;
    } else {

      flag = 1; // valid input
    }

  } while (flag != 1); // end of do while loop to get user integer value

  return returnedInt;

} // end of getPositiveIntegerfunction

int getIntFromRange(int min, int max) {
  // declare variables to store user input returned from getInteger function
  int user_range = 0;

  do {
    user_range =
        getInteger(); // returned value is validated by getInteger function

    if (user_range < min || user_range > max) {
      printf("ERROR: Value must be between %d and %d inclusive: ", min, max);
    }

  } while (user_range < min ||
           user_range > max); // end of do while loop in getInteger function

  return user_range;

} // end of getIntFromRange function

double getDouble(void) {
  // declare variables to use for user input
  double user_getDouble = 0.0;
  char user_dnewline = 'x'; // declared to make sure that when user press's
                            // enter after integer, it is still valid

  do {
    // ask user for int input
    scanf("%lf%c", &user_getDouble, &user_dnewline);

    // validate user input make sure that when user press's enter after double,
    // it is still valid
    if (user_dnewline != '\n') {
      // clear buffer funciton so user can enter input again without a problem
      clearStandardInputBuffer();
      printf("ERROR: Value must be a double floating-point number: ");
    }

  } while (user_dnewline != '\n'); // end of do while loop in getInteger
                                   // function

  return user_getDouble; // return user integer value

} // end of getDouble Function

double getPositiveDouble(void) {

  // Declare variables

  double returnedDouble = 0.0;
  int flag = 0;

  do {
    // ask user for double input by calling returnedDouble Function
    returnedDouble = getDouble();

    // validate user input make sure that when user press's enter after integer,
    // it is still valid
    if (returnedDouble <= 0) // invalid input
    {
      printf("ERROR: Value must be a positive double floating-point number: ");
      flag = 0;
    } else {

      flag = 1; // valid input
    }

  } while (flag != 1); // end of do while loop to get user integer value

  return returnedDouble;

} // end of getPositiveDouble function

char getCharOption(const char stringArray[]) {
  char userChar = 'y';  // initialize for safety
  char opnewline = 'x'; // initialize for safety
  int i;                // for loop variable
  int flag = 0;

  do {
    // Ask for user character input

    scanf("%c%c", &userChar, &opnewline);

    if (opnewline != '\n') // indicates that if second char is not an enter  or
                           // "\n' it is invalid
    {
      flag = 0; // invalid opnewline character (not an enter aka '\n')
      clearStandardInputBuffer(); // COMMENT OUT if not necessary
    } else                        // indicates opennewline value
    {
      for (i = 0; stringArray[i] != '\0' && flag != 1;
           i++) // iterate stringArray by element until we reach the string null
                // chracter indicating end of array
      {
        if (userChar ==
            stringArray[i]) // compares if userChar maches an element in
                            // stringArray[i] and is therefore valid
        {
          flag = 1; // indicates valid userChar and use to break out of do while
                    // loop
        } else {
          flag = 0; // indicates invalid userChar
        }
      }
    }

    if (flag != 1) // invalid open new and userChar values
    {
      int flag = 0;
      printf("ERROR: Character must be one of [%s]: ", stringArray);
    }

  } while (flag != 1); // repeat user input and validation if userChar and
                       // opnewline characters are invalid print error statment

  return userChar; // return valid userChar value

} // end of getCharOption function

void getCString(char stringPointer[], int cStringMin, int cStringMax) {
  // Declare variables
  int i = 0, j = 0;
  char userCString[31] = {0};
  char cStringnewline = 'x';
  int flag = 0;

  do {
    int countUserString = 0;

    scanf("%31[^\n]", userCString); //  reads input up to new line character and
                                    //  discards to clear buffer for next input
    clearStandardInputBuffer();

    for (i = 0; userCString[i] != '\0'; i++) {
      countUserString++; // cStringMinount number of elements user entered in
                         // userCString
    }

    // invalid user inputs
    if (countUserString > cStringMax ||
        countUserString < cStringMin) // invalid string input if cStringMin and
                                      // CStringMax are the same value
    {
      if (cStringMin == cStringMax) {
        printf("ERROR: String length must be exactly %d chars: ", cStringMax);
        flag = 0;
      } else if (countUserString > cStringMax) {
        printf("ERROR: String length must be no more than %d chars: ",
               cStringMax);
        flag = 0;
      } else if (countUserString < cStringMin) {
        printf("ERROR: String length must be between %d and %d chars: ",
               cStringMin, cStringMax);
        flag = 0;
      }

    } else {
      flag = 1; // valid inputs
    }
  } while (flag != 1);

  for (j = 0; userCString[j] != '\0';
       ++j) // copies values of userCStringString[i] to argument stringPointer
            // so we can return the whole string
  {
    stringPointer[j] = userCString[j];
  }
  stringPointer[j] = '\0'; // adds null to the end of stringPointer to return

} // end of getCString function

