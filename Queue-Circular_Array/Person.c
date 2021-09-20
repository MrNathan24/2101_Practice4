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
void init_DAL(PersonDynamicArrayList *list){
    list->max = MAX_LIST;
    list->count = 0;
    list->data = (Person *) malloc(sizeof(Person));
}

void insert_first_DAL(PersonDynamicArrayList *list, Person p){
    int x;
    if(list->count >= list->max){
        list->max *= 2;
        list->data = realloc(list->data, list->max);
    }else{
        //shif data to the right
        for(x = list->count; x > 0;x--){
            list->data[x] = list->data[x-1];   
        }
        list->data[0] = p;
        list->count++;
    }
}

void insert_last_DAL(PersonDynamicArrayList *list, Person p){
    if(list->count >= list->max){
        list->max *=2;
        list->data = realloc(list->data,list->max);
    }
        list->data[list->count++] = p;
    
}

void insert_at_DAL(PersonDynamicArrayList *list, Person p, int index){
    if(index >= list->max){
        list->max *=2;
        list->data = realloc(list->data,list->max);
    }else{
        int x;
        for(x = list->count; x > index; x--){
            list->data[x] = list->data[x-1];
        }
        list->data[index] = p;
        list->count++;
    }
}

void delete_first_DAL(PersonDynamicArrayList *list){
    if(list->count > 0){
        int x;
        for(x = 0; x < list->count; x++){
            list->data[x] = list->data[x+1];
        }
        list->count--;
    }
}

void delete_last_DAL(PersonDynamicArrayList *list){
    list->count--;
}

void delete_by_city_DAL(PersonDynamicArrayList *list, String city){
    if(list->count > 0){
        int x,y;
        for(x = 0; x < list->count && strcmp(list->data[x].city,city) != 0;x++){} // exits when city is found
        if(x != list->count){
            for(y = x; y < list->count;y++){
                list->data[y] = list->data[y+1];
            }
            list->count--;
        }
    }
}


void display_DAL(PersonDynamicArrayList list){
    if(list.count > 0){
        int x;
        for(x = 0; x < list.count;x++){
        displayPersonInfo(list.data[x]);
        }
    }
}

/* Dynamic Array List - v2 
 * Doubles the maximum size of the array when full.
 * The Dynamic Array List must also be created in the heap.
 */
void init_DAL_2(PersonDynamicArrayList **list){
    (*list) = (PersonDynamicArrayList *) malloc(sizeof(PersonDynamicArrayList));
    (*list)->max = MAX_LIST;
    (*list)->count = 0;
    (*list)->data = (Person *) malloc(sizeof(Person));
}

void insert_first_DAL_2(PersonDynamicArrayList *list, Person p){
    int x;
    if(list->count >= list->max){
        list->max *= 2;
        list->data = realloc(list->data, list->max);
    }else{
        //shif data to the right
        for(x = list->count; x > 0;x--){
            list->data[x] = list->data[x-1];   
        }
        list->data[0] = p;
        list->count++;
    }
}

void insert_last_DAL_2(PersonDynamicArrayList *list, Person p){
    if(list->count >= list->max){
        list->max *=2;
        list->data = realloc(list->data,list->max);
    }
    list->data[list->count++] = p;
    
}
void insert_at_DAL_2(PersonDynamicArrayList *list, Person p, int index){
    if(index >= list->max){
        list->max *=2;
        list->data = realloc(list->data,list->max);
    }else{
        int x;
        for(x = list->count; x > index; x--){
            list->data[x] = list->data[x-1];
        }
        list->data[index] = p;
        list->count++;
    }
}
void delete_first_DAL_2(PersonDynamicArrayList *list){
  if(list->count > 0){
        int x;
        for(x = 0; x < list->count; x++){
            list->data[x] = list->data[x+1];
        }
        list->count--;
    }
}
void delete_last_DAL_2(PersonDynamicArrayList *list){
    list->count--;
}

void delete_by_name_DAL_2(PersonDynamicArrayList *list, String name){ // last occurence
    if(list->count > 0){
        int x,y;
        for(x = list->count; x > 0 && strcmp(list->data[x].name,name) != 0; x--){}
        if(x > 0){
            for(y = x; y < list->count;y++){
                list->data[y] = list->data[y+1];
            }
        }
    }
}


void display_DAL_2(PersonDynamicArrayList list){
    if(list.count > 0){
        int x;
        for(x = 0; x < list.count;x++){
        displayPersonInfo(list.data[x]);
        }
    }
}

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
    PersonLinkedList temp;
    temp = (*list)->next;
    *list = temp->next;
    free(temp);
}

void delete_last_LL(PersonLinkedList *list){
    PersonLinkedList *trav,temp;

    for(trav = list; *trav != NULL && (*trav)->next != NULL; trav = &(*trav)->next){}
    if(*trav != NULL){
        temp = (*trav)->next;
        (*trav)->next = NULL;
        free(temp);
    } 
}
void delete_by_city_LL(PersonLinkedList *list, String city){
    PersonLinkedList *trav,temp;

    for(trav = list; *trav !=  NULL && strcmp((*trav)->elem.city, city) != 0;){
        if(*trav!= NULL){
            temp = (*trav)->next;
            *trav = temp->next;
            free(temp);
        }else{
            trav = &(*trav)->next;
        }
    }
}

void display_LL(PersonLinkedList list){
    PersonLinkedList trav;
    for(trav = list;list != NULL;list = list->next){
        displayPersonInfo(list->elem);
    }
}


/* Implement all VSpace conncept and Cusor Based List*/
void init_vspace(VSpace *vs){
    int x;
    for(x = 0; x < MAX_VSPACE;x++){
        vs->data[x].next = (x == MAX_VSPACE - 1)? -1: x+1;
    }
    vs->avail = 0;
}
Position alloc_space(VSpace *vs){
    Position temp = vs->avail;
    if(temp != -1){
        vs->avail = vs->data[temp].next;
    }
    return temp;
}

void free_space(VSpace *vs, Position index){
    if(index != -1 && index < MAX_VSPACE){
        vs->data[index].next = vs->avail;
        vs->avail = index;
    }
}

void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
    Position temp = alloc_space(vs);

    if(temp != -1){
       vs->data[temp].elem = p;
       vs->data[temp].next = *list;
        *list = temp;
    }
}


void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list){
    Position temp;
    if(*list!= -1) {
        temp = *list;
        *list= vs->data[temp].next;
        free_space(vs, temp);
    }
}

void display_CBL(VSpace vs, PersonCusorBasedList list){
    printf("\n{");
  for(;list != -1; list = vs.data[list].next){
    printf("%d ",vs.data[list].elem);
  }
    printf("}\n");
}



void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex); // all ocurrences
void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p);
void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list);
void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index);
void displayList(VSpace myspace, PersonCusorBasedList list); 