/*	driver.c 
	
	Batch No: 14

	Members: 

	Ishan Sharma 2016B2A70773P
	Sarthan Sahu 2015B5A70749P
	Anirudh Garg 2017A7PS0142P
	Sanjeev Singla 2017A7PS0152P

*/

#include "parser.h"

int main(int argc, char *argv[])
{
	FILE *f=fopen(argv[1],"r");

	f=getStream(f);

	removeComments("tc1.txt","mod.txt");

	return 0;
}
