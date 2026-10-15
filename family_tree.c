#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person {
char name[50];
int age;
struct Person *father;
struct Person *mother;
} Person;

Person* create_person(const char *name, int age) {
    Person *new_person = (Person *)malloc(sizeof(Person));
    if (new_person != NULL)
    {
        strncpy(new_person->name, name, sizeof(new_person->name) -1 );
        new_person->name[sizeof(new_person->name) - 1] = '\0';
        new_person->father = NULL;
        new_person->mother = NULL;
    }
return new_person;    
}

void get_info(const char *role, char *nameout, int *ageout) {
    printf("Enter name for %s: ", role);
    gets(nameout);
    nameout[strcspn(nameout, "\n")] = '\0';

    printf("Enter age for %s", role);
    scanf("%d", ageout);

}


