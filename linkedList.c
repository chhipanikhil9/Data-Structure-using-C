#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node
{
    char data;
    struct node *next;
};


struct node *head = NULL;


int main(){
    char name[100];
    int n;
    head = NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",name);
    }

    return 0;
}