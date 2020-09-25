#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    if(r==1){
            long long count = 0;
            long size = arr.size();
            map<long long, long long >myMap;
            for(int i=0;i<size;i++){
            if(myMap.find(arr[i])==myMap.end()){
                myMap.insert({arr[i],1});
            }else{
                myMap[arr[i]]++;
                }
            }
            for(auto i:myMap){
                count+=i.second*(i.second-1)*(i.second-2)/6;
            }
            return count;
        }

    long count = 0;
    long size = arr.size();
    map<long long, long long>myMap;
    for(int i=0;i<size;i++){
        if(myMap.find(arr[i])==myMap.end()){
            myMap.insert({arr[i],1});
        }else{
            myMap[arr[i]]++;
        }
    }
	for(auto i: myMap){
		cout<<"first "<<i.first<<" Second "<<i.second<<endl;
	}
    for(auto i:myMap){
        if(myMap.find(i.first*r)!=myMap.end() && myMap.find(i.first*r*r)!=myMap.end()){
            count+= i.second*myMap[i.first*r]*myMap[i.first*r*r];
			cout<<"i: "<<i.first<<" Count :"<<count<<endl;
            // i.second = 0;
        }
    }
    return count;
}

int main()
{
    // ofstream cout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    cout << ans << "\n";

    // cout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
