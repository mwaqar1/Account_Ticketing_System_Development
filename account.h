#ifndef ACCOUNT_H_
#define ACCOUNT_H_

struct Person {
  char fullName[31];
  int birthYear;
  double houseIncome;
  char customerCountry[31];

}; // end of struct Person

struct UserLogin {
  char userLogName[11];
  char userPassw[9];

}; // end of struct UserLogin

struct Account {
  int uAccountNo;
  char uAccountType;
  struct Person person;   // a1m3 update
  struct UserLogin login; // a1m3 update

}; // end of struct Account

void pauseExecution(void);

void getAccount(struct Account *accountPointer);
void getNewAccount(struct Account *accountPointer);
void getPerson(struct Person *personPointer);
void getUserLogin(struct UserLogin *loginPointer);

void updateUserLogin(struct UserLogin *loginPointer);
void updatePerson(struct Person *personPointer);
void updateAccount(struct Account *accountPointer);

#endif
