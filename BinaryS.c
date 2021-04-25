#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>


void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int bubbleSort(int arr[],int l, int r,int *count,int x)
{
while (l <= r) {
       *count+=1;
        int m = l + (r - l) / 2;
  
        if (arr[m] == x)
            return m;
  
        
        if (arr[m] < x)
            l = m + 1;
  
        else
            r = m - 1;
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
	int *a,i,j,k,n,count=0,cbest=0,cworst=0,cavg=0;
	int x=10,y=100000,inc=10;
	FILE *ptr,*fptr;
	system("rm binaryS.txt");
	system("rm binaryScount_operations.txt");
	srand(time(NULL));
	
	
	for(n=x;n<=y;n=n*2)
	   { count=1;
	     fptr=fopen("binaryS.text","a");
	     a=(int*)malloc(n*sizeof(int));
	       for(i=0;i<n;i++)
	          {
	             //a[i]=rand()%1000;
	             //a[i]=(n-i)*10-100;
	             a[i]=(i+1);
	          }
	       fprintf(fptr,"Iteration:");
	       k=a[n-1];
	       j=bubbleSort(a,0, n-1,&count,k);
	for(i=0;i<n;i++)
	   {
	      fprintf(fptr,"%d  ",a[i]);
	   }
	fprintf(fptr,"\n%d   %d\n",k,j);
	fclose(fptr);
	ptr=fopen("binaryScount_opertaion.txt","a");
	fprintf(ptr,"%d\t%d\t%d\t%d\n",n,count,cworst,cavg);
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

