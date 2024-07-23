//heap sort
#include<iostream>
using namespace std;
static int heapsize,length;
int Parent(int i)
{
	return i/2;
}
int Left(int i)
{
	return 2*i;
}
int Right(int i)
{
	return 2*i+1;
}

void MaxHeapify(int A[],int i)
{
	int l=Left(i);
	int r=Right(i);
	int largest;
	if(l<=heapsize && A[l]>A[i]) largest=l;
	else largest=i;
	if(r<=heapsize && A[r]>A[largest]) largest=r;
	if(largest!=i)
	{
		swap(A[i],A[largest]);
		MaxHeapify(A,largest);
	}
}

void BuildMaxHeap(int A[])
{
	heapsize=length;
	for(int i=heapsize/2;i>=1;i--)
		MaxHeapify(A,i);
}

void HeapSort(int A[])
{
	BuildMaxHeap(A);
	for(int i=length;i>=2;i--)
	{
		swap(A[i],A[1]);
		heapsize-=1;
		MaxHeapify(A,1);
		cout<<"\nPass "<<length-i+1<<":";
		for(int j=1;j<=length;j++)
		{
			cout<<A[j]<<"\t";
		}
	}
}

int main()
{
	int A[20];
	cout<<"Enter no. of elements:";
	cin>>length;
	cout<<"Enter the elements one by one :";
	for(int i=1;i<=length;i++)
		cin>>A[i];
	HeapSort(A);
	cout<<"\nFinal array after heap sort :\n";
	for(int i=1;i<=length;i++)
	{
		cout<<A[i]<<"\t";
	}
}

		
