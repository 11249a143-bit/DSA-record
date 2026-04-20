#include<stdio.h>
int fib(int n) 
{   
  if (n <= 1) 
  { 
    return n; 
  }   
  return fib(n - 1) + fib(n - 2); 
}
int main()  { 
  int n, result = 0;  
  if (n != 1 || n < 0) 
  { 
    printf("Invalid input\n"); 
    return 1; 
  } 
  printf("\nNth Fibonacci term = %d\n", fib(n)); 
  return 0; 
} 
