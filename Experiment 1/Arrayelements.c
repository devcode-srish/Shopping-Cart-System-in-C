/*Problem statement:
Write a C program to accept 5 integers from the user, store them in an array, 
display the elements, and calculate the sum of all elements in the array.*/

#include<stdio.h>
int main()
{
    int arr[5]; // Here we have declared an array of size 5
    int i,sum=0;
    printf("Enter 5 integers:\n"); // Here we have taken the input from the user.
    for(i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    // Displaying array elements
    printf("The elements in the array are:\n");
    for(i=0;i<5;i++)
    {
        printf("%d",arr[i]);
    }
    // Calculating the sum of the arrays
    for(i=0;i<5;i++)
{
    sum+=arr[i];
}
printf("The sum of the array elements is:%d\n",sum);
return 0;
}