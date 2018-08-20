#include<iostream>
#include<time.h>
#include<cstdlib>
	using namespace std;
class heap
{	public:
			void heapify(int *,int);
			void adjust(int *,int,int);
			void heapsort(int *,int);
};
void heap::heapify(int a[],int n)
{
	int key,i,j,p;
	for(i=0;i<n;i++)
	{
		key=a[i];
		j=i;
		p=(j-1)/2;
		while(j>0&&key>a[p])
		{
			a[j]=a[p];
			j=p;
			p=(j-1)/2;	
		}
		a[j]=key;
	}
}
void heap::adjust(int a[],int n,int p)
{
	int item,i;
	item=a[p];
	i=2*p+1;
	while(i<n)
	{
		if(i+1<n)
			if(a[i]<a[i+1])
				i++;
		if(item<a[i])
			{	a[p]=a[i];
				p=i;
				i=2*p+1;
			}
		else
			break;

	}
	a[p]=item;
}
void heap::heapsort(int a[],int n)
{
	int i,temp;
	heapify(a,n);
	for(i=n-1;i>0;i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		adjust(a,i,0);
	}	
}
int main()
{
	int *a,n,i;
	clock_t start,stop;
	heap h;
	//for(int j=1;j<11;j++)
	//{
		cout<<"Enter the no of elts";
		cin>>n;
		//n=j*1000;
		a=new int[n];
		cout<<"Enter the elts";
		for ( i = 0; i <n; i++)
		{
			//a[i]=rand()%n+1;
			cin>>a[i];
		}
		start=clock();
		h.heapsort(a,n);
		stop=clock();
		cout<<"Sorted elts are";
		for (int i = 0; i < n; i++)
		{
			cout<<a[i]<<endl;
		}
		cout<<"time="<<stop-start<<"s  ";
		cout<<"space consumed="<<sizeof(n)+n*sizeof(a)+sizeof(h)+sizeof(i)<<"bytes"<<endl;
	//}
}
