//Chandrashekar Naik,ISE
#include<iostream>
using namespace std;
class floyd
{
 int n,c[10][10];
 public:
 void read_data();
 void write_data();
 void dist();
};

int min(int a,int b)
{
return ((a<b)?a:b);
}

void floyd :: read_data()
{
 int i,j;
 cout<<" Enter no.of nodes"<<endl;
 cin>>n;
 cout<<"Enter the cost matrix \n";
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   cin>>c[i][j];
}

void floyd :: write_data()
{
 int i,j;
 cout<<"The distance matrix is shown below :"<<endl;
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
   cout<<c[i][j]<<"\t";
  cout<<endl;
 }
}

void floyd :: dist()
{
 int i,j,k;
 for(k=0;k<n;k++)
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   
    c[i][j]=min(c[i][j],(c[i][k]+c[k][j]));
}

main()
{
 floyd f;
 f.read_data();
 f.dist();
 f.write_data();
}
 
