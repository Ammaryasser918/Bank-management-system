#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
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


	static void Add_New_Client() {


		if (!clsScreen::Check_Access_Rights(clsUser::en_Permetions::eAddUsers)) {
			return;
		}


		Draw_Header("  Add New Client");

		cout << "Enter The Account Number : ";
		string AccNum;
		AccNum = clsInputValidate::Read_String();

		while (clsBankClient::Is_Exist(AccNum)) {
			cout << "Account Already Exist, Please Enter Another Account Number" << endl;
			cout << "Enter The Account Number : ";
			AccNum = clsInputValidate::Read_String();
		}
		clsBankClient client = clsBankClient::Get_New_Account_Object(AccNum);
		cout << "\nAdd Client Info : " << endl;
		cout << "----------------------------------" << endl;
		Read_client_Info(client);
		cout << "----------------------------------" << endl << endl;

		clsBankClient::enSave_result save_result;

		save_result = client.Save();

		if (save_result == clsBankClient::enSave_result::Saving_Failed) {
			cout << "Error ! , Account is't saved because it's empty" << endl;
		}
		else if (save_result == clsBankClient::enSave_result::Added_Successfully) {
			
			cout << "Account Added Successfully :-)" << endl << endl;
			_Print_Client(client);
		}

	}



};

