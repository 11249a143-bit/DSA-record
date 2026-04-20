#include <stdio.h> 
int main() 
{ 
int n; 
int a = 0, b = 1, c; 
printf("Enter the number of terms (n): "); 
if (scanf("%d", &n) != 1 || n <= 0) 
    { 
      printf("Invalid input. Please enter a positive integer.\n"); 
      return 0; 
    } 
printf("Fibonacci Series: "); 
if (n >= 1) 
  printf("%d ", a); 
if (n >= 2) 
  printf("%d ", b)
     for (int i = 3; i <= n; i++) 
  { 
    c = a + b; 
    printf("%d ", c); 
    a = b; 
    b = c; 
  }         
if (n == 1) 
  printf("\nFibonacci term %d = %d\n", n, a); 
else 
  printf("\nFibonacci term %d = %d\n", n, b); 
return 0;
}
