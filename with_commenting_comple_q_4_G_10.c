///with commenting
#include<stdio.h>

int Inversion_pair(int Arr[],int x) ///x is the index of which inversion pair to be found
{
    int inversion_pair=0,i,small;
    small=Arr[x]; ///small = the indexed element
    for(i=x-1;i>=0;i--)  ///checks all the elements of the array
    {
        if(Arr[i]>small)   ///inversion pair condition
            inversion_pair++;
    }
    return inversion_pair;   ///returns the no of inversion_paired elements
}

int Find_key(int Arr[],int last_index)  ///this fn finds the element with most inversion pairs and return its index
{
    int key,i;
    int big_inversion_pair=Inversion_pair(Arr,last_index); ///no of inversion pair of last index
    key=last_index;  ///suppose the last element has most inversion pairs
    for(i=last_index-1;i>=0;i--)  ///checking all the elements
    {

        if(Arr[i]<Arr[key])  ///only the element less than assumed element(last index) may have more inversion pairs than the key element
        {
            int new_inversion_pair=Inversion_pair(Arr,i); ///finds the no of inversion pairs of ith element
            if(new_inversion_pair>big_inversion_pair)  ///if ith has more inversion pairs
            {
                big_inversion_pair=new_inversion_pair;
                key=i; ///i is the key index
            }
        }
    }
    return key; ///returns the index that has most inversion pairs
}

void New_array(int arr[],int total_array_element,int res)   /// this fn removes the key element
 {                                   ///along with all its inversion pair until no element left in the array
    int i,j=0; ///j is the new array index
    res = res+1;
    int key_index=Find_key(arr,total_array_element-1); ///the element index with most inversion paired elements
    int num=Inversion_pair(arr,key_index);  /// no of inversion pair of the selected element
    int new_array_element=total_array_element-num-1; ///num= num of inversion pair of the key_index, -1 as the key_index element will be eaten no matter what
    if(new_array_element<1)   ///when array is empty then print the step and exit from the fn
    {
        printf("%d\n",res);
        return;
    }
    int N[new_array_element];    ///new array to hold the un_inversioned_paired elements
    for(i=0;i<total_array_element && j<new_array_element;i++)
    {
        if(arr[i]<=arr[key_index])  ///checking to find the un_inversion_paired element
        {
            N[j]=arr[i]; ///element storing in the new array
            j++;
        }
    }
    New_array(N,new_array_element,res);  ///fn calling within the fn
}

int main()
{
    int c=0,test_case,n,i,answer; ///n=no of elements, c=to count test case
    scanf("%d",&test_case);
    do{
        scanf("%d",&n);
        int array_element=n;
        int A[n]; ///array to hold the elements
        for(i=0; i<n; i++)
        {
            scanf("%d",&A[i]);
        }
        New_array(A,n,0);  ///here 0 is the step
        c++;
    }while(c<test_case);
    return 0;
}
