#include<stdio.h>

void New_array(int arr[],int total_array_element,int res)
{
    int i,j=0; ///j is the new array index
    res = res+1;
    int key_index=Find_key(arr,total_array_element-1);
    int num=Inversion_pair(arr,key_index);
    int new_array_element=total_array_element-num-1; ///num= num of inversion pair of the key_index, -1 as the key_index element will be eaten no matter what
    if(new_array_element<1)
    {
        printf("%d\n",res);
        return res;
    }
    int N[new_array_element];
    for(i=0;i<total_array_element && j<new_array_element;i++)
    {
        if(arr[i]<=arr[key_index])
        {
            N[j]=arr[i];
            j++;
        }
    }
    New_array(N,new_array_element,res);
}

