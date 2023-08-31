 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>

void push(int);
int pop();
int size();
int peek();
void traverse();


struct node{
    int data;
    struct node *next;
};
struct node *head,*top;


void push(int x){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->next = top;
    top = temp;
}

int pop(){
    if(top==NULL) 
        return 0;
    int ele = top->data;
    top = top->next;
    return ele;
}

void traverse(){
    struct node *temp = top;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int peek(){
    return top->data;
}

int size(){
    int cnt;
    struct node *temp;
    cnt = 0;
    temp = top;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main(){
    int ch,x;
    top = NULL;
    label1:

    printf("\nChoices: \n");
    printf("2. Push\n");
    printf("3. Pop\n");
    printf("4. Traverse\n");
    printf("5. Size\n");
    printf("6. Peek element\n");
    printf("7. Exit");

    scanf("%d",&ch);
    while(1){
        if(ch==2){
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
            printf("Size of the stack is: %d\n",size());
            goto label1;
        }
        else if(ch==6){
            printf("Peek element of the array is: %d\n",peek());
            goto label1;
        }
        else if(ch==7){
            exit(0);
        }
        else{
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
 }