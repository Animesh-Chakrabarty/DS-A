#include<bits/stdc++.h>
using namespace std;

int upperBound(int n,int arr[],int target){
	int ans=-1;
	int lo=0,hi=n-1;
	while(lo<=hi){
		int mid=lo+(hi-lo)/2;
		if(arr[mid]==target) {
			// edge case 1 : if we aim for the upper bound of the last element of the array it will return value of n as ans
			if(mid < n-1){
				ans=mid+1;
				break;	
			}
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

	int ans = upperBound(n,arr,target);
	cout << ans;
}