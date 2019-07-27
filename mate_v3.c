#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// player structure
  struct player {
    char name[11]; // Name String
	char class[9]; // Class String
	int level, health, xp, attack, mana, stamina, id; // Player Stats
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
  
  // Structure player and classes
  struct player ply[1];
  
  struct player Warrior;
	Warrior.level = 1;
	Warrior.xp = 0;
	Warrior.health = 25;
	Warrior.mana = 10;
	Warrior.stamina = 5;
	Warrior.attack = 7;
	Warrior.id = 1;
  
  struct player Mage;
	Mage.level = 1;
	Mage.xp = 0;
	Mage.health = 20;
	Mage.mana = 20;
	Mage.stamina = 7;
	Mage.attack = 3;
	Mage.id = 2;
  
  struct player Assassin;
	Assassin.level = 1;
	Assassin.xp = 0;
	Assassin.health = 18;
	Assassin.mana = 5;
	Assassin.stamina = 10;
	Assassin.attack = 3;
	Assassin.id = 3;
  
  // Structure pointer variable
  struct player *ptr = NULL;
  
  // Variables for menus and playerMoves
  int menuInput = 0, classInput = 0, battleInput = 0, dungeonInput = 0;
  int playerMoves = 0, fleeInput = 0, eventCreate = 0, i;
  char input, exitInput;
  
  // assign to ptr
  ptr = ply;
 
  // assign default player stats and coords
  strcpy(ptr->name, "Default");
  strcpy(ptr->class, "Warrior");
  ptr->level = 1;
  ptr->xp = 0;
  ptr->health = 25;
  ptr->mana = 10;
  ptr->stamina = 5;
  ptr->attack = 7;
  ptr->id = 1;
  
  // Default player coordinates
  struct coordinates cor = {1,1};
  
  // Town coordinates, sets the map  
  struct event_cor town; 
	town.x[0] = 3, town.y[0] = 3; // Town 1
	town.x[1] = 1, town.y[1] = 9; // Town 2
	town.x[2] = 9, town.y[2] = 5; // Town 3
	
  // Road coordinates, sets the map
  struct event_cor road;
    road.x[0] = 1, road.y[0] = 1;/* */road.x[1] = 2, road.y[1] = 1;/* */road.x[2] = 3, road.y[2] = 1;
	road.x[3] = 3, road.y[3] = 2;/* */road.x[4] = 3, road.y[4] = 4;/* */road.x[5] = 3, road.y[5] = 5;
	road.x[6] = 4, road.y[6] = 5;/* */road.x[7] = 5, road.y[7] = 5;/* */road.x[8] = 6, road.y[8] = 5;
	road.x[9] = 7, road.y[9] = 5;/* */road.x[10] = 8, road.y[10] = 5;/* */road.x[11] = 9, road.y[11] = 6;
	road.x[12] = 9, road.y[12] = 7;/* */road.x[13] = 9, road.y[13] = 8;/* */road.x[14] = 9, road.y[14] = 9;
	road.x[15] = 8, road.y[15] = 9;/* */road.x[16] = 7, road.y[16] = 9;/* */road.x[17] = 6, road.y[17] = 9;
	road.x[18] = 5, road.y[18] = 9;/* */road.x[19] = 4, road.y[19] = 9;/* */road.x[20] = 3, road.y[20] = 9;
	road.x[21] = 2, road.y[21] = 9;/* */road.x[22] = 3, road.y[22] = 8;/* */road.x[23] = 3, road.y[23] = 7;
	road.x[24] = 3, road.y[24] = 6;

  // Prints Main Menu
puts("Welcome to M.A.T.E!\n");
menuMain:		
		do
		{
			puts("\nType a number for selection: ");
			puts("1.) Create a New Player");
			puts("2.) View Player Stats");
			puts("3.) Enter the World");
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
						ptr->level = Warrior.level;
						ptr->xp = Warrior.xp;
						ptr->health = Warrior.health;
						ptr->mana = Warrior.mana;
						ptr->stamina = Warrior.stamina;
						ptr->attack = Warrior.attack;
						ptr->id = Warrior.id;
						goto menuMain;
						break;
								
					case 2: 							  // Mage class
						strcpy(ptr->class, "Mage");
						ptr->level = Mage.level;
						ptr->xp = Mage.xp;
						ptr->health = Mage.health;
						ptr->mana = Mage.mana;
						ptr->stamina = Mage.stamina;
						ptr->attack = Mage.attack;
						ptr->id = Mage.id;
						goto menuMain;
						break;
								
					case 3: 							  // Assassin class
						strcpy(ptr->class, "Assassin");
						ptr->level = Assassin.level;
						ptr->xp = Assassin.xp;
						ptr->health = Assassin.health;
						ptr->mana = Assassin.mana;
						ptr->stamina = Assassin.stamina;
						ptr->attack = Assassin.attack;
						ptr->id = Assassin.id;
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
	printf("\nSP: %d", ply->stamina);
	printf("\nATK: %d\n", ply->attack);
	goto menuMain;

enterDungeon: // Starts World Menu, allows the player to travel, counts moves and stamina
	
	printf("\n%s has entered the World.\n", ply->name);
	
dungeonMenu:
	
	playerMoves = playerMoves + 1; 			  			  // Increments the amount of player moves

	if (ply->id == 1 && ply->stamina > Warrior.stamina)   // Prevents Stamina from going above Warrior default
		ply->stamina = Warrior.stamina;
	
	if (ply->id == 2 && ply->stamina > Mage.stamina)      // Prevents Stamina from going above Mage default
		ply->stamina = Mage.stamina;
	
	if (ply->id == 3 && ply->stamina > Assassin.stamina)  // Prevents Stamina from going above Assassin default
		ply->stamina = Assassin.stamina;
	
	if (ply-> stamina == 0)
		printf("\n%s is tired from traveling. %s should rest.\n", ply->name, ply->name);
	
	while (ply->stamina < 0){
		ply->health = ply->health - 1;
		printf("\n%s is taking damage from exhaustion! %s needs rest!\n", ply->name, ply->name);
		break;}
	
	// Return Player to Map Boundaries
	while (cor.x < 1){
		cor.x = 1;
		printf("\n%s reached the boundary and turned around.\n", ply->name);
	break;}
		
	while (cor.x > 10){
		cor.x = 10;
		printf("\n%s reached the boundary and turned around.\n", ply->name);
	break;}
		
	while (cor.y < 1){
		cor.y = 1;
		printf("\n%s reached the boundary and turned around.\n", ply->name);
	break;}
		
	while (cor.y > 10){
		cor.y = 10;
		printf("\n%s reached the boundary and turned around.\n", ply->name);
	break;}
	
	while (cor.x ==  town.x[0] && cor.y == town.y[0] && fleeInput != 1) // Town 1 PREPARE YOURSELF AAAaaaa
	{   
		printf("\n%s has entered a town!\n", ply->name);	
		break;
	}
	
	while (cor.x ==  town.x[1] && cor.y == town.y[1] && fleeInput != 1) // Town 2
	{   
		printf("\n%s has entered a town!\n", ply->name);	
		break;
	}
	
	while (cor.x ==  town.x[2] && cor.y == town.y[2] && fleeInput != 1) // Town 3
	{   
		printf("\n%s has entered a town!\n", ply->name);	
		break;
	}
	
	while (cor.x ==  road.x[0] && cor.y == road.y[0] && fleeInput != 1) // Road 0
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[1] && cor.y == road.y[1] && fleeInput != 1) // Road 1
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[2] && cor.y == road.y[2] && fleeInput != 1) // Road 2
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
		while (cor.x ==  road.x[3] && cor.y == road.y[3] && fleeInput != 1) // Road 3
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[4] && cor.y == road.y[4] && fleeInput != 1) // Road 4
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[5] && cor.y == road.y[5] && fleeInput != 1) // Road 5
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
		while (cor.x ==  road.x[6] && cor.y == road.y[6] && fleeInput != 1) // Road 6
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[7] && cor.y == road.y[7] && fleeInput != 1) // Road 7
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[8] && cor.y == road.y[8] && fleeInput != 1) // Road 8
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
		while (cor.x ==  road.x[9] && cor.y == road.y[9] && fleeInput != 1) // Road 9
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[10] && cor.y == road.y[10] && fleeInput != 1) // Road 10
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[11] && cor.y == road.y[11] && fleeInput != 1) // Road 11
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[12] && cor.y == road.y[12] && fleeInput != 1) // Road 12
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[13] && cor.y == road.y[13] && fleeInput != 1) // Road 13
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[14] && cor.y == road.y[14] && fleeInput != 1) // Road 14
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
		while (cor.x ==  road.x[15] && cor.y == road.y[15] && fleeInput != 1) // Road 15
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[16] && cor.y == road.y[16] && fleeInput != 1) // Road 16
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[17] && cor.y == road.y[17] && fleeInput != 1) // Road 17
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
		while (cor.x ==  road.x[18] && cor.y == road.y[18] && fleeInput != 1) // Road 18
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[19] && cor.y == road.y[19] && fleeInput != 1) // Road 19
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[20] && cor.y == road.y[20] && fleeInput != 1) // Road 20
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
		while (cor.x ==  road.x[21] && cor.y == road.y[21] && fleeInput != 1) // Road 21
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[22] && cor.y == road.y[22] && fleeInput != 1) // Road 22
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	while (cor.x ==  road.x[23] && cor.y == road.y[23] && fleeInput != 1) // Road 23
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
		while (cor.x ==  road.x[24] && cor.y == road.y[24] && fleeInput != 1) // Road 24
	{   
		printf("\n%s is on a road!\n", ply->name);	
		break;
	}
	
	
	do 					   // Start World Menu Screen
	{ 	
			fleeInput = 0; // Resets Flee to OFF
			printf("\nSelect an Action for %s: ", ply->name);
			printf("\nMove: %i | Lvl: %i | HP: %i | XP: %i | SP: %i | Pos: %i, %i\n", playerMoves, ply->level, ply->health, ply->xp, ply->stamina, cor.x, cor.y);
			puts("1.) Travel North");
			puts("2.) Travel South");
			puts("3.) Travel East");
			puts("4.) Travel West");
			puts("5.) Rest");
			puts("6.) Main Menu");
			puts("7.) Exit Game");
			scanf(" %i", &dungeonInput);
			
				switch (dungeonInput)
				{
					case 1:
						printf("\n%s traveled north.\n", ply->name);
						cor.y = cor.y + 1;    // Increments player's Y Coordinate
						ply->stamina = ply->stamina - 1;
						goto dungeonMenu;
						break;
					case 2:
						printf("\n%s traveled south.\n", ply->name);
						cor.y = cor.y - 1;    // Decrements player's Y Coordinate
						ply->stamina = ply->stamina - 1;
						goto dungeonMenu;
						break;
					case 3:
						printf("\n%s traveled east.\n", ply->name);
						cor.x = cor.x + 1;    // Increments player's X Coordinate
						ply->stamina = ply->stamina - 1;
						goto dungeonMenu;
						break;
					case 4:
						printf("\n%s traveled west.\n", ply->name);
						cor.x = cor.x - 1;    // Decrements player's X Coordinate
						ply->stamina = ply->stamina - 1;
						goto dungeonMenu;
						break;
					case 5: 				  // Adds Stamina based off class
						if (ply->id == 1)
							ply->stamina = ply->stamina + Warrior.stamina;
						if (ply->id == 2)
							ply->stamina = ply->stamina + Mage.stamina;
						if (ply->id == 3)
							ply->stamina = ply->stamina + Assassin.stamina;
						printf("\n%s has rested!\n", ply->name);	
						goto dungeonMenu;
						break;
					case 6:
						printf("\n%s left the World.\n", ply->name);
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
								puts("\nInvalid option!");
								goto dungeonMenu;
								break;
							}
						
						break;
					
					default:
						puts("\nInvalid Option!");
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
						printf("\n%s left the fight!\n", ply->name);
						fleeInput = fleeInput + 1; // Sets Flee ON, so dungeonMenu will NOT loop
						goto dungeonMenu;
						break;
					default:
						puts("\nInvalid option!");
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
		scanf("%i %i",&town.x[3 + i], &town.y[3 + i]);
		printf("\nSuccessfully Created Event @ %i, %i!\n", town.x[3 + i], town.y[3 + i]);
	}
	
	goto menuMain;
};