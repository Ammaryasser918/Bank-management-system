#pragma once
#pragma warning (disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "clsString.h"
using namespace std;


class clsDate {

private:
	int _day = 1;
	int _month = 1;
	int _year = 1900;

public:

	clsDate() {
		time_t t = time(0);
		tm* now = localtime(&t);
		_day = now->tm_mday;
		_month = now->tm_mon + 1;
		_year = now->tm_year + 1900;
	}

	clsDate(string date) {
		vector<string> Vdate;
		Vdate = clsString::split_string(date, '/');

		_day = stoi(Vdate[0]);
		_month = stoi(Vdate[1]);
		_year = stoi(Vdate[2]);

	}

	clsDate(int day, int month, int year) {
		_day = day;
		_month = month;
		_year = year;
	}

	clsDate(int DateOrder, int Year)
	{
		clsDate d = Date_By_Order_Of_Day_In_Year(DateOrder, Year);
		_day = d.Day;
		_month = d.Month;
		_year = d.Year;
	}



	void SetDay(short Day) {
		_day = Day;
	}

	short GetDay() {
		return _day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month) {
		_month = Month;
	}

	short GetMonth() {
		return _month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;


	void SetYear(short Year) {
		_year = Year;
	}

	short GetYear() {
		return _year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short Year;


	void Print_Date() {
		cout << _day << '/' << _month << '/' << _year << endl;
	}
	
	// =============================================================
	// =============================================================
	// =============================================================

	static bool Is_Leap_Year(int year) {
		return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	}


	static int Num_Of_Days_In_Year(int year) {
		if (Is_Leap_Year(year)) {
			return 366;
		}
		else {
			return 365;
		}
	}

	static clsDate Get_System_Date() {
		time_t t = time(0);
		tm* now = localtime(&t);
		int day, month, year;
		day = now->tm_mday;
		month = now->tm_mon + 1;
		year = now->tm_year + 1900;
		return clsDate(day, month, year);
	}

	static string Date_To_String(clsDate dt) {
		return  to_string(dt.Day) + "/" + to_string(dt.Month) + "/" + to_string(dt.Year);
	}


	static int Num_Of_Hours_In_Year(int year) {
		return Num_Of_Days_In_Year(year) * 24;
	}
	int Num_Of_Hours_In_Year() {
		return Num_Of_Hours_In_Year(_year);
	}


	static int Num_Of_Minits_In_Year(int year) {
		return Num_Of_Hours_In_Year(year) * 60;
	}
	int Num_Of_Minits_In_Year() {
		return Num_Of_Minits_In_Year(_year);
	}
	

	static int Num_Of_Seconds_In_Year(int year) {
		return Num_Of_Minits_In_Year(year) * 60;
	}
	int Num_Of_Seconds_In_Year() {
		return Num_Of_Seconds_In_Year(_year);
	}


	static int Num_Of_Days_In_Month(int month, int year) {
		if (month > 12 || month < 1) return 0;

		vector<int> months{ 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2) return (Is_Leap_Year(year) ? 29 : 28);
		return months[month - 1];

	}
	int Num_Of_Days_In_Month() {
		return Num_Of_Days_In_Month(_month, _year);
	}

	static int Num_Of_Hours_In_Month(int month, int year) {
		return (Num_Of_Days_In_Month(month, year) * 24);
	}
	int Num_Of_Hours_In_Month() {
		return (Num_Of_Hours_In_Month(_month, _year));
	}

	static int Num_Of_Minits_In_Month(int month, int year) {
		return (Num_Of_Hours_In_Month(month, year) * 60);
	}
	int Num_Of_Minits_In_Month() {
		return (Num_Of_Minits_In_Month(_month, _year));
	}

	static int Num_Of_Seconds_In_Month(int month, int year) {
		return Num_Of_Minits_In_Month(month, year) * 60;
	}
	int Num_of_Seconds_In_Month() {
		return Num_Of_Seconds_In_Month(_month, _year);
	}

	static int Day_Of_Week_Index(int day, int month, int year) {
		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + 12 * a - 2;

		int res = day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12;
		return ((res % 7) + 7) % 7;
	}

	static string Day_Of_Week_Order(int day, int month, int year) {
		int order = Day_Of_Week_Index(day, month, year);
		vector<string> days_of_week{ "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return days_of_week[order];
	}
	string Day_Of_Week_Order() {
		return Day_Of_Week_Order(_day, _month, _year);
	}


	static string Current_Month_Name(int month) {
		vector<string> months{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return months[month - 1];
	}

	string Current_Month_Name() {
		return Current_Month_Name(_month);
	}

	static void Print_Month_Calinder(int month, int year) {

		int num_of_days = Num_Of_Days_In_Month(month, year);
		int current_day_idx = Day_Of_Week_Index(1, month, year);

		printf("\n  _______________%s_______________\n\n", Current_Month_Name(month).c_str());

		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i;
		for (i = 0; i < current_day_idx; i++) {
			printf("     ");
		}

		
		for (int j = 1; j <= num_of_days; j++) {
			printf("%5d", j);

			if (++i == 7) {
				i = 0;
				printf("\n");
			}

		}
		

		printf("\n  _________________________________\n");


	}


	void Print_Month_Calinder() {
		Print_Month_Calinder(_month, _year);
	}


	static void Print_Year_Calinder(int year) {
		for (int i = 1; i <= 12; i++) {
			Print_Month_Calinder(i, year);
			cout << endl << endl;
		}
	}

	void Print_Year_Calinder() {
		Print_Year_Calinder(_year);
	}


	static int Number_Of_Days_From_The_Beginning_Of_Year(int day, int month, int year) {

		int total_days = 0;

		for (int i = 1; i < month - 1; i++) {
			total_days += Num_Of_Days_In_Month(i, year);
		}
		total_days += day;
		return total_days;

	}
	int Number_Of_Days_From_The_Beginning_Of_Year() {
		return Number_Of_Days_From_The_Beginning_Of_Year(_day, _month, _year);
	}
	

	
	

	static clsDate Date_By_Order_Of_Day_In_Year(int order, int year) {

		int remain_days = order;
		clsDate dt;
		dt.Year = year;
		dt.Month = 1;

		while (true) {
			if (Num_Of_Days_In_Month(dt.Month, year) <= remain_days) {
				remain_days -= Num_Of_Days_In_Month(dt.Month, year);
				dt.Month++;
			}
			else
			{
				dt.Day = remain_days;
				break;
			}
		}

		return dt;


	}

	clsDate Date_By_Order_Of_Day_In_Year(int order) {
		return Date_By_Order_Of_Day_In_Year(order, _year);
	}



	static clsDate Date_After_N_Days(int day, int month, int year, int added) {
		clsDate dt;
		dt.Day = day;
		dt.Month = month;
		dt.Year = year;

		for (int i = 0; i < added; i++) {
			dt.Day++;

			if (dt.Day > Num_Of_Days_In_Month(dt.Month, dt.Year)) {
				dt.Day = 1;
				dt.Month++;

				if (dt.Month > 12) {
					dt.Month = 1;
					dt.Year++;
				}
			}
		}

		return dt;
	}

	static clsDate Date_After_N_Days(clsDate date, int added) {
		clsDate dt;
		dt.Day = date.Day;
		dt.Month = date.Month;
		dt.Year = date.Year;

		dt.Day += added;

		
		while (dt.Day > Num_Of_Days_In_Month(dt.Month, dt.Year)) {
			dt.Day -= Num_Of_Days_In_Month(dt.Month, dt.Year);
			dt.Month++;

			if (dt.Month > 12) {
				dt.Month = 1;
				dt.Year++;
			}
		}

		return dt;
	}

	clsDate Date_After_N_Days(int added) {
		return Date_After_N_Days(*this, added);
	}



	static bool Is_Date1_Before_Date2(clsDate date1, clsDate date2) {
		if (date1.Year < date2.Year) {
			return true;
		}
		else if (date1.Year > date2.Year) {
			return false;
		}
		else {
			if (date1.Month < date2.Month) {
				return true;
			}
			else if (date1.Month > date2.Month) {
				return true;
			}
			else {
				if (date1.Day < date2.Day) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}

	bool Is_Date1_Before_Date2(clsDate dt) {
		return Is_Date1_Before_Date2(*this, dt);
	}

	

	static bool Is_Date1_Equal_Date2(clsDate date1, clsDate date2) {
		if (date1.Year == date2.Year && date1.Month == date2.Month && date1.Day == date2.Day) {
			return true;
		}
		return false;
	}

	bool Is_Date1_Equal_Date2(clsDate dt) {
		return Is_Date1_Equal_Date2(*this, dt);
	}

	static bool Is_Last_Day_In_Month(clsDate date) {
		int days_in_month = Num_Of_Days_In_Month(date.Month, date.Year);
		return days_in_month == date.Day;
	}

	static bool Is_Last_Month_In_Year(int month) {
		return month == 12;
	}



	static int Difference_Between_Dates_In_Day(clsDate dt1, clsDate dt2, bool inclusive_end = false) {
		int cnt = 0;
		if (Is_Date1_Before_Date2(dt1, dt2)) {
			while (Is_Date1_Before_Date2(dt1, dt2)) {
				cnt++;
				dt1 = Date_After_N_Days(dt1, 1);
			}
			return (inclusive_end ? ++cnt : cnt);
		}
		else {
			swap(dt1, dt2);
			while (Is_Date1_Before_Date2(dt1, dt2)) {
				cnt++;
				dt1 = Date_After_N_Days(dt1, 1);
			}
			return (inclusive_end ? (++cnt) * -1 : cnt * -1); 
		}

		return (inclusive_end ? ++cnt : cnt);
	}





	static int Your_Age_In_Days(clsDate dt1, clsDate dt2) {
		return Difference_Between_Dates_In_Day(dt1, dt2, true);
	}

	int Your_Age_In_Days(clsDate dt) {
		return Difference_Between_Dates_In_Day(*this, dt, true);
	}

	
	static clsDate Increase_Date_By_One_Day(clsDate dt) {
		if (Is_Last_Day_In_Month(dt)) {
			if (Is_Last_Month_In_Year(dt.Month)) {
				dt.Year++;
				dt.Month = 1;
				dt.Day = 1;
			}
			else {
				dt.Month++;
				dt.Day = 1;
			}
		}
		else {
			dt.Day++;
		}

		return dt;

	}

	clsDate Increase_Date_By_One_Day() {
		return Increase_Date_By_One_Day(*this);
	}

	static clsDate Increase_Date_By_X_Days(clsDate dt, int x) {
		for (int i = 0; i < x; i++) {
			dt = Increase_Date_By_One_Day(dt);
		}
		return dt;
	}

	clsDate Increase_Date_By_X_Days(int x) {
		return Increase_Date_By_X_Days(*this, x);
	}

	static clsDate Increase_Date_By_One_Week(clsDate dt) {
		return Increase_Date_By_X_Days(dt, 7);
	}
	clsDate Increase_Date_By_One_Week() {
		return Increase_Date_By_One_Week(*this);
	}

	static clsDate Increase_Date_By_X_Weeks(clsDate dt, int x) {
		for (int i = 0; i < x; i++) {
			dt = Increase_Date_By_One_Week(dt);
		}
		return dt;
	}

	clsDate Increase_Date_By_X_Weeks(int x) {
		return Increase_Date_By_X_Weeks(*this, x);
	}

	static clsDate Increase_Date_By_One_Month(clsDate dt) {
		if (Is_Last_Month_In_Year(dt.Month)) {
			dt.Month = 1;
			dt.Year++;
		}
		else {
			dt.Month++;
		}

		int month_days = Num_Of_Days_In_Month(dt.Month, dt.Year);

		if (dt.Day > month_days) {
			dt.Day = month_days;
		}

		return dt;

	}

	clsDate Increase_Date_By_One_Month() {
		return Increase_Date_By_One_Month(*this);
	}

	static clsDate Increase_Date_By_X_Months(clsDate dt, int x) {
		for (int i = 0; i < x; i++) {
			dt = Increase_Date_By_One_Month(dt);
		}
		return dt;
	}

	clsDate Increase_Date_By_X_Months(int x) {
		return Increase_Date_By_X_Months(*this, x);
	}

	static clsDate Increase_Date_By_One_Year(clsDate dt) {
		dt.Year++;
		return dt;
	}

	clsDate Increase_Date_By_One_Year() {
		return Increase_Date_By_One_Year(*this);
	}

	static clsDate Increase_Date_By_X_Years(clsDate dt, int x) {
		dt.Year += x;
		return dt;
	}

	clsDate Increase_Date_By_X_Years(int x) {
		return Increase_Date_By_X_Years(*this, x);
	}


	static clsDate Decrease_Date_By_One_Day(clsDate dt) {
		if (dt.Day == 1) {
			if (dt.Month == 1) {
				dt.Year--;
				dt.Month = 12;
				dt.Day = Num_Of_Days_In_Month(dt.Month, dt.Year);
			}
			else {
				dt.Month--;
				dt.Day = Num_Of_Days_In_Month(dt.Month, dt.Year);
			}
		}
		else {
			dt.Day--;
		}
		return dt;
	}

	clsDate Decrease_Date_By_One_Day() {
		return Decrease_Date_By_One_Day(*this);
	}

	static clsDate Decrease_Date_By_X_Days(clsDate dt, int x) {
		while (x--) {
			dt = Decrease_Date_By_One_Day(dt);
		}
		return dt;
	}

	clsDate Decrease_Date_By_X_Days(int x) {
		return Decrease_Date_By_X_Days(*this, x);
	}

	static clsDate Decrease_Date_By_One_Week(clsDate dt) {
		return Decrease_Date_By_X_Days(dt, 7);
	}
	clsDate Decrease_Date_By_One_Week() {
		return Decrease_Date_By_One_Week(*this);
	}

	static clsDate Decrease_Date_By_X_Weeks(clsDate dt, int x) {
		for (int i = 0; i < x; i++) {
			dt = Decrease_Date_By_One_Week(dt);
		}
		return dt;
	}

	clsDate Decrease_Date_By_X_Weeks(int x) {
		return Decrease_Date_By_X_Weeks(*this, x);
	}


	static clsDate Decrease_Date_By_One_Month(clsDate dt) {
		if (dt.Month == 1) {
			dt.Year--;
			dt.Month = 12;
		}
		if (dt.Day > Num_Of_Days_In_Month(dt.Month, dt.Year)) {
			dt.Day = Num_Of_Days_In_Month(dt.Month, dt.Year);
		}
		return dt;

	}

	clsDate Decrease_Date_By_One_Month() {
		return Decrease_Date_By_One_Month(*this);
	}


	static clsDate Decrease_Date_By_X_Months(clsDate dt, int x) {
		while (x--) {
			dt = Decrease_Date_By_One_Month(dt);
		}
		return dt;
	}

	clsDate Decrease_Date_By_X_Months(int x) {
		return Decrease_Date_By_X_Months(*this, x);
	}

	static clsDate Decrease_Date_By_One_Year(clsDate dt) {
		dt.Year--;
		return dt;
	}
	clsDate Decrease_Date_By_One_Year() {
		return Decrease_Date_By_One_Year(*this);
	}

	static clsDate Decrease_Date_By_X_Years(clsDate dt, int x) {
		dt.Year -= x;
		return dt;
	}

	static int Day_Of_Week_Index(clsDate dt) {
		int a = (14 - dt.Month) / 12;
		int y = dt.Year - a;
		int m = dt.Month + 12 * a - 2;

		int res = dt.Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12;
		return ((res % 7) + 7) % 7;
	}

	static string Day_Of_Week_Order(clsDate dt) {
		int order = Day_Of_Week_Index(dt);
		static const char* days_of_week[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return days_of_week[order];
	}


	static bool Is_End_Of_Week(clsDate dt) {
		return (Day_Of_Week_Order(dt) == "Sat");
	}

	bool Is_End_Of_Week() {
		return Is_End_Of_Week(*this);
	}


	static bool Is_Week_End(clsDate dt) {
		string cur_day = Day_Of_Week_Order(dt);
		return (cur_day == "Sat" || cur_day == "Fri");
	}

	bool Is_Week_End() {
		return Is_Week_End(*this);
	}
	
	static bool Is_Business_Day(clsDate dt) {
		string cur_day = Day_Of_Week_Order(dt);
		return !(cur_day == "Sat" || cur_day == "Fri");
	}

	bool Is_Business_Day() {
		return Is_Business_Day(*this);
	}


	static int Until_End_Of_Week(clsDate dt) {
		return 6 - Day_Of_Week_Index(dt);
	}

	int Until_End_Of_Week() {
		return Until_End_Of_Week(*this);
	}

	static int Until_End_Of_Month(clsDate dt) {
		return Num_Of_Days_In_Month(dt.Month, dt.Year) - dt.Day;
	}
	
	int Until_End_Of_Month() {
		return Until_End_Of_Month(*this);
	}

	static int Until_End_Of_Year(clsDate dt) {
		clsDate dt2;
		dt2.Day = 31;
		dt2.Month = 12;
		dt2.Year = dt.Year;
		return Difference_Between_Dates_In_Day(dt, dt2, true);
	}

	int Until_End_Of_Year() {
		return Until_End_Of_Year(*this);
	}

	static int Vacation_Days(clsDate start_date, clsDate end_date) {
		int cnt = 0;
		while (Is_Date1_Before_Date2(start_date, end_date)) {
			if (Is_Business_Day(start_date)) {
				cnt++;
			}
			start_date = Increase_Date_By_One_Day(start_date);
		}
		
		return cnt;

	}

	int Vacation_Days(clsDate dt_end) {
		return Vacation_Days(*this, dt_end);
	}


	static clsDate Vacation_End_Date(clsDate dt, int days) {
		int cnt = 0;
		while (true) {
			if (Is_Business_Day(dt)) {
				cnt++;
				if (cnt == days) {
					break;
				}
			}
			dt = Increase_Date_By_One_Day(dt);
			
		}
		return dt;
	}

	static bool Is_Date1_After_Date2(clsDate dt1, clsDate dt2) {
		if (!Is_Date1_Before_Date2(dt1, dt2) && !Is_Date1_Equal_Date2(dt1, dt2)) {
			return true;
		}
		return false;
	}

	bool Is_Date1_After_Date2(clsDate dt) {
		return Is_Date1_After_Date2(*this, dt);
	}


	static int Get_Period_Length(clsDate dt1, clsDate dt2, bool inclusive_end = false) {
		return Difference_Between_Dates_In_Day(dt1, dt2, inclusive_end);
	}
	int Get_Period_Length(clsDate dt, bool inclusive_end = false) {
		return Get_Period_Length(*this, dt, inclusive_end);
	}

	static	bool Is_Valid_Date(clsDate dt)
	{

		if (dt.Day < 1 || dt.Day>31)
			return false;

		if (dt.Month < 1 || dt.Month>12)
			return false;

		if (dt.Month == 2)
		{
			if (Is_Leap_Year(dt.Year))
			{
				if (dt.Day > 29)
					return false;
			}
			else
			{
				if (dt.Day > 28)
					return false;
			}
		}

		short DaysInMonth = Num_Of_Days_In_Month(dt.Month, dt.Year);

		if (dt.Day > DaysInMonth)
			return false;

		return true;

	}

	bool Is_Valid() {
		return Is_Valid_Date(*this);
	}



	static string Get_System_Date_Time_String() {
		
		time_t t = time(0);
		tm* now = localtime(&t);
		int day, month, year, hour, min, sec;
		day = now->tm_mday;
		month = now->tm_mon + 1;
		year = now->tm_year + 1900;
		hour = now->tm_hour;
		min = now->tm_min;
		sec = now->tm_sec;

		string date = "";
		date += (to_string(day) + '/' + to_string(month) + '/' + to_string(year) + " - " + to_string(hour) + ':' + to_string(min) + ':' + to_string(sec));
		
		return date;

	}


	

	

    
};

