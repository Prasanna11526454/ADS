#include<stdio.h>

typedef struct{
    int Roll_No;
    char Name[50];
    int tot_Marks;
}Student;

void swap(Student *a, Student *b){
    Student temp=*a;
    *a=*b;
    *b=temp;
}

int partition(Student arr[],int low,int high,int *count){
    int pivot=arr[low].Roll_No;
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i].Roll_No<=pivot){
            i++;
        }while(arr[j].Roll_No>pivot){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
            (*count)++;
        }
    }
    swap(&arr[low],&arr[j]);
    (*count)++;
    return j;
}


void qsort(Student arr[],int low,int high,int *count){
    int pindex;
    if(low<high){
    pindex=partition(arr,low,high,count);
    qsort(arr,low,pindex-1,count);
    qsort(arr,pindex+1,high,count);
    }
}

void printArray(Student arr[],int n){
    for(int i=0;i<n;i++){
     printf("Roll No:%d Name:%s Tot_Marks:%d\n",arr[i].Roll_No,arr[i].Name,arr[i].tot_Marks);
    }
}



int main(){
    Student arr[]={
        {10,"Virat",90},
        {5,"Rohit",98},
        {2,"Shikar",95},
        {1,"ABD",79},
        {6,"erty",90},
        {4,"swert",76},
        {3,"hytr",80},
    };

    int n=sizeof(arr)/sizeof(arr[0]);
    int count=0;

   
    printf("Original Array :\n ");
    printArray(arr,n);
    qsort(arr,0,n-1,&count);
    
    printf("Sorted  Array :\n ");
    printArray(arr,n);

    printf("Total Count is:%d ",count);
    

}