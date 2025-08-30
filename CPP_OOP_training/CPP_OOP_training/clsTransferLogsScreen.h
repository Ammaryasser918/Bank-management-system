#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"


using namespace std;


class clsTransferLogsScreen : protected clsScreen
{

private :

    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogs TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(8) << left << TransferLogRecord.AccNum1;
        cout << "| " << setw(8) << left << TransferLogRecord.AccNum2;
        cout << "| " << setw(8) << left << TransferLogRecord.amount;
        cout << "| " << setw(10) << left << TransferLogRecord.Balance_After1;
        cout << "| " << setw(10) << left << TransferLogRecord.Balance_After2;
        cout << "| " << setw(8) << left << TransferLogRecord.UserName;


    }

public :

    static void ShowTransferLogScreen()
    {


        vector <clsBankClient::stTransferLogs> vTransferLogRecord = clsBankClient::Get_Transfer_Logs();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t  (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        Draw_Header(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTransferLogs Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

