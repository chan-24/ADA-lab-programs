//Chandrashekar Naik,ISE
#include<iostream>
#include<time.h>
#include<cstdlib>

using namespace std;
#define max 1000
class merge
{
	int low,high;
 public:void m_sort(int *,int ,int);
	void s_merge(int *,int ,int,int);
};
void merge::m_sort(int a[],int low,int high)
{
	if(low<high)
	{	int mid=(low+high)/2;
		m_sort(a,low,mid);
		m_sort(a,mid+1,high);
		s_merge(a,low,mid,high);
	}
}

void merge::s_merge(int a[],int low,int mid,int high)
{	int i=low,j=mid+1,k=low,c[max];
	while(i<=mid&&j<=high)
	{	
		if(a[i]<a[j])
		{	c[k]=a[i];
			i=i+1;
			k=k+1;
                }
		else
		{	c[k]=a[j];
			j=j+1;
			k=k+1;
		}
	}
	while(i<=mid)
		c[k++]=a[i++];
	while(j<=high)
		c[k++]=a[j++];
	for(i=low;i<=high;i++)
		a[i]=c[i];

}
int main()
{	
	int *a,i,n;
	clock_t start,stop;

	merge m;
	cout<<"enter no of elts"<<endl;
	cin>>n;
	a=new int[n];
	cout<<"elts"<<endl;
	for(i=0;i<n;i++)
		cin>>a[i];
	start=clock();
	m.m_sort(a,0,n-1);
	stop=clock();
	cout<<"sorted order ";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<"time taken="<<(stop-start)<<"s"<<endl;
	cout<<"space consumed="<<sizeof(n)+n*sizeof(a)+sizeof(i)+sizeof(m)<<"bytes"<< endl;
	return 0;
}
