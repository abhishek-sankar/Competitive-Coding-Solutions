#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
bool sortBySec(const pair<int,int>&a, const pair<int,int>&b){
    return (a.second<b.second);
}
int binarySearch(vector<pair<int, int>>myVec, int num, int left, int right){
    if(left>right)return -1;
    int mid = left+(right-left)/2;
    if(myVec[mid].second<num && myVec[mid+1].second>num)return mid;
    else if(myVec[mid].second<num && myVec[mid+1].second<num)return binarySearch(myVec, num, mid+1, right);
    else return binarySearch(myVec, num, left, mid-1);
}

float getMedian(int arr[], int arrSize){
	float median, leftSum=arr[0], rightSum=arr[arrSize-1];
	int i,j;
	for(i=0, j=arrSize-1;i!=j-1;){
		if(leftSum>rightSum){
			j--;
			rightSum+=arr[j];
		}
		else {
			i++;
			leftSum+=arr[i];
		}
	}
	// cout<<"The spot is i:"<<i<<" j:"<<j<<endl;
	if(leftSum>rightSum)return i;
	if(rightSum>leftSum)return j;
	median = float(i+j)/2;
	// cout<<"Median: "<<median<<endl;
	return median;
}
// Complete the activityNotifications function below.
void printArray(int arr[], int size){
	for(int i=0;i<size;i++){
		cout<<"i: "<<i<<" arr["<<i<<"] :"<<arr[i]<<endl;
	}
}
int activityNotifications(vector<int> expenditure, int d) {
	int arr[201] = {0};
	int arrSize = 201;
	for(int i=0;i<d;i++){
		arr[expenditure[i]]++;
	}
	int count = 0;
	for(int i=d;i<expenditure.size();i++){
		float median = getMedian(arr, arrSize);
		if(expenditure[i]>=2*median)count++;
		arr[expenditure[i-d]]--;
		arr[expenditure[i]]++;
	}
	return count;
}

int main()
{
    // ofstream cout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    cout << result << "\n";

    // cout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
