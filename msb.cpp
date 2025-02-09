#include <iostream>
using namespace std;
int maxleft,maxright;
int FindMaxCrossingSubArray(int A[],int low,int mid,int high)
{
    int leftsum=-9999;
    int sum=0;
    for(int i=mid;i>=1;i--)
    {
        sum=sum+A[i];
        if(sum>leftsum)
        {
            leftsum=sum;
            maxleft=i;
        }
    }
    int rightsum=-9999;
    sum=0;
    for(int j=mid+1;j<=high;j++)
    {
        sum=sum+A[j];
        if(sum>rightsum)
        {
            rightsum=sum;
           maxright=j;
        }
    }
    return (maxleft,maxright,leftsum+rightsum);
}

int FindMaxSubArray(int A[],int low,int high)
{
    int leftlow,lefthigh,leftsum,rightlow,righthigh,rightsum,crosslow,crosshigh,crosssum;
    if(high==low)
    {
        return (low,high,A[low]);
    }
    else
    {
        int mid=(low+high)/2;
        leftlow,lefthigh,leftsum=FindMaxSubArray(A,low,mid);
        rightlow,righthigh,rightsum=FindMaxSubArray(A,mid+1,high);
        crosslow,crosshigh,crosssum=FindMaxCrossingSubArray(A,low,mid,high);
        if(leftsum>=rightsum && leftsum>=crosssum)
        {
            return (leftlow,lefthigh,leftsum);
        }
        else if(rightsum>=leftsum && rightsum>=crosssum)
        {
            return (rightlow,righthigh,rightsum);
        }
        else
        {
            return (crosslow,crosshigh,crosssum);
        }
    }
}
int main()
{
    int n,A[20],result;
    cout<<"Enter no. of elements :";
    cin>>n;
    cout<<"Enter the elements :";
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    maxleft,maxright,result=FindMaxSubArray(A,1,n);
    cout<<"The maximum contiguous sub array is :";
    for(int i=maxleft;i<=maxright;i++)
    {
        cout<<A[i]<<"\t";
    }
    cout<<"\nMaximum sum obtained :"<<result<<endl;
}
