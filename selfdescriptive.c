#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>


/*What is self-descriptive number?

A number is called self-descriptive
when the position of digit represents the number
 of time it appears in that number.
There are so many numbers are self-descriptive.
For example: 1210,   2020,   21200,   3211000,   42101000 etc 

Consider 2020,

    position 0 has value 2 and there are two 0s in the number;
    position 1 has value 0 and there are no 1s in the number;
    position 2 has value 2 and there are two 2s in the number;
    position 3 has value 0 and there are zero 3s in the number.

*/

//Declared test and num of integers variables
int test(int,int);
int grabNumOfIntegers(int);
int num;
int main()
{
    FILE *fp = fopen("self.in", "r");
    int digit=0,count=0;
    int num;
    int testCase;
  
    //fp=fopen("self.in", "r");
    // if (fp == NULL)
    // { 
    //     printf("Unable to open file");
    // }
    // fscanf(fp,"%d",&num);
    fscanf(fp,"%d",&testCase);
    for (int i = 0; i < testCase; i++)
    {
          fscanf(fp,"%d",&num);

// printf("num is %d", num);
    int temp = num;

  int  compareDigit = 1;
  int numDigit = grabNumOfIntegers(temp);
  while(temp>0)
  {
    digit=temp%10;
    int count=test(num,numDigit);
    if(count!= digit)
    {
      printf("\t\n\n\n Digits are not self descriptive\n");
      compareDigit = 0;
      break;
    }
    temp=temp/10;
    numDigit--;
  }
  if(compareDigit )
  {
    printf("\t\nDigits are self descriptive\n");   
  }
    }
    


fclose(fp);

return 0;

}

// check number of times the digit appear in num
int test(int num,int digit)
{
  int count=0;
  while(num>0)
  {
    if(num%10 == digit)
    {
       count++;
    }
    num=num/10;
  }
  return count;
}

//to check number of digits in number 
int grabNumOfIntegers(int num)
{
  printf("%d",num);
  int digits = 0;
  while(num>0)
  {
    digits++;
    num=num/10;   
  }
  return digits-1;
}