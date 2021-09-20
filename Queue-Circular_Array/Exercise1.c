#include "Exercise1.h"


/** \fn int get_queue_length(CircularArrayQueue list);
 *  \brief Get the number of elements in the current queue.
 *  \param list The current queue.
*/
int get_queue_length(CircularArrayQueue list){
    int x,count = 0;
    for(x = list.front; x != (list.rear +1)%MAX; x = (list.front+1) % MAX){
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
    int x,queueSize = get_queue_length(list); 
    for(x = 0; x < queueSize; x++,list.front = (list.front+1)%MAX){
      if(list.data[list.front].sex == 'F'){
        //add to linkedlist
          insert_first_LL(&femaleList,list.data[list.front]);
          //remove from the queue and add again at the rear          
          personTemp = front(list);
          dequeue(&list);
          enqueue(&list,personTemp);
      }
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
    while(list->front != list->rear){
      if(list->data[list->front].sex == 'M'){
        //remove from list
        temp = list->data[list->front];
        //add to dynamic arr list
        list->front = (list->front + 1)% MAX;
        new.data[new.count++] = temp;
      }else{
         //remove from list and add to the rear
        temp = list->data[list->front];
        list->rear = (list->rear + 1)% MAX;
        list->data[list->rear] = temp;
      }
    }
    return new;
}
