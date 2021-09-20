#include "Exercise1.h"


/** \fn int get_queue_length(CircularArrayQueue list);
 *  \brief Get the number of elements in the current queue.
 *  \param list The current queue.
*/
int get_queue_length(CircularArrayQueue list){
    int x,count = 0;
    for(;list.front != (list.rear +1)%MAX; list.front = (list.front+1) % MAX){
      count++;
    }
    return count;
}

/** \fn PersonLinkedList get_all_females(CircularArrayQueue list);
 *  \brief Returns all females as a linked list using the current list without removing them in the current list.
 *  \param list The current queue.
 *  Note: Use the queue basic operations (enqueue, dequeue, front)
*/
PersonLinkedList get_all_females(CircularArrayQueue list){
    PersonLinkedList femaleList = NULL;
    Person personTemp;
    int originalRear = list.rear;  

    while(list.front != (originalRear+1)%MAX){ // stop when list.front is equal to the original list.rear
      if(list.data[list.front].sex == 'F'){
          //add to linkedlist
          insert_first_LL(&femaleList,list.data[list.front]);
      }
          //remove from the queue and add again at the rear          
          personTemp = front(list);
          dequeue(&list);
          enqueue(&list,personTemp);
    }
    
    return femaleList;
}

/** \fn PersonDynamicArrayList remove_all_males(CircularArrayQueue *list);
 *  \brief Remove all males in the current list and returns the removed males as a dynamic array list.
 *  \param list The current queue.
 *  Note: Use the concept of queue with out using the basic operations.
*/
PersonDynamicArrayList remove_all_males(CircularArrayQueue *list){
    PersonDynamicArrayList new;
    init_DAL(&new);
    Person temp;

    Position originalRear = list->rear;
    while(list->front != (originalRear+1)%MAX){
        if(list->data[list->front].sex == 'M'){
            insert_last_DAL(&new,list->data[list->front]);
        }else{
            temp = list->data[list->front];
            list->rear = (list->rear+1)%MAX;
            list->data[list->rear] = temp;
        }
        list->front = (list->front+1)%MAX;
    }
    return new;
}
