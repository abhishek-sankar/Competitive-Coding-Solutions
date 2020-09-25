#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long res = n;
    //asasd
    int startIndex = 0, diffCharIndex = -1;
    for(int i=0;i<n;i++){
        startIndex = i;
        diffCharIndex = -1;
        for(int j=i+1;j<n;j++){
            if(s[startIndex]==s[j]){
                if(diffCharIndex==-1 || (diffCharIndex-startIndex==j-diffCharIndex)){
                    res++;
                }
            }else{
                if(diffCharIndex==-1){
                    diffCharIndex = j;
                }else{
                    break;
                    }
                }
            }
        }
    return res;
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
