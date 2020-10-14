

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