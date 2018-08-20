//Chandrashekar Naik,ISE
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
class quick
{
			int temp,high,low;
	public: int partition(int *,int,int);
			void qsort(int *,int,int);
};
int quick::partition(int a[],int low,int high)
{	
	int i,j,key;
	i=low+1;
	j=high;
	key=a[low];
	while(1)
	{
		while(i<high && a[i]<=key)
			i++;
		while(j>=low && a[j]>key)
			j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else
		{
			temp=a[low];
			a[low]=a[j];
			a[j]=temp;
			return j;
		}
	}
}
void quick::qsort(int a[],int low,int high)
{
	if(low<high)
	{
		int j=partition(a,low,high);
		qsort(a,low,j-1);
		qsort(a,j+1,high);
	}
}
int main()
{
	int n,i;
	clock_t start,stop;
	quick q;
	cout<<"Enter the no.of elements"<<endl;
	cin>>n;
	//for(int j=1;j<11;j++)
	//{
	//	n=1000*j;
		int a[n];
		cout<<"Enter the elements"<<endl;
		for(i=0;i<n;i++)
		//	a[i]=rand()%n+1;
		cin>>a[i];
		start=clock();
		q.qsort(a,0,n-1);
		stop=clock();
			cout<<"Sorted elements are"<<endl;
			for(i=0;i<n;i++)
				cout<<a[i]<<endl;
			
		cout<<"Time taken "<<(stop-start)<<" seconds   ";
		cout<<"Space consumed="<<sizeof(n)+n*sizeof(a)+sizeof(i)+sizeof(q)<<"bytes"<<endl;
//	}
}
