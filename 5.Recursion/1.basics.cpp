#include<bits/stdc++.h>
using namespace std;

// 1.Print name 5 times
void printName(string name , int count){
	if(count == 0) return;
	cout << name << " ";
	count--;
	printName(name,count);
}

// 2.Print from 1 to N
void print1ToN(int M,int N){
	if(M>N) return;
	cout << M << " ";
	M++;
	print1ToN(M,N);
}

// 3.Print from N to 1
void printNto1(int N,int M){
	if(N<M) return;
	cout << N << " ";
	N--;
	printNto1(N,M);
}

int main(){
	// 1.Print name 5 times
	printName("Animesh",5);
	cout << endl;
	// 2.Print from 1 to N
	print1ToN(1,10);
	cout << endl;
	// 3.Print from N to 1
	printNto1(10,1);
	cout<<endl;
}