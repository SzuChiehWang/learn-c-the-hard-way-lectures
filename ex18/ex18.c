#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void die(const char *message)
{
  if(errno) perror(message);
  else
    printf("ERROR: %s\n", message);
  exit(1);
}

typedef int (*compare_cb) (int a, int b);

int *bubble_sort(int *numbers, int count, compare_cb cmb)
{
  int tmp;
  int i=0;
  int j=0;
  int *target=malloc(count*sizeof(int));
  memcpy(target, numbers, count*sizeof(int));

  for(i=0;i<count;i++)
  { 
    for(j=0;j<count-1;j++)
    {
      if(cmb(target[j], target[j+1])>0)
      {
        tmp=target[j+1];
        target[j+1]=target[j];
        target[j]=tmp;
      }


    }
  }
  return target;

}



int sorted_order(int a, int b)
{
  return (a>b)-(a<b);
}

int reverse_order(int a, int b)
{
  return (a<b)-(a>b);
}

int strange_order(int a, int b)
{
  if(a==0 || b==0) return 0;
  else return a%b;
}


void test_sorting(int *numbers, int count, compare_cb cmp)
{
  int i=0;
  int *sorted=bubble_sort(numbers, count, cmp);
  if(!sorted) {die("Failed to sort as requested.");}

  for(i=0; i<count; i++)
  {
    printf("%d",sorted[i]);
  }
   
  printf("\n");

  free(sorted);

}




int main(int argc, char *argv[])
{

  int count=argc-1;
  char **inputs=argv+1;
  int i=0;

  int *numbers=malloc(count*sizeof(int));
  if(!numbers) die("Memory error.");


  for(i=0;i<count;i++)
  {
    numbers[i]=atoi(inputs[i]);  
  } 

  free(numbers);

  test_sorting(numbers, count, sorted_order);
  test_sorting(numbers, count, reverse_order);
  test_sorting(numbers, count, strange_order);
  return 0;
}
