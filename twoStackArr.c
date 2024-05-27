#include<stdio.h>

#define size 20

int arr[size];
int top1=-1,top2=size;

void isFull1(){
    if(top1==top2-1){
        printf("Stack1 is Full\n");
    }else{
        printf("Stack1 is not zFull\n");
    }
}
void isFull2(){
    if(top2==top1+1){
        printf("Stack2 is Full\n");
    }else{
        printf("Stack2 is not zFull\n");
    }
}

void isEmpty1(){
    if(top1==-1){
        printf("Stack1 is Empty\n");
    }else{
        printf("Stack1 is not Empty\n");
    }
}
void isEmpty2(){
    if(top2==size){
        printf("Stack2 is Empty\n");
    }else{
        printf("Stack2 is not empty\n");
    }
}

void push1(int data){
    if(top1<top2-1){
        top1++;
        arr[top1]=data;
    }else{
        isFull1();
    }
}

void push2(int data){
    if(top2>top1+1){
        top2--;
        arr[top2]=data;
    }else{
        isFull2();
    }

}

void pop1(){
    if(top1>=0){
        int item=arr[top1];
        top1--;
        printf("Popped item is: %d\n",item);
    }else{
        isEmpty1();
    }
}
void pop2(){
    if(top2<size){
        int item=arr[top2];
        top2++;
        printf("Popped element is : %d\n",item);

    }else{
        isEmpty2();
    }
}

void display1(){
    int i;
    printf("Stack one contents: \n");
    for(i=top1;i>=0;i--){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void display2(){
    int i;
    printf("Stack two contents: \n");
    for(i=top2;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int array[size];
    int i;

    isEmpty1();
    isEmpty2();

    for(i=1;i<10;i++){
        push1(i);
    }

    for(i=11;i<20;i++){
        push2(i);
    }

 

    display1();
    display2();


    push1(29);
    push2(30);


    display1();
    display2();

    push1(40);
    push2(46);


    pop1();
    pop2();

    push2(41);
    display1();
    display2();


}