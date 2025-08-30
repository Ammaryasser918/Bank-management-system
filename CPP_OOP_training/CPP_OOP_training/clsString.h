#pragma once
#include <iostream>
#include <string>
using namespace std;


class clsString
{

private :
	string _str;
	char _ch;
public :

	// ----- < constructors > -----

	clsString() {
		_str = "";
		_ch = NULL;
	}

	clsString(string s) {
		_str = s;
		_ch = NULL;
	}
	
	clsString(char ch) {
		_str = "";
		_ch = ch;
	}

	// ========================================


	// ----- < set & get > -----
	void Set_string(string s) {
		_str = s;

	}
	string Get_string() {
		return _str;
	}


	__declspec(property(put = Set_string, get = Get_string)) string str;


	// ========================================



	int count_certain_letter(char c) {
		int cnt = 0;
		for (char i : _str) {
			if (i == c) cnt++;
		}
		return cnt;
	}


	int sencitive_count_certain_letter(char c) {
		int cnt = 0;
		for (char i : _str) {
			if (tolower(i) == c) {
				cnt++;
			}
		}
		return cnt;
	}


	// ========================================

	static bool is_vowel(char c) {
		if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
			return true;
		}
		return false;
	}

	bool is_vowel() {
		return is_vowel(_ch);
	}


	// ========================================

	int Sz() {
		return _str.size();
	}
	__declspec(property(get = Sz)) int sz;

	// ========================================


	void print_vowels() {
		for (char i : _str) {
			if (is_vowel(i)) {
				cout << i << "  ";
			}
		}
	}

	// ========================================
	
	static void print_each_word(string s) {
		string tmp = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				cout << tmp << endl;
				tmp.clear();
				continue;
			}
			tmp += s[i];
		}
		if (!tmp.empty()) cout << tmp << endl;
	}
	

	void print_each_word() {
		print_each_word(_str);
	}

	// ========================================

	static int count_words(string s) {
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				cnt++;
			}
		}
		return (cnt + 1); // two spaces = 3 strings
	}
	
	int count_words() {
		return count_words(_str);
	}

	// ========================================

	static vector<string> split_string(string s, char delim) {
		string tmp = "";
		vector<string> res;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == delim) {
				res.push_back(tmp);
				tmp.clear();
				continue;
			}
			tmp += s[i];
		}
		if (!tmp.empty()) res.push_back(tmp);
		
		return res;

	}

	vector<string> split_string(char delim) {
		return split_string(_str, delim);
	}


	// ========================================


	static int count_uppers(string s) {
		int cnt = 0;
		for (char i : s) {
			if (isupper(i)) cnt++;
		}
		return cnt;
	}

	int count_caps() {
		return count_uppers(_str);
	}

	// ========================================

	static int count_lowers(string s) {
		int cnt = 0;
		for (char i : s) {
			if (islower(i)) {
				cnt++;
			}
		}
		return cnt;
	}

	int count_lowers() {
		return count_lowers(_str);
	}

	// ========================================


	static string join_string(vector<string> strs) {
		string ans = "";
		for (int i = 0; i < strs.size(); i++) {
			if (i == 0) {
				ans += strs[i];
			}
			else {
				ans += (' ' + strs[i]);
			}
		}
		return ans;
	}


	// ========================================


	static string All_lower(string s) {
		for (int i = 0; i < s.size(); i++) {
			s[i] = tolower(s[i]);
		}
		return s;
	}
	string All_lower() {
		return All_lower(_str);
	}

	// ========================================


	static string All_upper(string s) {
		for (int i = 0; i < s.size(); i++) {
			s[i] = toupper(s[i]);
		}
		return s;
	}
	string All_upper() {
		return All_upper(_str);
	}

	// ========================================

	static string Upper_First_Each_Word(string s) {
		bool is_first_letter = true;
		for (int i = 0; i < s.size(); i++) {
			if (is_first_letter) {
				s[i] = toupper(s[i]);
				is_first_letter = false;
			}
			if (s[i] == ' ') {
				is_first_letter = true;
			}
		}
		return s;
	}

	void Upper_First_Each_Word() {
		_str = Upper_First_Each_Word(_str);
	}



	static string Lower_First_Each_Word(string S1)
	{

		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}

		return S1;
	}

	void  Lower_First_Each_Word()
	{
		_str = Lower_First_Each_Word(_str);
	}

	
	// ========================================

	static string TrimLeft(string S1)
	{


		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}

	void TrimLeft()
	{
		_str = TrimLeft(_str);
	}

	static string TrimRight(string S1)
	{


		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}

	void TrimRight()
	{
		_str = TrimRight(_str);
	}

	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));

	}

	void Trim()
	{
		_str = Trim(_str);
	}


	// ========================================


	static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{

		vector<string> vString = split_string(S1, ' ');

		for (string& s : vString)
		{

			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}

			}
			else
			{
				if (All_lower(s) == All_lower(StringToReplace))
				{
					s = sRepalceTo;
				}

			}

		}

		return join_string(vString);
	}

	string ReplaceWord(string StringToReplace, string sRepalceTo)
	{
		return ReplaceWord(_str, StringToReplace, sRepalceTo);
	}


	// ========================================



};

