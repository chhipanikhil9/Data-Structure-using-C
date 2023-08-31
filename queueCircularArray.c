#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define capacity 15

int isFull();
int isEmpty();
void insert(int);
int dequeue();

int front,rear;
int *queue;

int isEmpty(){
    // check underflow
    // when front and rear=-1;
    return (front==-1)?1:0;
}

int isFull(){
    // check overflow (front==rear+1) front can be anywhere and the second case where 
    // front is 0 and rear is n-1
    return ((front==rear+1) || ((front==0)&&(rear == capacity-1)))?1:0;
}

void insert(int x){
    if(isFull()){
        printf("Queue is Full!\n");
        return;
    }
    
    if(front==-1){
        front = rear = 0;
    }
    else if(rear == capacity-1){
        rear = 0;
    }
    else{
        rear++;
    }
    queue[rear] = x;
    printf("Ele inserted!\n");
}

int dequeue(){
    int x;
    if(isEmpty()){
        printf("Queue is empty!\n");
        return 0;
    }
    x = queue[front];
    // if queue has only one element
    if(front==rear){
        front = rear = -1;
    }
    else if(front == capacity-1){//front is on last pos(n-1) then we have to shift it at 0
        front = 0;
    }
    else{
        front++;
    }
    return x;
}

int size(){
    int cnt,i;
    i = front,cnt = 0;
    if(front==-1){
        printf("Queue is empty!\n");
        return 0;
    }

    if(front>=rear){
        for(i = front;i<capacity;i++){
            cnt++;
        }
    }
    else{
        for(i=0;i<=rear;i++){
            cnt++;
        }
    }
    printf("\n");
    return cnt;
}

void traverse(){
    int i = front;
    if(front==-1){
        printf("Queue is empty!\n");
        return;
    }

    if(front>=rear){
        for(i = front;i<capacity;i++){
            printf("%d->",queue[i]);
        }
    }
    else{
        for(i=0;i<=rear;i++){
            printf("%d->",queue[i]);
        }
    }
    printf("\n");
}

int main(){
    int ch,x;
    front = rear = -1;
    queue = (int *)malloc(sizeof(int)*capacity);
    label1:
    printf("\nChoices: \n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Traverse\n");
    printf("4. Size\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
    scanf("%d",&ch);
    while(1){
        if(ch==1){
            printf("Enter element: ");
            scanf("%d",&x);
            insert(x);
            goto label1;
        }
        else if(ch==2){
            printf("Element %d is dequeued!\n",dequeue());
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