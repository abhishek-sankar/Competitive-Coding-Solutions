/*
https://www.interviewbit.com/problems/large-factorial/

*/
vector<int> multiply(vector<int> v, int n) {
    int carry = 0;
    for(int i = 0; i < v.size(); ++i) {
        int m = v[i] * n + carry;
        v[i] = m % 10;
        carry = m / 10;
    }
    vector<int> res(v.begin(), v.end());
    while(carry) {
        res.push_back(carry % 10);
        carry = carry / 10;
    }
    return res;
}

string Solution::solve(int n) {
    vector<int> res;
    if(n == 0 or n == 1)
        return to_string(1);
    res.push_back(1);
    for(int i = 2; i <= n; ++i)
        res = multiply(res, i);
    string s;
    for(int i = res.size() - 1; i >= 0; --i)
        s += res[i] + '0';
    return s;
}

// void doFact(int arr[], int& size, int mul){
//     int carry = 0;
//     int i;
//     for(i=0;i<size;i++){
//         arr[i]*=mul;
//         arr[i]+=carry;
//         carry = arr[i]/10;
//         arr[i] = arr[i]%10;
//     }
//     if(carry){
//         size++;
//         arr[i] = carry;
//     }    
// }
// string Solution::solve(int A) {
//     int arr[1000] = {1};
//     int size = 1;
//     for(int i=2;i<=A;i++){
//         doFact(arr, size, i);
//     // for(int i=size-1;i>=0;i--){
//     //     cout<<arr[i];
//     // }
//     // cout<<endl;
//     }
//     vector<int>v;
//     for(int i=size-1;i>=0;i--){
//         cout<<arr[i];
//         v.push_back(arr[i]);
//     }
//     // cout<<v.size()<<endl;
//     // std::string str(v.begin(), v.end());
//     // cout<<"String is "<<str<<endl;
//     return str;
// }

/*
Passes sample testcases, but gets only a partial for final testcases
string Solution::solve(int A) {
    long double fact=1;
    for(int i=A;i>1;i--){
        fact*=i;
    }
    string str = to_string(fact);
    string st = str.substr(0, str.find('.'));
    return st;
}
*/