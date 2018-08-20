//Chandrashekar Naik,ISE
#include<iostream>
using namespace std;
class krus
{
	int c[10][10];
	public: int n,m;
		void read_data();
		int find(int,int[]);
		void union_ij(int,int,int[]);
		void kruskal();
};
void krus::read_data()
{
	int i,j,u,v;
	cout<<"enter the number of nodes"<<endl;
	cin>>n;
	cout<<"enter the number of edges"<<endl;
	cin>>m;
	for(i=0;i<n;i++)
		 for(j=0;j<n;j++)
			 c[i][j]=999;
	for(i=0;i<m;i++)
	{
		cout<<"enter the edges and its cost"<<endl;
		cin>>u>>v;
		cin>>c[u][v];
		c[v][u]=c[u][v];
	}
}
int krus::find(int v,int p[] )
{
	while(p[v]!=v)
		v=p[v];
	return v;
}
void krus::union_ij(int i,int j,int p[])
{
	if(i<j)
		p[j]=i;
	else
		p[i]=j;
}
void krus::kruskal()
{
	int count,p[10],min,i,j,u,v,k,t[10][2],sum;
	count=0;k=0;sum=0;
	for(i=0;i<n;i++)
		p[i]=i;
	while(count<n)
	{
		min=999;
		for(i=0;i<n;i++)
		{	for(j=0;j<n;j++)
			{
				if(c[i][j]<min)
				{
					min=c[i][j];
					u=i;
					v=j;
				}
			}
		}	
	
		if(min==999)
			break;
		i=find(u,p);
		j=find(v,p);
		if(i!=j)
		{
			t[k][0]=u;
			t[k][1]=v;
			k++;
			count++;
			sum+=min;
			union_ij(i,j,p);
		}
		c[u][v]=c[v][u]=999;
	}
	if(count==n-1)
	{
		cout<<"cost of the spanning tree="<<sum<<endl;
		cout<<"spanning tree is shown below"<<endl;
		for(k=0;k<n-1;k++)
			cout<<t[k][0]<<","<<t[k][1]<<endl;
		return;
	}
	cout<<"spanning tree does not exit"<<endl;
}
int main()
{
	krus k;
	k.read_data();
	k.kruskal();
	return 0;
}
