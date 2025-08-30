#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogsScreen.h"



using namespace std;

class clsTransactionScreen : protected clsScreen
{

private :

	enum en_Transaction {
		eDeposit = 1, eWithdraw = 2, eTotal_Balance = 3, eMain_Menu = 6, eTranfer = 4, eTransferLogs = 5
	};


	static int _Read_Transaction_Option() {
		cout << endl;
		cout << setw(47) << left << "" << "\tEnter What You Want to Do : ";
		return clsInputValidate::Read_Num_In_Range(1, 6);
	}

	static void _Back_To_Transaction_Menu() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menu...\n";

		system("pause>0");
		system("cls");
		Show_Transaction_Menu();
	}



	static void _Perform_Transaction_Option(en_Transaction option) {

		switch (option)
		{
		case en_Transaction::eDeposit:
			system("cls");
			_Deposit();
			_Back_To_Transaction_Menu();
			break;
		case en_Transaction::eWithdraw:
			system("cls");
			_Withdraw();
			_Back_To_Transaction_Menu();
			break;
		case en_Transaction::eTotal_Balance:
			system("cls");
			_Total_Balance();
			_Back_To_Transaction_Menu();
			break;
		case en_Transaction::eMain_Menu:
			system("cls");
			_Main_Menu();
			break;
		case en_Transaction::eTranfer:
			system("cls");
			_Transfer();
			_Back_To_Transaction_Menu();
			break;
		case en_Transaction::eTransferLogs:
			system("cls");
			_Transfer_Logs();
			_Back_To_Transaction_Menu();
		default:
			break;
		}

	}



	static void _Deposit() {
		clsDepositScreen::Deposit();
	}

	static void _Withdraw() {
		clsWithdrawScreen::Withdraw();
	}

	static void _Total_Balance() {
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _Main_Menu() {
		// nothing to do
	}

	static void _Transfer() {
		// code will be here
		clsTransferScreen::Transfer();
	}

	static void _Transfer_Logs() {
		// code will be here
		clsTransferLogsScreen::ShowTransferLogScreen();
	}






public :


	static void Show_Transaction_Menu() {

		if (!clsScreen::Check_Access_Rights(clsUser::en_Permetions::eTransactions)) {
			return;
		}

		Draw_Header("  Transaction Menu");

		cout << "\t\t\t" << "=======================================================================" << endl;
		cout << "\t\t\t\t\t\tTransaction Menu" << endl;
		cout << "\t\t\t" << "=======================================================================" << endl;

		cout << setw(47) << left << "" << "\t[1] DEPOSIT" << endl;
		cout << setw(47) << left << "" << "\t[2] WITHDRAW" << endl;
		cout << setw(47) << left << "" << "\t[3] TOTAL BALANCE" << endl;
		cout << setw(47) << left << "" << "\t[4] TRANSFER" << endl;
		cout << setw(47) << left << "" << "\t[5] SHOW TRANSFER LOGS" << endl;
		cout << setw(47) << left << "" << "\t[6] MAIN MENU" << endl;
		
		cout << "\t\t\t" << "=======================================================================" << endl;

		_Perform_Transaction_Option((en_Transaction)_Read_Transaction_Option());

	}


};

