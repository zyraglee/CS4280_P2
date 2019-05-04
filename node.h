#ifndef NODE_H
#define NODE_H
#include "token.h"

#define STRSIZE 100
#define CHARSIZE 500

struct node {
	char label[STRSIZE];
	Tk tk[STRSIZE];
	char data[STRSIZE][CHARSIZE];
	struct node *left, *eq, *eq2, *right;
	int counts;
};

#endif 

