 #include <stdio.h> 
 struct Item 
{ 
    int weight; 
   int value; 
float ppw; 
 }; 
 void sort(struct Item items[], int n) 
 { 
     struct Item temp; 
     for (int i = 0; i < n - 1; i++) 
     { 
         for (int j = 0; j < n - i - 1; j++) 
         { 
             if (items[j].ppw < items[j + 1].ppw) 
             { 
                 temp = items[j]; 
                 items[j] = items[j + 1]; 
                 items[j + 1] = temp; 
             } 
        } 
    } 
 }
 int main() 
 { 
     int n; 
     float capacity;   
  printf("Enter number of items: "); 
    scanf("%d", &n); 
     if (n <= 0) 
         return 1; 
    struct Item items[n]; 
  
     printf("Enter weight and value of each item:\n"); 
     for (int i = 0; i < n; i++) 
     { 
         printf("Item %d: ", i + 1); 
         scanf("%d %d", &items[i].weight, &items[i].value); 
         items[i].ppw = (float)items[i].value / items[i].weight; 
     }   
     printf("Enter knapsack capacity: "); 
     scanf("%f", &capacity); 
    sort(items, n); 
  
     float totalProfit = 0.0; 
     for (int i = 0; i < n; i++) 
    { 
         if (capacity >= items[i].weight) 
         { 
             totalProfit += items[i].value; 
             capacity -= items[i].weight; 
         } 
        e { 
            totalProfit += items[i].ppw * capacity; 
             break; 
         } 
     } 
     printf("Maximum profit = %.2f\n", totalProfit); 
     return 0; 
 }
