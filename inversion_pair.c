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

int main()
{
    int n,i;
    printf("Enter element:\n");
    scanf("%d",&n);
    int A[n];
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    int s;
    printf("enter element index to check inversion pair\n");
    scanf("%d",&s);
    int x=Inversion_pair(A,s);
    printf("%d has %d inversion pair\n",A[s],x);
}
