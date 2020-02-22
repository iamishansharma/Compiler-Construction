#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "parserDef.h"
#include "lexerDef.h"

int hash(char *str);
int search(char *str,char **Hashtable);
int insert(char *str,char **Hashtable);
/*int hashcallparser(char *tosearch, Term T,int sizeofT);
int hashcalllexer(char *tosearch, char **Keywords,int sizeofK);*/

#endif