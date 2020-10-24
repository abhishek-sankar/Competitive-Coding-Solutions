#include <bits/stdc++.h>

using namespace std;

int main() {
    int total, initial;
    int ch;
    cin>>initial>>total;
    vector<char>lights(total, '0');
    for(int i=0;i<initial;i++){
        cin>>ch;
        lights[ch] = '1';
    }
    map<string, int>kid_memory;
    string initial_pattern (lights.begin(), lights.end());
	// cout<<"Initial pattern is: "<<initial_pattern<<endl;
    // kid_memory.insert({current_pattern, 1});
    int i;
	for(i=1;i<total;i++){
        ch = lights[i-1];
        lights.push_back(ch);
        string current_pattern (lights.begin()+i, lights.end());
		// cout<<current_pattern<<endl;
		if(current_pattern.compare(initial_pattern)==0){
			cout<<(i-1)<<endl;
			return 0;
		}

        // if(kid_memory.find(current_pattern)!=kid_memory.end()){
        //     cout<< kid_memory.size()-1<<endl;
        //     return 0;
        // }else{
        //     kid_memory[current_pattern] = 1;
        // }
    }
    cout<<i-1<<endl;
    return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int total, initial;
    long long int ch;
    cin>>initial>>total;
    vector<char>lights(total, '0');
    for(int i=0;i<initial;i++){
        cin>>ch;
        lights[ch] = '1';
    }
    map<string, int>kid_memory;
    string current_pattern (lights.begin(), lights.end());
// 	cout<<"Initial pattern is: "<<current_pattern<<endl;
    kid_memory.insert({current_pattern, 1});
    for(int i=1;i<total;i++){
        ch = lights[i-1];
        lights.push_back(ch);
        string current_pattern (lights.begin()+i, lights.end());
// 		cout<<current_pattern<<endl;
        
        if (kid_memory.size() > total){
            cout << total-1 << endl;
        }
        if(kid_memory.find(current_pattern)!=kid_memory.end()){
            cout<< kid_memory.size()-1<<endl;
            return 0;
        }else{
            kid_memory[current_pattern] = 1;
        }
    }
    cout<<kid_memory.size()-1<<endl;
    return 0;
}
*/