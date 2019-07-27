#include <stdio.h>
#include <stdlib.h>
    
// student structure
struct student {
  char id[15];
  char firstname[64];
  char lastname[64];
  float points;
};

// function declaration
void getDetail(struct student *);
void displayDetail(struct student *);

int main(void) {
  
  struct student std[3];
  int menuInput = 0;
  
  do
		{
			puts("\nType a number for selection: ");
			puts("1.) Get student details");
			puts("2.) Display student details");
			puts("3.) Exit Game");
			scanf(" %i", &menuInput);
			
				switch (menuInput)
				{
					case 1:
						getDetail(std);
						break;
					case 2:
						displayDetail(std);
						break;
					case 3:
						puts("Exiting game...");
						exit(0);
					default:
						puts("Invalid option!");
				}
	
		}while (menuInput = 0);
  return 0;
}

// function definition


void getDetail(struct student *ptr) {

  int i;

  for (i = 0; i < 3; i++) {
    printf("Enter detail of student #%d\n", (i + 1));
    printf("Enter ID: ");
    scanf("%s", ptr->id);
    printf("Enter first name: ");
    scanf("%s", ptr->firstname);
    printf("Enter last name: ");
    scanf("%s", ptr->lastname);
    printf("Enter Points: ");
    scanf("%f", &ptr->points);
    
    // update pointer to point at next element
    // of the array std
    ptr++;
  }
	main();
}

void displayDetail(struct student *ptr) {

  int i;

  for (i = 0; i < 3; i++) {
    printf("\nDetail of student #%d\n", (i + 1));
    
    // display result via ptr variable
    printf("\nResult via ptr\n");
    printf("ID: %s\n", ptr->id);
    printf("First Name: %s\n", ptr->firstname);
    printf("Last Name: %s\n", ptr->lastname);
    printf("Points: %f\n", ptr->points);
    
    // update pointer to point at next element
    // of the array std
    ptr++;
  }
	main();
}