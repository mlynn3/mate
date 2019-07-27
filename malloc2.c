#include <stdio.h>

// Student structure
struct student
{
	char id[15];
	char firstname[64];
	char lastname[64];
	float points;
};

// Function declaration
void getDetail(struct student *);
void displayDetail(struct student *);

int main(void)
{
	// Student strcuture variable
	struct student std[3];
	
	// Get student detail
	getDetail(std);
	
	// Display student detail
	displayDetail(std);
	
	return 0;
}

// Function definition

void getDetail(struct student *ptr)
{
	int i;
	
	for (i = 0; i < 3; i++)
	{
		printf("Enter detail of student #%d\n", (i + 1));
		printf("Enter ID: ");
		scanf("%s", ptr->id);
		printf("Enter first name: ");
		scanf("%s", ptr->firstname);
		printf("Enter last name: ");
		scanf("%s", ptr->lastname);
		printf("Enter points: ");
		scanf("%f", &ptr->points);
		
		// Update pointer to point at next element
		// of the array std
		ptr++;
	}
}

void displayDetail(struct student *ptr)
{
	int i;
	
	for (i = 0; i < 3; i++)
	{
		printf("\nDetail of student #%d\n", (i+1));
		
		// Display result via ptr variable
		printf("\nResult via ptr\n");
		printf("ID: %s\n", ptr->id);
		printf("First Name: %s\n", ptr->firstname);
		printf("Last Name: %s\n", ptr->lastname);
		printf("Points: %f\n", ptr->points);
		
		// Update pointer to point at next element
		// of the array std
		ptr++;
	}
}