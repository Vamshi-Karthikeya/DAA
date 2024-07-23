//counting sort
#include<iostream>
using namespace std;
static int n;
void CountingSort(int A[],int B[],int k)
{	
	int C[k+1];
	for(int i=0;i<=k;i++)
	{
		C[i]=0;
	}
	for(int j=1;j<=n;j++)
	{
		C[A[j]]=C[A[j]]+1;
	}
	for(int i=1;i<=k;i++)
	{
		C[i]=C[i]+C[i-1];
	}
	cout<<"j\tA[j]\tC[A[j]]\tB[C[A[j]]]\n";
	for(int j=n;j>=1;j--)
	{
		B[C[A[j]]]=A[j];
		C[A[j]]=C[A[j]]-1;
		cout<<j<<"\t"<<A[j]<<"\t"<<C[A[j]]<<"\t"<<A[j]<<endl;
	}
}
int main()
{
	int A[20],B[20],k;
	cout<<"Enter the range of elements :";
	cin>>k;
	cout<<"Enter no. of elements :";
	cin>>n;
	cout<<"Enter the elements one by one:";
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
	}
	CountingSort(A,B,k);
	cout<<"\n\nFinal B array status :\n";
	for(int i=1;i<=n;i++)
	{
		cout<<B[i]<<"\t";
	}
}
