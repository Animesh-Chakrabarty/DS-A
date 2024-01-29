#include<bits/stdc++.h>
using namespace std;

int findMin(int n,int nums[]){
	int lo = 0,hi = n-1,ans=10;
	while(lo<=hi){
		int mid = lo+(hi-lo)/2;
		if(nums[lo] < nums[mid]){
			if(nums[lo]<ans) ans=nums[lo];
			lo=mid+1;
		}
		if(nums[mid]<nums[hi]){
			if(nums[mid]<ans)ans =nums[mid];
			hi=mid-1;
		}
	}
 	return ans;
}


int main(){
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)cin >> arr[i];
	int ans = findMin(n,arr);
	cout << ans;
}