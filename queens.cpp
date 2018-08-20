//Chandrashekar Naik,ISE
#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;
#define true 1
#define false 0
class queen
{
	public: void prints(int n,int x[]);
		int place(int x[],int k);
		void nqueens(int n);
};

int queen:: place(int x[],int k)
{
  int i;
  for(i=1;i<k;i++)
  {
    if(x[i]==x[k]||i-x[i]==k-x[k]||i+x[i]==k+x[k])
    return false;
  }

 return true;
}
void queen::prints(int n,int x[])
{	char c[10][10];
	 for(int i=1;i<=n;i++)
	 {
		   for(int j=1;j<=n;j++)
			c[i][j]='x';
	}
    for(int i=1;i<=n;i++)
	c[i][x[i]]='q';
for(int i=1;i<=n;i++)
{
	for(int j=1;j<=n;j++)
	      cout<<c[i][j];
	 cout<<endl;
     }
 
}
void queen::nqueens(int n)
{
  int k=1;
  int x[10];
  int count=0;
  x[k]=0;
  while(k!=0)
  {
    x[k]=x[k]+1;
    while((x[k]<=n)&&(!place(x,k)))
    	  x[k]++;
    if(x[k]<=n)
    {
     	if(k==n)
     	{	count++;
     		 cout<<"solution "<<count<<"is"<<endl;
		prints(n,x);
 	  }
	else
	 {
	    k++;
	    x[k]=0;
         }
     }
    else
   k--;
  }
}
int main()
{ 
 int n;
 queen q;
 cout<<"enter the number of queens"<<endl;
 cin>>n;
 q.nqueens(n);
 return 0;
}
