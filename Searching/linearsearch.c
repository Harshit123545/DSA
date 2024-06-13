#include<stdio.h>

void search(int arr[], int n, int key)
{
    int i;
    int flag=0;
    for(i=0; i<n ; i++)
    {
        if(arr[i]==key)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("Element %d is Found in the array: ",key);
    }
    else{
        printf("Element %d is Not Found in the array: ",key);
    }
}
int main()
{
    int arr[]={24,45,35,20,50};
    int n=5;
    int key;
    printf("Enter the key to be found in the array: ");
    scanf("%d", &key);
    search(arr,n,key);


}