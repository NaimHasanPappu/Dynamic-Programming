#include<bits/stdc++.h>

using namespace std;

#define Pair pair <int , int>

vector <Pair> arr;

bool comp(Pair a , Pair b){
	
	return a.second*b.first > a.first*b.second;
}

void Knap_Sack(){
	
	arr.clear();
	
	printf("\nNumber of item\n");
	
	int item;
	
	cin>>item;
	
	printf("\nEnter their weight and price\n");
	
	for(int i=0; i<item; i+=1){
		
		int w,p;
		
		cin>>w>>p;
		
		arr.push_back(make_pair(w,p));
	}
	
	sort(arr.begin(),arr.end(),comp);
	
	printf("\nEnter maximum capacity\n");
	
	int W;
	
	cin>>W;
	
	int ans=0;
	
	for(int i=0; i<item; i+=1){
		
		int z = min(W,arr[i].first);
		
		W -= z;
		
		ans+=z*arr[i].second;
		
		if(W==0){
			
			break;
		}
	}
	
	printf("Maximum profit is = ");
	
	cout<<ans<<endl;
}

int main(){
	
	Knap_Sack();
}
