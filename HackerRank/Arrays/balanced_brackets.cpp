#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<int> my_stack;
    for(int i=0;i<s.size();i++){
        switch(s[i]){
            case '(':my_stack.push(1);break;
            case ')':if(!my_stack.empty() && my_stack.top()==1){
                        my_stack.pop();
                        }else{
                            return "NO";
                        }break;
            case '{':my_stack.push(2);break;
            case '}':if(!my_stack.empty() && my_stack.top()==2){
                        my_stack.pop();
                        }else{
                            return "NO";
                        }break;
            case '[':my_stack.push(3);break;
            case ']':if(!my_stack.empty() && my_stack.top()==3){
                        my_stack.pop();
                        }else{
                            return "NO";
                        }break;  
            default: return "NO";          
        }
    }
    if(my_stack.empty()){
        return "YES";
    }else{
        return "NO";
    }

}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
