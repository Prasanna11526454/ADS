#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int Roll_No;
    char Name[50];
    int tot_marks;
}Student;

void swap(Student *a,Student *b){
    Student temp=*a;
    *a=*b;
    *b=temp;
}

void maxheap(Student arr[],int i,int n,int *swapcount){
    int child;
    while(2*i+1<n){
        child=2*i+1;
        if(arr[child+1].Roll_No>arr[child].Roll_No && child+1<n){
            child=child+1;
        }
        if(arr[child].Roll_No>arr[i].Roll_No){
            swap(&arr[child],&arr[i]);
            (*swapcount)++;
        }else{
            break;
        }
      i=child;
    }

}

void heapsort(Student arr[],int n,int *swapcount){
    int i;
    for(i=n/2-1;i>=0;i--){
        maxheap(arr,i,n,swapcount);
    }

    for(i=n-1;i>0;i--){
        swap(&arr[0],&arr[i]);
        maxheap(arr,0,i,swapcount);
        (*swapcount)++;
    }
}


void printArray(Student arr[], int n) {
    printf("Sorted Students by Roll Number:\n");
    for (int i = 0; i < n; i++) {
        printf(" Roll No: %d,Name: %s, Total Marks: %d\n",  arr[i].Roll_No,arr[i].Name, arr[i].tot_marks);
    }
}



int main(){
    Student arr[]={
        {2,"Kartar",98},
        {5,"Vishal",60},
        {4,"Rohit",80},
        {1,"Om",54},
        {3,"Danni",85},
    };

    int n=sizeof(arr)/sizeof(arr[0]);

    int swapcount=0;

    heapsort(arr,n,&swapcount);

    printf("Sorted Array : \n");

    printArray(arr,n);
    

    printf("Total Swap Count is  :%d ",swapcount);
}