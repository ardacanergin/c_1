//Arda Can Ergin 150123060

//this program creates an integer array from 1 to n, n is decided by the user
//returns an integer based on the following computation
//Starting from left to right, remove the first number and every other number afterward
//until you reach the end of the list.
//Repeat the previous step again, but this time from right to left, remove the rightmost
//number and every other number from the remaining numbers.
//Keep repeating the steps again, alternating left to right and right to left, until a single
//number remains

#include <stdio.h>
#include <stdlib.h>
//execute it with -std=c99 compiler option

void createArray(int*,int n);
int computeIteration(int array[],int size);
int computeRecursion(int array[],int size);
void reverseArray(int array[],int size);

int main(void)
{
    printf("enter an integer\n");
    int n;
    scanf("%d",&n);
    int array1[n];
    int array2[n];
    //arrays are pass by reference
    createArray(array1,n);
    createArray(array2,n);
    printf("%s:%d\n","iteration",computeIteration(array1,n));
    printf("%s:%d","recursion",computeRecursion(array2,n));

}

void createArray(int newArray[],int n)
{
    for(int i=0; i<n; i++)
    {
        newArray[i]=i+1;
    }
}
int computeIteration(int array[], int size)
{
    int record=0; //it will help to decide whether the deletion will be done from left or right side of the array
    while(size>1)
    {
        //if it is an add numbered operation array will be reversed and operation will be performed
        if(record%2!=0)
        {
            reverseArray(array,size);
        }
        size = size/2;
        for(int i=0; i<size; i++)
        {
            array[i]=array[2*i+1];
        }
        //reverse array again so it will be back in the normal order
        if(record%2!=0)
        {
            reverseArray(array,size);
        }
        record++;
    }
    return array[0];
}
int computeRecursion(int array[], int size )
{
    static int record=0;
    if(record%2!=0)
    {
        reverseArray(array,size);
    }
    size=size/2;
    if(size>0)
    {
        for(int i=0; i<size; i++)
        {
            array[i]=array[2*i+1];
        }
        //reverse array again so it will be back in the normal order
        if(record%2!=0)
        {
            reverseArray(array,size);
        }
        record++;
        computeRecursion(array,size);
    }
    return array[0];
}
void reverseArray(int array[],int size)
{
    int reverseArray[size];
    //reverse array
    for(int i=0; i<size; i++)
    {
        reverseArray[i]=array[size-1-i];
    }
    //copy local array to the parameter array
    for(int i=0; i<size; i++)
    {
        array[i]=reverseArray[i];
    }
}
