#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "transistors.h"

/*
 * Name :  < insert name here >
 * Description : Simple transistor description example program
*/

int main()
{

	int i;
	Tran *trans;
	int numTrans = 0;
	char buffer[100];
	char answer;

	printf("transistors!\n");

	trans = malloc(sizeof(Tran) * 1);
	numTrans = 1;

	trans[0] = InputTransistor();
	while (true)
	{
		printf("Would you like to enter another transistor (Y/N)? ");
		fgets(buffer, sizeof(buffer), stdin);
		if (strlen(buffer) > 1)
		{
			buffer[strlen(buffer) - 1] = '\0';
		}
		sscanf(buffer, "%c", &answer);

		if (answer == 'y' || answer == 'Y')
		{
			trans = realloc(trans, sizeof(Tran) * (numTrans + 1));
			trans[numTrans] = InputTransistor();
			numTrans++;
		}
		else if (answer == 'n' || answer == 'N')
		{
			break;
		}
	}

	printf("\nThe transistors:\n");
	for (i = 0; i < numTrans; i++)
	{
		DisplayTransistor(trans[i]);
	}

	free(trans);
}
