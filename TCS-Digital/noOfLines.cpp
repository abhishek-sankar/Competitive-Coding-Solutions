#include<bits/stdc++.h>

using namespace std;

int main(){
	long noOfPagesInBookOne, noOfLinesPerPageInBookOne, noOfPagesInBookTwo, noOfLinesPerPageInBookTwo, readingSpeed, writingSpeed, time;
	cin>>noOfPagesInBookOne>>noOfLinesPerPageInBookOne>>noOfPagesInBookTwo>>noOfLinesPerPageInBookTwo>>readingSpeed>>writingSpeed>>time;
	
	long totalNoOfLinesInBookOne = noOfLinesPerPageInBookOne * noOfPagesInBookOne; 
	long totalNoOfLinesInBookTwo = noOfLinesPerPageInBookTwo * noOfPagesInBookTwo;
	long readingTime = totalNoOfLinesInBookOne/readingSpeed;
	long writingTime = totalNoOfLinesInBookTwo/writingSpeed;
	cout<<"Total Lines: "<<totalNoOfLinesInBookOne<<" "<<totalNoOfLinesInBookTwo<<endl;
	cout<<readingTime<<" "<<writingTime<<endl;
	if(time >= readingTime){
		//now youre writing
		time  = time - readingTime;
		long pageNo = time * writingSpeed / noOfLinesPerPageInBookTwo;
		long lineNo = time * writingSpeed % noOfLinesPerPageInBookTwo;
		cout<<"WRITE "<<pageNo<<" "<<lineNo<<endl;
	}else{
		//youre still reading
		long pageNo = time*readingSpeed/noOfLinesPerPageInBookOne;
		long lineNo = time*readingSpeed%noOfLinesPerPageInBookOne;
		if(pageNo!=0 && lineNo == 0){
			lineNo = noOfLinesPerPageInBookOne;
		}
		cout<<"READ "<<pageNo<<" "<<lineNo<<endl;
	}
	return 0;
}