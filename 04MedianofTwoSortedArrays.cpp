// Problem Description 
// Given two sorted arrays, a[] and b[],
// the task is to find the median of these sorted arrays, 
// where N is the number of elements in the first array, 
// and M is the number of elements in the second array. 
  

//  A[ ] = { -5, 3, 6, 12, 15 }, n = 5  &  B[ ] = { -12, -10, -6, -3, 4, 10} , m = 6

// realmidinmergedarray = 6. 
// start = 0 and end = 5 => mid = 2
// leftAsize = 2 and leftBsize = 4
// leftA = 3
// leftB = -3
// rightA = 6
// rightB = 4
//  A[ ] = { -5, 3, 6, 12, 15 } &  B[ ] = { -12, -10, -6, -3, 4, 10} 
// As leftA <= rightB and leftB <= rightA, so the condition holds and 3 is returned as the median
// Follow the steps below to solve the problem:

// If we would have merged the two arrays, the median is the point that will divide the sorted merged array into two equal parts. So the actual median point in the merged array would have been (M+N+1)/2;
// We divide A[] and B[] into two parts. We will find the mid value and divide the first array A[] into two parts and simlutaneously choose only those elements from left of B[] array such that the sum of the count of elements in the left part of both A[] and B[] will result in the left part of the merged array. 
//  Now we have 4 variables indicating four values two from array A[] and two from array B[].
// leftA -> Rightmost element in left part of A.
// leftb -> Rightmost element in left part of B
// rightA -> Leftmost element in right part of A
// rightB -> Leftmost element in right part of B
// Hence to confirm that the partition was correct we have to check if leftA<=rightB and leftB<=rightA. This is the case when the sum of two parts of A and B results in the left part of the merged array.
//  If the condition fails we have to find another midpoint in A and then left part in B[]. 
// If we find leftA > rightB. means we have to decrease the size of A’s partition and shift to lesser value in A[]. 
// So update the right pointer of to mid-1 else we will increase the left pointer to mid+1. 
// Repeat the above steps with new partitions till we get the answers.
// If leftA ≤ rightB and leftB ≤ rightA, then we get the correct partition and our answer depends on the total size of the merged array (i.e. M+N). If (M+N) is even we take max(leftA, leftB) and min(rightA, rightB), add them and divide by 2 to get our answer, else we will just return the maximum of leftA and leftB.


// Below is the implementation of the above problem:


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
       if(m>n)
        return findMedianSortedArrays(nums2,nums1);//ensuring that binary search happens on minimum size array
        
    int low=0,high=m,medianPos=((m+n)+1)/2;
    while(low<=high) {
        int cut1 = low + (high - low)/2;
        int cut2 = medianPos - cut1;
        
        int l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
        int l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
        int r1 = (cut1 == m)? INT_MAX:nums1[cut1];
        int r2 = (cut2 == n)? INT_MAX:nums2[cut2];
        
        if(l1<=r2 && l2<=r1) {
            if((m+n)%2 != 0)
                return max(l1,l2);
            else 
                return (max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1>r2) high = cut1-1;
        else low = cut1+1;
    }
    return 0.0;

    }
};
