#pragma once
#include <iostream>
#include <iomanip>
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
public :
    static void Draw_Header(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t__________________________________________";
        cout << "\n\n\t\t\t\t\t    " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t     " << SubTitle;
        }
        cout << "\n\t\t\t\t__________________________________________\n\n";

        cout << "\t\t\t\tUser : " << Current_User.User_Name << endl;

        clsDate date = clsDate::Get_System_Date();
        cout << "\t\t\t\tDate : "; date.Print_Date(); cout << endl << endl;
        
    }


    static bool Check_Access_Rights(clsUser::en_Permetions permission) {

        if (!Current_User.Check_Permission(permission)) {

            cout << "\n\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else{
            return true;
        }

    }

};

