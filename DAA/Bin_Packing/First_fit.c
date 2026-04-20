#include <stdio.h>
void firstFit(int items[], int n, int capacity) 
 { 
  int bin[n];       
     int binCount = 0;
     for (int i = 0; i < n; i++) 
      bin[i] = capacity; 
  for (int i = 0; i < n; i++) 
  {
  int placed = 0; 
    for (int j = 0; j < binCount; j++) 
       { 
         if (bin[j] >= items[i]) 
            { 
                 bin[j] -= items[i]; 
               printf("Item %d placed in Bin %d\n", items[i], j + 1);     
              placed = 1;          
              break;
            }  
       }     
    if (!placed) 
        { 
            bin[binCount] -= items[i]; 
           printf("Item %d placed in Bin %d\n", items[i], binCount + 1); 
            binCount++; 
        } 
    } 
     printf("Total bins used = %d\n", binCount);
 }  
 int main() 
 { 
     int n, capacity; 
     printf("Enter number of items: "); 
     scanf("%d", &n);  
     printf("Enter bin capacity: "); 
     scanf("%d", &capacity); 
     int items[n];  
    printf("Enter item sizes:\n"); 
     for (int i = 0; i < n; i++) 
     { 
        int itemSize; 
        printf("Item %d: ", i + 1); 
         scanf("%d", &itemSize); 
  
         if (itemSize <= capacity) 
        { 
             items[i] = itemSize; 
         } 
        else 
         {      
           1printf("Item size exceeds bin capacity. Please enter a valid 
size.\n"); 
  i--; 
} 
} 
  firstFit(items, n, capacity); 
  return 0; 
}
