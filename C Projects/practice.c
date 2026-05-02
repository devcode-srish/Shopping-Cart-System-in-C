// Check if a number is divisble by 2 or not//
#include<stdio.h>
#include<math.h>
int main()
{
    int num;
    printf("Enter a number:\n");
     scanf("%d",&num);
     if(num%2==0)
     {
        printf("Number is divisible by two\n");
     }
     else
     {
        printf("Number is not divisible by two\n");
     }
    return 0;
}