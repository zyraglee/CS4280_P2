#ifndef PARSER_H
#define PARSER_H

struct node* parser();
struct node* program();
struct node* vars();
struct node* block();
struct node* stat();
struct node* stats();
struct node* in();
struct node* out();
struct node* if1();
struct node* loop();
struct node* assign();
struct node* expr();
struct node* a();
struct node* n();
struct node* m();
struct node* r();
struct node* ro();
struct node* id();
struct node*  mStat();
void errorParser();


char duplicate[100];

struct node *newNode(char *label);





#endif
