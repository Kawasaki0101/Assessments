/*From Kawasaki0101*/
#include<iostream>
#include<stdio.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
bool isLeapYear(int year) 
{
	return ((year%4==0 && year%100!=0) || year%400==0);
}
int getDays(int year, int month, int day)
{
	int m[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(isLeapYear(year))
		m[2]++;
	int result = 0;
	for(int i = 1;i < year;i++)
	{
		result += 365;
		if(isLeapYear(i))
			result ++;
	}
	for(int i = 1;i < month;i++)
	{
		result += m[i];
	}
	result += day;
	
	return result;
}
int getYears(int days)
{
	int sum = 0;int years = 1;int finalyears = 0;
	    for(int i =1;days>sum;i++){
        if(isLeapYear(i) ){
            sum = sum + 366;
          }else{
            sum = sum + 365;
               }
    years++;
    }
	finalyears = years - 1;
	return finalyears;
}
int getRemainder(int days,int finalyears )
{
	   for(int i = 1;i<=finalyears-1;i++){
        if(isLeapYear(i)){
            days = days - 366;
        }else{
            days = days -365;
        }
    }
	return days;
}
int main(){
	int days,month,years,num;
	int finaltotalldays;
	cout<<"Enter the difference in days: ";
	cin>>num;
	cout<<"Enter a date in the form day month year: ";
	cin>>days>>month>>years;
	finaltotalldays = getDays(years,month,days) + num;
	//cout<<totalldays;
	int fianlyears;
	fianlyears = getYears(finaltotalldays);
	int remianderDays;
	remianderDays = getRemainder(finaltotalldays,fianlyears);
	int sum = 0, i = 0;
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	 if((fianlyears%4==0&&fianlyears%100!=0)||(fianlyears%400==0)){
	 	a[1]=29;
	 }
	 while(sum+a[i]<remianderDays){
	 	sum+=a[i];
	 	i++;
	 }
	 cout<<remianderDays-sum<<"/"<<i+1<<"/"<<fianlyears;
}