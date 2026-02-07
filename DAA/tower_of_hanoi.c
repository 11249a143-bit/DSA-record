#include<stdio.h>
void tower(int n,char S,char D,char T)
{
if(n==1)
{
printf("Move the disk %d from %c to %c\n",n,S,D);
return;
}
tower(n-1,'S','T','D');
printf("Move disk %d from  %c to %c\n",n,S,D);
tower(n-1,T,D,S);
}

int main()
{
int disk_count;
printf("Enter the no of Disk");
scanf("%d",&disk_count);
printf("\n Required moves!!\n");
tower(disk_count,'S','D','T');
}