#include "stack.h"


//Stack store
int stack_store[STACK_SIZE];

//Stack pointer
int* stack_ptr;

void stack_init(void)
{
  // Initialize stack_ptr
  stack_ptr = &stack_store[0];
  //Clear the stack elements
  for (int i = 0; i <STACK_SIZE; i++){
    stack_store[i] = 0;      
  }
}

int stack_push(int data)
{
  //Stack is full?
  if (stack_ptr == &stack_store[STACK_SIZE])
  {
    return -1;
  }
  *stack_ptr = data;
  stack_ptr++;
  return 0;
}

int stack_pop(int* data)
{
  //Stack is empty
  if (stack_ptr == &stack_store[0])
  {
    return -1;
  }
  stack_ptr--;
  *data = *stack_ptr;
  return 0;
}

int stack_is_full(void)
{
  if (stack_ptr == &stack_store[STACK_SIZE])
  {
    return 1;
  }
  return 0;
}

int stack_is_empty(void)
{
  if (stack_ptr == &stack_store[0])
  {
    return 1;
  }
  return 0;
}