#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;


class clsFindUserScreen : protected clsScreen
{

private :

	static void _Print_User(clsUser user) {
		cout << "Client Card : " << endl;
		cout << "-----------------------------------------" << endl;
		cout << "First Name     : " << user.Get_First_Name() << endl;
		cout << "Last Name      : " << user.Get_Last_Name() << endl;
		cout << "Full Name      : " << user.Full_Name() << endl;
		cout << "Email          : " << user.Get_Email() << endl;
		cout << "Phone          : " << user.Get_Phone() << endl;
		cout << "UserName       : " << user.User_Name << endl;
		cout << "Password       : " << user.PassWord << endl;
		cout << "Permission     : " << user.Permission << endl;
		cout << "-----------------------------------------" << endl;
	}

public :



	static void Find_User() {

		Draw_Header("\tFind User");


		cout << "Enter The User Name : ";
		string UserName; UserName = clsInputValidate::Read_String();

		while (!clsUser::Is_Exist(UserName)) {
			cout << "User Not Found! , Please Try Another one" << endl;
			cout << "Enter The User Name : "; UserName = clsInputValidate::Read_String();
		}


		clsUser user = clsUser::Find(UserName);
		

		if (!user.Is_Empty()) {
			cout << "User Found :-)" << endl << endl;
			_Print_User(user);
			cout << endl;
		}
		else {
			cout << "User Not Found :-(" << endl;
		}



	}


};

