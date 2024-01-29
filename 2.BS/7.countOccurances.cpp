#include<bits/stdc++.h>
using namespace std;

int findFirstPos(int n,int arr[], int target){
	int lo = 0,hi=n-1;
	int ans=-1;
	while(lo<=hi){
		int mid=lo+(hi-lo)/2;
		if(arr[mid]==target){
			ans=mid;
			hi=mid-1;
		}
		else if(arr[mid]<target)lo=mid+1;
		else if(arr[mid]>target)hi=mid-1;
	}
	return ans;
}

int findLastPos(int n,int arr[], int target){
int lo = 0,hi=n-1;
	int ans=-1;
	while(lo<=hi){
		int mid=lo+(hi-lo)/2;
		if(arr[mid]==target){
			ans=mid;
			lo=mid+1;
		}
		else if(arr[mid]<target)lo=mid+1;
		else if(arr[mid]>target)hi=mid-1;
	}
	return ans;
}

int countOccurances(int n,int arr[],int target){
	int ans = -1;
	int firstPos = findFirstPos(n,arr,target);
	int lastPos = findLastPos(n,arr,target);
	if(firstPos != -1 && lastPos !=-1){
		ans = lastPos - firstPos+1;
	}
	return ans;
}

int main(){
	int n,target;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)cin>>arr[i];
	cin >> target;
	int ans = countOccurances(n,arr,target);
	cout << ans ;
}