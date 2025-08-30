#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrencyExchange.h"


class clsCurrencyCalculatorScreen : protected clsScreen
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


	static float _Calculate_Rate(clsCurrencyExchange cur1, clsCurrencyExchange cur2, float amount) {
		return ((amount / cur1.Get_Rate()) * cur2.Get_Rate());
	}


public :

	static void Currency_Exchange() {

		while (true){
			Draw_Header("Currency Exchange Calculator");

			cout << "Enter The Currency To Exchange from : ";
			string cur_From;
			cur_From = clsInputValidate::Read_String();

			while (!clsCurrencyExchange::Is_Exist(cur_From)) {
				cout << "Currency Not Found!, Please Try Anothe One" << endl;
				cout << "Enter The Currency : ";
				cur_From = clsInputValidate::Read_String();
			}

			clsCurrencyExchange cur1 = clsCurrencyExchange::Find_By_Currency_Code(cur_From);
			_Print_Currency(cur1);


			cout << endl << endl;
			cout << "Enter The Currency To Exchange To : ";
			string cur_to = clsInputValidate::Read_String();

			while (!clsCurrencyExchange::Is_Exist(cur_to)) {
				cout << "Currency Not Found!, Please Try Another One" << endl;
				cout << "Enter The Currency : ";
				cur_to = clsInputValidate::Read_String();
			}

			clsCurrencyExchange cur2 = clsCurrencyExchange::Find_By_Currency_Code(cur_to);
			_Print_Currency(cur2);

			cout << endl << endl;
			cout << "Enter The Amount : ";
			float amount = clsInputValidate::Read_flt_Num();

			cout << amount << ' ' << cur_From << " = " << _Calculate_Rate(cur1, cur2, amount) << ' ' << cur_to << endl;

			cout << endl << endl;
			cout << "------------------------------------- " << endl;
			cout << "Do You Want To Make More Calculations ? (Y/N) " << endl;
			cout << "------------------------------------- " << endl;
			char ans; cin >> ans;
			if (ans == 'Y' || ans == 'y') {
				system("cls");

			}
			else {
				break;
			}
			

		}
	}


};

