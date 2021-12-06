/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STACK_H__
#define __STACK_H__

#define STACK_SIZE 30
void stack_init(void);
int stack_push(int data);
int stack_pop(int* data);
int stack_is_full(void);
int stack_is_empty(void);

#endif