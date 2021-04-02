#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define x 10
#define y 100
#define inc 10
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int linearS(int a[], int n,int *count,int k)
{
int i, j;
for (i = 0; i < n; i++)
{   *count=*count+1;
	if(a[i]==k)
	   return i;
	
}
return -1;
}

void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("n");
}

int main()
{
	int *a,i,j,k,n,best,worst,avg,cworst,cavg,cbest;
	//int x=10,y=100,inc=10;
	FILE *ptr,*fptr;
	system("rm linear.txt");
	system("rm count_operations");
	srand(time(NULL));
	a=(int*)malloc(n*sizeof(int));
	
	for(n=x;n<=y;n+=inc)
	   {   fptr=fopen("linear.text","a");
	       cworst=0;cavg=0;cbest=0;
	       for(i=0;i<n;i++)
	          {
	             a[i]=rand()%100;
	          }
	       best=a[0];
	       worst=rand()%100+100;
	       avg=a[(int)n/2];
	       linearS(a,n,&cworst,worst);
	       linearS(a,n,&cbest,best);
	       linearS(a,n,&cavg,avg);
	       
	       fprintf(fptr,"Iteration:");
	       for(i=0;i<n;i++)
	        {
	            fprintf(fptr,"%d  ",a[i]);
	        }
	       fprintf(fptr,"\n");
	       fclose(fptr);
	       ptr=fopen("count_opertaion","a");
	       fprintf(ptr,"%d\t%d\t%d\t%d\n",n,cbest,cworst,cavg);
	       fclose(ptr);
	
	       printf("Sorted array: \n");
	       printArray(a, n);
	  }
	  system("gnuplot -persist>load 'l.txt'");
	return 0;
}

