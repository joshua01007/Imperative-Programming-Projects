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
        new_person->age = age;
    }
return new_person;    
}

void get_info(const char *role, char *nameout, int *ageout) {
    printf("Enter name for %s: ", role);
    fgets(nameout, 50, stdin);
    nameout[strcspn(nameout, "\n")] = '\0';

    printf("Enter age for %s", role);
    scanf("%d", ageout);
}

void print_family_relationships(const Person *me){
    printf("\n === Family Tree Relationships ===\n");
    printf("1. Yourself:\n");
    printf(" - Name: %s | Age: %d\n", me->name, me->age);

    printf("2. Parents:\n");
    if(me->father){
        printf(" - Father: %s | Age: %d\n", me->father->name, me->father->age);
    }
    if(me->mother){
        printf(" - Mother: %s | Age: %d\n", me->mother->name, me->mother->age);
    }

    printf("3. Paternal Grandparents (via Fathers Pointers):\n");
    if(me->father && me->father->father)
    {
        printf(" - Grandfather: %s | Age: %d\n", me->father->father->name, me->father->father->age);
    }

    if(me->father && me->father->mother){
        printf(" - Grandmother: %s | Age: %d\n", me->father->mother->name, me->father->mother->age);
    }
}

 
void free_family_tree(Person *people[], int count) {
        for (int i = 0; i < count; i++)
        {
            free(people[i]);
        }
}



int main(){
    Person *people[7];
    char name[50];
    int age;


    const char *role[7] = {
        "Yourself",
        "Father",
        "Mother",
        "Paternal Grandfather",
        "Paternal Grandmother",
        "Maternal Grandfather",
        "Mathernal Grandmother"

    };


    for (int i = 0; i < 7; i++)
    {
        get_info(role[i], name, &age);
        people[i] = create_person(name, age);
    }

    Person *me = people[0];
    Person *father = people[1];
    Person *mother = people[2];
    Person *pgf = people[3];
    Person *pgm = people[4];
    Person *mgf = people[5];
    Person *mgm = people[6];

}





