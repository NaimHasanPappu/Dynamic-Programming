#include<bits/stdc++.h>

using namespace std;

vector <int> DP;

void Knap_Sack(){
	
	DP.clear();
	
	cout<<endl<<"How many items?"<<endl;
	
	int item;
	
	cin>>item;
	
	cout<<endl<<"Enter their value and weight"<<endl;
	
	vector <int> Value,Weight;
	
	for(int i=0; i<item; i+=1){
		
		int v,w;
		
		cin>>v>>w;
		
		Value.push_back(v);
		
		Weight.push_back(w);
	}
	
	cout<<endl<<"Enter maximum capacity"<<endl;
	
	int Max_Cap;
	
	for(int i=0; i<=Max_Cap; i+=1){
		
		DP.push_back(0);
	}
	
	for(int i=0; i<item; i+=1){
		
		for(int j=Max_Cap; j>=Weight[i]; j-=1){
			
			DP[j] = max ( DP[j] , Value[i] + DP[j-Weight[i]] );
		}
	}
	
	cout<<endl<<"Highest value you can earn = "<<DP[Max_Cap]<<endl;
}

int main(){
	
	Knap_Sack();
}
