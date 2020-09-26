// https://www.hackerrank.com/challenges/common-child/
#include <bits/stdc++.h>

using namespace std;

int LCS(string s1, string s2, int l1, int l2, map<pair<int,int>, int>&keyMap){
    if(keyMap.find(make_pair(l1,l2))!=keyMap.end()) return keyMap[make_pair(l1,l2)];
    if(l1<=0||l2<=0){
        return 0;
    }else if(s1[l1-1]==s2[l2-1]){
        cout<<l1<<" "<<l2<<endl;
        int res = LCS(s1, s2, l1-1, l2-1, keyMap)+1;
        keyMap.insert({make_pair(l1,l2),res});
        keyMap.insert({make_pair(l1-1,l2-1),res-1});
        return res;
    }else{
        int leftVal = LCS(s1, s2, l1-1, l2, keyMap);
        int rightVal = LCS(s1, s2, l1, l2-1, keyMap);
        keyMap.insert({make_pair(l1-1,l2),leftVal});
        keyMap.insert({make_pair(l1,l2-1),rightVal});
        return max(leftVal, rightVal);
    }
}

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    map<pair<int,int>, int>keyMap;
    return LCS(s1, s2, s1.length(), s2.length(), keyMap);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
