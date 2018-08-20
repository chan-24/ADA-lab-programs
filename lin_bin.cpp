#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
class linear
{
			int loc;
	public: void ln(int *,int,int);
};
class binary
{
			int loc,low,mid,high;
	public: void bs(int *,int,int);
};
void linear::ln(int a[],int n,int key)
{	loc=-1;
	for(int i=0;i<n;i++)
	{	if(a[i]==key)
			{	
				loc=i;
				 break;
			}
	}
	if(loc>=0)
		cout<<"Elt found at position"<<loc+1<<"\n";
	else
		cout<<"Elt not found"<<"\n";
}
void binary::bs(int a[],int n,int key)
{
	low=0;
	high=n-1;
	loc=-1;
	while(low<=high)
		{
			mid=(low+high)/2;
			if (a[mid]==key)
			{
				loc=mid;
				break;
			}
			if (a[mid]>key)
			{
				high=mid-1;
			}
			else
				low=mid+1;
		}
		if(loc>=0)
		cout<<"Elt found at position"<<loc+1<<"\n";
	else
		cout<<"Elt not found"<<"\n";
}
int main(int argc, char *argv[])
{
	int *a,n,key,choice,i;
	clock_t start,stop;
	cout<<"1.Linear search 2.Binary search"<<"\n";
	cout<<"Enter your choice"<<"\n";
	cin>>choice;
	switch(choice)
	{
		case 1: linear l;
				//for(int j=1;j<10;j++)
				//{	//
				cout<<"Enter n"<<"\n";
				//
				cin>>n;
				//n=10*j;
				a=new int[n];
				cout<<"enter elts\n";
				for(i=0;i<n;i++)
					cin>>a[i];		
					//a[i]=rand()%n+1;
				cin>>key;
				//key=rand()%n+1;
				start=clock();
				l.ln(a,n,key);
				stop=clock();
				cout<<"time taken="<<(stop-start)<<"s"<<"\n";
				cout<<"space consumed="<<sizeof(n)+n*sizeof(a)+sizeof(key)+sizeof(i)+sizeof(l)<<"bytes"<<"\n";
				//}
				break;
		case 2: binary b;
				for(int j=1;j<10;j++)
				{
					//cout<<"Enter n"<<"\n";
				//cin>>n;
				n=10*j;
				a=new int [n];
				for(i=0;i<n;i++)
					//cin>>a[i];		
					a[i]=rand()%n+1;
				//cin>>key;			
				key=a[1];//rand()%n+1;
				start=clock();
				b.bs(a,n,key);
				stop=clock();
				cout<<"time taken="<<(stop-start)<<"s"<<"\n";
				cout<<"space consumed="<<sizeof(n)+n*sizeof(a)+sizeof(key)+sizeof(i)+sizeof(l)<<"bytes"<<"/n";
				}break;

	}
	return 0;
}
