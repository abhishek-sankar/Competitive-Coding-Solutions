#include<bits/stdc++.h>

using namespace std;

int main(){
map<char, int>m;
string name;
cin>>name;
for(int i=0;i<name.size();i++){
	//check if it exists in the map
	if(m.find(name[i])==m.end()){
		//does not exist
		m.insert({name[i],1});
	}else{
		m[name[i]] = m[name[i]]+1;
	}
}
for(auto i: m){
	cout<<i.first<<": "<<i.second<<endl;
}

return 0;
}
