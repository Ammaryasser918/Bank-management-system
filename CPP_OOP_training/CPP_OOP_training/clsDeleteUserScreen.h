#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsDeleteUserScreen : protected clsScreen
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

	static void Delete_User() {

		Draw_Header("    Delete User");

		cout << "Enter The User Name : ";
		string UserName = clsInputValidate::Read_String();

		while (!clsUser::Is_Exist(UserName)) {
			cout << "Account Not Exist :-(" << endl;
			cout << "Enter Another User Name : "; UserName = clsInputValidate::Read_String();
		}

		cout << endl;
		clsUser user = clsUser::Find(UserName);
		_Print_User(user);
		cout << endl;

		cout << "Are You Sure You Want To Delete The User ? (Y/N) ";
		char ans; cin >> ans;

		if (ans == 'Y' || ans == 'y') {

			

			user = clsUser::Delete_User(UserName);

			clsUser::enSave_result save_res;
			save_res = user.Save();

			if (save_res == clsUser::enSave_result::Deleted_Successfully) {
				cout << "User Deleted Successfully :-)" << endl;
			}
			else {
				cout << "Operation Failed User Doesn't Exist" << endl;
			}

		}



	}





};

