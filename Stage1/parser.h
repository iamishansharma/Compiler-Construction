/*	parser.h 

	Batch No: 14

	Members: 

	Ishan Sharma 2016B2A70773P
	Sarthan Sahu 2015B5A70749P
	Anirudh Garg 2017A7PS0142P
	Sanjeev Singla 2017A7PS0152P

*/ 

#ifndef PARSER_H
#define PARSER_H

#include "parserDef.h"

// Primary Functions Declarations - 

FirstAndFollow ComputeFirstAndFollowSets(Grammar G, FirstAndFollow F);
ParseTable createParseTable(FirstAndFollow F, ParseTable T);
ParseTree* parseInputSourceCode(char *testcaseFile, ParseTable T, Grammar G);
void printParseTree(ParseTree *head,FILE *f);

// Supporting Functions Declarations - 

Grammar getGrammar(FILE *f);
void make_stack();
void push(int ele);
int pop();
ParseTree* insert_in_tree(ParseTree *head,int rule,Grammar G,Node *n);
int search_nont_in_G(int value, Grammar G);
ParseTree seach_in_tree(ParseTree* head,int rule);
int size_of_rule(int rule, Grammar G);

#endif