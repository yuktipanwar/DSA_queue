#include <stdio.h>
#include <stdlib.h>

struct circularQueue {
    int size;
    int f;
    int r;
    int *arr;
};

//If Queue is full
int isFull(struct circularQueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }else{
        return 0;
    }
}

//If Queue is Empty (same as linear queue)
int isEmpty(struct circularQueue *q){
    if(q->r == q->f){
        return 1;
    }else{
        return 0;
    }
}

//ENQUEUE
void enqueue (struct  circularQueue *q, int val){
    if(isFull(q)){
        printf("Queue is Full, cannot insert.\n");
    }else{
        q->r= (q->r+1)%q->size;
        q->arr [q->r] = val;
        printf("Enqueue ement: %d\n", val);
    }
}

//DEQUEUE
int dequeue (struct  circularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is Empty, cannot remove.\n");
    }else{
        q-> f= (q->f+1)%q->size;
        a= q->arr[q->f];
    }
    return a;
}

int main(){

    struct circularQueue q;
    q.size = 5;
    q.f = q.r = 0;
    q.arr = (int *) malloc(q.size*sizeof(int));

    if(isEmpty(&q)){
        printf("Queue is Empty\n");
    }

    //enqueue few elements
    enqueue(&q,12);            // '&' because it is taking the address and assigning value to it.
    enqueue(&q,23);
    enqueue(&q,18); 
    enqueue(&q,54); 
    enqueue(&q,66); 

      if(isFull(&q)){
        printf("Queue is Full\n");
    }

    printf("Dequeusing element %d\n", dequeue(&q));
    printf("Dequeusing element %d\n", dequeue(&q));
    printf("Dequeusing element %d\n", dequeue(&q));

       if(isEmpty(&q)){
        printf("Queue is Empty\n");
    }

    enqueue(&q,99);
    enqueue(&q,99); 
    enqueue(&q,99); 
    enqueue(&q,99);

          if(isFull(&q)){
        printf("Queue is Full\n");
    }
    
    return 0;
}