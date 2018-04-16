#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

struct Person{
  char *name;
  int age;
  int weight;
  int height;
};

struct Person *Person_Create(char *name, int age, int height, int weight)
{
  struct Person *someone=malloc(sizeof(struct Person));
  assert(someone!=NULL);
  someone->name=strdup(name);
  someone->age=age;
  someone->weight=weight;
  someone->height=height;

  return someone;
}

void Person_Destory(struct Person *someone)
{
  assert(someone!=NULL);
  free(someone->name);
  free(someone);
}

void Person_Print(struct Person *someone)
{
  printf("Name:%s\n", someone->name);
  printf("\tAge:%d\n", someone->age);
  printf("\tWeight:%d\n", someone->weight);
  printf("\tHeight:%d\n", someone->height);
}

int main(int argc, char *argv[])
{
  struct Person *Joe, *Frank;
  Joe=Person_Create("Joe Alex", 32, 64, 140);
  Frank=Person_Create("Frank Blank", 20, 72, 180);

  printf("Joe is at memory location: %p\n", Joe);
  printf("Frank is at memory location: %p\n", Frank);   
 
  Person_Print(Joe);
  Person_Print(Frank);

  Joe->age+=20;
  Joe->height-=2;
  Joe->weight+=40;
  Person_Print(Joe);



  Person_Destory(Joe);
  Person_Destory(Frank);
  
  return 0;
}
