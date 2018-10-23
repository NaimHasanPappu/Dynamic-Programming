/*	Each coin can be used as many time as you want.

	Find out if a specific amount can be made or not.
*/

#include<bits/stdc++.h>

using namespace std;

vector <int> dp,coin;

void make(int n){
	
	dp.clear();
	
	for(int i=0; i<=n; i+=1){
		
		dp.push_back(0);
	}
}

void DP(int n){
	
	dp[0]=1;
	
	int t=coin.size();
	
	for(int i=1; i<=n; i+=1){
		
		for(int j=0; j<t; j+=1){
			
			if(i >= coin[j]){
				
				dp[i] |= dp[i-coin[j]];
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
	
	for(int i=0; i<=n; i+=1){
		
		cout<<endl<<"Amount = "<<i<<endl;
		
		cout<<"Mark = "<<dp[i]<<endl;
	}
}
