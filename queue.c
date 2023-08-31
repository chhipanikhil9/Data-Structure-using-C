
// insert at rear and delete from front
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define capacity 5

void enqueue(int);
int full();
int empty();
void traverse();
int dequeue();

int *queue;
int rear,front;

void enqueue(int x){
    if(full()){
        printf("Queue is full!\n");
        return ;
    }
    queue[rear++] = x;
}

int full(){
    return (rear == capacity)?1:0;
}

int empty(){
    return (rear == front)?1:0;
}


void traverse(){
    int i;
    if(empty()){
        printf("Queue is empty!");
        return;
    }
    for(i=front;i<rear;i++){
        printf("%d ",queue[i]);
    }
}

int dequeue(){
    int ele,i;
    if(empty()){
        printf("Queue is empty!\n");
        return -1;
    }
    ele = queue[front];
    for(i=front+1;i<rear;i++){
        queue[i-1] = queue[i];
    }
    rear--;
    return ele;
}

int main(){
    int ch,x;
    queue = (int *)malloc(sizeof(int)*capacity);
    rear = 0,front = 0;

    label1:
    printf("\nChoices: \n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Traverse\n");
    printf("4. Size\n");
    printf("5. Exit");

    scanf("%d",&ch);
    while(1){
        if(ch==1){
            printf("Enter element: ");
            scanf("%d",&x);
            enqueue(x);
            goto label1;
        }
        else if(ch==2){
            dequeue(x);
            printf("Elements is dequeued!\n");
            goto label1;
        }
        else if(ch==3){
            printf("The Elements are : \n");
            traverse();
            goto label1;
        }
        else if(ch==4){
            printf("Size of the Queue is: %d\n",size());
            goto label1;
        }
        else if(ch==5){
            exit(0);
        }
        else{
            printf("Invalid choice!\n");
            break;
        }
    }


    return 0;
}