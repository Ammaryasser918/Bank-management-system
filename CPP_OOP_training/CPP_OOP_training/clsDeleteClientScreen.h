#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;


class clsDeleteClientScreen : protected clsScreen
{

private :

	static void Read_client_Info(clsBankClient& client) {

		cout << "Enter The First Name : ";
		client.First_Name = clsInputValidate::Read_String();
		cout << "Enter The Last Name : ";
		client.Last_Name = clsInputValidate::Read_String();
		cout << "Enter The Email : ";
		client.Email = clsInputValidate::Read_String();
		cout << "Enter The Phone Number : ";
		client.Phone = clsInputValidate::Read_String();
		cout << "Enter The PIN Code : ";
		client.PIN_Code = clsInputValidate::Read_String();
		cout << "Enter The Balance : ";
		client.Balance = clsInputValidate::Read_flt_Num();


	}

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

public :

	static void Delete_Client() {


		if (!clsScreen::Check_Access_Rights(clsUser::en_Permetions::eDeleteUser)) {
			return;
		}


		Draw_Header("   Delete Client");

		string Acc_Num;

		cout << "Enter Account Number : ";
		Acc_Num = clsInputValidate::Read_String();

		while (!clsBankClient::Is_Exist(Acc_Num)) {
			cout << "Account Not Exist, Please Enter Another Account Number" << endl;
			cout << "Enter Account Number : ";
			Acc_Num = clsInputValidate::Read_String();
		}

		cout << endl;
		clsBankClient client = clsBankClient::Find(Acc_Num);
		_Print_Client(client);
		cout << endl;


		cout << "Are You Sure You Want To Delete The Accont ? (Y/N) ";
		char ans; cin >> ans;

		if (ans == 'y' || ans == 'Y') {

			

			client = clsBankClient::Delete_Account(Acc_Num);

			clsBankClient::enSave_result save_result;
			save_result = client.Save();

			if (save_result == clsBankClient::enSave_result::Deleted_Successfully) {
				cout << "Account Deleted Successfully :-)" << endl;
			}
			else {
				cout << "Error! , Account Not Exist" << endl;
			}


		}
		else {
			return;
		}


	}



};

