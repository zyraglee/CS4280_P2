//Zyra De Los Reyes
//CS4280 P1 - scanner implementation
//
#include <stdio.h>
#include "token.h"
#include "scanner.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

//Driver that loops throught the table, while doing it we store the token in the struct. token, lin number, and tokentype
void driver(char *input, int line) {
		int i;
		int nextChar = 0;
		int state = 0;	
		int j = 0;
		ignoreComments(input);
		for(i = 0; i < strlen(input); i++) {
				//driver that loops through the table
				nextChar = isCharacter(input[i], input, i);	
				if(nextChar == -1){	
					sprintf(errorBuffer, "Scanner Error in Line %d:  %c Invalid Character", line, input[i]);
					strcpy(error[errorIndex], errorBuffer);
					errorIndex++;	
					isError = 1;
				} else {
				
					state = table[state][nextChar];

					if(state == -1) {
						sprintf(errorBuffer, "Scanner Error in Line %d:  %c Invalid Character", line, input[i]);
						strcpy(error[errorIndex], errorBuffer);
						errorIndex++;	
						isError = 1;
						
					}

					if(state == 1001){
						tokens[z].tokenType = IDENTIFIER;
					}

					if(state == 1002){	
						tokens[z].tokenType = NUMBER;
					}
		
					if(state == 1003){	
						tokens[z].tokenType = EQUAL;
					}

					if(state == 1004){	
						tokens[z].tokenType = LESS_THAN;
					}
					
					if(state == 1006){	
						tokens[z].tokenType = GREATER_THAN;
					}

					if(state == 1007){	
						tokens[z].tokenType = COLON;
					}

					if(state == 1008){	
						tokens[z].tokenType = PLUS;
					}

					if(state == 1009){	
						tokens[z].tokenType = MINUS;
					}
					
					if(state == 1010){	
						tokens[z].tokenType = STAR;
					}
					
					if(state == 1011){	
						tokens[z].tokenType = SLASH;
					}
					
					if(state == 1012){	
						tokens[z].tokenType = PERCENT;
					}
					
					if(state == 1013){	
						tokens[z].tokenType = DOT;
					}
					
					if(state == 1014){	
						tokens[z].tokenType = LEFT_PARENT;
					}
					
					if(state == 1015){	
						tokens[z].tokenType = RIGHT_PARENT;
					}
					
					if(state == 1016){	
						tokens[z].tokenType = COMMA;
					}
					
					if(state == 1017){	
						tokens[z].tokenType = LEFT_BRACE;
					}
					
					if(state == 1018){	
						tokens[z].tokenType = RIGHT_BRACE;
					}
					
					if(state == 1019){	
						tokens[z].tokenType = SEMICOLON;
					}
					
					if(state == 1020){	
						tokens[z].tokenType = LEFT_BRACKETS;
					}
					
					if(state == 1021){	
						tokens[z].tokenType = RIGHT_BRACKETS;
					}
					if(state == 1022) {
						tokens[z].tokenType = NOT_EQUAL;
					}
					if(state >= 1001 && state <= 1022){
						state = 0;
						tokens[z].lineNum = line;
						checkError();	
						z++;
						i--;
						j=0;
						j--;
					}	 

					if(!isspace(input[i])){
						tokens[z].instance[j] = input[i];
						j++;
					}
				}
			
			}
			

}


//Check the character. Once Identified,  return the respective value to the nextChar index
//note to self: rearrange later
int isCharacter(char c, char *input, int i) {

	 if( isalpha(c)) {
                return 0;
        }

        if(isdigit(c)){
                return 1;
        }

        if(c == '='){
		return 2;
        }

        if(c == '<'){
                return 3;
        }

         if(c == ' ' || c == '\t' || c == '\n') {
                return 4;
        }

	if(c == '>'){
		return 7;
	}
	
	
	if(c == ':'){
		return 8;
	}
	
	if(c == '+'){
		return 9;
	}

	
	if(c == '-'){
		return 10;
	}
	
	if(c == '*'){
		return 11;
	}


	if(c == '/'){
		return 12;
	}

	if(c == '%'){
		return 13;
	}


	if(c == '.'){
		return 14;
	}
	
	if(c == '('){
		return 15;
	}


	if(c == ')'){
		return 16;
	}

	if(c == ','){
		return 17;
	}


	if(c == '{'){
		return 18;
	}

	if(c == '}'){
		return 19;
	}
	
	if(c == ';'){
		return 20;
	}
	if(c == '['){
		return 21;
	}

	if(c == ']'){
		return 22;
	}
	return -1;
}

//functions that removes a single line comment
void ignoreComments(char *input){
	int x;
	size_t len = strlen(input);

	//if a '\' is detected
	for(x = 0; x < len; x++){
		if (input[x] == '\\') {
			int m;			
			input[x] = ' ';
			//traverse through the input		
			for(m=x+1; m < len; m++ ){
				//if end of line has not been reached, continue to replace char with spaces
				if(input[m] == '\\' && input[m] != '\n'){	
					input[m] = ' ';
					m = len+1;
				} else {//replace the entire line
					input[m] = ' ';
				}
						
			}
		}
	}	
}

//check if the identifier is keyword 
void checkIfKeyword() {

	int i,j;
	char *keywords[] = {"Begin","End","Loop","INT","Read","Output","Program","IFF"};
	size_t len = sizeof(keywords)/sizeof(keywords[0]);;
	
	for(i=0; i < z; i++) {
		if(tokens[i].tokenType == IDENTIFIER){
			for (j=0; j < len; j++){
				if(strcmp(tokens[i].instance, "Begin") == 0){
					tokens[i].tokenType = BEGIN_KEYWORD;	
				}
			
				if(strcmp(tokens[i].instance, "End") == 0){
					tokens[i].tokenType = END_KEYWORD;	
				}
				
				if(strcmp(tokens[i].instance, "Loop") == 0){
					tokens[i].tokenType = LOOP_KEYWORD;	
				}
				
				
				if(strcmp(tokens[i].instance, "INT") == 0){
					tokens[i].tokenType = INT_KEYWORD;	
				}

				if(strcmp(tokens[i].instance, "Read") == 0){
					tokens[i].tokenType = READ_KEYWORD;	
				}

				if(strcmp(tokens[i].instance, "Output") == 0){
					tokens[i].tokenType = OUT_KEYWORD;	
				}

				if(strcmp(tokens[i].instance, "Program") == 0){
					tokens[i].tokenType = PROGRAM_KEYWORD;	
				}
				
				if(strcmp(tokens[i].instance, "IFF") == 0){
					tokens[i].tokenType = IF_KEYWORD;	
				}
				
			}

		}


	}
}


void checkError(){	

	//check the identifier first letter starts  with capital letter
	int len = strlen(tokens[z].instance);
		
	//check if the identifier is longer than 8 and start with Capital letter
	if(tokens[z].tokenType == IDENTIFIER){
		
			//check if length is greater than 8 show error
			if (len > 8) {
				sprintf(errorBuffer, "Scanner Error in Line %d: identifier %s, needs to have max letter of 8", tokens[z].lineNum, tokens[z].instance);
				strcpy(error[errorIndex], errorBuffer);
				errorIndex++;
				isError = 1;

			}

			//check if the beginning of ID starts with an uppercase,if not it gives error
			if(!isupper(tokens[z].instance[0])){
				sprintf(errorBuffer, "Scanner Error in Line %d: identifier %s, first letter should be uppercase", tokens[z].lineNum, tokens[z].instance);
				strcpy(error[errorIndex], errorBuffer);
				errorIndex++;	
				isError = 1;
			}
		}

		//check if the length of digit is longer than 8 then show error
		if(tokens[z].tokenType == NUMBER){
					
			if (len > 8) {
				sprintf(errorBuffer, "Scanner Error in Line %d: integer %s, needs to have max digit of 8", tokens[z].lineNum, tokens[z].instance);
				strcpy(error[errorIndex], errorBuffer);
				errorIndex++;
				isError = 1;

			}	
		}
	

}


//create the FSATable
void createFSATable() {
    
    //first state
    table[0][0] = 1;
    table[0][1] = 2;
    table[0][2] = 3;
    table[0][3] = 4;
    table[0][4] = 0;
    table[0][5] = 1005;
    table[0][6] = -1;
    table[0][7] = 5;
    table[0][8] = 6;
    table[0][9] = 7;
    table[0][10] = 8;
    table[0][11] = 9;
    table[0][12] = 10;
    table[0][13] = 11;
    table[0][14] = 12;
    table[0][15] = 13;
    table[0][16] = 14;
    table[0][17] = 15;
    table[0][18] = 16;
    table[0][19] = 17;
    table[0][20] = 18;
    table[0][21] = 19;
    table[0][22] = 20;
    table[0][23] = 21;
    
    
    //identifier states
    table[1][0] = 1;
    table[1][1] = 1;
    table[1][2] = 1001;
    table[1][3] = 1001;
    table[1][4] = 1001;
    table[1][5] = 1001;
    table[1][6] = 1;
    table[1][7] = 1001;
    table[1][8] = 1001;
    table[1][9] = 1001;
    table[1][10] = 1001;
    table[1][11] = 1001;
    table[1][12] = 1001;
    table[1][13] = 1001;
    table[1][14] = 1001;
    table[1][15] = 1001;
    table[1][16] = 1001;
    table[1][17] = 1001;
    table[1][18] = 1001;
    table[1][19] = 1001;
    table[1][20] = 1001;
    table[1][21] = 1001;
    table[1][22] = 1001;
    table[1][23] = 1001;
    
    //integer states
    table[2][0] = 1002;
    table[2][1] = 2;
    table[2][2] = 1002;
    table[2][3] = 1002;
    table[2][4] = 1002;
    table[2][5] = 1002;
    table[2][6] = 1002;
    table[2][7] = 1002;
    table[2][8] = 1002;
    table[2][9] = 1002;
    table[2][10] = 1002;
    table[2][11] = 1002;
    table[2][12] = 1002;
    table[2][13] = 1002;
    table[2][14] = 1002;
    table[2][15] = 1002;
    table[2][16] = 1002;
    table[2][17] = 1002;
    table[2][18] = 1002;
    table[2][19] = 1002;
    table[2][20] = 1002;
    table[2][21] = 1002;
    table[2][22] = 1002;
    table[2][23] = 1002;
    
    //equal states
    table[3][0] = 1003;
    table[3][1] = 1003;
    table[3][2] = 1003;
    table[3][3] = 1003;
    table[3][4] = 1003;
    table[3][5] = 1003;
    table[3][6] = 1003;
    table[3][7] = 1003;
    table[3][8] = 1003;
    table[3][9] = 1003;
    table[3][10] = 1003;
    table[3][11] = 1003;
    table[3][12] = 1003;
    table[3][13] = 1003;
    table[3][14] = 1003;
    table[3][15] = 1003;
    table[3][16] = 1003;
    table[3][17] = 1003;
    table[3][18] = 1003;
    table[3][19] = 1003;
    table[3][20] = 1003;
    table[3][21] = 1003;
    table[3][22] = 1003;
    table[3][23] = 1003;
    
    
    //less than states
    table[4][0] = 1004;
    table[4][1] = 1004;
    table[4][2] = 1004;
    table[4][3] = 1004;
    table[4][4] = 1004;
    table[4][5] = 1004;
    table[4][6] = 1004;
    table[4][7] = 1004;
    table[4][8] = 1004;
    table[4][9] = 1004;
    table[4][10] = 1004;
    table[4][11] = 1004;
    table[4][12] = 1004;
    table[4][13] = 1004;
    table[4][14] = 1004;
    table[4][15] = 1004;
    table[4][16] = 1004;
    table[4][17] = 1004;
    table[4][18] = 1004;
    table[4][19] = 1004;
    table[4][20] = 1004;
    table[4][21] = 1004;
    table[4][22] = 1004;
    table[4][23] = 1004;
    
    //greater than states
    table[5][0] = 1006;
    table[5][1] = 1006;
    table[5][2] = 1006;
    table[5][3] = 1006;
    table[5][4] = 1006;
    table[5][5] = 1006;
    table[5][6] = 1006;
    table[5][7] = 1006;
    table[5][8] = 1006;
    table[5][9] = 1006;
    table[5][10] = 1006;
    table[5][11] = 1006;
    table[5][12] = 1006;
    table[5][13] = 1006;
    table[5][14] = 1006;
    table[5][15] = 1006;
    table[5][16] = 1006;
    table[5][17] = 1006;
    table[5][18] = 1006;
    table[5][19] = 1006;
    table[5][20] = 1006;
    table[5][21] = 1006;
    table[5][22] = 1006;
    table[5][23] = 1006;
    
    //Colon states
    table[6][0] = 1007;
    table[6][1] = 1007;
    table[6][2] = 1007;
    table[6][3] = 1007;
    table[6][4] = 1007;
    table[6][5] = 1007;
    table[6][6] = 1007;
    table[6][7] = 1007;
    table[6][8] = 1007;
    table[6][9] = 1007;
    table[6][10] = 1007;
    table[6][11] = 1007;
    table[6][12] = 1007;
    table[6][13] = 1007;
    table[6][14] = 1007;
    table[6][15] = 1007;
    table[6][16] = 1007;
    table[6][17] = 1007;
    table[6][18] = 1007;
    table[6][19] = 1007;
    table[6][20] = 1007;
    table[6][21] = 1007;
    table[6][22] = 1007;
    table[6][23] = 1007;
    
    
    //Plus states
    table[7][0] = 1008;
    table[7][1] = 1008;
    table[7][2] = 1008;
    table[7][3] = 1008;
    table[7][4] = 1008;
    table[7][5] = 1008;
    table[7][6] = 1008;
    table[7][7] = 1008;
    table[7][8] = 1008;
    table[7][9] = 1008;
    table[7][10] = 1008;
    table[7][11] = 1008;
    table[7][12] = 1008;
    table[7][13] = 1008;
    table[7][14] = 1008;
    table[7][15] = 1008;
    table[7][16] = 1008;
    table[7][17] = 1008;
    table[7][18] = 1008;
    table[7][19] = 1008;
    table[7][20] = 1008;
    table[7][21] = 1008;
    table[7][22] = 1008;
    table[7][23] = 1008;
    
    //minus states
    table[8][0] = 1009;
    table[8][1] = 1009;
    table[8][2] = 1009;
    table[8][3] = 1009;
    table[8][4] = 1009;
    table[8][5] = 1009;
    table[8][6] = 1009;
    table[8][7] = 1009;
    table[8][8] = 1009;
    table[8][9] = 1009;
    table[8][10] = 1009;
    table[8][11] = 1009;
    table[8][12] = 1009;
    table[8][13] = 1009;
    table[8][14] = 1009;
    table[8][15] = 1009;
    table[8][16] = 1009;
    table[8][17] = 1009;
    table[8][18] = 1009;
    table[8][19] = 1009;
    table[8][20] = 1009;
    table[8][21] = 1009;
    table[8][22] = 1009;
    table[8][23] = 1009;
    
    //Star states
    table[9][0] = 1010;
    table[9][1] = 1010;
    table[9][2] = 1010;
    table[9][3] = 1010;
    table[9][4] = 1010;
    table[9][5] = 1010;
    table[9][6] = 1010;
    table[9][7] = 1010;
    table[9][8] = 1010;
    table[9][9] = 1010;
    table[9][10] = 1010;
    table[9][11] = 1010;
    table[9][12] = 1010;
    table[9][13] = 1010;
    table[9][14] = 1010;
    table[9][15] = 1010;
    table[9][16] = 1010;
    table[9][17] = 1010;
    table[9][18] = 1010;
    table[9][19] = 1010;
    table[9][20] = 1010;
    table[9][21] = 1010;
    table[9][22] = 1010;
    table[9][23] = 1010;
    
    //Slash states
    table[10][0] = 1011;
    table[10][1] = 1011;
    table[10][2] = 1011;
    table[10][3] = 1011;
    table[10][4] = 1011;
    table[10][5] = 1011;
    table[10][6] = 1011;
    table[10][7] = 1011;
    table[10][8] = 1011;
    table[10][9] = 1011;
    table[10][10] = 1011;
    table[10][11] = 1011;
    table[10][12] = 1011;
    table[10][13] = 1011;
    table[10][14] = 1011;
    table[10][15] = 1011;
    table[10][16] = 1011;
    table[10][17] = 1011;
    table[10][18] = 1011;
    table[10][19] = 1011;
    table[10][20] = 1011;
    table[10][21] = 1011;
    table[10][22] = 1011;
    table[10][23] = 1011;
    
    
    //Percent states
    table[11][0] = 1012;
    table[11][1] = 1012;
    table[11][2] = 1012;
    table[11][3] = 1012;
    table[11][4] = 1012;
    table[11][5] = 1012;
    table[11][6] = 1012;
    table[11][7] = 1012;
    table[11][8] = 1012;
    table[11][9] = 1012;
    table[11][10] = 1012;
    table[11][11] = 1012;
    table[11][12] = 1012;
    table[11][13] = 1012;
    table[11][14] = 1012;
    table[11][15] = 1012;
    table[11][16] = 1012;
    table[11][17] = 1012;
    table[11][18] = 1012;
    table[11][19] = 1012;
    table[11][20] = 1012;
    table[11][21] = 1012;
    table[11][22] = 1012;
    table[11][23] = 1012;
    
    //Dot states
    table[12][0] = 1013;
    table[12][1] = 1013;
    table[12][2] = 1013;
    table[12][3] = 1013;
    table[12][4] = 1013;
    table[12][5] = 1013;
    table[12][6] = 1013;
    table[12][7] = 1013;
    table[12][8] = 1013;
    table[12][9] = 1013;
    table[12][10] = 1013;
    table[12][11] = 1013;
    table[12][12] = 1013;
    table[12][13] = 1013;
    table[12][14] = 1013;
    table[12][15] = 1013;
    table[12][16] = 1013;
    table[12][17] = 1013;
    table[12][18] = 1013;
    table[12][19] = 1013;
    table[12][20] = 1013;
    table[12][21] = 1013;
    table[12][22] = 1013;
    table[12][23] = 1013;
    
    //Left parenthesis states
    table[13][0] = 1014;
    table[13][1] = 1014;
    table[13][2] = 1014;
    table[13][3] = 1014;
    table[13][4] = 1014;
    table[13][5] = 1014;
    table[13][6] = 1014;
    table[13][7] = 1014;
    table[13][8] = 1014;
    table[13][9] = 1014;
    table[13][10] = 1014;
    table[13][11] = 1014;
    table[13][12] = 1014;
    table[13][13] = 1014;
    table[13][14] = 1014;
    table[13][15] = 1014;
    table[13][16] = 1014;
    table[13][17] = 1014;
    table[13][18] = 1014;
    table[13][19] = 1014;
    table[13][20] = 1014;
    table[13][21] = 1014;
    table[13][22] = 1014;
    table[13][23] = 1014;
    
    //Right parenthesis states
    table[14][0] = 1015;
    table[14][1] = 1015;
    table[14][2] = 1015;
    table[14][3] = 1015;
    table[14][4] = 1015;
    table[14][5] = 1015;
    table[14][6] = 1015;
    table[14][7] = 1015;
    table[14][8] = 1015;
    table[14][9] = 1015;
    table[14][10] = 1015;
    table[14][11] = 1015;
    table[14][12] = 1015;
    table[14][13] = 1015;
    table[14][14] = 1015;
    table[14][15] = 1015;
    table[14][16] = 1015;
    table[14][17] = 1015;
    table[14][18] = 1015;
    table[14][19] = 1015;
    table[14][20] = 1015;
    table[14][21] = 1015;
    table[14][22] = 1015;
    table[14][23] = 1015;
    
    //Comma states
    table[15][0] = 1016;
    table[15][1] = 1016;
    table[15][2] = 1016;
    table[15][3] = 1016;
    table[15][4] = 1016;
    table[15][5] = 1016;
    table[15][6] = 1016;
    table[15][7] = 1016;
    table[15][8] = 1016;
    table[15][9] = 1016;
    table[15][10] = 1016;
    table[15][11] = 1016;
    table[15][12] = 1016;
    table[15][13] = 1016;
    table[15][14] = 1016;
    table[15][15] = 1016;
    table[15][16] = 1016;
    table[15][17] = 1016;
    table[15][18] = 1016;
    table[15][19] = 1016;
    table[15][20] = 1016;
    table[15][21] = 1016;
    table[15][22] = 1016;
    table[15][23] = 1017;
    
    
    //left braces states
    table[16][0] = 1017;
    table[16][1] = 1017;
    table[16][2] = 1017;
    table[16][3] = 1017;
    table[16][4] = 1017;
    table[16][5] = 1017;
    table[16][6] = 1017;
    table[16][7] = 1017;
    table[16][8] = 1017;
    table[16][9] = 1017;
    table[16][10] = 1017;
    table[16][11] = 1017;
    table[16][12] = 1017;
    table[16][13] = 1017;
    table[16][14] = 1017;
    table[16][15] = 1017;
    table[16][16] = 1017;
    table[16][17] = 1017;
    table[16][18] = 1017;
    table[16][19] = 1017;
    table[16][20] = 1017;
    table[16][21] = 1017;
    table[16][22] = 1017;
    table[16][23] = 1017;
    
    
    //right brace states
    table[17][0] = 1018;
    table[17][1] = 1018;
    table[17][2] = 1018;
    table[17][3] = 1018;
    table[17][4] = 1018;
    table[17][5] = 1018;
    table[17][6] = 1018;
    table[17][7] = 1018;
    table[17][8] = 1018;
    table[17][9] = 1018;
    table[17][10] = 1018;
    table[17][11] = 1018;
    table[17][12] = 1018;
    table[17][13] = 1018;
    table[17][14] = 1018;
    table[17][15] = 1018;
    table[17][16] = 1018;
    table[17][17] = 1018;
    table[17][18] = 1018;
    table[17][19] = 1018;
    table[17][20] = 1018;
    table[17][21] = 1018;
    table[17][22] = 1018;
    table[17][23] = 1018;
    
    
    
    //semicolon states
    table[18][0] = 1019;
    table[18][1] = 1019;
    table[18][2] = 1019;
    table[18][3] = 1019;
    table[18][4] = 1019;
    table[18][5] = 1019;
    table[18][6] = 1019;
    table[18][7] = 1019;
    table[18][8] = 1019;
    table[18][9] = 1019;
    table[18][10] = 1019;
    table[18][11] = 1019;
    table[18][12] = 1019;
    table[18][13] = 1019;
    table[18][14] = 1019;
    table[18][15] = 1019;
    table[18][16] = 1019;
    table[18][17] = 1019;
    table[18][18] = 1019;
    table[18][19] = 1019;
    table[18][20] = 1019;
    table[18][21] = 1019;
    table[18][22] = 1019;
    table[18][23] = 1019;
    
    //left bracket states
    table[19][0] = 1020;
    table[19][1] = 1020;
    table[19][2] = 1020;
    table[19][3] = 1020;
    table[19][4] = 1020;
    table[19][5] = 1020;
    table[19][6] = 1020;
    table[19][7] = 1020;
    table[19][8] = 1020;
    table[19][9] = 1020;
    table[19][10] = 1020;
    table[19][11] = 1020;
    table[19][12] = 1020;
    table[19][13] = 1020;
    table[19][14] = 1020;
    table[19][15] = 1020;
    table[19][16] = 1020;
    table[19][17] = 1020;
    table[19][18] = 1020;
    table[19][19] = 1020;
    table[19][20] = 1020;
    table[19][21] = 1020;
    table[19][22] = 1020;
    table[19][23] = 1020;
    
    
    //right brackets states
    table[20][0] = 1021;
    table[20][1] = 1021;
    table[20][2] = 1021;
    table[20][3] = 1021;
    table[20][4] = 1021;
    table[20][5] = 1021;
    table[20][6] = 1021;
    table[20][7] = 1021;
    table[20][8] = 1021;
    table[20][9] = 1021;
    table[20][10] = 1021;
    table[20][11] = 1021;
    table[20][12] = 1021;
    table[20][13] = 1021;
    table[20][14] = 1021;
    table[20][15] = 1021;
    table[20][16] = 1021;
    table[20][17] = 1021;
    table[20][18] = 1021;
    table[20][19] = 1021;
    table[20][20] = 1021;
    table[20][21] = 1021;
    table[20][22] = 1021;
    table[20][23] = 1021;

    //not equal states
    table[21][0] = 1022;
    table[21][1] = 1022;
    table[21][2] = 1022;
    table[21][3] = 1022;
    table[21][4] = 1022;
    table[21][5] = 1022;
    table[21][6] = 1022;
    table[21][7] = 1022;
    table[21][8] = 1022;
    table[21][9] = 1022;
    table[21][10] = 1022;
    table[21][11] = 1022;
    table[21][12] = 1022;
    table[21][13] = 1022;
    table[21][14] = 1022;
    table[21][15] = 1022;
    table[21][16] = 1022;
    table[21][17] = 1022;
    table[21][18] = 1022;
    table[21][19] = 1022;
    table[21][20] = 1022;
    table[21][21] = 1022;
    table[21][22] = 1022;
    table[21][23] = 1022;
} 
