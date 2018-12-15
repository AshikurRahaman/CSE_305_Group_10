#include<stdio.h>
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
int main ()

{
    int Find_key(int Arr[],int last_index);

}
