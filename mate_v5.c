#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Player structure
  struct player {
    char name[11]; // Name String
	char class[9]; // Class String
	int level, health, xp, attack, mana, stamina, id, gold; // Player Stats
 };
 
 // Enemy structure
  struct enemy {
    char *name[11]; // Name String
	int level, health, xp, attackMin, attackMax, mana, id, goldMin, goldMax; // Enemy Stats
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
	char *name[3];
  };
  
  // Structure player and classes
  struct player ply[1];
  
  struct player Warrior;
	Warrior.level = 1;
	Warrior.xp = 0;
	Warrior.health = 25;
	Warrior.mana = 10;
	Warrior.stamina = 5;
	Warrior.attack = 4;
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
	
  struct enemy Rat;
	Rat.level = 1;
	Rat.xp = 5;
	Rat.health = 13;
	Rat.attackMin = 1;
	Rat.attackMax = 2;
	Rat.mana = 0;
	Rat.goldMin = 0;
	Rat.goldMax = 3;
	Rat.id = 1;
	
  struct enemy Goblin;
	Goblin.level = 1;
	Goblin.xp = 8;
	Goblin.health = 16;
	Goblin.attackMin = 2;
	Goblin.attackMax = 4;
	Goblin.mana = 5;
	Goblin.goldMin = 3;
	Goblin.goldMax = 10;
	Goblin.id = 2;
	
  struct enemy Ghost;
	Ghost.level = 1;
	Ghost.xp = 15;
	Ghost.health = 23;
	Ghost.attackMin = 3;
	Ghost.attackMin = 6;
	Ghost.mana = 7;
	Ghost.goldMin = 0;
	Ghost.goldMax = 10;
	Ghost.id = 3;
	
  struct enemy Outlaw;
	Outlaw.level = 1;
	Outlaw.xp = 13;
	Outlaw.health = 18;
	Outlaw.attackMin = 3;
	Outlaw.attackMax = 4;
	Outlaw.mana = 0;
	Outlaw.goldMin = 3;
	Outlaw.goldMax = 10;
	Outlaw.id = 4;
  
  struct enemy Bandit;
	Bandit.level = 1;
	Bandit.xp = 14;
	Bandit.health = 20;
	Bandit.attackMin = 2;
	Bandit.attackMax = 2;
	Bandit.mana = 0;
	Bandit.goldMin = 3;
	Bandit.goldMax = 12;
	Bandit.id = 5;
  
  
  // Structure pointer variable
  struct player *ptr = NULL;
  
  // Variables for menus and playerMoves
  int playerMoves = 0, fleeInput = 0, eventCreate = 0, i, diceRoll, fightRoll, attackCalculate;
  char input, exitInput, dungeonInput, menuInput, classInput, battleInput, townInput;
  
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
  ptr->attack = 4;
  ptr->id = 1;
  ptr->gold = 0;
  
  // Proper Randomization
  srand (time(NULL));
  
  // Default player starting coordinates
  struct coordinates cor = {1,1};
  
  // Town coordinates, sets the map  
  struct event_cor town; 
	town.x[0] = 3, town.y[0] = 3, town.name[0] = "Greenwillow"; // Town 1
	town.x[1] = 1, town.y[1] = 9, town.name[1] = "Borleah"; // Town 2
	town.x[2] = 9, town.y[2] = 5, town.name[2] = "Goldmount"; // Town 3
	
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
			puts("4.) Exit Game");
			scanf(" %c", &menuInput);
			
				switch (menuInput) // Chooses Menu
				{
					case '1':
						goto createPlayer;
						break;
					case '2':
						goto displayStats;
						break;
					case '3':
						goto enterDungeon;
						break;
					case '4':
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
					scanf(" %c", &classInput);

				switch (classInput)
					{
					case '1': 							  // Warrior class
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
								
					case '2': 							  // Mage class
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
								
					case '3': 							  // Assassin class
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
		printf("\n%s has entered the town of %s.\n", ply->name, town.name[0]);
		goto townMenu;
		break;
	}
	
	while (cor.x ==  town.x[1] && cor.y == town.y[1] && fleeInput != 1) // Town 2
	{   
		printf("\n%s has entered the town of %s.\n", ply->name, town.name[1]);
		goto townMenu;
		break;
	}
	
	while (cor.x ==  town.x[2] && cor.y == town.y[2] && fleeInput != 1) // Town 3
	{   
		printf("\n%s has entered the town of %s.\n", ply->name, town.name[2]);
		goto townMenu;
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
	
	while (cor.x  >= 4 && cor.y >= 1 && cor.x <= 10 && cor.y <= 4 && fleeInput != 1) // Wilderness 1
	{   
		printf("\n%s is in the wilderness.\n", ply->name);
		goto randomEncounter1;
		break;
	}
	
	while (cor.x  >= 1 && cor.y >= 2 && cor.x <= 2 && cor.y <= 8 && fleeInput != 1) // Wilderness 2
	{   
		printf("\n%s is in the wilderness.\n", ply->name);
		goto randomEncounter2;		
		break;
	}
	
	while (cor.x  >= 4 && cor.y >= 6 && cor.x <= 8 && cor.y <= 8 && fleeInput != 1) // Wilderness 3
	{   
		printf("\n%s is in the wilderness.\n", ply->name);
		goto randomEncounter3;
		break;
	}
	
	while (cor.x  >= 1 && cor.y >= 10 && cor.x <= 9 && cor.y <= 10 && fleeInput != 1) // Wilderness 4
	{   
		printf("\n%s is in the wilderness.\n", ply->name);
		goto randomEncounter4;
		break;
	}
	
		while (cor.x  >= 10 && cor.y >= 5 && cor.x <= 10 && cor.y <= 10 && fleeInput != 1) // Wilderness 5
	{   
		printf("\n%s is in the wilderness.\n", ply->name);
		goto randomEncounter5;
		break;
	}
	
worldMenu:
	do 			  // Start World Menu Screen
	{ 	
			fleeInput = 0; // Resets Flee to OFF
			printf("\nSelect an Action for %s: ", ply->name);
			printf("\nMove: %i | Lvl: %i | HP: %i | XP: %i | SP: %i | Pos: %i, %i | Gold: %i\n", playerMoves, ply->level, ply->health, ply->xp, ply->stamina, cor.x, cor.y, ply->gold);
			puts("1.) Travel North");
			puts("2.) Travel South");
			puts("3.) Travel East");
			puts("4.) Travel West");
			puts("5.) Rest");
			puts("6.) Main Menu");
			puts("7.) Exit Game");
			scanf(" %c", &dungeonInput);
			
				switch (dungeonInput)
				{
					case '1':
						printf("\n%s traveled north.\n", ply->name);
						cor.y = cor.y + 1;    // Increments player's Y Coordinate
						ply->stamina = ply->stamina - 1;
						goto dungeonMenu;
						break;
					case '2':
						printf("\n%s traveled south.\n", ply->name);
						cor.y = cor.y - 1;    // Decrements player's Y Coordinate
						ply->stamina = ply->stamina - 1;
						goto dungeonMenu;
						break;
					case '3':
						printf("\n%s traveled east.\n", ply->name);
						cor.x = cor.x + 1;    // Increments player's X Coordinate
						ply->stamina = ply->stamina - 1;
						goto dungeonMenu;
						break;
					case '4':
						printf("\n%s traveled west.\n", ply->name);
						cor.x = cor.x - 1;    // Decrements player's X Coordinate
						ply->stamina = ply->stamina - 1;
						goto dungeonMenu;
						break;
					case '5': 				  // Adds Stamina based off class
						if (ply->id == 1)
							ply->stamina = ply->stamina + Warrior.stamina;
						if (ply->id == 2)
							ply->stamina = ply->stamina + Mage.stamina;
						if (ply->id == 3)
							ply->stamina = ply->stamina + Assassin.stamina;
						printf("\n%s has rested!\n", ply->name);	
						goto dungeonMenu;
						break;
					case '6':
						printf("\n%s left the World.\n", ply->name);
						cor.x = 0, cor.y = 0; //Resets player coordinates
						playerMoves = 0;	  //Resets player moves
						goto menuMain;
						break;
					case '7':
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
	
randomEncounter1: // Enemies for section 1, 2/6 chance you will encounter an enemy
	
	for (i = 1; i <= 1; i++)
	{
		diceRoll = ( rand() % 6 ) + 1;	

		switch(diceRoll)
		{
			case 1:
				goto worldMenu;
			case 2:
				goto worldMenu;
			case 3:
				goto worldMenu;
			case 4:
				printf("\n%s encountered a Outlaw!\n", ply->name);
				goto battleMenu;
			case 5:
				printf("\n%s encountered a Bandit!\n", ply->name);
				goto battleMenu;
			case 6:
				goto worldMenu;
		}
	}

randomEncounter2: // Enemies for section 2, 4/6 chance you will encounter an enemy
	
	for (i = 1; i <= 1; i++)
	{
		diceRoll = ( rand() % 6 ) + 1;	

		switch(diceRoll)
		{
			case 1:
				printf("\n%s encountered a Rat!\n", ply->name);
				goto battleMenu;
			case 2:
				printf("\n%s encountered a Goblin!\n", ply->name);
				goto battleMenu;
			case 3:
				goto worldMenu;
			case 4:
				printf("\n%s encountered a Outlaw!\n", ply->name);
				goto battleMenu;
			case 5:
				printf("\n%s encountered a Bandit!\n", ply->name);
				goto battleMenu;
			case 6:
				goto worldMenu;
		}
	}
	
randomEncounter3: // Enemies for section 3, 4/6 chance you will encounter an enemy
	
	for (i = 1; i <= 1; i++)
	{
		diceRoll = ( rand() % 6 ) + 1;	

		switch(diceRoll)
		{
			case 1:
				printf("\n%s encountered a Rat!\n", ply->name);
				goto battleMenu;
			case 2:
				printf("\n%s encountered a Goblin!\n", ply->name);
				goto battleMenu;
			case 3:	
				goto worldMenu;
			case 4:
				printf("\n%s encountered a Outlaw!\n", ply->name);
				goto battleMenu;
			case 5:
				printf("\n%s encountered a Bandit!\n", ply->name);
				goto battleMenu;
			case 6:
				goto worldMenu;
		}
	}
	
randomEncounter4: // Enemies for section 4, 4/6 chance you will encounter an enemy
	
	for (i = 1; i <= 1; i++)
	{
		diceRoll = ( rand() % 6 ) + 1;	

		switch(diceRoll)
		{
			case 1:
				printf("\n%s encountered a Rat!\n", ply->name);
				goto battleMenu;
			case 2:
				printf("\n%s encountered a Goblin!\n", ply->name);
				goto battleMenu;
			case 3:
				goto worldMenu;
			case 4:
				printf("\n%s encountered a Outlaw!\n", ply->name);
				goto battleMenu;
			case 5:
				printf("\n%s encountered a Bandit!\n", ply->name);
				goto battleMenu;
			case 6:
				goto worldMenu;
		}
	}
	
randomEncounter5: // Enemies for section 5, 5/6 chance you will encounter an enemy
	
	for (i = 1; i <= 1; i++)
	{
		diceRoll = ( rand() % 6 ) + 1;	

		switch(diceRoll)
		{
			case 1:
				printf("\n%s encountered a Rat!\n", ply->name);
				goto battleMenu;
			case 2:
				printf("\n%s encountered a Goblin!\n", ply->name);
				goto battleMenu;
			case 3:
				printf("\n%s encountered a Ghost!\n", ply->name);
				goto battleMenu;
			case 4:
				printf("\n%s encountered a Outlaw!\n", ply->name);
				goto battleMenu;
			case 5:
				printf("\n%s encountered a Bandit!\n", ply->name);
				goto battleMenu;
			case 6:
				goto worldMenu;
		}
	}
	
battleMenu:
	
	while (diceRoll == Rat.id){    // Shows the Rat's stats
    printf("\nDetails of Rat:");
	printf("\nLvl: %d", Rat.level);
	printf("\nHP: %d\n", Rat.health);
	break;
	}
		
	while (diceRoll == Goblin.id){ // Shows the Goblin's stats
    printf("\nDetails of Goblin:", Goblin.name);
	printf("\nLvl: %d", Goblin.level);
	printf("\nHP: %d\n", Goblin.health);
	break;}
	
	while (diceRoll == Ghost.id){  // Shows the Ghost's stats
    printf("\nDetails of Ghost:", Ghost.name);
	printf("\nLvl: %d", Ghost.level);
	printf("\nHP: %d\n", Ghost.health);
	break;}
	
	while (diceRoll == Outlaw.id){ // Shows the Outlaw's stats
    printf("\nDetails of Outlaw:", Outlaw.name);
	printf("\nLvl: %d", Outlaw.level);
	printf("\nHP: %d\n", Outlaw.health);
	break;}
	
	while (diceRoll == Bandit.id){ // Shows the Bandit's stats
    printf("\nDetails of Bandit:", Bandit.name);
	printf("\nLvl: %d", Bandit.level);
	printf("\nHP: %d\n", Bandit.health);
	break;}
	
	do 			  // Start Battle Menu
	{ 	
			puts("\nType a Number for Selection: ");
			printf("Move: %i | Lvl: %i | HP: %i | XP: %i | SP: %i | Pos: %i, %i | Gold: %i\n", playerMoves, ply->level, ply->health, ply->xp, ply->stamina, cor.x, cor.y, ply->gold);
			puts("1.) Attack");
			puts("2.) Magic");
			puts("3.) Item");
			puts("4.) Escape");
			scanf(" %c", &battleInput);
			
				switch (battleInput)
				{
					case '1': 						
						
						while (diceRoll == Rat.id)    // Attack Rat
						{
							Rat.health = Rat.health - ply->attack; //Player attacks Rat
							printf("\n%s did %i damage to the Rat!\n", ply->name, ply->attack);	
							
							if (Rat.health <= 0)
							{
								Rat.health = 0;
								printf("\n%s killed the Rat!\n", ply->name);
								ply->gold = ply->gold + Rat.goldMax;
								printf("\n%s gained %i gold.", ply->name, Rat.goldMax);
								ply->xp = ply->xp + Rat.xp;
								printf("\n%s gained %i XP.\n",ply->name, Rat.xp);
								Rat.health = 13;	 // Reset the Rat's health
								attackCalculate = 0; // Reset the calculator
								goto worldMenu;
								break;
							}
							
							attackCalculate = Rat.attackMin + rand() % (Rat.attackMax + 1 - Rat.attackMin); //Rat attacks Player
							ply->health = ply->health - attackCalculate;
							printf("\nThe Rat attacks! %s takes %i damage!\n", ply->name, attackCalculate);
						
						goto battleMenu;
						break;
						}

						while (diceRoll == Goblin.id)    // Attack Goblin
						{
							Goblin.health = Goblin.health - ply->attack; //Player attacks Goblin
							printf("\n%s did %i damage to the Goblin!\n", ply->name, ply->attack);	
							
							if (Goblin.health <= 0)
							{
								Goblin.health = 0;
								printf("\n%s killed the Goblin!\n", ply->name);
								ply->gold = ply->gold + Goblin.goldMax;
								printf("\n%s gained %i gold.", ply->name, Goblin.goldMax);
								ply->xp = ply->xp + Goblin.xp;
								printf("\n%s gained %i XP.\n",ply->name, Goblin.xp);
								Goblin.health = 16;	 // Reset the Goblin's health
								attackCalculate = 0; // Reset the calculator
								goto worldMenu;
								break;
							}
							
							attackCalculate = Goblin.attackMin + rand() % (Goblin.attackMax + 1 - Goblin.attackMin); //Goblin attacks Player
							ply->health = ply->health - attackCalculate;
							printf("\nThe Goblin attacks! %s takes %i damage!\n", ply->name, attackCalculate);
						
						goto battleMenu;
						break;
						}						
						
						while (diceRoll == Ghost.id)    // Attack Ghost
						{
							Ghost.health = Ghost.health - ply->attack; //Player attacks Ghost
							printf("\n%s did %i damage to the Ghost!\n", ply->name, ply->attack);	
							
							if (Ghost.health <= 0)
							{
								Ghost.health = 0;
								printf("\n%s killed the Ghost!\n", ply->name);
								ply->gold = ply->gold + Ghost.goldMax;
								printf("\n%s gained %i gold.", ply->name, Ghost.goldMax);
								ply->xp = ply->xp + Ghost.xp;
								printf("\n%s gained %i XP.\n",ply->name, Ghost.xp);
								Ghost.health = 23;	 // Reset the Ghost's health
								attackCalculate = 0; // Reset the calculator
								goto worldMenu;
								break;
							}
							
							attackCalculate = Ghost.attackMin + rand() % (Ghost.attackMax + 1 - Ghost.attackMin); //Ghost attacks Player
							ply->health = ply->health - attackCalculate;
							printf("\nThe Ghost attacks! %s takes %i damage!\n", ply->name, attackCalculate);
						
						goto battleMenu;
						break;
						}

						while (diceRoll == Outlaw.id)    // Attack Outlaw
						{
							Outlaw.health = Outlaw.health - ply->attack; //Player attacks Outlaw
							printf("\n%s did %i damage to the Outlaw!\n", ply->name, ply->attack);	
							
							if (Outlaw.health <= 0)
							{
								Outlaw.health = 0;
								printf("\n%s killed the Outlaw!\n", ply->name);
								ply->gold = ply->gold + Outlaw.goldMax;
								printf("\n%s gained %i gold.", ply->name, Outlaw.goldMax);
								ply->xp = ply->xp + Outlaw.xp;
								printf("\n%s gained %i XP.\n",ply->name, Outlaw.xp);
								Outlaw.health = 18;	 // Reset the Outlaw's health
								attackCalculate = 0; // Reset the calculator
								goto worldMenu;
								break;
							}
							
							attackCalculate = Outlaw.attackMin + rand() % (Outlaw.attackMax + 1 - Outlaw.attackMin); //Outlaw attacks Player
							ply->health = ply->health - attackCalculate;
							printf("\nThe Outlaw attacks! %s takes %i damage!\n", ply->name, attackCalculate);
						
						goto battleMenu;
						break;
						}

						while (diceRoll == Bandit.id)    // Attack Bandit
						{
							Bandit.health = Bandit.health - ply->attack; //Player attacks Bandit
							printf("\n%s did %i damage to the Bandit!\n", ply->name, ply->attack);	
							
							if (Bandit.health <= 0)
							{
								Bandit.health = 0;
								printf("\n%s killed the Bandit!\n", ply->name);
								ply->gold = ply->gold + Bandit.goldMax;
								printf("\n%s gained %i gold.", ply->name, Bandit.goldMax);
								ply->xp = ply->xp + Bandit.xp;
								printf("\n%s gained %i XP.\n",ply->name, Bandit.xp);
								Bandit.health = 20;	 // Reset the Bandit's health
								goto worldMenu;
								break;
							}
							
							attackCalculate = Bandit.attackMin + rand() % (Bandit.attackMax + 1 - Bandit.attackMin); //Bandit attacks Player
							ply->health = ply->health - attackCalculate;
							printf("\nThe Bandit attacks! %s takes %i damage!\n", ply->name, attackCalculate);
						
						goto battleMenu;
						break;
						}						
							
					case '2':
						puts("\nThis option is still in development.");
						goto battleMenu;
						break;
					case '3':
						puts("\nThis option is still in development.");
						goto battleMenu;
						break;
					case '4':
						printf("\n%s left the fight!\n", ply->name);
						fleeInput = fleeInput + 1;    // Sets Flee ON, so worldMenu will NOT loop
						goto dungeonMenu;
						break;
					default:
						puts("\nInvalid option!");
						goto battleMenu;
						break;
				}
	}while (battleInput = 0);
	
townMenu:
	do 			  // Start Town Menu
	{ 	
			puts("\nType a Number for Selection: ");
			puts("1.) Item Shop");
			puts("2.) Weapon Shop");
			puts("3.) Talk to Townsfolk");
			puts("4.) Leave the Town");
			scanf(" %c", &townInput);
			
				switch (townInput)
				{
					case '1':
						puts("\nItem Shop Menu");
						goto townMenu;
						break;
					case '2':
						puts("\nWeapon Shop Menu");
						goto townMenu;
						break;
					case '3':
						puts("\nTalk to Townsfolk");
						goto townMenu;
						break;
					case '4':
						printf("\n%s left the town.\n", ply->name);
						goto worldMenu;
						break;
					default:
						puts("\nInvalid option!");
						goto townMenu;
						break;
				}
	}while (townInput = 0);
	
};

