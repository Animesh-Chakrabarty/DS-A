#include<bits/stdc++.h>
using namespace std;

bool searchElement(int n,int nums[],int target){
	int lo = 0,hi = n-1;
	while(lo<=hi){
		int mid = lo+(hi-lo)/2;
		if(nums[mid]==target)return true;
		// edge case :
		if(nums[lo] == nums[mid] && nums[mid] == nums[hi]){
			lo++,hi--;
			continue;
		}
		// identify the sorted half
		if(nums[mid]<nums[hi]){
			// right half is sorted
			// check whether element lies in the right half or not
			// if lies then eleminate left half else eleminate right half
			if(target > nums[mid] && target <= nums[hi])lo=mid+1;
			else hi = mid-1;
		}
		else {
			// left half is sorted
			// check whether element lies on the the left half or not
			// if lies then eleminate right half else eliminate left half
			if(target >= nums[lo] && target < nums[mid] ) hi = mid-1;
			else lo = mid+1;
		}
	}
 	return false;
}


int main(){
	int n,target;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)cin >> arr[i];
	cin>>target;
	bool ans = searchElement(n,arr,target);
	cout << ans;
}