#include<assert.h>
#include"stack.h"

int main()
{
  int result1, result2;
  int test_int1, test_int2;
  //Intitialize the stack
  stack_init();
  
  //****Test 1 pop from an empty stack
  //Arrange:
  result1 = 74;
  test_int1 = 142;
  
  
  //Act:
  result1 = stack_pop(&test_int1);
  
  //Assert:
  assert(-1 == result1);
  assert(142 == test_int1);
  
  //*****Test 2 push and pop from stack
  //Arrange:
  result1 = 74;
  result2 = 75;
  test_int1 = 142;
  test_int2 = -245;
  
  //Act:
  result1 = stack_push(test_int1);
  result2 = stack_pop(&test_int2);
  
  //Assert:
  assert(0 == result1);
  assert(0 == result2);
  assert(142 == test_int1);
  assert(142 == test_int2);
  
  //Test 3: fill stack, check if full, try to push an element onto a full stack
  //pop all elements, check for an empty stack
  //Intitialize the stack
  stack_init();
  
  int test_arr[30];
  //Clear the test array
  for (int i = 0; i < 30; i++)
  {
    test_arr[i] = 0;
  }
  
  //Act:
  //Fill the stack with even numbers
  for (int i = 0; i<30; i++)
  {
    result1 = stack_push((i+1)*2);
    assert(0 == result1);
  }
  
  //Check if the stack is full
  result1 = stack_is_full();
  assert(1 == result1);
  
  //Push onto a full stack
  result2 = stack_push(test_int1);
  assert(-1 == result2);
  
  //Pop the stack into the array backwards
  for (int i = 29; i>=0; i--)
  {
    result1 = stack_pop(&test_arr[i]);
    assert(0 == result1);
  }
  //Assert:
  for (int i = 0; i<30; i++)
  { 
    assert((i+1)*2 == test_arr[i]);
  }
  
  //Check if the stack is empty
  result2 = stack_is_empty();
  assert(1 == result2);
  return 0;
}
