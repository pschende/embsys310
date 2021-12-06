#include<assert.h>

int big_endian(void);

int main(void)
{
  int result;
  result = big_endian();
  //Kick back an assert error to see if the system is big endian or not.
  assert(1 == result);
  return 0;
}

int big_endian(void)
{
  int test_int = 0x000000FF;
  char test;
  char* ptr;
  ptr = (char*)&test_int;
  test = *ptr;
  //See if the pointer is looking at the most significant byte or the least of the 32-bit int.
  if (test == 0xff){
    return 0; //Little endian
  }
  //Else it is big endian
  return 1;
}