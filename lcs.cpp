#include<iostream>
#include<string.h>
using namespace std;
int C[10][10];int B[10][10];
int m,n;string X,Y;
void LCSLength(string X,string Y)
{
	m=X.length();
	n=Y.length();
	for(int i=0;i<=m;i++)
		C[i][0]=0;
	for(int j=0;j<=n;j++)
		C[0][j]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(X[i-1]==Y[j-1])
			{
				C[i][j]=C[i-1][j-1]+1;
				B[i][j]=11;//diagonal arrow
			}
			else if(C[i-1][j]>=C[i][j-1])
			{
				C[i][j]=C[i-1][j];
				B[i][j]=22;//up arrow
			}
			else	
			{
				C[i][j]=C[i][j-1];
				B[i][j]=33;//left arrow
			}
		}
	}
	cout<<"C matrix :\n";
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<C[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"B matrix :\n";
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<B[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void printLCS(int B[][10],string X,int i,int j)
{
	if(i==0||j==0)
		return;
	if(B[i][j]==11)
	{
		printLCS(B,X,i-1,j-1);
		cout<<X[i-1];
	}
	else if(B[i][j]==22)
		printLCS(B,X,i-1,j);
	else
		printLCS(B,X,i,j-1);
}

int main()
{
	cout<<"Enter string X : ";cin>>X;
	cout<<"Enter string Y : ";cin>>Y;
	LCSLength(X,Y);
	cout<<"LCS of X and Y is : ";
	printLCS(B,X,m,n);
	cout<<endl;
}
		
	
	
