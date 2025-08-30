#pragma once
#include <iostream>
using namespace std;
#include "clsPerson.h"
#include <fstream>
#include <string>
#include "clsString.h"
#include "Global.h"
#include "clsUtil.h"
class clsBankClient : public clsPerson
{

private :

	enum en_Mode {Empty_Mode = 0, Update_Mode = 1, Add_New_Mode = 2, Delete_Mode = 4};
	en_Mode _Mode;

	string _Account_Number;
	string _PIN_Code;
	float _Balance;

	struct stTransferLogs;

	static stTransferLogs _Convert_Line_To_Logs(string line) {

		vector<string> Logs = clsString::split_string(line, '#');

		stTransferLogs TransLog;
		TransLog.DateTime = Logs[0];
		TransLog.AccNum1 = Logs[1];
		TransLog.AccNum2 = Logs[2];
		TransLog.amount = stof(Logs[3]);
		TransLog.Balance_After1 = stof(Logs[4]);
		TransLog.Balance_After2 = stof(Logs[5]);
		TransLog.UserName = Logs[6];

		return TransLog;

	}

	static clsBankClient _Convert_Line_To_Object(string line) {
		vector<string> data = clsString::split_string(line, '#');
		if (data.size() < 7) {
			
			return _Get_Empty_Object();
		}
		return clsBankClient(en_Mode::Update_Mode, data[0], data[1], data[2], data[3], data[4], data[5], stod(data[6]));
	}

	static clsBankClient _Get_Empty_Object() {
		return clsBankClient(en_Mode::Empty_Mode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _Load_Data_From_File() {
		vector<clsBankClient> _Clients;
		fstream file;
		file.open("Clients.txt", ios::in);

		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				_Clients.push_back(_Convert_Line_To_Object(line));
			}
			file.close();
		}
		return _Clients;

	}

	string _Convert_Object_To_Line(clsBankClient cli) {

		string line;
		line += cli.First_Name + '#';
		line += cli.Last_Name + '#';
		line += cli.Email + '#';
		line += cli.Phone + '#';
		line += cli.Get_Account_Number() + '#';
		line += cli.Get_PIN_Code() + '#';
		line += to_string(cli.Get_Balance());

		return line;

	}

	void _Save_Data_To_File(vector<clsBankClient> _Clients) {

		fstream file;
		file.open("Clients.txt", ios::out);

		if (file.is_open()) {
			string line;
			for (clsBankClient cli : _Clients) {
				line = _Convert_Object_To_Line(cli);
				file << line << endl;
			}

			file.close();

		}
		

	}

	void _Update() {

		vector<clsBankClient> _clients;
		_clients = _Load_Data_From_File();

		for (clsBankClient &cli : _clients) {
			if (cli.Get_Account_Number() == Get_Account_Number()) {
				cli = *this;
				break;
			}
		}

		_Save_Data_To_File(_clients);

	}

	void _Add_New() {
		
		_Add_Line_To_File(_Convert_Object_To_Line(*this));

	}

	void _Add_Line_To_File(string line) {
		fstream file;
		file.open("Clients.txt", ios::out | ios::app);

		if (file.is_open()) {
			file << line << endl;
			file.close();
		}

	}

	void _Delete() {
		_Delete_Data_From_File();
	}

	void _Delete_Data_From_File() {
		vector<clsBankClient> _clients;
		fstream file;
		file.open("Clients.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsBankClient cli = _Convert_Line_To_Object(line);
				if (cli.Get_Account_Number() == Get_Account_Number()) {
					continue;
				}
				_clients.push_back(cli);
			}

			file.close();
		}
		_Save_Data_To_File(_clients);

	}




public :

	clsBankClient(en_Mode mode, string fname, string lname, string mail, string phone, string AccNum, string pin, float balance) : clsPerson(fname, lname, mail, phone){

		_Mode = mode;
		_Account_Number = AccNum;
		_PIN_Code = pin;
		_Balance = balance;

	}


	string Get_Account_Number() {
		return _Account_Number;
	}

	void Set_PIN_Code(string pin) {
		_PIN_Code = pin;
	}
	string Get_PIN_Code() {
		return _PIN_Code;
	}
	__declspec(property(get = Get_PIN_Code, put = Set_PIN_Code)) string PIN_Code;

	void Set_Balance(float bal) {
		_Balance = bal;
	}
	float Get_Balance() {
		return _Balance;
	}
	__declspec(property(get = Get_Balance, put = Set_Balance)) float Balance;

	
	

	bool Is_Empty() {
		return (en_Mode::Empty_Mode == _Mode);
	}

	static clsBankClient Find(string Acc_Num) {

		vector<clsBankClient> Vclient;

		fstream file;
		file.open("Clients.txt", ios::in);

		if (file.is_open()) {

			string line;
			while (getline(file, line)) {
				clsBankClient client = _Convert_Line_To_Object(line);
				if (client.Get_Account_Number() == Acc_Num) {
					file.close();
					return client;
				}
				Vclient.push_back(client);
			}
			file.close();
		}
		return _Get_Empty_Object();

	}

	static clsBankClient Find(string Acc_Num, string PIN) {

		vector<clsBankClient> Vclient;
		fstream file;
		file.open("Clients.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsBankClient client = _Convert_Line_To_Object(line);
				if (client.Get_Account_Number() == Acc_Num && client.Get_PIN_Code() == PIN) {
					file.close();
					return client;
				}
				Vclient.push_back(client);
			}
			file.close();
		}

		return _Get_Empty_Object();


	}



	static bool Is_Exist(string Acc_Num) {
		clsBankClient client = clsBankClient::Find(Acc_Num);
		return (!client.Is_Empty());
	}


	enum enSave_result {Saving_Failed = 0, Saved_Successfully, Added_Successfully = 2, Failed_Account_Already_Exist = 3, Deleted_Successfully = 4, Deleting_Failed_Acount_Not_Exist = 5};

	enSave_result Save() {

		if (_Mode == en_Mode::Empty_Mode) {
			return enSave_result::Saving_Failed;
		}
		else if (_Mode == en_Mode::Update_Mode) {
			_Update();
			return enSave_result::Saved_Successfully;
		}
		else if (_Mode == en_Mode::Add_New_Mode) {
			if (clsBankClient::Is_Exist(_Account_Number)) {
				return enSave_result::Failed_Account_Already_Exist;
			}
			else {
				_Add_New();
				return enSave_result::Added_Successfully;
			}
		}
		else if (_Mode == en_Mode::Delete_Mode) {
			if (!clsBankClient::Is_Exist(_Account_Number)) {
				return clsBankClient::enSave_result::Deleting_Failed_Acount_Not_Exist;
			}
			else {
				_Delete();
				return clsBankClient::enSave_result::Deleted_Successfully;
			}
		}
	}
	

	static clsBankClient Get_New_Account_Object(string Acc_Num) {
		return clsBankClient(en_Mode::Add_New_Mode, "", "", "", "", Acc_Num, "", 0);
	}


	static clsBankClient Delete_Account(string Acc_Num) {
		clsBankClient cli = clsBankClient::Find(Acc_Num);
		cli._Mode = en_Mode::Delete_Mode;
		return cli;
	}


	static vector<clsBankClient> List_Clients() {
		
		return _Load_Data_From_File();


	}


	static float GetTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::List_Clients();

		double TotalBalances = 0;

		for (clsBankClient Client : vClients)
		{

			TotalBalances += Client.Balance;
		}

		return TotalBalances;

	}


	void Deposit(float amount) {
		_Balance += amount;
		Save();
	}

	void Withdraw(float amount) {
		_Balance -= amount;
		Save();
	}

	void Transfer(clsBankClient &cli2, float amount) {
		this->Withdraw(amount);
		cli2.Deposit(amount);
		Save();
	}

	


	void Save_Transfer_To_Transfer_Logs_File(clsBankClient &cli2, float amount) {
		fstream file;
		file.open("TransferLogs.txt", ios::app);

		if (file.is_open()) {
			string date = clsDate::Get_System_Date_Time_String();
			string line = date + '#';
			line += (Get_Account_Number() + '#');
			line += (cli2.Get_Account_Number() + '#');
			line += (to_string(amount) + '#');
			line += (to_string(Balance) + '#');
			line += (to_string(cli2.Balance) + '#');
			line += (Current_User.User_Name);
			file << line << endl;
			file.close();
		}

	}
	
	
	
	struct stTransferLogs {

		string DateTime;
		string AccNum1;
		string AccNum2;
		int amount;
		int Balance_After1;
		int Balance_After2;
		string UserName;

	};

	static vector<stTransferLogs> Get_Transfer_Logs() {
		vector<stTransferLogs> Vlogs;
		fstream file;
		file.open("TransferLogs.txt", ios::in);
		if (file.is_open()) {

			stTransferLogs TransLog;
			string line;
			while (getline(file, line)) {
				TransLog = _Convert_Line_To_Logs(line);
				Vlogs.push_back(TransLog);
			}
			file.close();

		}
		
		return Vlogs;


	}
	







};

