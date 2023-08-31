#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define capacity 5
int pop();
void push(int);
int isFull();
int isEmpty();
void traverse();
int peek();
int size();

int stack[capacity];
int top = -1;

int pop(){
    if(isEmpty()){
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top--];
}

void push(int x){
    if(isFull()){
        return ;
    }
    stack[++top] = x;
}

int isFull(){
    return (top==capacity)?1:0;
}

int isEmpty(){
    return (top==-1)?1:0;
}

int peek(){
    if(isEmpty()){
        return 0;
    }
    return stack[top];
}

int size(){
    return top+1;
}

void traverse(){
    if(isEmpty()){
        printf("Stack is empty!\n");
        return;
    }

    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
}

int main(){

    label1:

    printf("\n1. Creation\n");
    printf("2. Push\n");
    printf("3. Pop\n");
    printf("4. Traverse\n");
    printf("5. isEmpty\n");
    printf("6. isFull\n");
    printf("7. Size\n");
    printf("8. Peek element\n");
    int ch;
    scanf("%d",&ch);
    while(1){
        if(ch==2){
            int x;
            printf("Enter element: ");
            scanf("%d",&x);
            push(x);
            goto label1;
        }
        else if(ch==3){
            printf("Elements is:%d\n",pop());
            goto label1;
        }
        else if(ch==4){
            printf("The Elements are : \n");
            traverse();
            goto label1;
        }
        else if(ch==5){

        }
        else if(ch==6){

        }
        else if(ch==7){
            printf("Size of the stack is: %d\n",size());
            goto label1;
        }
        else if(ch==8){
            printf("Peek element of the array is: %d\n",peek());
            goto label1;
        }
        else{
            printf("Invalid choice!\n");
            break;
        }
    }


    return 0;
}