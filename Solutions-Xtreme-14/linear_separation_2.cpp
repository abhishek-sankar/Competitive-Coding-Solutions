/*
A linear classifier, especially the Support Vector Machine (SVM), is a popular tool in the task of pattern recognition and artificial intelligence. An essential problem for the linear classifier is whether the given samples are linearly separable.

Let’s consider the 2D cases without the bias term. Each sample has two features, x_{1} \in \mathbb Rx
​1
​​ ∈R and x_{2} \in \mathbb Rx
​2
​​ ∈R, and a label y \in \{ 1,-1\}y∈{1,−1}. You will be given TT queries. For each query you are given a group of points on a 2D plane, your task is to determine whether the positive samples (labelled 11) and the negative samples (labelled -1−1) can be separated by a line through the origin (0,0)(0,0). If a line goes through some positive and/or negative points but separates all other points, it can be also accepted.


Mathematically speaking, you are asked to find whether there exist w_{1} \in \mathbb Rw
​1
​​ ∈R and w_{2} \in \mathbb Rw
​2
​​ ∈R , s. t.s.t.

\langle[ w_{1},w_{2}], [x_{1},x_{2}]\rangle = w_{1}x_{1}+w_{2}x_{2}\ge0\;\mathrm{IFF}\;y=1⟨[w
​1
​​ ,w
​2
​​ ],[x
​1
​​ ,x
​2
​​ ]⟩=w
​1
​​ x
​1
​​ +w
​2
​​ x
​2
​​ ≥0IFFy=1

\langle[ w_{1},w_{2}], [x_{1},x_{2}]\rangle = w_{1}x_{1}+w_{2}x_{2}\leq0\;\mathrm{IFF}\;y=-1⟨[w
​1
​​ ,w
​2
​​ ],[x
​1
​​ ,x
​2
​​ ]⟩=w
​1
​​ x
​1
​​ +w
​2
​​ x
​2
​​ ≤0IFFy=−1

hold for all samples (x_1,x_2),y(x
​1
​​ ,x
​2
​​ ),y.


Standard input
The first line of the input has an integer TT which represents the number of queries. Then, TT queries follow. The first line of each query has an integer NN that denotes the number of points in the query. Each of the following NN rows has two floating point numbers and an integer separated by single spaces. They represent the two features x_{1}x
​1
​​ , x_{2}x
​2
​​  and the label yy of one point.

Standard output
For each query, output the answer on a single line. Output YES if the given points can be separated by a line through the origin, and NO otherwise.


Constraints and notes
1\leq T\leq101≤T≤10
1 \leq N \leq 10^51≤N≤10
​5
​​ 
-100.0 \leq x_{1},x_{2} \leq 100.0−100.0≤x
​1
​​ ,x
​2
​​ ≤100.0
y=1y=1 or y=-1y=−1
x_1, x_2x
​1
​​ ,x
​2
​​  are given with at most two decimal points.
Points may overlap and have the same x_1, x_2x
​1
​​ ,x
​2
​​ .
For 50\%50% of the test data, 1 \leq N \leq 5\,0001≤N≤5000
Input	Output	Explanation
2
9
-2.0 1.0 1
2.0 2.0 -1
4.0 2.5 -1
4.0 0.5 -1
-1.0 -1.0 1
4.0 1.5 -1
-3.0 -1.0 1
2.0 3.0 -1
-4.0 1.0 1
4
2.0 2.0 1
2.0 -2.0 -1
-2.0 2.0 -1
-2.0 -2.0 1
YES
NO

For the first query, it can be seen from the figure that those points can be separated by the line there.


For the second query, it is the famous XOR case. It's impossible to separate the four points using just one line.
*/
#include <bits/stdc++.h>

using namespace std;
    
void result() {
    int T, label_val;
    float x_val, y_val;
    cin>>T;
    map<pair<float, float>, int>labelled_points;
    
    for(int i=0;i<T;i++){
        cin>>x_val>>y_val>>label_val;
        labelled_points.insert({{x_val, y_val}, label_val});
    }
    // the problem here is my code doesnt deal with 2 points collinear 
	// (3rd point being 0,0), but one is 1 and the other is -1
    for(auto i: labelled_points){
        int flag_1 = 0, flag_2 = 0;
        for(auto j: labelled_points){
            if(j.first!=i.first){
                if(j.second*((0-i.first.first)*(j.first.second - i.first.second) - (0-i.first.second)*(j.first.first - i.first.first))<0){
                    //>=0 means it is right
                    flag_1 = 1;
                }
                if(j.second*((0-i.first.first)*(j.first.second - i.first.second) - (0-i.first.second)*(j.first.first - i.first.first))>0){
                   flag_2 = 1;
                }
				if(j.second*((0-i.first.first)*(j.first.second - i.first.second) - (0-i.first.second)*(j.first.first - i.first.first))==0){
					if(j.second!=i.second){cout<<"NO"<<endl;
					return;}
				}
            }
        }
            if((flag_1 == 0 && flag_2 != 0) || (flag_1 != 0 && flag_2 == 0)){
                cout<<"YES"<<endl;
                return;
            }
    }
    //check flags and return appropriately
    cout<<"NO"<<endl;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
		// cout<<"Test"<<endl;
        result();
    }
}