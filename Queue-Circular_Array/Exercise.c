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
    PersonLinkedList femaleList = NULL,temp;
    int x,queueSize = get_queue_length(list);



    for(x = 0; x < queueSize && list.front != (list.rear+1)%MAX; x++,list.front = (list.front+1)%MAX){
      if(list.data[list.front].sex == 'F'){
        //add to linkedlist
          
          
        } 
        
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

}
