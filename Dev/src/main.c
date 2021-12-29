#include <stdio.h>
#include <stdlib.h>
#include "../include/indexation.h"
#include "../include/recherche.h"

int main(int argc, char *argv[])
{
	lanceRechercheViaNom(*(argv+1));
	return 0;
}