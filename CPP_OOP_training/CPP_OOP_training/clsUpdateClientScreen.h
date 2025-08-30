#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
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

	static void Update_Client() {

		if (!clsScreen::Check_Access_Rights(clsUser::en_Permetions::eUpdateUser)) {
			return;
		}

		Draw_Header("   Update Client");

		cout << "Enter the account number : ";
		string AccNum;
		AccNum = clsInputValidate::Read_String();

		while (!clsBankClient::Is_Exist(AccNum)) {
			cout << "Wrong account number, please try again!" << endl;
			cout << "Enter the account number : ";
			AccNum = clsInputValidate::Read_String();
		}

		clsBankClient client = clsBankClient::Find(AccNum);
		_Print_Client(client);
		cout << endl << endl;

		cout << "Update client info : " << endl;
		cout << "-----------------------------------" << endl;
		Read_client_Info(client);
		cout << "-----------------------------------" << endl;

		clsBankClient::enSave_result save_result;

		save_result = client.Save();

		if (save_result == clsBankClient::enSave_result::Saved_Successfully) {
			cout << "Account Updated Successfully :-)" << endl << endl;
			_Print_Client(client);
		}
		else if (save_result == clsBankClient::enSave_result::Saving_Failed) {
			cout << "Error ! , Account is't saved because it's empty" << endl;
		}




	}



};

