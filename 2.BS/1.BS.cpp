#include<bits/stdc++.h>
using namespace std;

int binarySearch(int n , int nums[], int target){
	int lo = 0,hi=n-1;
	while(lo<=hi){
		int mid = lo+(hi-lo)/2;
		if(nums[mid]==target) return mid;
		else if(nums[mid]<target)lo=mid+1;
		else if(nums[mid]>target)hi=mid-1;
	}
	return -1;
}

int main(){
	int n,target;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)cin >> arr[i];
	cin >> target;
	int ans = binarySearch(n,arr,target);
	cout << ans;
}