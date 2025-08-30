#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrencyExchange.h"


using namespace std;

class clsCurrencyListScreen : protected clsScreen
{

private :


    static void PrintCurrencyRecordLine(clsCurrencyExchange Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Get_Country();
        cout << "| " << setw(8) << left << Currency.Get_Currency_Code();
        cout << "| " << setw(45) << left << Currency.Get_Currency_Name();
        cout << "| " << setw(10) << left << Currency.Get_Rate();

    }


public :

    static void ShowCurrenciesListScreen()
    {


        vector <clsCurrencyExchange> vCurrencys = clsCurrencyExchange::Get_Currency_List();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t  (" + to_string(vCurrencys.size()) + ") Currency.";

        Draw_Header(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        if (vCurrencys.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrencyExchange Currency : vCurrencys)
            {

                PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

    }



};

