#include<bits/stdc++.h>
using namespace std;

int lowerBound(int n,int arr[],int target){
	int ans=-1;
	int lo=0,hi=n-1;
	while(lo<=hi){
		int mid=lo+(hi-lo)/2;
		if(arr[mid]==target) {
			ans=mid;
			break;
		}else if(arr[mid]>target){
			ans=mid;
			hi=mid-1;
		}else if(arr[mid]<target){
			lo=mid+1;
		}
	}
	return ans;
}

int main(){
	int n,target;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)cin >> arr[i];
	cin>>target;

	int ans = lowerBound(n,arr,target);
	cout << ans;
}