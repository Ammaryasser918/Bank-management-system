#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
{

private:

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

	static void Read_User_Info(clsUser& user) {

		cout << "Enter The First Name : ";
		user.First_Name = clsInputValidate::Read_String();
		cout << "Enter The Last Name : ";
		user.Last_Name = clsInputValidate::Read_String();
		cout << "Enter The Email : ";
		user.Email = clsInputValidate::Read_String();
		cout << "Enter The Phone Number : ";
		user.Phone = clsInputValidate::Read_String();
		cout << "Enter The Password : ";
		user.PassWord = clsInputValidate::Read_String();
		cout << "Enter The permissions : " << endl;
		user.Permission = Read_User_Permissions();


	}

	static int Read_User_Permissions() {
		cout << "Do You Want To Give User All Access ? (Y/N) ";
		char ans; cin >> ans;
		if (ans == 'Y' || ans == 'y') return -1;

		int perm = 0;
		cout << "Do You Want To Give User Access On List Users ? (Y/N) "; cin >> ans;
		if (ans == 'Y' || ans == 'y') perm |= clsUser::en_Permetions::eListUsers;

		cout << "Do You Want To Give User Access On Add Users ? (Y/N) "; cin >> ans;
		if (ans == 'Y' || ans == 'y') perm |= clsUser::en_Permetions::eAddUsers;

		cout << "Do You Want To Give User Access On Delete Users ? (Y/N) "; cin >> ans;
		if (ans == 'Y' || ans == 'y') perm |= clsUser::en_Permetions::eDeleteUser;

		cout << "Do You Want To Give User Access On Update Users ? (Y/N) "; cin >> ans;
		if (ans == 'Y' || ans == 'y') perm |= clsUser::en_Permetions::eUpdateUser;

		cout << "Do You Want To Give User Access On find Users ? (Y/N) "; cin >> ans;
		if (ans == 'Y' || ans == 'y') perm |= clsUser::en_Permetions::eFindUser;

		cout << "Do You Want To Give User Access On Transactions ? (Y/N) "; cin >> ans;
		if (ans == 'Y' || ans == 'y') perm |= clsUser::en_Permetions::eTransactions;

		cout << "Do You Want To Give User Access On Manage Users ? (Y/N) "; cin >> ans;
		if (ans == 'Y' || ans == 'y') perm |= clsUser::en_Permetions::eManageUsers;
		
		cout << "Do You Want To Give User Access On Login Register History ? (Y/N) "; cin >> ans;
		if (ans == 'Y' || ans == 'y') perm |= clsUser::en_Permetions::eLoginRegister;


		return perm;


	}

	
public:


	static void Update_User() {

		Draw_Header("    Update User");

		cout << "Enter The User Name : ";
		string UserName; UserName = clsInputValidate::Read_String();

		while (!clsUser::Is_Exist(UserName)) {
			cout << "Users Doesn't Exist, try Another User Name" << endl;
			cout << "Enter the User Name : "; UserName = clsInputValidate::Read_String();
		}

		cout << endl;
		clsUser user = clsUser::Find(UserName);
		_Print_User(user);
		cout << endl;


		cout << "Are You Sure You Want To Update The User ? (Y/N) ";
		char ans; cin >> ans;

		if (ans == 'Y' || ans == 'y') {
			cout << "-----------------------------------" << endl;
			Read_User_Info(user);
			cout << "-----------------------------------" << endl << endl;


			clsUser::enSave_result save_result;
			save_result = user.Save();

			if (save_result == clsUser::enSave_result::Saved_Successfully) {
				cout << "User Updated Successfully :-)" << endl << endl;
				_Print_User(user);
				cout << endl;
			}
			else {
				cout << "OperationFailed ! , User Not Found" << endl;
			}

			
		}
		else
		{
			cout << "Operation canceled !" << endl;
		}


	}



};

