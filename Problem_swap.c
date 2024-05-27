#include<stdio.h>

void findSwapelement(int arr[],int n){
    int x=-1,y=-1;
    int first=-1,second=-1;

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            if(x==-1){
                x=arr[i];
                first=i;
                y=arr[i+1];
                second=i+1;
            }else{
                y=arr[i+1];
                second=i+1;
            }
        }
    }

    if(x!=-1 && y!=-1){
        printf("Swapped Elements are: %d and %d \n",x,y);
        printf("Position at which elements are swapped are: %d and %d \n",first,second);
    }
    else{
        printf("\nNo swapped elements array is sorted");
    }
    
}



int main(){
    int arr[]={1,2,6,4,5,3,7,8,9,};
    int n=sizeof(arr)/sizeof(arr[0]);

    findSwapelement(arr,n);
}