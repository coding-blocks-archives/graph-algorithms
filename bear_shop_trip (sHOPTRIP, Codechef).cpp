/*https://codingblocks.com/ide/#/s/3897 */
#include<bits/stdc++.h>
using namespace std;
#define INT_MAX  100000000ll
#define N 50

long double distance(pair<int,int> p1,pair<int,int> p2){
	int dx = p1.first - p2.first;
	int dy = p1.second - p2.second; 
	return  sqrt(dx*dx+dy*dy);
}

long double dist[N][N] = {0};
long double dp[1<<13][N] ;
vector<pair<int,int> > coordinates;
vector<int> ingridents;

int n,k;
long double shopTrip(int mask,int idx){

	//Base Case - if you have collected all ingridents and returned to origin 
	if(mask==((1<<k)-1) && idx==0){
		return 0;
	}	
	if(dp[mask][idx]!=-1){
		return dp[mask][idx];
	}
	//Otherwise lets compute our answer
	dp[mask][idx] = INT_MAX;
	for(int i=0;i<=n;i++){
		if((mask|ingridents[i])!=mask||i==0){
			dp[mask][idx] = min(dp[mask][idx],dist[idx][i]+shopTrip(mask|ingridents[i],i));
		}
	}
	return dp[mask][idx];

}


int main(){
	int t,x,y;
	string temp;
	cin>>t;

	

	while(t--){
		cin>>n>>k;
		coordinates.clear();
		ingridents.clear();
		
		coordinates.push_back(make_pair(0,0));
		for(int i=0;i<n;i++){
			cin>>x>>y;
			coordinates.push_back(make_pair(x,y));
		}
		int possible = 0;
		ingridents.push_back(0);
		for(int i=0;i<n;i++){
			cin>>temp;
			reverse(temp.begin(),temp.end());

			int temp_mask = 0;
			for(int j=0;j<temp.length();j++){
				temp_mask |= (1<<j)*(temp[j]-'0');
			}
			possible |= temp_mask;

			ingridents.push_back(temp_mask);
		}
		if(possible!=((1<<k)-1)){
			cout<<"-1"<<endl;
			continue;
		}
		memset(dist,0,sizeof(dist));
		//Precompute distances between all nodes
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				dist[i][j] = distance(coordinates[i],coordinates[j]);
			}
		}
		//DP array - Initialisation
		for(int i=0;i<(1<<k);i++){
			for(int j=0;j<=n;j++){
				dp[i][j] =  -1;
			}
		}
		
		//Compute the Final Ans
		long double ans = shopTrip(0,0);
		cout<<fixed<<setprecision(9)<<ans<<endl;
	}

	return 0;
}