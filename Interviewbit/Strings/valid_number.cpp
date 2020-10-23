/*
https://www.interviewbit.com/problems/valid-number/

Valid Number
Asked in:  Adobe
Please Note:
Note: It is intended for some problems to be ambiguous. You should gather all requirements up front before implementing one.
Please think of all the corner cases and clarifications yourself.

Validate if a given string is numeric.

Examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Clarify the question using “See Expected Output”

Is 1u ( which may be a representation for unsigned integers valid?
For this problem, no.
Is 0.1e10 valid?
Yes
-01.1e-10?
Yes
Hexadecimal numbers like 0xFF?
Not for the purpose of this problem
3. (. not followed by a digit)?
No
Can exponent have decimal numbers? 3e0.1?
Not for this problem.
Is 1f ( floating point number with f as prefix ) valid?
Not for this problem.
How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
Not for this problem.
How about integers preceded by 00 or 0? like 008?
Yes for this problem
*/

int Solution::isNumber(const string A) {
    int point = 0;
    int exp = 0;
    int i=0;
    int sign = 1;
    int flag = 0;
    while(A[i]==' ')i++;
    if(A[i]=='-'){sign = -1; i++;}
    if(i==A.size()) return 0;
    while(A[i]=='0')i++;
    if(i==A.size()) return 1;
    // -01.1e-10
    for(;i<A.size();i++){
        // cout<<A[i]<<" ";
        if(!isdigit(A[i])){
            flag = 1;
            if(A[i]=='.' && point == 0 && isdigit(A[i+1]) && exp == 0){
                // cout<<A[i]<<" exp "<<exp<<" point "<<point<<endl;
                point = 1;
                flag = 0;
            }else if(A[i]=='.'){
                return 0;
            }
            if(A[i]=='e' && exp == 0 && (isdigit(A[i+1]) || A[i+1]=='-')){
                // cout<<A[i]<<" Exp "<<exp<<endl;
                exp = 1;
                if(A[i+1]=='-')i++;
                flag = 0;
            }else if(A[i]=='e'){
                return 0;
            }
            if(A[i]==' '){
                int k=i;
                while(A[k]==' ')k++;
                if(k==A.size())return 1;
            }
            if(flag==1)
            return 0;
        }
    }
    return 1;
}
