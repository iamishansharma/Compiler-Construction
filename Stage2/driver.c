/*	

	driver.c 
	
	Batch No: 14

	Members: 

	Ishan Sharma 2016B2A70773P
	Sarthak Sahu 2015B5A70749P
	Anirudh Garg 2017A7PS0142P
	Sanjeev Singla 2017A7PS0152P

*/

// Stage 1 header files ->

#include "parser.h"
#include "lexer.h"
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>

// Stage 2 header files ->

#include "ast.h"
#include "SymbolTable.h"
#include "TypeChecker.h"
#include "CodeGen.h"

int truncate(const char *path, off_t length);
int ftruncate(int fd, off_t length);

ParseTree *temphead;
ParseTree *temphead2;

void printLexer(char *filename)
{
	FILE *f=fopen(filename,"r");
	f=getStream(f);
	
	printf("\n");

	printf("\nLine Number      Lexeme            Token\n\n");
	Node *n=(Node*)malloc(sizeof(Node));
	do
	{
		n=getNextToken();
		if(strcmp(n->t->token,"EOB")==0)
		{
			break;
		}
		if(strcmp(n->t->token,"Error"))
		{
			printf("     %d           %s           %s\n",n->t->lineno,n->t->value,n->t->token);
		}
		else
		{
			printf("     %d           %s           %s\n",n->t->lineno,n->t->value,n->t->token);
		}
	}while(buffer[fwd]!='\0');
}

void removedollar(char *filename)
{
	//printf("Comes here");
	FILE *f=fopen(filename,"a");
	int charsToDelete = 1;
	fseeko(f,-charsToDelete,SEEK_END);
	int position = ftello(f);
	ftruncate(fileno(f), position);
	fclose(f);
}

void calculateCPUtime(FILE *f4, ParseTable T, Grammar G)
{
	clock_t start_time, end_time;
	double total_CPU_time, total_CPU_time_in_seconds;
	start_time = clock();

		//parseInputSourceCode(f4,T,G);

	end_time = clock();
	total_CPU_time = (double)(end_time - start_time);
	total_CPU_time_in_seconds = total_CPU_time / CLOCKS_PER_SEC;

	printf("\n\n\tTotal CPU time is: %lf\n",total_CPU_time);
	printf("\tTotal CPU time in seconds is: %lfs\n",total_CPU_time_in_seconds);
	printf("\tTotal CPU time in miliseconds is: %lfms\n",total_CPU_time_in_seconds*1000);
}

int main(int argc, char *argv[])
{
	Grammar G;
	FirstAndFollow F;
	ParseTable T;

	FILE *f2=fopen(argv[2],"w"); // for printing parse tree

	FILE *f3=fopen("grammar.txt","r"); // for reading grammar file

	FILE *f1=fopen(argv[1],"a"); // appending $

	FILE *f9=fopen(argv[3],"w");

	FILE *semantic = fopen("Type&Semantics.txt","w+");

	int ParseTreeCount[1]={0};

	int ASTCount[1]={0};

	float comper;

	char scope[100];

	int option=-1;

	SymbolTable *Table;

	int scopeError;

	if(argc!=4)
	{
		printf("Too few/many arguments, exiting! Please enter in format as ./compiler *.txt {<- test case file} *.asm {<- machine code file}");
		exit(1);
	}

	do
	{
		printf("\n\n************************* %sERPLAG Compiler Stage2%s ***************************\n",BOLDYELLOW,RESET);
		printf("%sBatch 14:%s Ishan Sharma 2016B2A70773P | Sarthak Sahu 2015B5A70749P\n",BOLDRED,RESET);
		printf("\t  Anirudh Garg 2017A7PS0142P | Sanjeev Singla 2017A7PS0152P\n\n");
		printf("Status:  \n");
		printf("\t1. AST is being generated as required\n");
		printf("\t2. Symbol Table is being populated as required.\n");
		printf("\t3. Type Checking and Semantic Check are working as required. \n");
		printf("\t4. Code Gen?\n\n");
		printf("Please select one of the following options -\n\n");
		printf("\t0. Exit the program.\n");
		printf("\t1. Remove Comments and display on console.\n");
		printf("\t2. Display token list on console.\n");
		printf("\t3. Parse the input file and write the Parse Tree into a file.\n");
		printf("\t4. Print the total time taken for parsing the input file.\n");
		printf("\t5. Clear the Screen.\n\n");
		printf("Enter your option here: ");
		scanf("%d",&option);

		switch(option)
		{
			case 0: printf("%sExiting, Thank you for using the compiler!\n%s",BOLDGREEN,RESET);
					break;

			case 1:

					printf("\n");
					removeComments(argv[1]);
					break;

			case 2: 
					//hashkeywords();
					printLexer(argv[1]);
					break;

			case 3: 
					fputc('$',f1);
					fclose(f1);
					FILE *f4=fopen(argv[1],"r"); // now reading that file
					G=getGrammar(f3);
					F=ComputeFirst(F,G);
					F=ComputeFollow(F,G);
					T=createParseTable(F,T,G);
					printf("\n%sRunning Status: %s\n",BOLDRED,RESET);
					parseInputSourceCode(f4,T,G,f9);
					temphead=returnhead();
					countNodes(temphead, ParseTreeCount);
					printParseTree(f2);
					fprintf(f2,"\n\n*************************************************************************************** \n\n");
					fprintf(f2, "\nAST: \n\n");

					// Making nad printing AST here:

					callingAST(temphead);
					countNodes(temphead, ASTCount);
					printParseTree(f2);

					// Printing the compression percentage: 

					printf("\n\nNo of Parse Tree Nodes: %d\n",ParseTreeCount[0]);
					printf("No of AST Nodes: %d\n\n", ASTCount[0]);
					comper = (((float)ParseTreeCount[0] - (float)ASTCount[0]) / (float)ParseTreeCount[0])*100;
					printf("Compression Percentage: %f\n",comper);

					// Symbol Table: 

					Table = CallingSymbolTable(temphead, &scopeError);

					printf("\n\n**********************************   %sSYMBOL TABLE%s   ******************************************\n", BOLDRED, RESET);
					printf("----------------------------------------------------------------------------------------------\n");
					printf("IDENTIFIER \t USAGE \t\t TYPE \t     LINE NO. \t SCOPE \t     NESTING   WIDTH   OFFSET\n");
					printf("----------------------------------------------------------------------------------------------\n");

					printSymbolTable(Table);

					printf("**********************************************************************************************\n");

					removedollar(argv[1]);
					fclose(f4);
					break;

			case 4: 
					fputc('$',f1);
					fclose(f1);
					FILE *f5=fopen(argv[1],"r"); // now reading that file
					G=getGrammar(f3);
					F=ComputeFirst(F,G);
					F=ComputeFollow(F,G);
					T=createParseTable(F,T,G);
					calculateCPUtime(f5,T,G);
					printParseTree(f5);
					removedollar(argv[1]);
					fclose(f5);
					break;

			case 5:
					system("clear");
					break;

			default:
					printf("\nWrong option, try again!\n");
					break;
		}

	}while(option!=0);

	return 0;
}
