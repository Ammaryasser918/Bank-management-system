#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{

private :

	enum enCur_change {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrency = 3, CurrencyCalculator = 4, MainMenu = 5
	};


	static int _Read_Currency_Exchange_Options() {
		cout << endl;
		cout << setw(47) << left << "" << "\tEnter What You Want to Do : ";
		return clsInputValidate::Read_Num_In_Range(1, 5);
	}

	static void _Back_To_Currency_Exchange_Screen() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Exchange Menu...\n";

		system("pause>0");
		system("cls");
		Show_Currency_Exchange_Screen();
	}

	static void _Perform_Currency_Exchange_Option(enCur_change option) {

		switch (option)
		{
		case clsCurrencyExchangeScreen::eListCurrencies:
			system("cls");
			_List_Currencies();
			_Back_To_Currency_Exchange_Screen();
			break;
		case clsCurrencyExchangeScreen::eFindCurrency:
			system("cls");
			_Find_Currency();
			_Back_To_Currency_Exchange_Screen();
			break;
		case clsCurrencyExchangeScreen::eUpdateCurrency:
			system("cls");
			_Update_Currency();
			_Back_To_Currency_Exchange_Screen();
			break;
		case clsCurrencyExchangeScreen::CurrencyCalculator:
			system("cls");
			_Currency_Calculator();
			_Back_To_Currency_Exchange_Screen();
			break;
		case clsCurrencyExchangeScreen::MainMenu:
			system("cls");
			_Main_Menu();
			break;
		default:
			break;
		}

	}


	static void _List_Currencies() {
		// code will be here
		clsCurrencyListScreen::ShowCurrenciesListScreen();
	}

	static void _Find_Currency() {
		// code will be here
		clsFindCurrencyScreen::Find_Currency();
	}

	static void _Update_Currency() {
		// code will be here
		clsUpdateCurrencyScreen::Update_Currency();
	}

	static void _Currency_Calculator() {
		// code will be here
		clsCurrencyCalculatorScreen::Currency_Exchange();
	}

	static void _Main_Menu() {
		// Nothing to do
	}


public :

	static void Show_Currency_Exchange_Screen() {
		Draw_Header("\tCurrency Exchange");

		cout << "\t\t\t" << "=======================================================================" << endl;
		cout << "\t\t\t\t\t\tCurrency Exchange Menu" << endl;
		cout << "\t\t\t" << "=======================================================================" << endl;
		cout << setw(47) << left << "" << "\t[1] LIST CURRENCIES" << endl;
		cout << setw(47) << left << "" << "\t[2] FIND CURRENCY" << endl;
		cout << setw(47) << left << "" << "\t[3] UPDATE CURRENCY" << endl;
		cout << setw(47) << left << "" << "\t[4] CURRENCY CALCULATOR" << endl;
		cout << setw(47) << left << "" << "\t[5] MAIN MENU" << endl;
		cout << "\t\t\t" << "=======================================================================" << endl;

		_Perform_Currency_Exchange_Option((enCur_change)_Read_Currency_Exchange_Options());


	}


};

