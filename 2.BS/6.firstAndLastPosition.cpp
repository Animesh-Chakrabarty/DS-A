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

vector<int> firstAndLastPos(int n,int arr[],int target){
	vector<int> ans;
	int firstPos = findFirstPos(n,arr,target);
	int lastPos = findLastPos(n,arr,target);
	ans.push_back(firstPos);
	ans.push_back(lastPos);
	return ans;
}

int main(){
	int n,target;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)cin>>arr[i];
	cin >> target;
	vector<int> ans = firstAndLastPos(n,arr,target);
	for(auto it:ans) cout << it << " ";
}