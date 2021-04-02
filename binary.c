#include <stdio.h>
#include<time.h>
#include<stdlib.h>


void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n,int *count)
{
int i, j;
int swaps;
for (i = 0; i < n-1; i++)
{
	swaps= 0;
	for (j = 0; j < n-i-1; j++)
	{   *count+=1;
		if (arr[j] > arr[j+1])
		{
		swap(&arr[j], &arr[j+1]);
		swaps= 1;
		}
	}
	if (swaps== 0)
		break;
}
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
	int *a,i,j,k,n,count=0,cbest=0,cworst=0,cavg=0;
	int x=100,y=1000,inc=100;
	FILE *ptr,*fptr;
	system("rm binary.txt");
	system("rm binarycount_operations.txt");
	srand(time(NULL));
	a=(int*)malloc(n*sizeof(int));
	
	for(n=x;n<=y;n+=inc)
	   { count=0;
	     fptr=fopen("binary.text","a");
	       ptr=fopen("binarycount_opertaion.txt","a");
	       
	       for(i=0;i<n;i++)
	          {
	             //a[i]=rand()%1000;
	             a[i]=(n-i)*10-100;
	          }
	       //fprintf(fptr,"Iteration:");
	       bubbleSort(a, n,&count);
	       fprintf(ptr,"%d\t%d\t",n,count);
	       count=0;
	       for(i=0;i<n;i++)
	          {
	             //a[i]=rand()%1000;
	             a[i]=(i)*10;
	          }
	       bubbleSort(a, n,&count);
	       fprintf(ptr,"%d\t",count);
	       count=0;
	       for(i=0;i<n;i++)
	          {
	             a[i]=rand()%100;
	             //a[i]=(n-i)*10-100;
	          }
	       //fprintf(fptr,"Iteration:");
	       bubbleSort(a, n,&count);
	       fprintf(ptr,"%d\n",count);
	for(i=0;i<n;i++)
	   {
	      fprintf(fptr,"%d  ",a[i]);
	   }
	fprintf(fptr,"\n");
	fclose(fptr);
	//ptr=fopen("binarycount_opertaion.txt","a");
	//fprintf(ptr,"%d\t%d\t%d\t%d\n",n,count,cworst,cavg);
	fclose(ptr);
	printf("Sorted array: \n");
	printArray(a, n);
	}
	system("gnuplot -p l.txt");
	//system("gnuplot >load 'l.txt'");
	//system("gnuplot -persist>load 'l.txt'");
	
	//system("plot sin(x)");
	return 0;
}

