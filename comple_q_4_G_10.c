#include<stdio.h>

int Inversion_pair(int Arr[],int x) ///x=last index
{
    int inversion_pair=0,i,small;
    small=Arr[x];
    for(i=x-1;i>=0;i--)
    {
        if(Arr[i]>small)
            inversion_pair++;
    }
    return inversion_pair;
}

int Find_key(int Arr[],int last_index)
{
    int key,i;
    int big_inversion_pair=Inversion_pair(Arr,last_index);
    key=last_index;
    for(i=last_index-1;i>=0;i--)
    {

        if(Arr[i]<Arr[key])
        {
            int new_inversion_pair=Inversion_pair(Arr,i);
            if(new_inversion_pair>big_inversion_pair)
            {
                big_inversion_pair=new_inversion_pair;
                key=i;
            }
        }
    }
    return key;
}

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

int main()
{
    int c=0,test_case,n,i,answer;
    scanf("%d",&test_case);
    do{
        scanf("%d",&n);
        int array_element=n;
        int A[n];
        for(i=0; i<n; i++)
        {
            scanf("%d",&A[i]);
        }
        New_array(A,n,0);
        c++;
    }while(c<test_case);
    return 0;
}
