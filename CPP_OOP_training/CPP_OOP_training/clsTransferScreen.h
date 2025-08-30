#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{

private :

	static void _Print_client(clsBankClient& cli) {
		cout << "Client Card : " << endl;
		cout << "_________________________________________" << endl;
		cout << "Client Name    : " << cli.Full_Name() << endl;
		cout << "Account Number : " << cli.Get_Account_Number() << endl;
		cout << "Balance        : " << cli.Balance << endl;
		cout << "_________________________________________" << endl << endl;
	}

	

public :

	static void Transfer() {

		Draw_Header("\tTransfer");

		cout << "Enter Account Number To Transfer From : ";
		string AccNum1; AccNum1 = clsInputValidate::Read_String();

		while (!clsBankClient::Is_Exist(AccNum1)) {
			cout << "Account Not Exist, Please Try Another One" << endl;
			cout << "Enter Account Number To Transfer From : "; AccNum1 = clsInputValidate::Read_String();
		}
		clsBankClient cli1 = clsBankClient::Find(AccNum1);
		_Print_client(cli1);
		cout << endl << endl;
		

		cout << "Enter Account Number To Transfer To : ";
		string AccNum2; AccNum2 = clsInputValidate::Read_String();

		while (!clsBankClient::Is_Exist(AccNum2)) {
			cout << "Account Not Exist, Please Try Another One" << endl;
			cout << "Enter Account Number To Transfer To : "; AccNum2 = clsInputValidate::Read_String();
		}

		clsBankClient cli2 = clsBankClient::Find(AccNum2);
		_Print_client(cli2);
		cout << endl << endl;


		cout << "Enter The Amount : ";
		float amount; amount = clsInputValidate::Read_flt_Num();

		cout << "Are You Sure You Want To Do This Operation ? (Y/N) ";
		char ans; cin >> ans;
		if (ans == 'Y' || ans == 'y') {

			if (cli1.Balance < amount) {
				cout << "Operation Failes! , Your Balance Not Enough" << endl;
				cout << "Your Balance is : " << cli1.Balance << endl;
			}
			else {
				cli1.Transfer(cli2, amount);
				cli1.Save_Transfer_To_Transfer_Logs_File(cli2, amount);
				cout << endl;
				cout << "Transfered Successfully :-)" << endl << endl;
				_Print_client(cli1);
				cout << endl << endl;
				_Print_client(cli2);
				cout << endl;
			}

		}
		else {
			cout << "Operation Canceled!" << endl;
			return;
		}
		


	}


};

