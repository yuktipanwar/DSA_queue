#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

//GLOBAL VARIABLES
struct Node * f = NULL;
struct Node * r = NULL;

// Function for TRAVERSING
void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the element of Queue-\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//ENQUEUE
void enqueue( int val){
    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full!");
    }else{
        n->data = val;
        n->next = NULL;

        if(f==NULL){
            f=r=n;
        }else{ 
            r->next =n;
            r = n;
        }
    }

}

//DEQUEUE
int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}



int main(){
 
    
    linkedListTraversal(f);

    // printf("Linked list after deletion\n");

    printf("Dequeueing element %d\n ", dequeue());

    enqueue(34);
    enqueue(66);
    enqueue(78);
    enqueue(18);

    printf("Dequeueing element %d\n ", dequeue());
    printf("Dequeueing element %d\n ", dequeue());

    linkedListTraversal(f); 


    return 0;

}