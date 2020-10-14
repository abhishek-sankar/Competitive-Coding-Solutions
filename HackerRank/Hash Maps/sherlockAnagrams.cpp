#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    map<string, int>myMap;
    long count = 0;
    for(int len=1; len<=s.size();len++){
        for(int i=0;i<=s.size()-len; i++){
            string str = s.substr(i, len);
			// cout<<str<<endl;
			sort(str.begin(),str.end());
            if(myMap.find(str)==myMap.end()){
                myMap.insert({str, 1});
				// cout<<str<<endl<<"Value :"<<myMap[str]<<" count"<<count<<endl;
            }else{
                count+=myMap[str];
                myMap[str]+=1;
				// cout<<str<<endl<<"Value :"<<myMap[str]<<" count"<<count<<endl;
            }
        }
    }
    return count;
}

int main()
{
    // ofstream cout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        cout << result << "\n";
    }

    // cout.close();

    return 0;
}
