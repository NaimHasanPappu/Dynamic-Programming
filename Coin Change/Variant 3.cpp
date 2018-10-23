/*	Each coin can be used only once.

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
	
	for(int j=0; j<t; j+=1){
		
		for(int i=n; i>=1; i-=1){
			
			if (i >= coin[j] && dp[i-coin[j]] ){
				
				dp[i]=1;
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
		
		cout<<endl<<"Money = "<<i<<endl;
		
		if(dp[i]){
			
			cout<<"Yes";
		}
		
		else{
			
			cout<<"No";
		}
		
		cout<<endl;
	}
}
