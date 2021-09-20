#include <stdio.h>
#include <string.h>
#include "Exercise1.c"
#include "Person.c"
#include "CircularArrayQ.c"

int main(void){

    // To do code logic here.
    CircularArrayQueue mylist = create_array_queue();
    PersonDynamicArrayList dynamicList;
    PersonLinkedList personList = NULL;
    init_array_queue(&mylist);
    
    enqueue(&mylist,createPerson("Erika",'F',"Cebu"));
    enqueue(&mylist,createPerson("Cliford",'M',"Lapu-Lapu"));
    enqueue(&mylist,createPerson("Rae",'F',"Cordova"));
    enqueue(&mylist,createPerson("Keasar",'M',"Bohol"));
    enqueue(&mylist,createPerson("Hannah",'F',"Quezon"));


    //Display the linkedlist of females extracted from the circular array queue
    personList = get_all_females(mylist);
    display_LL(personList);

    //Display all the males removed from the circular array
    // dynamicList = remove_all_males(&mylist);
    // display_DAL(dynamicList);
    
    return 0;
}