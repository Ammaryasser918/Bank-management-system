#pragma once
#include <iostream>
#include<string>
#include "clsString.h"
#include <vector>
#include <fstream>


class clsCurrencyExchange
{

private :

	enum enMode {
		Empty_Mode = 0, Update_Mode = 1
	};
	enMode _Mode;
	string _Country;
	string _Currency_Code;
	string _Currency_Name;
	float _Rate;


	static clsCurrencyExchange _Convert_Line_To_Object(string line) {
		vector<string> vCurrency;
		vCurrency = clsString::split_string(line, '#');

		return clsCurrencyExchange(enMode::Update_Mode, vCurrency[0], vCurrency[1], vCurrency[2], stof(vCurrency[3]));

	}

	static vector<clsCurrencyExchange> _Load_Data_From_File() {
		vector<clsCurrencyExchange> data;
		fstream file;
		file.open("Currencies.txt", ios::in);

		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				data.push_back(_Convert_Line_To_Object(line));
			}
			file.close();
		}
		return data;

	}

	void _Update(){
		
		vector<clsCurrencyExchange> vCurrency = _Load_Data_From_File();

		for (clsCurrencyExchange &Cur : vCurrency) {
			if (Cur.Get_Currency_Code() == Get_Currency_Code()) {
				Cur = *this;
				break;
			}
		}
		
		_Save_Data_To_File(vCurrency);
	
	}

	static string _Convert_Object_To_Line(clsCurrencyExchange cur) {

		string line = "";
		line += cur.Get_Country() + '#';
		line += cur.Get_Currency_Code() + '#';
		line += cur.Get_Currency_Name() + '#';
		line += to_string(cur.Get_Rate());

		return line;
	}

	static void _Save_Data_To_File(vector<clsCurrencyExchange> vCurrency) {
		fstream file;
		file.open("Currencies.txt", ios::out);
		if (file.is_open()) {
			for (clsCurrencyExchange& cur : vCurrency) {
				string line = _Convert_Object_To_Line(cur);
				file << line << endl;
			}
			file.close();
		}

	}


	static clsCurrencyExchange _Get_Empty_Currency_Object() {
		return clsCurrencyExchange(enMode::Empty_Mode, "", "", "", 0);
	}


	



public :
	clsCurrencyExchange(enMode mode, string country, string currency_code, string currency_name, float rate) {
		_Mode = mode;
		_Country = country;
		_Currency_Code = currency_code;
		_Currency_Name = currency_name;
		_Rate = rate;
	}

	bool Is_Empty() {
		return (_Mode == enMode::Empty_Mode);
	}


	string Get_Country() {
		return _Country;
	}
	string Get_Currency_Code() {
		return _Currency_Code;
	}
	string Get_Currency_Name() {
		return _Currency_Name;
	}

	float Get_Rate() {
		return _Rate;
	}
	void Set_Rate(float rate) {
		_Rate = rate;
		_Update();
	}


	
	static clsCurrencyExchange Find_By_Country(string country) {

		country = clsString::All_upper(country);

		fstream file;
		file.open("Currencies.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsCurrencyExchange currency = _Convert_Line_To_Object(line);
				if (clsString::All_upper(currency.Get_Country()) == country) {
					file.close();
					return currency;
				}
			}
			file.close();

		}

	}

	static clsCurrencyExchange Find_By_Currency_Code(string code) {

		code = clsString::All_upper(code);

		fstream file;
		file.open("Currencies.txt", ios::in);

		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				clsCurrencyExchange currency = _Convert_Line_To_Object(line);
				if (currency.Get_Currency_Code() == code) {
					file.close();
					return currency;
				}
			}
			file.close();
		}


	}


	static bool Is_Exist(string currency_code) {
		clsCurrencyExchange currency = clsCurrencyExchange::Find_By_Currency_Code(currency_code);
		return (!currency.Is_Empty());
	}


	static vector<clsCurrencyExchange> Get_Currency_List() {
		return _Load_Data_From_File();
	}
	


};

