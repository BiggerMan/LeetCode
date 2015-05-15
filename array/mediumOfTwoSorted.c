#include <stdio.h>
#include <stdlib.h>

int getMediumIndex(int start, int end)
{
	int mid=(start+end)/2;
	return mid;
}

double getMedium(int *nums, int start, int end)
{
	int n=end-start+1;
	if( (n&1)==1 )
		return *(nums+start+n/2)/1.0;
	else
		return (*(nums+start+n/2)+*(nums+start+n/2-1))/2.0;
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	int aStart=0;
	int bStart=0;
	int aEnd=nums1Size-1;
	int bEnd=nums2Size-1;
	int aIndex=0,bIndex=0;
	while( (aEnd-aStart)>1 || (bEnd-bStart)>1 )
	{
		double aMid=getMedium(nums1,aStart,aEnd);
		double bMid=getMedium(nums2,bStart,bEnd);
		printf("aMid:%lf,bLen:%lf\n",aMid,bMid);
		if(aMid==bMid)
		{
			return aMid;
		}
		else if(aMid < bMid)
		{
			aIndex = getMediumIndex(aStart,aEnd);
			bIndex = getMediumIndex(bStart,bEnd);
			if( (aEnd-aStart)>1 )
				aStart=aIndex;
			if( (bEnd-bStart)>1 )
				bEnd=bIndex;
		}
		else
		{
			aIndex = getMediumIndex(aStart,aEnd);
			bIndex = getMediumIndex(bStart,bEnd);
			if( (aEnd-aStart)>1 )
				aEnd=aIndex;
			if( (bEnd-bStart)>1 )
				bStart=bIndex;
		}
	}
	printf("here\n");
	double aMid=(nums1[aStart]+nums1[aEnd])/2.0;
	double bMid=(nums2[bStart]+nums2[bEnd])/2.0;
	
	return (aMid+bMid)/2.0;
}
int main()
{
	int a[]={1,3,5};
	int b[]={2,4,6};
	int aLen=sizeof(a)/sizeof(a[0]);
	int bLen=sizeof(b)/sizeof(b[0]);
	printf("aLen:%d,bLen:%d\n",aLen,bLen);
	printf("result of medium %lf\n",findMedianSortedArrays(a,aLen,b,bLen));

	return 0;
}
