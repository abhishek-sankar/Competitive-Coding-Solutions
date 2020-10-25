#include <bits/stdc++.h>

using namespace std;
    
void result() {
    int T, label_val;
    float x_val, y_val;
    cin>>T;
    map<pair<float, float>, int>labelled_points;
    
    for(int i=0;i<T;i++){
        cin>>x_val>>y_val>>label_val;
        labelled_points.insert({{x_val, y_val}, label_val});
    }
    // the problem here is my code doesnt deal with 2 points collinear 
	// (3rd point being 0,0), but one is 1 and the other is -1
    for(auto i: labelled_points){
        int flag_1 = 0, flag_2 = 0;
        for(auto j: labelled_points){
            if(j.first!=i.first){
                if(j.second*((0-i.first.first)*(j.first.second - i.first.second) - (0-i.first.second)*(j.first.first - i.first.first))<0){
                    //>=0 means it is right
                    flag_1 = 1;
                }
                if(j.second*((0-i.first.first)*(j.first.second - i.first.second) - (0-i.first.second)*(j.first.first - i.first.first))>0){
                   flag_2 = 1;
                }
				if(j.second*((0-i.first.first)*(j.first.second - i.first.second) - (0-i.first.second)*(j.first.first - i.first.first))==0){
					if(j.second!=i.second){cout<<"NO"<<endl;
					return;}
				}
            }
        }
            if((flag_1 == 0 && flag_2 != 0) || (flag_1 != 0 && flag_2 == 0)){
                cout<<"YES"<<endl;
                return;
            }
    }
    //check flags and return appropriately
    cout<<"NO"<<endl;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
		// cout<<"Test"<<endl;
        result();
    }
}