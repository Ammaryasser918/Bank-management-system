#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsCurrencyExchange.h"

using namespace std;


class clsUpdateCurrencyScreen : protected clsScreen
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

	static void Update_Currency() {

		Draw_Header("    Update Currency");

		cout << "Enter The Currency : ";
		string currency = clsInputValidate::Read_String();

		while (!clsCurrencyExchange::Is_Exist(currency)) {
			cout << "Currency Not Found! , Please Enter Another One : " << endl;
			cout << "Enter the Currency : ";
			currency = clsInputValidate::Read_String();
		}

		clsCurrencyExchange cur = clsCurrencyExchange::Find_By_Currency_Code(currency);

		_Print_Currency(cur);
		cout << endl << endl;

		cout << "Are You Sure You Want To Change The Currency? (Y/N)";
		char ans; cin >> ans;

		if (ans == 'y' || ans == 'Y') {
			float rate;
			cout << "Enter The New Rate : "; 
			rate = clsInputValidate::Read_flt_Num();
			cur.Set_Rate(rate);

			cout << "Currency Updated Successfully :-)" << endl << endl;
			_Print_Currency(cur);

		}
		else {
			cout << "Operation canceled!" << endl;
		}




	}



};

