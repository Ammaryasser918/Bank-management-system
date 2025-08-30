#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUserMenu.h"
#include "Global.h"
#include "clsRegisterLoginScreen.h"
#include "clsCurrencyExchange.h"
#include "clsCurrencyExchangeScreen.h"


using namespace std;

class clsMainMenu : protected clsScreen
{

private:

	enum en_Menu {
		eShowList = 1, eAdd = 2, eDelete = 3, eUpdate = 4, eFind = 5, eTransaction = 6, eManageUser = 7, eLogout = 10, eRegisterHistory = 8, eCurrencyExchange = 9
	};


	static int _Read_Main_Menu_Option() {
		cout << endl;
		cout << setw(47) << left << "" << "\tEnter What You Want to Do : ";
		return clsInputValidate::Read_Num_In_Range(1, 10);
	}

	static void _Logout() {
		Current_User = clsUser::Find("", "");
	}

	static void _Perform_Main_Menu_Option(en_Menu option) {
		switch (option)
		{
		case en_Menu::eShowList:
			system("cls");
			_Show_client_List();
			_Back_To_Main_Menu();
			break;
		case en_Menu::eAdd:
			system("cls");
			_Add_New_Client();
			_Back_To_Main_Menu();
			break;
		case en_Menu::eDelete:
			system("cls");
			_Delete_Client();
			_Back_To_Main_Menu();
			break;
		case en_Menu::eUpdate:
			system("cls");
			_Update_Client();
			_Back_To_Main_Menu();
			break;
		case en_Menu::eFind:
			system("cls");
			_Find_Client();
			_Back_To_Main_Menu();
			break;
		case en_Menu::eTransaction:
			system("cls");
			_Transactions();
			_Back_To_Main_Menu();
			break;
		case en_Menu::eManageUser:
			system("cls");
			_Manage_User();
			_Back_To_Main_Menu();
			break;
		case en_Menu::eLogout:
			system("cls");
			_Log_Out();
			break;
		case en_Menu::eRegisterHistory:
			system("cls");
			_Register_History();
			_Back_To_Main_Menu();
		case en_Menu::eCurrencyExchange:
			system("cls");
			_Currency_Exchange();
			_Back_To_Main_Menu();
		default:
			break;
		}

	}

	static void _Back_To_Main_Menu() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

		system("pause>0");
		system("cls");
		Show_Main_Menu();
	}

	static void _Show_client_List() {
		clsClientListScreen::Show_Clients_List();
	}

	static void _Add_New_Client() {
		// code will be here
		clsAddNewClientScreen::Add_New_Client();
	}

	static void _Delete_Client() {
		// code will be here
		clsDeleteClientScreen::Delete_Client();
	}

	static void _Update_Client() {
		// code will be here
		clsUpdateClientScreen::Update_Client();
	}

	static void _Find_Client() {
		// code will be here
		clsFindClientScreen::Find_Client();
	}

	static void _Transactions() {
		// code will be here
		clsTransactionScreen::Show_Transaction_Menu();
	}

	static void _Manage_User() {
		// code will be here
		clsManageUserMenu::Show_Manage_Menu();
	}

	static void _Log_Out() {
		// code will be here
		_Logout();
	}

	static void _Register_History() {
		//code will be here
		clsRegisterLoginScreen::ShowLoginRegisterScreen();
	}

	static void _Currency_Exchange() {
		// code will be here
		clsCurrencyExchangeScreen::Show_Currency_Exchange_Screen();
	}
	

public:

	static void Show_Main_Menu() {

		Draw_Header("    Main Menu");


		cout << "\t\t\t" << "=======================================================================" << endl;
		cout << "\t\t\t\t\t\tMain Menu" << endl;
		cout << "\t\t\t" << "=======================================================================" << endl;
		cout << setw(47) << left << "" << "\t[1] SHOW CLIENTS LIST" << endl;
		cout << setw(47) << left << "" << "\t[2] ADD NEW CLIENT" << endl;
		cout << setw(47) << left << "" << "\t[3] DELETE CLIENT" << endl;
		cout << setw(47) << left << "" << "\t[4] UPDATE CLIENT" << endl;
		cout << setw(47) << left << "" << "\t[5] FIND CLIENT" << endl;
		cout << setw(47) << left << "" << "\t[6] TRANSACTIONS" << endl;
		cout << setw(47) << left << "" << "\t[7] Manage Users" << endl;
		cout << setw(47) << left << "" << "\t[8] SHOW LOGIN REGISTER HISTORY" << endl;
		cout << setw(47) << left << "" << "\t[9] CURRENCY EXCHANGE" << endl;
		cout << setw(47) << left << "" << "\t[10] LOGOUT" << endl;
		cout << "\t\t\t" << "=======================================================================" << endl;

		_Perform_Main_Menu_Option((en_Menu)_Read_Main_Menu_Option()); // casting int to enum


	}


};

