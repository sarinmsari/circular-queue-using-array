//update code here....

#include <stdio.h>
int queue[10];
int front=-1,rear=-1;

void insert(int elem){
    if(front==0 && rear==9 || front==rear+1){
        printf("\nQueue is full (overflow)");
    }else if(front == -1){
        front =0;
        rear =0;
        queue[rear]= elem;
    }else if(rear == 9){
        rear = 0;
        queue[rear]=elem;
    }else
    {
        rear++;
        queue[rear]=elem;
    }
}

void delete(){
    if(front==-1){
        printf("\nQueue is empty (underflow)");
        return;
    }
    printf("\ndeleted element is %d",queue[front]);
    if (front==rear)
    {
        front=-1;
        rear=-1;
    }else if (front == 9)
    {
        front=0;
    }else
    {
        front++;
    }
}

void display(){
    if(front==-1){
        printf("\nQueue is empty");
        return;
    }
    printf("\nElements are:");
    if(front <= rear){
        while(front <= rear){
            printf("%d",queue[front]);
            if(front==9){
                front=0;
            }else
            {
                front++;
            }
        }
    }else
    {
        while(front <= 9){
            printf("%d",queue[front]);
            if(front==9){
                front=0;
            }else
            {
                front++;
            }
        }
        while(front <= rear){
            printf("%d",queue[front]);
            front++;
        }
    }
    
}

void main(){
    int opt,elem;
    do{
    printf("\nChoose an option,\n1.Insert\n2.Delete\n3.Display\n4.Quit\n");
    scanf("%d",&opt);
        switch (opt)
        {
        case 1: printf("\nEnter element to insert:");
            scanf("%d",&elem);
            insert(elem);
            break;

        case 2: delete();
            break;

        case 3: display();
            break;

        case 4: break;
        
        default: printf("Enter a valid choice!");
            break;
        }
    }while(opt != 4);
}
