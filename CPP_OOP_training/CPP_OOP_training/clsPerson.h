#pragma once
#include <iostream>
using namespace std;

class clsPerson
{

private :

	string _First_Name;
	string _Last_Name;
	string _Email;
	string _Phone;

public :

	

	clsPerson(string fname, string lname, string mail, string phone) {
		_First_Name = fname;
		_Last_Name = lname;
		_Email = mail;
		_Phone = phone;
	}

	void Set_First_Name(string name) {
		_First_Name = name;
	}
	string Get_First_Name() {
		return _First_Name;
	}
	__declspec(property(put = Set_First_Name, get = Get_First_Name)) string First_Name;

	void Set_Last_Name(string name) {
		_Last_Name = name;
	}
	string Get_Last_Name() {
		return _Last_Name;
	}
	__declspec(property(put = Set_Last_Name, get = Get_Last_Name)) string Last_Name;

	void Set_Email(string mail){
		_Email = mail;
	}
	string Get_Email() {
		return _Email;
	}
	__declspec(property(put = Set_Email, get = Get_Email)) string Email;


	void Set_Phone(string phone) {
		_Phone = phone;
	}
	string Get_Phone() {
		return _Phone;
	}
	__declspec(property(put = Set_Phone, get = Get_Phone)) string Phone;


	string Full_Name() {
		return (_First_Name + ' ' + _Last_Name);
	}


};

