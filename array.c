#include<stdio.h>

//static arr's size remain unchanged
arr[]={1,2,3,4,5,6,7,8,9,10};
size=sizeof(arr)/sizeof(arr[0]);
void insert(int index,int value){
    //a b c d z k
    //--->a b  []  c d z k
    for(int i=size;i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=value;

}

//dynamic array auto grow
typedef struct{
    int *data;
    size_t size;
    size_t capacity;
}DynamicArray;

void grow(DynamicArray* a){
    int new_cap=a->capacity;
    int *newdata=malloc(new_cap*sizeof(int));
    //put old data into newhome
    for(int i=0;i<a->size;i++){
        newdata[i]=a->data[i];

    }
    free(a->data);
    a->data=newdata;
    a->capacity=new_cap;
}


void push_back(DynamicArray* a,int val){
    if(a->size==a->capacity){
        grow(a);
    }
    a->data[a->size]=val;
    a->size++;
}
