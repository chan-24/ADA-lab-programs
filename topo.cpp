//Chandrashekar Naik,ISE
#include<iostream>
#include<stdlib.h>

	using namespace std;
class topo
{	int n,a[10][10],in[10];
	public: void read();
			void find();
			void sort();
};
void topo::read()
{
	cout<<"Enter the no elts\n";
	cin>>n;
	cout<<"Enter the adjacency matrix\n";
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
				cin>>a[i][j];
}
void topo::find()
{	for(int j=0;j<n;j++)
	{
		int sum=0;
		for(int i=0;i<n;i++)
				sum=sum+a[i][j];
		in[j]=sum;

	}
}
void topo::sort()
{
	int u,v,t[10],s[10];
	find();
	int top=-1;
	int k=0;
	for(int i=0;i<n;i++)
		if(in[i]==0)
			s[++top]=i;
	while(top!=-1)
	{
			u=s[top--];
			t[k++]=u;
			for(v=0;v<n;v++)
			{
				if(a[u][v]==1)
				{
					in[v]--;          
					if(in[v]==0)
						s[++top]=v;  
				}
			}
	}
	cout<<"Topological order seq is\n";
	for(int i=0;i<n;i++)
		cout<<t[i]<<" ";

}
int main()
{	topo t;
	
	t.read();
	t.sort();
	return 0;
}
