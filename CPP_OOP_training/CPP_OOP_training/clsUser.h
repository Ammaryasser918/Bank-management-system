#pragma once
#include <iostream>
using namespace std;
#include "clsPerson.h"
#include <fstream>
#include <string>
#include "clsString.h"
#include <vector>
#include "clsDate.h"
#include "Global.h"
#include "clsUtil.h"

using namespace std;

class clsUser : public clsPerson
{

private :

	enum en_Mode {
		Empty_Mode = 0, Update_Mode = 1, Add_New_Mode = 2, Delete_Mode = 4
	};
	en_Mode _Mode;

	string _User_Name;
	string _Password;
	int _Permission;

	struct stLoginRegisterRecord;

	static stLoginRegisterRecord _Convert_LoginRegister_Line_To_Object(string line) {
		vector<string> Record = clsString::split_string(line, '#');

		stLoginRegisterRecord Login_Register_Object;
		Login_Register_Object.DateTime = Record[0];
		Login_Register_Object.UserName = Record[1];
		Login_Register_Object.PassWord = clsUtil::decrypt_string(Record[2]);
		Login_Register_Object.Permission = stoi(Record[3]);

		return Login_Register_Object;

	}

	string _Convert_Object_To_Line(clsUser User) {

		string line;
		line += User.First_Name + '#';
		line += User.Last_Name + '#';
		line += User.Email + '#';
		line += User.Phone + '#';
		line += User._User_Name + '#';
		line += clsUtil::encrypt_string(User.PassWord) + '#';
		line += to_string(User.Permission);

		return line;

	}

	static clsUser _Convert_Line_To_Object(string line) {
		vector<string> data = clsString::split_string(line, '#');
		if (data.size() < 7) {

			return _Get_Empty_Object();
		}
		return clsUser(en_Mode::Update_Mode, data[0], data[1], data[2], data[3], data[4], clsUtil::decrypt_string(data[5]), stoi(data[6]));
	}

	static vector<clsUser> _Load_Data_From_File() {
		vector<clsUser> _Users;
		fstream file;
		file.open("Users.txt", ios::in);

		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				_Users.push_back(_Convert_Line_To_Object(line));
			}
			file.close();
		}
		return _Users;

	}

	static clsUser _Get_Empty_Object() {
		return clsUser(en_Mode::Empty_Mode, "", "", "", "", "", "", 0);
	}

	void _Add_New() {

		_Add_Line_To_File(_Convert_Object_To_Line(*this));

	}

	void _Add_Line_To_File(string line) {
		fstream file;
		file.open("Users.txt", ios::out | ios::app);

		if (file.is_open()) {
			file << line << endl;
			file.close();
		}

	}

	void _Delete() {
		_Delete_Data_From_File();
	}

	void _Delete_Data_From_File() {
		vector<clsUser> _clients;
		fstream file;
		file.open("Users.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsUser user = _Convert_Line_To_Object(line);
				if (user.Get_User_Name() == Get_User_Name()) {
					continue;
				}
				_clients.push_back(user);
			}

			file.close();
		}
		_Save_Data_To_File(_clients);

	}

	void _Update() {

		vector<clsUser> _users;
		_users = _Load_Data_From_File();

		for (clsUser& User : _users) {
			if (User.User_Name == _User_Name) {
				User = *this;
				break;
			}
		}

		_Save_Data_To_File(_users);

	}

	void _Save_Data_To_File(vector<clsUser> _Users) {

		fstream file;
		file.open("Users.txt", ios::out);

		if (file.is_open()) {
			string line;
			for (clsUser user : _Users) {
				line = _Convert_Object_To_Line(user);
				file << line << endl;
			}

			file.close();

		}


	}



public :

	clsUser(en_Mode Mode, string fname, string lname, string mail, string phone, string user_name, string password, int permission) : clsPerson(fname, lname, mail, phone) {
		_User_Name = user_name;
		_Password = password;
		_Permission = permission;
		_Mode = Mode;
	}

	void Set_User_Name(string name) {
		_User_Name = name;
	}
	string Get_User_Name() {
		return _User_Name;
	}
	__declspec(property(get = Get_User_Name, put = Set_User_Name)) string User_Name;

	void Set_Password(string pass) {
		_Password = pass;
	}
	string Get_Password() {
		return _Password;
	}
	__declspec(property(get = Get_Password, put = Set_Password)) string PassWord;

	void Set_Permission(int perm) {
		_Permission = perm;
	}
	int Get_Permission() {
		return _Permission;
	}
	__declspec(property(get = Get_Permission, put = Set_Permission)) int Permission;


	bool Is_Empty() {
		return (_Mode == en_Mode::Empty_Mode);
	}

	static clsUser Find(string UserName) {
		
		fstream file;
		file.open("Users.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsUser user = _Convert_Line_To_Object(line);
				if (user.User_Name == UserName) {
					file.close();
					return user;
				}
				
			}
			file.close();
		}

		return _Get_Empty_Object();
	
	}

	static clsUser Find(string UserName, string Pass) {
		fstream file;
		file.open("Users.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsUser user = _Convert_Line_To_Object(line);
				if (user.User_Name == UserName && user.PassWord == Pass) {
					file.close();
					return user;
				}

			}
			file.close();
		}

		return _Get_Empty_Object();
	}

	static bool Is_Exist(string UserName) {
		clsUser user = clsUser::Find(UserName);
		return (!user.Is_Empty());
	}

	enum enSave_result { Saving_Failed = 0, Saved_Successfully, Added_Successfully = 2, Failed_UserName_Already_Exist = 3, Deleted_Successfully = 4, Deleting_Failed_UserName_Not_Exist = 5 };

	enSave_result Save() {

		if (_Mode == en_Mode::Empty_Mode) {
			return enSave_result::Saving_Failed;
		}
		else if (_Mode == en_Mode::Update_Mode) {
			_Update();
			return enSave_result::Saved_Successfully;
		}
		else if (_Mode == en_Mode::Add_New_Mode) {
			if (clsUser::Is_Exist(_User_Name)) {
				return enSave_result::Failed_UserName_Already_Exist;
			}
			else {
				_Add_New();
				return enSave_result::Added_Successfully;
			}
		}
		else if (_Mode == en_Mode::Delete_Mode) {
			if (!clsUser::Is_Exist(_User_Name)) {
				return clsUser::enSave_result::Deleting_Failed_UserName_Not_Exist;
			}
			else {
				_Delete();
				return clsUser::enSave_result::Deleted_Successfully;
			}
		}
	}

	static clsUser Get_New_User_Object(string UserName) {
		return clsUser(en_Mode::Add_New_Mode, "", "", "", "", UserName, "", 0);
	}

	static clsUser Delete_User(string UserName) {
		clsUser user = clsUser::Find(UserName);
		user._Mode = en_Mode::Delete_Mode;
		return user;
	}


	static vector<clsUser> List_Users() {

		return _Load_Data_From_File();

	}



	enum en_Permetions {
		eAll = -1, eListUsers = 1, eAddUsers = 2, eDeleteUser = 4, eUpdateUser = 8, eFindUser = 16, eTransactions = 32, eManageUsers = 64, eLoginRegister = 128
	};


	bool Check_Permission(en_Permetions perm) {

		if (this->Permission == en_Permetions::eAll) {
			return true;
		}
		if ((this->Permission & perm) == perm) {
			return true;
		}
		else {
			return false;
		}

	}

	void Save_Login_To_Register_File() {
		fstream file;
		file.open("LoginRegister.txt", ios::app);
		if (file.is_open()) {
			string date = clsDate::Get_System_Date_Time_String();
			string line = date + '#';
			line += (User_Name + '#');
			line += (clsUtil::encrypt_string(PassWord)+'#');
			line += to_string(Permission);
			file << line << endl;
			file.close();
		}
	}

	struct stLoginRegisterRecord {

		string DateTime;
		string UserName;
		string PassWord;
		int Permission;

	};
	
	

	static vector<stLoginRegisterRecord> GetLoginRegisterList() {
		vector<stLoginRegisterRecord> vLogin;

		fstream file;
		file.open("LoginRegister.txt", ios::in);

		if (file.is_open()) {
			string line;
			stLoginRegisterRecord Login_Register_Record;
			while (getline(file, line)) {
				
				Login_Register_Record = _Convert_LoginRegister_Line_To_Object(line);
				
				vLogin.push_back(Login_Register_Record);

			}
			file.close();
		}

		return vLogin;


	}


};

