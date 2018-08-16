#include <bits/stdc++.h>
#include<windows.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
const int N = 1e6 + 10;
const ll inf = 1e18;
const int mod = 1e9 + 7;


map<string, int> mp;
map<int, string> mpp;
vector<pair<int, int> > v[N];
vector<int> vi;
ll dist[N];
bool visit[N];
multiset<pair<ll, ll> > st;
int n;

ll ans;
void input(){
	int m, z;
	string x, y;
	string xx[5] = {"pune",
				   "mumbai",
				   "delhi",
				   "chennai",
                    "jaipur"};
	//cout << "Enter the no of staiton\n";
	n = 5;
	for(int i = 1; i <= n; i++){
		//cout << "Enter the name of station : ";

		mp[xx[i - 1]] = i;
		mpp[i] = xx[i - 1];
	}
	//cout << "Enter the no of routes\n";
	m = 6;
	string ss[6] = {"pune",
					"pune",
					"mumbai",
					"chennai",
					"mumbai",
					"jaipur"};
	string ee[6] = {"mumbai",
					"delhi",
					"delhi",
					"jaipur",
					"chennai",
					"chennai"};
	int wt[6] = {3, 12, 8, 15, 10, 4};
	for(int i = 1; i <= m; i++){
		//cout << "Enter starting and ending destination and fair\n";
		x = ss[i - 1];
		y = ee[i - 1];
		z = wt[i - 1];
		v[mp[x]].push_back({mp[y], z});
		v[mp[y]].push_back({mp[x], z});
	}
	//cout << "Graph creation complete\n";
}

ll calc(ll strt, ll end){
	st.clear();
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= n; i++){
		if(i == strt)
			dist[i] = 0;
		else
			dist[i] = inf;
	}
	st.insert({0LL, strt});
	while(!st.empty()){
		ll vertex = st.begin()->second;
		ll currdist = st.begin()->first;
		st.erase(st.begin());
		if(visit[vertex])
			continue;
		else
			visit[vertex] = 1;
		for(auto i : v[vertex]){
			if(currdist + i.second < dist[i.first]){
				st.insert({currdist + i.second, i.first});
				dist[i.first] = currdist + i.second;
			}
		}
	}
	return dist[end];
}



ll querry(){
	//cout << "Enter the starting destination and ending destination\n";
	vi.clear();
	string s, end;
	cin >> s>> end;
	ll mndist = calc(mp[s], mp[end]);
	ll temp = mp[end], tt = dist[mp[end]];
	while(temp != mp[s]){
		vi.push_back(temp);
		for(auto i : v[temp]){
			if(dist[i.first] + i.second == tt){
				temp = i.first;
				tt = dist[temp];
				break;
			}
		}
	}
	vi.push_back(mp[s]);
	for(auto i : vi ) {
		cout << mpp[i] << ' ' ;
	}
	cout << endl ;
	cout << "FARE  - " << mndist * 75 << "\n" ;
	//cout << mndist << "\n"
	ans =  mndist * 75 ;
}


int main(){
	//while(1)
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	input();
	 querry();

	 cout << "TOTAL FARE IS -----------"  << ans ;
	 return 0 ;
}
