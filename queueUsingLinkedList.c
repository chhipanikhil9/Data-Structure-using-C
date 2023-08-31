#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void enqueue();
int dequeue();
void traverse();
int size();
struct node *newNode(int);

struct node{
    int data;
    struct node *next;
};

struct node *head,*tail;

struct node *newNode(int x){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void enqueue(){
    int x;
    struct node *temp;
    printf("Enter the element:\n");
    scanf("%d",&x);

    if(head==NULL){
        head = newNode(x);
    }
    temp = newNode(x);
    temp->next = head;
    tail->next = temp;
}


int dequeue(){
    int ele;
    struct node *temp;
    if(head==NULL){
        printf("Queue is empty!\n");
        return -1;
    }
    ele = head->data;
    head = head->next;
    
    return ele;
}

void traverse(){
    struct node *it = head;
    while(it != NULL){
        printf("%d ",it->data);
        it = it->next;
    }
}

int size(){
    int cnt;
    struct node *it = head;
    cnt = 1;
    while(it != NULL){
        cnt++;
        it = it->next;
    }
    return cnt;
}


int main(){
    int ch,x;
    head = tail = NULL; 
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
            enqueue(x);
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