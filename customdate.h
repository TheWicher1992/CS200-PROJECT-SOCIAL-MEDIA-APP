//#include <iostream>
//#include<string>
//#include <stdio.h> 
//#include <stdlib.h> 
//#include <time.h> 
//#include<iomanip>
//using namespace std;
struct Date {
	int day;
	int month;
	int year;
	Date() {
		day = 0;
		month = 0;
		year = 0;
	}
	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	void print() {
		string m;
		switch (month)
		{
		case 0:
			m = "January";
			break;
		case 1:
			m = "Febraury";
			break;
		case 2:
			m = "March";
			break;
		case 3:
			m = "April";
			break;
		case 4:
			m = "May";
			break;
		case 5:
			m = "June";
			break;
		case 6:
			m = "July";
			break;
		case 7:
			m = "August";
			break;
		case 8:
			m = "September";
			break;
		case 9:
			m = "October";
			break;
		case 10:
			m = "November";
			break;
		case 11:
			m = "December";
			break;
		default:
			break;
		}

		cout << day << "/" << m << "/" << year << endl;
	}
};

#pragma once
#pragma once
