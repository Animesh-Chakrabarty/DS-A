#include<bits/stdc++.h>
using namespace std;

int lowerBound(int n,int arr[],int target){
	int ans=-1;
	int lo=0,hi=n-1;
	while(lo<=hi){
		int mid=lo+(hi-lo)/2;
		if(arr[mid]==target) {
			ans=arr[mid];
			break;
		}else if(arr[mid]>target){
			ans=arr[mid];
			hi=mid-1;
		}else if(arr[mid]<target){
			lo=mid+1;
		}
	}
	return ans;
}

int findFloor(int n,int arr[],int target){
	int lo=0,hi=n-1;
	int ans=-1;
	while(lo<=hi){
		int mid=lo+(hi-lo)/2;
		if(arr[mid]==target) {
			ans=arr[mid];
			break;
		}else if(arr[mid]<target){
			ans=arr[mid];
			lo=mid+1;
		}else if(arr[mid]>target){
			hi=mid-1;
		}
	}
	return ans;
}

vector<int> floorAndCeil(int n, int arr[], int target){
	vector<int> ans;
	int floor = findFloor(n,arr,target);
	int ceil = lowerBound(n,arr,target);
	ans.push_back(floor);
	ans.push_back(ceil);
	return ans;
}

int main(){
	int n,target;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)cin >> arr[i];
	cin>>target;

	vector<int> ans = floorAndCeil(n,arr,target);
	for(auto it:ans) cout << it << " ";
}