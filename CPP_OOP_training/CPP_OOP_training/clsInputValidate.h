#pragma once
#include <iostream>
using namespace std;

class clsInputValidate
{
public :
	static bool Num_In_Range(int num, int from, int to) {
		return (num >= from && num <= to);
	}
	static bool Num_In_Range(float num, float from, float to) {
		return (num >= from && num <= to);
	}
	static bool Num_In_Range(double num, double from, double to) {
		return (num >= from && num <= to);
	}

	//====================================================================

	static int Read_Int_Num() {

		int N;
		//cout << "Enter the number : " << endl;
		cin >> N;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Error ! , Please Enter a number" << endl << endl;
			cout << "Enter the number : "; cin >> N;
		}
		return N;

	}
	static double Read_dbl_Num() {

		double N;
		cout << "Enter the number : " << endl;
		cin >> N;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Error ! , Please Enter a number" << endl << endl;
			cout << "Enter the number : "; cin >> N;
		}
		return N;

	}
	static float Read_flt_Num() {

		float N;
		//cout << "Enter the number : " << endl;
		cin >> N;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Error ! , Please Enter a number" << endl << endl;
			cout << "Enter the number : "; cin >> N;
		}
		return N;

	}


	static string Read_String()
	{
		string  S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}



	//====================================================================


	static bool Is_Date_Between(clsDate dt, clsDate dt_start, clsDate dt_end) {
		if ((clsDate::Is_Date1_Before_Date2(dt, dt_end) || clsDate::Is_Date1_Equal_Date2(dt, dt_end)) && clsDate::Is_Date1_After_Date2(dt, dt_start) || clsDate::Is_Date1_Equal_Date2(dt, dt_end)) {
			return true;
		}
		
		if ((clsDate::Is_Date1_After_Date2(dt, dt_end) || clsDate::Is_Date1_Equal_Date2(dt, dt_end)) && clsDate::Is_Date1_Before_Date2(dt, dt_start) || clsDate::Is_Date1_Equal_Date2(dt, dt_end))
		{
			return true;
		}
		return false;

	}


	bool Is_Valid_Date(clsDate dt) {
		return clsDate::Is_Valid_Date(dt);
	}


	//====================================================================


	static int Read_Num_In_Range(int from, int to) {

		int N; cin >> N;
		while (N > to || N < from) {
			cout << "Invalid Number" << endl;
			cout << "Enter Another Number : "; cin >> N;
		}
		return N;

	}
	static double Read_Num_In_Range(double from, double to) {

		double N; cin >> N;
		while (N > to || N < from) {
			cout << "Invalid Number" << endl;
			cout << "Enter Another Number : "; cin >> N;
		}
		return N;

	}
	static float Read_Num_In_Range(float from, float to) {

		float N; cin >> N;
		while (N > to || N < from) {
			cout << "Invalid Number" << endl;
			cout << "Enter Another Number : "; cin >> N;
		}
		return N;

	}







};

