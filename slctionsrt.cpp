//Chandrashekar Naik,ISE
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
void selectionsort(int a[],int n)
{
	int temp,i,j,pos=0;
	for(i=0;i<n-1;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[pos])
				pos=j;
		temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;
		
	}
}
int main()
{
	int n,j;
	clock_t start,stop;
	//for(int i=0;i<10;i++)
	//{
	//	j=(i+1)*1000;
	//	int arr[j];
	//	for(n=0;n<j;n++)
	//	{
	//		arr[n]=(rand()%j)+1;
	//	}
		cout<<"enter no of elts\n";
		cin>>n;
		int arr[n];
		cout<<"enter array elts\n";
		for(j=0;j<n;j++)
			cin>>arr[j];
		start=clock();
		selectionsort(arr,n);
		stop=clock();
		for(j=0;j<n;j++)
			cout<<arr[j]<<" ";
		cout<<"\nFor input size"<<n<<"difference is "<<(stop-start)<<endl;
	//}
	return 0;
}
