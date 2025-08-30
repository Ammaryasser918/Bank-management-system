#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;



class clsUtil
{


public:
    

    // ---------------------------------------------------------------------

    /*static string encrypt_string(string txt, int key = 2) {
        string ans = txt;
        for (int i = 0; i < ans.size(); i++) {
            if (islower(ans[i])) {
                ans[i] = 'a' + (ans[i] - 'a' + key) % 26;
            }
            else if (isupper(ans[i])) {
                ans[i] = 'A' + (ans[i] - 'A' + key) % 26;
            }
        }
        return ans;
    }

    



    static string decrypt_string(string txt, int key = 2) {
        string ans = txt;
        for (int i = 0; i < ans.size(); i++) {
            if (islower(ans[i])) {
                ans[i] = 'a' + (((ans[i] - 'a' - key) % 26 + 26) % 26);
            }
            else if (isupper(ans[i])) {
                ans[i] = 'A' + (((ans[i] - 'A' - key) % 26 + 26) % 26);
            }
        }
        return ans;
    }*/

    static string  encrypt_string(string Text, short EncryptionKey = 2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  decrypt_string(string Text, short EncryptionKey = 2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }

    

    // ---------------------------------------------------------------------

    static int get_random_num(int from, int to) {
        static bool seeded = false;
        if (!seeded) {
            srand((unsigned)time(NULL));
            seeded = true;
        }

        return from + (rand() % (to - from + 1));

    }

    // ---------------------------------------------------------------------

    enum char_type { small_letter = 1, capital_letter = 2, special_character = 3, digit = 4, random_char };

    static char Get_random_char(char_type type) {

        if (type == small_letter) {
            return get_random_num('a', 'z');
        }
        else if (type == capital_letter) {
            return get_random_num('A', 'Z');
        }
        else if (type == special_character) {
            return get_random_num(33, 47);
        }
        else if (type == digit) {
            return get_random_num('0', '9');
        }
        else if (type == random_char) {
            return get_random_num(33, 127);
        }

    }

    // ---------------------------------------------------------------------


    static string generate_word(char_type type, int len) {

        string word = "";
        while (len--) {
            word += Get_random_char(type);
        }
        return word;

    }


    // ---------------------------------------------------------------------



    static string generate_key(char_type type, int num_of_slots) {
        string key = "";
        for (int i = 0; i < num_of_slots - 1; i++) {
            key += generate_word(type, 4) + '-';
        }
        key += generate_word(type, 4);
        return key;
        
    }

    // ---------------------------------------------------------------------


    static vector<int> random_num_array(int len, int from, int to) {
        vector<int> arr;
        for (int i = 0; i < len; i++) {
            arr.push_back(get_random_num(from, to));
        }
        return arr;
    }


    // ---------------------------------------------------------------------

    static vector<string> random_word_array(char_type type, int len, int str_len) {
        vector<string> words;
        while (len--) {
            words.push_back(generate_word(type, str_len));
        }
        return words;
    }

    // ---------------------------------------------------------------------

    static vector<string> random_key_array(char_type type, int len, int num_of_slots) {
        vector<string> keys;
        while (len--) {
            keys.push_back(generate_key(type, num_of_slots));
        }
        return keys;
    }

    // ---------------------------------------------------------------------


    static void Swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    static void Swap(string& a, string& b) {
        string tmp = a;
        a = b;
        b = tmp;
    }

    static void Swap(double& a, double& b) {
        double tmp = a;
        a = b;
        b = tmp;
    }

    // ---------------------------------------------------------------------

    static void shuffle_array(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            Swap(arr[get_random_num(0, arr.size() - 1)], arr[get_random_num(0, arr.size() - 1)]);
        }
    }

    // ---------------------------------------------------------------------


    static void shuffle_array(vector<string>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            Swap(arr[get_random_num(0, arr.size() - 1)], arr[get_random_num(0, arr.size() - 1)]);
        }
    }

    // ---------------------------------------------------------------------

    static void shuffle_array(vector<double>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            Swap(arr[get_random_num(0, arr.size() - 1)], arr[get_random_num(0, arr.size() - 1)]);
        }
    }

    // ---------------------------------------------------------------------




    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }








};
