#include<stdio.h>

void swap(int *a,int *b){

int temp=*a;
*a=*b;
*b=temp;

}

int par(int arr[],int high,int low){
    int k=low-1;
    for(int i=low;i<high;i++){
        if(arr[i]<arr[high]){
            k++;
            swap(&arr[k],&arr[i]);
        }
    }
    swap(&arr[k+1],&arr[high]);
    return k+1;
}


void quicksort(int arr[],int low,int high){

if(low<high){
    int pi=par(arr,high,low);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);
}

}

int main(){

 int arr[] = {6, 5, 12, 10, 9, 1};
 int size=sizeof(arr)/sizeof(arr[0]);

 quicksort(arr,0,size-1);
 for(int i=0;i<size;i++){
    printf("%d\n",arr[i]);
   
}
 return 0;
}