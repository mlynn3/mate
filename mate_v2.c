#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// player structure
  struct player {
    char name[11]; // Name String
	char class[9]; // Class String
	int level, health, xp, attack, defense, mana, speed; // Player Stats
 };
 
 // enemy structure
  struct enemy {
    char name[11]; // Enemy Name
	int level, health, xp, attack, defense, mana, speed; // Enemy Stats
 };
 
int main(void)
{
    
  // Default coordinate structure
  struct coordinates {
    int x, y;
  };
  
  // Event coordinate structure
  struct event_cor{
	int x[50],y[50]; // Number of possible events
  };
  
  // Structure player and enemy variables
  struct player ply[1];
  struct enemy eny[1];
  
  // Structure pointer variable
  struct player *ptr = NULL;
  struct enemy *e_ptr = NULL;
  
  // Variables for menus and playerMoves
  int menuInput = 0, classInput = 0, battleInput = 0, dungeonInput = 0;
  int playerMoves = 0, fleeInput = 0, eventCreate = 0, i;
  char input, exitInput;
  
  // assign to ptr
  ptr = ply;
  e_ptr = eny;
  
  // assign default player stats and coords
  strcpy(ptr->name, "Default");
  strcpy(ptr->class, "Warrior");
  ptr->level = 1;
  ptr->xp = 0;
  ptr->health = 25;
  ptr->mana = 10;
  ptr->speed = 3;
  ptr->attack = 7;
  ptr->defense = 5;
  
  // Default player coordinates
  struct coordinates cor = {0,0};
  
  // Event coordinates, sets the map  
  struct event_cor event; 
	event.x[0] = 1, event.y[0] = 1; 
	event.x[1] = 3, event.y[1] = 5;
	event.x[2] = 5, event.y[2] = 8;

  // Prints Main Menu
puts("Welcome to M.A.T.E!\n");
menuMain:		
		do
		{
			puts("\nType a number for selection: ");
			puts("1.) Create a New Player");
			puts("2.) View Player Stats");
			puts("3.) Enter the Dungeon");
			puts("4.) Create an Event (WIP)");
			puts("5.) Exit Game");
			scanf(" %i", &menuInput);
			
				switch (menuInput) // Chooses Menu
				{
					case 1:
						goto createPlayer;
						break;
					case 2:
						goto displayStats;
						break;
					case 3:
						goto enterDungeon;
						break;
					case 4:
						goto createEvent;
						break;
					case 5:
						printf("Are you sure you want to leave? [Y/N]: "); // Exit protection
						scanf(" %c", &exitInput);
							
							switch (exitInput)
							{
								case 'y': case 'Y':
								puts("Exiting game...");
								exit(0);
								
								case 'n': case 'N':
								goto menuMain;
								break;
								
								default:
								puts("Invalid option!");
								goto menuMain;
								break;
							}
						
						break;
						
					default:
						puts("Invalid option!");
						break;
				}
	
		}while (menuInput = 0);

createPlayer: 											  // Sets a players name and class
 
    printf("\nEnter the name for your new player: ");
    scanf("\n%s", ptr->name); 							  // Set player name
	printf("%s? Is that your name? [Y/N]: ", ply->name);  // Confirms player name
	scanf(" %c", &input);
	
	switch (input) 										  // Chooses a class
		{
		case 'y': case 'Y':
				selectClass:
					printf("\nSelect a class for %s: ", ply->name);
					puts("\n1.) Warrior");
					puts("2.) Mage");
					puts("3.) Assassin");
					scanf(" %i", &classInput);

				switch (classInput)
					{
					case 1: 							  // Warrior class
						strcpy(ptr->class, "Warrior");
						ptr->level = 1;
						ptr->xp = 0;
						ptr->health = 25;
						ptr->mana = 10;
						ptr->speed = 3;
						ptr->attack = 7;
						ptr->defense = 5;
						goto menuMain;
						break;
								
					case 2: 							  // Mage class
						strcpy(ptr->class, "Mage");
						ptr->level = 1;
						ptr->xp = 0;
						ptr->health = 20;
						ptr->mana = 20;
						ptr->speed = 5;
						ptr->attack = 3;
						ptr->defense = 2;
						goto menuMain;
						break;
								
					case 3: 							  // Assassin class
						strcpy(ptr->class, "Assassin");
						ptr->level = 1;
						ptr->xp = 0;
						ptr->health = 18;
						ptr->mana = 5;
						ptr->speed = 10;
						ptr->attack = 3;
						ptr->defense = 2;
						goto menuMain;
						break;
								
					default:
						puts("Invalid option!");
						goto selectClass;
						break;
			}
			break;
			
		case 'n': case 'N':
			goto createPlayer;
			break;
		default:
			puts("Invalid option!");
			goto createPlayer;
			break;
		}	

displayStats: // Shows the players stats 
    
    printf("\nDetails of %s %s:", ply->class, ply->name);
	printf("\nLvl: %d", ply->level);
	printf("\nXP: %d", ply->xp);
	printf("\nHP: %d", ply->health);
	printf("\nMP: %d", ply->mana);
	printf("\nSP: %d", ply->speed);
	printf("\nATK: %d", ply->attack);
	printf("\nDF: %d\n\n", ply->defense);
	goto menuMain;

enterDungeon: // Starts Dungeon Menu, allows the player to travel, and counts moves
	
	printf("\n%s has entered the dungeon.\n", ply->name);
	
dungeonMenu:
	
	playerMoves = playerMoves + 1; 			  // Increments the amount of player moves
	
											  
	while (cor.x ==  event.x[0 || 1 || 2 || 3 || 4] && cor.y == event.y[0 || 1 || 2 || 3 || 4] && fleeInput != 1)
	{										  // Calculates events, Event 1 @ 3,5
		puts("\nYou have landed on an event!");
		goto battleMenu;
		break;
	}
	
	do 									      // Start Menu Screen
	{ 	
			fleeInput = 0; 					  // Resets Flee to OFF
			puts("\nType a number for selection: ");
			printf("Move: %i\n", playerMoves);
			puts("1.) Travel North");
			puts("2.) Travel South");
			puts("3.) Travel East");
			puts("4.) Travel West");
			puts("5.) Check Map");
			puts("6.) Leave the dungeon");
			puts("7.) Exit Game");
			scanf(" %i", &dungeonInput);
			
				switch (dungeonInput)
				{
					case 1:
						printf("\n%s traveled north.\n", ply->name);
						cor.y = cor.y + 1;    // Increments player's Y Coordinate
						goto dungeonMenu;
						break;
					case 2:
						printf("\n%s traveled south.\n", ply->name);
						cor.y = cor.y - 1;    // Decrements player's Y Coordinate
						goto dungeonMenu;
						break;
					case 3:
						printf("\n%s traveled east.\n", ply->name);
						cor.x = cor.x + 1;    // Increments player's X Coordinate
						goto dungeonMenu;
						break;
					case 4:
						printf("\n%s traveled west.\n", ply->name);
						cor.x = cor.x - 1;    // Decrements player's X Coordinate
						goto dungeonMenu;
						break;
					case 5:
						printf("\n%s's coordinates are X: %i, Y: %i\n",ply->name, cor.x, cor.y); 
						goto dungeonMenu; 
						break;
					case 6:
						printf("\n%s left the dungeon.\n", ply->name);
						cor.x = 0, cor.y = 0; //Resets player coordinates
						playerMoves = 0;	  //Resets player moves
						goto menuMain;
						break;
					case 7:
						printf("\nAre you sure you want to leave? [Y/N]: "); // Exit protection
						scanf(" %c", &exitInput);
							
							switch (exitInput)
							{
								case 'y': case 'Y':
								puts("Exiting game...");
								exit(0);
								
								case 'n': case 'N':
								goto dungeonMenu;
								break;
								
								default:
								puts("Invalid option!");
								goto dungeonMenu;
								break;
							}
						
						break;
					
					default:
						puts("Invalid Option!");
						goto dungeonMenu;
						break;
				}
	}while (dungeonInput = 0);
	
battleMenu:
	
	do // Start Battle Menu
	{ 	
			puts("\nType a Number for Selection: ");
			puts("1.) Attack");
			puts("2.) Magic");
			puts("3.) Item");
			puts("4.) Escape");
			scanf(" %i", &battleInput);
			
				switch (battleInput)
				{
					case 1:
						puts("\nAttack Menu");
						goto battleMenu;
						break;
					case 2:
						puts("\nMagic Menu");
						goto battleMenu;
						break;
					case 3:
						puts("\nItem Menu");
						goto battleMenu;
						break;
					case 4:
						printf("\n%s left the fight!", ply->name);
						fleeInput = fleeInput + 1; // Sets Flee ON, so dungeonMenu will NOT loop
						goto dungeonMenu;
						break;
					default:
						puts("Invalid option!");
						goto battleMenu;
						break;
				}
	}while (battleInput = 0);
	
createEvent:
	
	puts("\nEnter the Amount of Events to Add: ");
	scanf("%i", &eventCreate);
	
	for ( i = 0; i < eventCreate; i++)
	{
		printf("\nEnter X and Y Coordinates for Event #%i: ", i);
		scanf("%i %i",&event.x[3 + i], &event.y[3 + i]);
		printf("\nSuccessfully Created Event @ %i, %i!\n", event.x[3 + i], event.y[3 + i]);
	}
	
	goto menuMain;
};