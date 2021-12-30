#include <stdio.h>
#include <stdlib.h>
#include "../include/indexation.h"
#include "../include/recherche.h"

int main(int argc, char *argv[])
{
	char* mess = lanceRechercheViaNom(*(argv+1));
	printf("\n==========\n%s",mess);
	return 0;
}