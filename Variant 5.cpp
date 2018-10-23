/*	Each coin can be used as many time as you want.

	Find out how many ways a specific amount can be made.
	
	Here (1,2,5) , (1,5,2) , (2,1,5) , (2,5,1) , (5,1,2) , (5,2,1) all are same.
*/

#include<bits/stdc++.h>

using namespace std;

vector <int> way,coin;

void make(int n){
	
	way.clear();
	
	for(int i=0; i<=n; i+=1){
		
		way.push_back(0);
	}
}

void DP(int n){
	
	way[0]=1;
	
	int t=coin.size();
	
	for(int j=0; j<t; j+=1){
		
		for(int i=1; i<=n; i+=1){
			
			if(i >= coin[j]){
				
				way[i] += way[i-coin[j]];
			}
		}
	}
}

int main(){
	
	cout<<endl<<"How many coins?"<<endl;
	
	int c;
	
	cin>>c;
	
	cout<<endl<<"Enter their values"<<endl;
	
	coin.clear();
	
	for(int i=0; i<c; i+=1){
		
		int C;
		
		cin>>C;
		
		coin.push_back(C);
	}
	
	cout<<endl<<"Enter upper limit"<<endl;
	
	int n;
	
	cin>>n;
	
	make(n);
	
	DP(n);
	
	for(int i=1; i<=n; i+=1){
		
		cout<<endl<<"Amount = "<<i<<endl;
		
		cout<<"Way = "<<way[i]<<endl;
	}
}
