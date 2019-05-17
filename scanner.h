#ifndef SCANNER_H
#define SCANNER_H

#define row 21
#define col 24

#define MAX 9
#define LIMIT 200

 
int table[row][col];

extern int z;
char error[LIMIT][LIMIT];
char errorBuffer[LIMIT];
extern int errorIndex;
int isError;

void createFSATable();
void driver(char *input, int line);

int isExAcceptibleChar(char c);
int isCharacter(char c, char *input, int line);

void checkError();
void checkIfKeyword();
void ignoreComments(char *input);

#endif
