/*
https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem?h_l=interview&h_r%5B%5D%5B%5D=next-challenge&h_r%5B%5D%5B%5D=next-challenge&h_v%5B%5D%5B%5D=zen&h_v%5B%5D%5B%5D=zen&isFullScreen=false&playlist_slugs%5B%5D%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D%5B%5D=strings
Awesome testcaes
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    map<char, int>myMap;
    for(int i=0;i<s.size();i++){
        if(myMap.find(s[i])==myMap.end()){
            myMap.insert(make_pair(s[i],1));
        }else{
            myMap[s[i]]++;
        }
    }
    map<int, int> M;
    for(auto i: myMap){
        if(M.find(i.second)==M.end()){
            M.insert({i.second,1});
        }else{
            M[i.second]++;
        }
    }
    if(M.size()>2)return "NO";
    else if(M.size()==1)return "YES";
    else if(M.size()==2){
        cout<<"Hi"<<endl;
        map<int,int>::iterator itr, itr2;
        itr = M.begin();
        itr2 = M.begin();
        itr2++;
        cout<<itr->first<<" "<<itr2->first<<endl;
        // cout<<abs(itr->first - (itr2)->first)<<" "<<itr->second<<" "<<itr2->second<<endl;
        // if ((abs(itr->first - itr2->first)==1) &&
        //         ((itr->first==1 && itr->second ==1)||
        //             (itr2->first==1 && itr2->second==1)) || (itr->second ==1||itr2->second==1))
        //     return "YES";
        // return "NO";
        if(abs(itr->first - itr2->first)==1){
            if(itr->second ==1||itr2->second==1)return "YES";
        }else if(((itr->first==1 && itr->second ==1)||(itr2->first==1 && itr2->second==1))){
            return "YES";
        }
        return "NO";

    }
    return "YES";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
