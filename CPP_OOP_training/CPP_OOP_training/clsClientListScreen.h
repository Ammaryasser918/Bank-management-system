#pragma once
#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
#include <vector>


using namespace std;

class clsClientListScreen : protected clsScreen
{
	static void _Print_Client_Record_Line(clsBankClient client) {

		cout << setw(8) << left << "" << "| " << setw(15) << left << client.Get_Account_Number();
		cout << "|" << setw(20) << left << client.Full_Name();
		cout << "|" << setw(12) << left << client.Phone;
		cout << "|" << setw(20) << left << client.Email;
		cout << "|" << setw(10) << left << client.PIN_Code;
		cout << "|" << setw(12) << left << client.Balance;

	}

public :

	static void Show_Clients_List() {

		if (!clsScreen::Check_Access_Rights(clsUser::en_Permetions::eListUsers)) {
			return;
		}


		vector<clsBankClient> list = clsBankClient::List_Clients();

		string Title = "Client List Screen";
		string SubTitle = "(" + to_string(list.size()) + ") Client(s).";

		Draw_Header(Title, SubTitle);

		//cout << "\n\t\t\t\t\tClient List (" << list.size() << ") Client(s).";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(19) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(18) << "Email";
		cout << "| " << left << setw(9) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (list.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else
		{
			for (clsBankClient& cli : list) {
				_Print_Client_Record_Line(cli);
				cout << endl;
			}
			cout << setw(8) << left << "" << "\n\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;

		}

	}

};

