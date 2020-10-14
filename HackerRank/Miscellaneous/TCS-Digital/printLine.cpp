#include<bits/stdc++.h>

using namespace std;

int main(){
	long linesPerPageInBookOne, linesPerPageInBookTwo, noOfPagesInBookOne, noOfPagesInBookTwo, readingSpeed, writingSpeed, time;
	cin>>noOfPagesInBookOne>>linesPerPageInBookOne>>noOfPagesInBookTwo>>linesPerPageInBookTwo>>readingSpeed>>writingSpeed>>time;
	long totalLinesInBookOne = linesPerPageInBookOne * noOfPagesInBookOne;
	long totalLinesInBookTwo = linesPerPageInBookTwo * noOfPagesInBookTwo;
	long timeSpentReading = totalLinesInBookOne/readingSpeed;
	long timeSpentWriting = totalLinesInBookTwo/writingSpeed;
	cout<<"ReadTime: "<<timeSpentReading<<endl<<"WriteTime: "<<timeSpentWriting<<endl;
	if(timeSpentReading <= time && time <= (timeSpentReading+ timeSpentWriting)){
		time-=timeSpentReading;
		cout<<"Time: "<<time<<"WritingSpeed: "<<writingSpeed<<endl;
		long pageNo = (time*writingSpeed)/linesPerPageInBookTwo;
		long lineNo = (time*writingSpeed)%linesPerPageInBookTwo;
		cout<<"Writing: "<<pageNo<<" "<<lineNo<<endl;
	}else if (time < timeSpentReading){
		long pageNo = (time*readingSpeed)/linesPerPageInBookOne;
		long lineNo = (time*readingSpeed)%linesPerPageInBookOne;
		cout<<"Reading: "<<pageNo<<" "<<lineNo<<endl;
	}else{
		//last page last line 
	}
	
	return 0;
}