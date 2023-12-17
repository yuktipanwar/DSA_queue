#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

//If Queue is full
int isFull(struct queue *q){
    if(q->r == q->size - 1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct queue *q){
    if(q->r == q->f){
        return 1;
    }else{
        return 0;
    }
}

//ENQUEUE
void enqueue (struct  queue *q, int val){
    if(isFull(q)){
        printf("Queue is Full\n");
    }else{
        q->r++;
        q->arr [q->r] = val;
    }
}

//DEQUEUE
int dequeue (struct  queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is Empty\n");
    }else{
        q-> f++;
        a= q->arr[q->f];
    }
    return a;
}

int main(){

    struct queue q;
    q.size = 3;
    q.f = q.r = -1;
    q.arr = (int *) malloc(q.size*sizeof(int));

    if(isEmpty(&q)){
        printf("Queue is Empty\n");
    }

    //enqueue few elements
    enqueue(&q,12);            // '&' because it is taking the address and assigning value to it.
    enqueue(&q,23);
    enqueue(&q,18); 

      if(isFull(&q)){
        printf("Queue is Full\n");
    }

    printf("Dequeusing element %d\n", dequeue(&q));
    printf("Dequeusing element %d\n", dequeue(&q));
    printf("Dequeusing element %d\n", dequeue(&q));

       if(isEmpty(&q)){
        printf("Queue is Empty\n");
    }

    //drawback of queue
    //enqueue(&q,18); 
    // if(isFull(&q)){
    //     printf("Queue is Full\n");
    // }


    return 0;
}