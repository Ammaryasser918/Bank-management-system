#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsMainMenu.h"
#include <fstream>
#include "clsDate.h"

using namespace std;


class clsLoginScreen : protected clsScreen
{

private :

	


	static void _Login(int &trials) {

		Draw_Header("   Login Screen");

		bool login_failed = false;
		
		short* tmp;
		tmp = new short;
		*tmp = trials;
		do {
			string UserName, Pass_word;
			if (login_failed) {
				cout << endl;
				cout << "Invalid Name/Password, Please Try Another One" << endl;
				cout << "You Have more " << --trials << " Trials To Login" << endl << endl;
				if (trials == 0) {
					cout << endl << "System Locked ! , You Used " << *tmp << " Trials" << endl;

					return;
				}
			}

			cout << "Enter UserName : "; UserName = clsInputValidate::Read_String();
			cout << "Enter Password : "; Pass_word = clsInputValidate::Read_String();

			Current_User = clsUser::Find(UserName, Pass_word);

			login_failed = Current_User.Is_Empty();

		} while (login_failed);
		delete tmp;


		Current_User.Save_Login_To_Register_File();



		system("cls");
		clsMainMenu::Show_Main_Menu();
		
	}


public :

	static void Show_Login_Screen(int &trials) {
		_Login(trials);
	}


};

