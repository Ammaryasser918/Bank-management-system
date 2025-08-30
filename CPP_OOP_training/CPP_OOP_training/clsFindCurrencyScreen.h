#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrencyExchange.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{

private :

	static void _Print_Currency(clsCurrencyExchange currency) {
		cout << "Currency Card : " << endl;
		cout << "-----------------------------------------" << endl;
		cout << "Country     : " << currency.Get_Country() << endl;
		cout << "Code        : " << currency.Get_Currency_Code() << endl;
		cout << "Name        : " << currency.Get_Currency_Name() << endl;
		cout << "Rate        : " << currency.Get_Rate() << endl;
		cout << "-----------------------------------------" << endl;
	}


public :

	static void Find_Currency() {

		Draw_Header("    Find Currency");

		cout << "Find By [1] Code or [2] Country : ";
		int choice = clsInputValidate::Read_Num_In_Range(1, 2);

		if (choice == 1) {
			cout << endl << endl;
			cout << "Please Enter The Currency Code : ";
			string code = clsInputValidate::Read_String();
			clsCurrencyExchange currency = clsCurrencyExchange::Find_By_Currency_Code(code);

			if (currency.Is_Empty()) {
				cout << "Currency Not Found :-(" << endl;
			}
			else {
				cout << "Currency Found :-)" << endl << endl;
				_Print_Currency(currency);
				cout << endl << endl;
			}

		}
		else {
			cout << endl << endl;
			cout << "Please Enter The Country : ";
			string country = clsInputValidate::Read_String();
			clsCurrencyExchange currency = clsCurrencyExchange::Find_By_Country(country);
			
			if (currency.Is_Empty()) {
				cout << "Currency Not Found :-(" << endl;
			}
			else {
				cout << "Currency Found :-)" << endl;
				_Print_Currency(currency);
				cout << endl << endl;
			}



		}

	}


};

