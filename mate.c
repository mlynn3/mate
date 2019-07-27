#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct playerStucture{
		char name[11];
		int level;
};

// Function Prototypes
void createPlayer(struct playerStucture *);
void displayStats(struct playerStucture *);

void main(void)
{
	int menuInput = 0;
	struct playerStucture player[10];

	puts("Welcome to M.A.T.E!");
		
		do
		{
			puts("\nType a number for selection: ");
			puts("1.) Create a Player");
			puts("2.) View Player Stats");
			puts("3.) Exit Game");
			scanf(" %i", &menuInput);
			][w
				switch (menuInput)
				{
					case 1:
						createPlayer(player);
						break;
					case 2:][
						displayStats(player);
						break;
					case 3:
						puts("Exiting game...");
						exit(0);
					default:
						puts("Invalid option!");
				}
	
		}while (menuInput = 0);
}

void createPlayer(struct playerStucture *ptr)
{
	int i;
	int *ptr = NULL;
	
	for (i = 0; i < 1; i++)
	{
		printf("Enter your player's name: (Must be under 10 characters) ");
		scanf("%s", ptr->name);
		printf("Enter your player's level: ");
		scanf("%d", &ptr->level);
		
		ptr++;
	}
	main();
}	

void displayStats(struct playerStucture *ptr)
{
	int i;
	int *ptr = NULL;
		
	for (i = 0; i < 1; i++)
	{
		printf("\n%s's stats: ", &ptr->name);
		printf("\nLevel: %d\n", &ptr->level);
		
		ptr++;
	}
}