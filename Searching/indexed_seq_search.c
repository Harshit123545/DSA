#include<stdio.h>
#include<stdlib.h>
#define size 12

int Indexseq( int arr[], int s, int key){
    int valarr[size],indxarr[size],index =0,i;
    int flag1 = 0, flag2 = 0, start,end;
    for(i = 0; i < s; i+=3){
        valarr[index] = arr[i];
        indxarr[index] = i; index++;
    }
    if(key < valarr[0]) return flag1;
    for( i = 0; i < index; i++){
        if(key <= valarr[i]){
            start = indxarr[i-1];
            end= indxarr[i];
            flag2=1;break;
        }
    }

    if(flag2 == 0) {
        start = i; end = s;
    }
    for( i = start; i<=end; i++){
        if(arr[i] == key){
            flag1=1;
            break;
        }
    }
    return flag1;
}


int main(){
    int arr[size] = {10,20,30,40,50,60,70,80,90,100,110,120};
    int key = 50;
    int ans = Indexseq(arr,size,key);
    if( ans == 1){
        printf("value found");
    }
    else{
        printf("value not found");
    }
}