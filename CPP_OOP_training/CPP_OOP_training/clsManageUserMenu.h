#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;
class clsManageUserMenu : protected clsScreen
{
private :


	enum en_Manage {
		eList_Users = 1, eAdd_User = 2, eDelete_User = 3, eUpdate_User = 4, eFind_User = 5, eMain_Menu = 6
	};

	static int _Read_Manage_Menu_Options() {
		cout << endl;
		cout << setw(47) << left << "" << "\tEnter What You Want to Do : ";
		return clsInputValidate::Read_Num_In_Range(1, 6);
	}

	static void _Back_To_Manage_Menu() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Menu...\n";

		system("pause>0");
		system("cls");
		Show_Manage_Menu();
	}

	static void _Perform_Manage_Menu_Options(en_Manage option) {

		switch (option)
		{
		case clsManageUserMenu::eList_Users:
			system("cls");
			_List_Users();
			_Back_To_Manage_Menu();
			break;
		case clsManageUserMenu::eAdd_User:
			system("cls");
			_Add_User();
			_Back_To_Manage_Menu();
			break;
		case clsManageUserMenu::eDelete_User:
			system("cls");
			_Delete_User();
			_Back_To_Manage_Menu();
			break;
		case clsManageUserMenu::eUpdate_User:
			system("cls");
			_Update_User();
			_Back_To_Manage_Menu();
			break;
		case clsManageUserMenu::eFind_User:
			system("cls");
			_Find_User();
			_Back_To_Manage_Menu();
			break;
		case clsManageUserMenu::eMain_Menu:
			system("cls");
			_Main_Menu();
			break;
		default:
			break;
		}

	}

	static void _List_Users() {
		clsUserListScreen::ShowUsersList();
	}

	static void _Add_User() {
		clsAddNewUserScreen::Add_New_User();
	}

	static void _Delete_User() {
		clsDeleteUserScreen::Delete_User();
	}

	static void _Update_User() {
		clsUpdateUserScreen::Update_User();
	}

	static void _Find_User() {
		clsFindUserScreen::Find_User();
	}

	static void _Main_Menu() {
		// nothing to do
	}









public :

	static void Show_Manage_Menu() {

		if (!clsScreen::Check_Access_Rights(clsUser::en_Permetions::eManageUsers)) {
			return;
		}

		Draw_Header("   Manage Users Menu");

		cout << "\t\t\t" << "=======================================================================" << endl;
		cout << "\t\t\t\t\t\t  Manage Menu" << endl;
		cout << "\t\t\t" << "=======================================================================" << endl;
		cout << setw(47) << left << "" << "\t[1] SHOW Users LIST" << endl;
		cout << setw(47) << left << "" << "\t[2] ADD NEW USERS" << endl;
		cout << setw(47) << left << "" << "\t[3] DELETE USERS" << endl;
		cout << setw(47) << left << "" << "\t[4] UPDATE USERS" << endl;
		cout << setw(47) << left << "" << "\t[5] FIND USERS" << endl;
		cout << setw(47) << left << "" << "\t[6] MAIN MENU" << endl;
		cout << "\t\t\t" << "=======================================================================" << endl << endl;

		_Perform_Manage_Menu_Options((en_Manage)_Read_Manage_Menu_Options());

	}

};

