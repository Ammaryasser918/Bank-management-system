#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

// Remove this invalid line from the class scope:
// AccNum = clsInputValidate::Read_String();

// If you want to initialize AccNum, do it inside a method or constructor.
// For example, add a method to read and set AccNum:

class clsFindClientScreen : protected clsScreen
{
private:
    
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

public:

    static void Find_Client() {

		if (!clsScreen::Check_Access_Rights(clsUser::en_Permetions::eFindUser)) {
			return;
		}


        Draw_Header("   Find Client");
        
        string AccNum;
		cout << "Enter the Account Number : ";
        AccNum = clsInputValidate::Read_String();

        clsBankClient cli = clsBankClient::Find(AccNum);
		cout << endl;

		if (!cli.Is_Empty()) {
			cout << "Client Found :-)" << endl << endl;
			_Print_Client(cli);
			cout << endl;
		}
		else {
			cout << "Client Wasn't Found :-(" << endl << endl;
		}

		
        

    }

    
};

