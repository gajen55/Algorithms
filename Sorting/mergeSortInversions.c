#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long merge(long a[], long s, long l, long m);
long long split(long a[], long s, long l)
{
	long long X,Y,Z;
	long m = (s+l)/2;
	if(l==s)
		return 0;
	
	X=split(a,s,m);
	Y=split(a,m+1,l);
	Z=merge(a,s,l,m);
	
	return X+Y+Z;
}

long long merge(long a[], long s, long l, long m)
{
	long n1 = m-s+1;
	long n2 = l-m;
	long i,j,k;
	long long w= 0;
	
	
	long A[n1], B[n2];
	
	for(i=0;i<n1;i++)
	{
		A[i] = a[s+i];
	}
	for(i=0;i<n2;i++)
	{	
		B[i] = a[m+1+i];
	}
	k=s;
	i=0;
	j=0;
	while(i<n1 && j<n2)
	{
		if(A[i]>B[j])
		{
			a[k]=B[j];
			j++;
			k++;
		}
		else
		{
			a[k]=A[i];
			i++;
			k++;
		}
	}
	for(;i<n1;i++)
	{
		a[k]=A[i];
		k++;
	}
	for(;j<n2;j++)
	{
		a[k]=B[j];
		k++;
	}
	
        i = 0;
        for(j=0;j<n2;j++)
        {
                while(i<n1)
                {
                        if(A[i]>B[j])
                        {
                                w = w+(n1-i);
                                break;
                        }
                        else
                        {
                                i++;
                        }
                }
        }
        return w;
}

int main(int argc,char *argv[])
{
	long i = 0 ;
	long a[100000];
	FILE * fp;
	char *read;
	long line_size = 15;
	char line[15];
	long size = sizeof(a)/sizeof(long);
	fp = fopen(argv[1],"r");
	if(fp==NULL)
		printf("Error opening file\n");
	
	while(1)
	{
		if(fgets(line,line_size,fp)==NULL) break;
		a[i]= strtol(line,(char **)NULL,10);
		i++;
	}
	
	printf("Hello. execution started\n");

	long long Inv = split(a,0,size-1);
	printf("Inversions=%lld\n",Inv);
	for(long i=0;i<size;i++)
	printf("%d ",a[i]);
	return 0;
}
