#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsWithdrawScreen : protected clsScreen
{

private :

	static void _Print_Client(clsBankClient cli) {
		cout << "Client Card : " << endl;
		cout << "-----------------------------------------" << endl;
		cout << "First Name     : " << cli.Get_First_Name() << endl;
		cout << "Last Name      : " << cli.Get_Last_Name() << endl;
		cout << "Full Name      : " << cli.Full_Name() << endl;
		cout << "Email          : " << cli.Get_Email() << endl;
		cout << "Phone          : " << cli.Get_Phone() << endl;
		cout << "Account Number : " << cli.Get_Account_Number() << endl;
		cout << "Password       : " << cli.Get_PIN_Code() << endl;
		cout << "Balance        : " << cli.Get_Balance() << endl;
		cout << "-----------------------------------------" << endl;
	}


	static string Read_Account_Number() {
		return clsInputValidate::Read_String();
	}

public :

	static void Withdraw() {
		Draw_Header("    Withdraw");

		cout << "Enter Account Number : ";
		string AccNum = Read_Account_Number();

		while (!clsBankClient::Is_Exist(AccNum)) {
			cout << "This Account Doesn't Exist ! " << endl;
			cout << "Enter Another Account Number : "; AccNum = Read_Account_Number();
		}

		cout << endl;
		clsBankClient cli = clsBankClient::Find(AccNum);
		_Print_Client(cli);
		cout << endl;

		cout << "Enter the amount of withdraw, please : ";
		float amount = clsInputValidate::Read_flt_Num();

		cout << endl;
		char ans;
		cout << "Are you sure you want to do this operation ? (Y/N) ";
		cin >> ans;

		if (ans == 'Y' || ans == 'y'){
			if (cli.Balance < amount) {
				cout << "Operation failed, Your balance isn't enough :-(" << endl;
				cout << "Your balance is " << cli.Balance << endl;
			}
			else {
				cli.Withdraw(amount);
				cout << "Amount withdrew successfully :-)" << endl;
				cout << "Your balance is " << cli.Balance << endl;
			}
		}
		else
		{
			cout << "Operation canceled !" << endl;
		}
		

	}


};

