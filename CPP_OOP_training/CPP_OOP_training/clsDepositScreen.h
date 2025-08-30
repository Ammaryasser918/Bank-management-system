#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsDepositScreen : protected clsScreen
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


	static void Deposit() {

		Draw_Header("     Deposit");

		cout << "Enter the Account Number : ";
		string AccNum = Read_Account_Number();

		while (!clsBankClient::Is_Exist(AccNum)) {
			cout << "This Account Doesn't Exist ! " << endl;
			cout << "Enter Another Account Number : "; AccNum = Read_Account_Number();
		}
		cout << endl;
		clsBankClient cli = clsBankClient::Find(AccNum);
		_Print_Client(cli);
		cout << endl;

		cout << "Enter the amount of deposit, please : ";
		float amount = clsInputValidate::Read_flt_Num();

		cout << endl << endl;
		cout << "Are you sure you want to perform this operation ? (Y/N) ";
		char ans; cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			cli.Deposit(amount);
			cout << endl;
			cout << "Deposit done successfully :-)" << endl;
			cout << "The New balance is : " << cli.Balance << endl;
		}
		else {
			cout << "Operation Canceled !" << endl;
		}


	}



};

