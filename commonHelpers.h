
#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_

int currentYear(void);

void clearStandardInputBuffer(void);

int getInteger(void);

int getPositiveInteger(void);

int getIntFromRange(int min, int max);

double getDouble(void);

double getPositiveDouble(void);

char getCharOption(const char stringArray[]);

void getCString(char stringPointer[], int cStringMin, int cStringMax);

#endif
