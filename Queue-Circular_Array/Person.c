#include <stdio.h>
#include <string.h>
#include "Person.h"

Person createPerson(String name, char sex, String city) {
    Person p;
    strcpy(p.name, name);
    p.sex = sex;
    strcpy(p.city, city);
    return p;
}

void displayPersonInfo(Person p) {
    printf("{%s | %c | %s}", p.name, p.sex, p.city);
}


/* Static Array List*/
void init_SAL(PersonStaticArrayList *list);
void insert_first_SAL(PersonStaticArrayList *list, Person p);
void insert_last_SAL(PersonStaticArrayList *list, Person p);
void insert_at_SAL(PersonStaticArrayList *list, Person p, int index);
void delete_first_SAL(PersonStaticArrayList *list);
void delete_last_SAL(PersonStaticArrayList *list);
void delete_by_sex_SAL(PersonStaticArrayList *list, char sex); // all ocurrences
void display_SAL(PersonStaticArrayList list);

/* Dynamic Array List - v1 
 * Doubles the maximum size of the array when full.
 */
void init_DAL(PersonDynamicArrayList *list);
void insert_first_DAL(PersonDynamicArrayList *list, Person p);
void insert_last_DAL(PersonDynamicArrayList *list, Person p);
void insert_at_DAL(PersonDynamicArrayList *list, Person p, int index);
void delete_first_DAL(PersonDynamicArrayList *list);
void delete_last_DAL(PersonDynamicArrayList *list);
void delete_by_city_DAL(PersonDynamicArrayList *list, String city); // first ocurrence
void display_DAL(PersonDynamicArrayList list);

/* Dynamic Array List - v2 
 * Doubles the maximum size of the array when full.
 * The Dynamic Array List must also be created in the heap.
 */
void init_DAL_2(PersonDynamicArrayList **list);
void insert_first_DAL_2(PersonDynamicArrayList *list, Person p);
void insert_last_DAL_2(PersonDynamicArrayList *list, Person p);
void insert_at_DAL_2(PersonDynamicArrayList *list, Person p, int index);
void delete_first_DAL_2(PersonDynamicArrayList *list);
void delete_last_DAL_2(PersonDynamicArrayList *list);
void delete_by_name_DAL_2(PersonDynamicArrayList *list, String name); // last ocurrence
void display_DAL_2(PersonDynamicArrayList list);

/* Singly Linked List */
void insert_first_LL(PersonLinkedList *list, Person p){
    PersonLinkedList *trav;
    PersonLinkedList temp = (PersonLinkedList) malloc(sizeof(PersonNode));

    if(temp != NULL){
        for(trav = list; *trav != NULL; trav = &(*trav)->next){
            temp->elem = p;
            temp->next = *trav;
            *trav = temp;
        }
    }
}


void insert_last_LL(PersonLinkedList *list, Person p){
    PersonLinkedList *trav;
    PersonLinkedList temp = (PersonLinkedList) malloc(sizeof(PersonNode));
    if(temp != NULL){
        for(trav = list; *trav != NULL; trav = &(*trav)->next){}
        temp->elem = p;
        temp->next = *trav;
        *trav = temp;
    }    
}

void insert_after_LL(PersonLinkedList *list, Person p, String name){
    PersonLinkedList *trav;
    PersonLinkedList temp;

    for(trav = list; *trav != NULL && strcmp((*trav)->elem.name,name) != 0 ; trav = &(*trav)->next){}
    if(*trav != NULL){
        temp->elem = p;
        temp->next = (*trav)->next;
        *trav = temp;
    }
}

void delete_first_LL(PersonLinkedList *list){
    PersonLinkedList *trav,temp;
    temp = (*list)->next;
    *list = temp->next;
    free(temp);
}

void delete_last_LL(PersonLinkedList *list);
void delete_by_city_LL(PersonLinkedList *list, String city); // all ocurrences
void display_LL(PersonLinkedList list);


/* Implement all VSpace conncept and Cusor Based List*/
void init_vspace(VSpace *vs);
Position alloc_space(VSpace *vs);
void free_space(VSpace *vs, Position index);
void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p);
void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p);
void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index);
void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list);
void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list);
void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex); // all ocurrences
void display_CBL(VSpace vs, PersonCusorBasedList list);