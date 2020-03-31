/*  ast.h 
	
	Batch No: 14

	Members: 

	Ishan Sharma 2016B2A70773P
	Sarthak Sahu 2015B5A70749P
	Anirudh Garg 2017A7PS0142P
	Sanjeev Singla 2017A7PS0152P

*/

#include "lexer.h"
#include "lexerDef.h"
#include "parser.h"
#include "parserDef.h"

/* Function definations */

void ConstructAST(ParseTree *head);
void printAST(ParseTree *head);
ParseTree* liftUpNode(ParseTree *child);
ParseTree* removeNode(ParseTree *head, ParseTree *child);
void removeTerminals(ParseTree *head);