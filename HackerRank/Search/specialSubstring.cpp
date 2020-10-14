#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
void checkSpecialSubstring(string s, int start, int end, long &count){

    long strSize = end+1;
    // cout<<strSize<<endl;
    if(strSize<=1) {
        count+=1;
        return;
    }
    char ch = s[start];
    for(int i=start;i<start+strSize;i++){
        if(i==(start+(strSize-1)/2))continue;
        if(s[i]!=ch)
            return;
    }
    for(int i=start; i<=start+end;i++){
        cout<<s[i];
    }
    // cout<<endl;    
    // cout<<s<<endl;
    // cout<<"Test"<<endl;
    count++;
}
// Complete the substrCount function below.
long substrCount(int n, string s) {
    long count = 0;
    for(int len = 1; len<=n;len++){
        for(int i=0;i<=n-len;i++){
            //str : i to i + len - 1
            checkSpecialSubstring(s, i, len-1, count);
        }
    }
    return count;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
