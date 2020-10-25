/*
A group of Xtreme soldiers are fighting a tough war but are unfortunately trapped within the enemy territory. But don't worry, they managed to find NN hideouts along a long battle line. The hideouts are numbered 11 to NN. Initially there are S_iS
​i
​​  soldiers at hideout ii.

There is a safe rendezvous location. Each hideout has one path to the rendezvous location. However, since the enemies are heavily patrolling the area, that path between the rendezvous location and hideout ii cannot be taken unless the weather around hideout ii is foggy.

You are planning a rescue mission to safely evacuate these soldiers in the next DD days. You are able to forecast that on day ii, the hideouts numbered L_i, L_i+1, ...R_{i}L
​i
​​ ,L
​i
​​ +1,...R
​i
​​  will have foggy weather, and will be able to gather at the rendevouz location. You will send a vehicle that can evacuate V_iV
​i
​​  soldiers. The remaining soldiers must go back to the hideouts. The soldiers do not necessarily need to go back to the hideout where they came from. Instead, they can go to any hideout with a number between L_iL
​i
​​  and R_iR
​i
​​ . Each hideout may have an arbitrary number of soldiers at any time, including zero.


If you coordinate the movements of the soldiers carefully, what is the maximum total number of soldiers you can evacuate?


Standard input
There is a single integer NN on the first line, the number of hideouts. The second line has NN integer. The ii-th integer is S_iS
​i
​​ .

The next line has a single integer DD, the number of days. Each of the next DD lines has three integers L_iL
​i
​​ , R_iR
​i
​​ , and V_iV
​i
​​ . They indicate that on day ii hideouts L_i, L_i+1, ... R_iL
​i
​​ ,L
​i
​​ +1,...R
​i
​​  will have foggy weather, and you will send a vehicle to the rendezvous location that can evacuate V_iV
​i
​​  soldiers from these hideouts.


Standard output
Output the maximum total number of soldiers you can evacuate.


Constraints and notes
1 \leq N \leq 10^51≤N≤10
​5
​​ 
0 \leq S_i \leq 10^40≤S
​i
​​ ≤10
​4
​​ 
1 \leq D \leq 5\,0001≤D≤5000
1 \leq L_i \leq R_i \leq N1≤L
​i
​​ ≤R
​i
​​ ≤N
1 \leq V_i \leq 10^91≤V
​i
​​ ≤10
​9
​​ 
For 30\%30% of the test data, D \leq 50D≤50 and N \leq 50N≤50.
For 60\%60% of the test data, D \leq 50D≤50.

Input	Output	Explanation
4
5 4 3 2
4
1 2 4
1 1 3
2 4 1
3 3 4
12
At the beginning, the number of soldiers at the hideouts are [5, 4, 3, 2][5,4,3,2]. On day 11, there are 99 soldiers from hideout 11 and 22 that can be evacuated. The vehicle takes 44, and the 33 of the 55 remaining soldiers can go to hideout 11 to wait for the vehicle on day 22. The other 22 remaining soldiers go to hideout 22. The number of soldiers at the hideouts are therefore [3, 2, 3, 2][3,2,3,2]. After day 22, the numbers become [0, 2, 3, 2][0,2,3,2]. On day 33, we can evacuate one solder from hideout 22, and let the other soldier there go to hideout 33. The numbers of soldiers at the hideouts become [0, 0, 4, 2][0,0,4,2]. On the last day, the 44 soldiers at hideout 33 will be evacuated.

3
7 8 7
6
1 2 1
2 3 1
3 3 9
2 3 1
1 2 1
1 1 9
22
At the beginning, we have [7, 8, 7][7,8,7] soldiers. In the first two days, two soldiers can be evacuated, and at the same time all soldiers can move to hideout 33, getting [0, 0, 20][0,0,20] by the end of day 22. On day 33 we can evacuate 99 soldiers, getting [0, 0, 11][0,0,11]. Then on day 44 and 55 two soldiers can be evacuated, and at the same time all soldiers can move to hideout 11, getting [9, 0, 0][9,0,0]. On the last day all the remaining soldiers can be evacuated.
*/

#include <bits/stdc++.h> 
using namespace std; 

typedef long long int ll;

int main(){

    int n;
    cin >> n;

    vector<int> soldierCount;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        soldierCount.push_back(x);
    }

    int d;
    cin >> d;
    vector<int> left;
    vector<int> right;
    vector<int> rescueLimit;
    int res = 0; 
    for (int i = 0; i < d; i++){
        int l, r, v;
        cin >> l >> r >> v;

        left.push_back(l);
        right.push_back(r);
        rescueLimit.push_back(v);
        res += v;
    }

    res -= rescueLimit[0];
    int maxRescued = soldierCount[left[0]-1];
    for (int i = left[0]-1; i < right[0]; i++){
        maxRescued = maxRescued < soldierCount[i]? soldierCount[i]:maxRescued;
    }

    int rescuedFirst = rescueLimit[0] < maxRescued? rescueLimit[0]:maxRescued;
    res += rescuedFirst;

    cout << res;
    return 0;
}