#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "scanner.h"
#include "token.h"
#include "parser.h"

//print tree
void traversePreorder(struct node *root,int level) {
    if (root != NULL) {

        int j;
	
        for(j=0; j < level*2; j++) {
            fprintf(stdout, " ");
        }

        fprintf(stdout,"%s ", root->label);
	//fprintf(stdout, "\n ");
        int i;

        for(i=0;i<root->counts-1;i++) {
            if(root->tk[i].tokenType == IDENTIFIER){
                fprintf(stdout,"ID %s ", root->tk[i].instance);
            }
		
            if(root->tk[i].tokenType == NUMBER){
                fprintf(stdout,"INT %s ", root->tk[i].instance);
            }
		
            if(root->tk[i].tokenType == PLUS){
                fprintf(stdout,"PLUS %s ", root->tk[i].instance);
            }
            
            if(root->tk[i].tokenType == STAR){
                fprintf(stdout,"STAR %s ", root->tk[i].instance);
            }
				
            if(root->tk[i].tokenType == SLASH){
                fprintf(stdout,"SLASH %s ", root->tk[i].instance);
            }
            
            if(root->tk[i].tokenType == MINUS){
                fprintf(stdout,"MINUS %s ", root->tk[i].instance);
            }
		
            if(root->tk[i].tokenType == EQUAL){
                fprintf(stdout,"EQUAL %s ", root->tk[i].instance);
            }
		
            if(root->tk[i].tokenType == GREATER_THAN){
                fprintf(stdout,"GREATER %s ", root->tk[i].instance);
            }
            if(root->tk[i].tokenType == LESS_THAN){
                fprintf(stdout,"LESS %s ", root->tk[i].instance);
            }
//	    if(root->tk[i].tokenType == STAR){
  //              fprintf(stdout,"STAR %s ", root->tk[i].instance);
    //        }

//	fprintf(stdout,"\n");

        }

	
//       fprintf(stdout,"\n");
	 fprintf(stdout,"\n");
        traversePreorder(root->left,level+1);
        traversePreorder(root->eq, level+1);
        traversePreorder(root->eq2, level+1);
  //       fprintf(stdout,"\n");

        traversePreorder(root->right,level+1);

	}
}
