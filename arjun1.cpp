#include <iostream>
#include <unordered_map>
#include <fstream>
#include <cstring>
#include<stack>
#include <conio.h>
// #include "ascii.cpp"
#include"animations.cpp"
using namespace std;

struct temp{
    int id;
    char name[29];
    char phoneNumber1[33];
    char phoneNumber2[42];
    char address[55];
    char email[40];
} t;

int get_id(){
    ifstream in;
    in.open("main1.txt");
    t.id = 0;
    while (in.read((char *)&t, sizeof(t)))
    {
    }
    return t.id + 1;
}

bool isnum(char ch)
{
    if (ch >= 48 && ch <= 57)
        return 1;
    else
        return 0;
}

void validators(int choice, temp &t)
{
    if (choice == 1)
    {
        for (int j = 0; j < strlen(t.name); j++)
        {
            if (t.name[j] >= 97 && t.name[j] <= 122 || t.name[j] >= 65 && t.name[j] <= 90 && strlen(t.name) >= 2 )
            {
                continue;
            }
            else
            {
                cout << " Enter a valid name " << endl;
                cin >> t.name;
            }
        }
    }
    else if (choice == 2)
    {
        for (int j = 0; j < strlen(t.address); j++)
        {
            if (t.address[j] >= 97 && t.address[j] <= 122 || t.address[j] >= 65 && t.address[j] <= 90 || isnum(t.address[j]))
            {
                continue;
            }
            else if (t.address[j] >= 58 && t.address[j] <= 64 || t.address[j] >= 48 && t.address[j] <= 57)
            {
                cout << " Enter a valid address " << endl;
                cin >> t.address;
            }
        }
    }
    else if (choice == 3)
    {
        for (int j = 0; j < strlen(t.phoneNumber1); j++)
        {
            if (t.phoneNumber1[j] >= 48 && t.phoneNumber1[j] <= 57 && strlen(t.phoneNumber1) == 10)
            {
                continue;
            }
            else
            {
                cout << " Enter a valid phone number " << endl;
                cin >> t.phoneNumber1;
            }
        }
    }
    else if (choice == 4)
    {
        for (int j = 0; j < strlen(t.phoneNumber2); j++)
        {
            if (t.phoneNumber2[j] >= 48 && t.phoneNumber2[j] <= 57 && strlen(t.phoneNumber2) == 10)
            {
                continue;
            }
            else
            {
                cout << " Enter a valid phone number " << endl;
                cin >> t.phoneNumber2;
            }
        }
    }
    else if (choice == 5)
    {
        if ((t.email[0] >= 65 && t.email[0] <= 90))
        {
            cout << "Enter a Valid E-mail ID (eg-> xyz@gmail.com)...." << endl;
            cout << "E-mail can't be started with First character as an Uppercase character.." << endl;
            cin >> t.email;
        }
        int At = -1, Dot = -1;
        for (int j = 0; j < strlen(t.email); j++)
        {

            if (t.email[j] == '@')
            {
                At = j;
            }
            else if (t.email[j] == '.')
            {
                Dot = j;
            }
        }
        if (At == -1 || Dot == -1)
        {
            cout << "Enter a Valid E-mail ID (eg-> xyz@gmail.com) " << endl
                 << "E-mail must contain '@' or '.com' " << endl;
            cin >> t.email;
        }
        if (At > Dot)
        {
            cout << "Enter a Valid E-mail ID (eg-> xyz@gmail.com) " << endl
                 << ".com' can't come before '@'" << endl;
            cin >> t.email;
        }
    }
}

void insert_info(){
    ofstream fout;
    t.id = get_id();
    ani("**************************************************************************");
    cout << endl;
    cout << " Enter the name of the person :";
    cin >> t.name;
    validators(1, t);
    cout << " Enter the first phone number of the person ";
    cin >> t.phoneNumber1;
    validators(3, t);
    cout << " Enter the second phone number of the person :";
    cin >> t.phoneNumber2;
    validators(4, t);
    cout << " Enter the address of the person :";
    cin >> t.address;
    validators(2, t);
    cout << " Enter the email id of the person ";
    cin >> t.email;
    validators(5, t);
    ani("**************************************************************************");
    cout<<endl;
    cout << "     Registrartion Sucessfull!!" << endl;
    cout << endl;
    fout.open("main1.txt", ios::app);
    fout.write((char*)&t, sizeof(t));
    fout.close();
}
void transfer_tomap(unordered_map<int, pair<string, pair<string, pair<string, pair<string, string>>>>> &m){
    ifstream in;
    in.open("main1.txt");
    while (in.read((char *)&t, sizeof(t)))
    {
        pair<int, pair<string, pair<string, pair<string, pair<string, string>>>>> p = make_pair(t.id, make_pair(t.name, make_pair(t.address, make_pair(t.email, make_pair(t.phoneNumber1, t.phoneNumber2)))));
        m.insert(p);
    }
    in.close();
}

void print_info(unordered_map<int, pair<string, pair<string, pair<string, pair<string, string>>>>> &m)
{
    cout << " Printing all the records " << endl;
    cout<<endl;
    // stack<int, pair<string, pair<string, pair<string, pair<string, string>>>>>s;
    auto itr = m.begin();
    ani("********************************************************************************************");
    cout << endl
         << "ID        NAME         ADDRESS                     E-MAIL      PHONE NUMBER-1    PHONE NUMBER-2                     " << endl;
    cout<<endl;
    ani("********************************************************************************************");
    cout << endl;
    int i = 1;
    while (itr != m.end())
    {
        cout << i << "      " << itr->second.first << "     " << itr->second.second.first << "      " << itr->second.second.second.first << "       " << itr->second.second.second.second.first << "        " << itr->second.second.second.second.second << endl;
        itr++;
        ++i;
    }
}

void search_information(int no, unordered_map<int , pair<string, pair<string, pair<string, pair<string, string>>>>> &m)
{
    string name, address, phonenumber;
    if (no == 1)
    {
        auto itr = m.begin();
        cout << " Enter your ID : " << endl;
        int id;
        cin >> id;
        ani("********************************************************************************************");
        cout << endl
             << "ID        NAME         ADDRESS                     E-MAIL      PHONE NUMBER    PHONE NUMBER                     " << endl;
        ani("********************************************************************************************");
        cout << endl;
        int i=1;
        while (itr != m.end())
        {
            if (i==id)
            cout << i << "      " << itr->second.first << "     " << itr->second.second.first << "      " << itr->second.second.second.first << "       " << itr->second.second.second.second.first << "        " << itr->second.second.second.second.second << endl;

            i++;
            itr++;
        }
    }
    else if (no == 2)
    {
        cout << " Enter the name of the person you want to search " << endl;
        cin >> name;
        ani("********************************************************************************************");
        cout << endl
             << "ID        NAME         ADDRESS                     E-MAIL      PHONE NUMBER    PHONE NUMBER                     " << endl;
        ani("********************************************************************************************");
        cout << endl;
        cout << endl;
        int i = 1;
        auto itr = m.begin();
        while (itr != m.end())
        {
            if (itr->second.first == name)
                cout << i << "      " << itr->second.first << "     " << itr->second.second.first << "      " << itr->second.second.second.first << "       " << itr->second.second.second.second.first << "        " << itr->second.second.second.second.second << endl;

            itr++;
        }
    }
    // unordered_map<int, pair<string, pair<string, pair<string, pair<string, string>>>>> &m
    else if (no == 3)
    {
        string phone_number;
        cout << " Enter the phone number of the person " << endl;
        cin >> phone_number;
        ani("********************************************************************************************");
        cout << endl
             << "ID        NAME         ADDRESS                     E-MAIL      PHONE NUMBER    PHONE NUMBER                     " << endl;

        ani("********************************************************************************************");
        cout << endl;
        cout << endl;
        int i = 1;
        auto itr = m.begin();
        while (itr != m.end())
        {
            if (itr->second.second.second.second.first == phone_number || itr->second.second.second.second.second == phone_number)
                cout << i << "      " << itr->second.first << "     " << itr->second.second.first << "      " << itr->second.second.second.first << "       " << itr->second.second.second.second.first << "        " << itr->second.second.second.second.second << endl;

            itr++;
        }
    }
    else if (no == 4)
    {
        string address;
        cout << " Enter the address of the person " << endl;
        cin >> address;
        ani("********************************************************************************************");
        cout << endl
             << "ID        NAME         ADDRESS                     E-MAIL      PHONE NUMBER    PHONE NUMBER                     " << endl;
        ani("********************************************************************************************");
        cout << endl;
        cout << endl;
        int i = 1;
        auto itr = m.begin();
        while (itr != m.end())
        {
            if (itr->second.second.first == address)
            cout << i << "      " << itr->second.first << "     " << itr->second.second.first << "      " << itr->second.second.second.first << "       " << itr->second.second.second.second.first << "        " << itr->second.second.second.second.second << endl;\

            itr++;
        }
    }
    else if (no == 5)
    {
        string email;
        auto itr = m.begin();
        cout << " Enter the email id You want to search " << endl;
        cin >> email;
        ani("********************************************************************************************");
        cout << endl
             << "ID        NAME         ADDRESS                     E-MAIL      PHONE NUMBER    PHONE NUMBER                     " << endl;
        ani("********************************************************************************************");
        cout << endl;
        cout << endl;
        int i = 1;
        while (itr != m.end())
        {
            if (itr->second.second.second.first == email)
            cout << i << "      " << itr->second.first << "     " << itr->second.second.first << "      " << itr->second.second.second.first << "       " << itr->second.second.second.second.first << "        " << itr->second.second.second.second.second << endl;

            itr++;
        }
    }
}

void search_info(unordered_map<int, pair<string, pair<string, pair<string, pair<string, string>>>>> &m)
{
    int choice;
    do
    {
        system("cls");
        cout << "-------------------------------------------------------------------" << endl;
        cout << " Press 1 to search information on basis of serial Numeber " << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << " Press 2 to search information on basis of Name " << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << " Press 3 to search information on basis of Phone Numeber " << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << " Press 4 to search information on basis of Address " << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << " Press 5 to search on basis of email id " << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << " Press 6 to exit " << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << " Enter your choice : ";
        cin >> choice;
        cout << "-------------------------------------------------------------------" << endl;
        switch (choice)
        {
        case 1:
            system("cls");
            search_information(1, m);
            ani("       Press any key to continue");
            getch();
            break;
        case 2:
            system("cls");
            search_information(2, m);
            ani("       Press any key to continue");
            getch();
            break;
        case 3:
            system("cls");
            search_information(3, m);
            ani("       Press any key to continue");
            getch();
            break;
        case 4:
            system("cls");
            search_information(4, m);
            ani("       Press any key to continue");
            getch();
            break;
        case 5:
            system("cls");
            search_information(5, m);
            ani("       Press any key to continue");
            getch();
            break;
        case 6:
            break;
        }
    } while (choice != 6);
}

void update_info1(char phonenumber[30], char newphonenumber[30])
{
    ifstream in;
    in.open("main1.txt");
    fstream out;
    out.open("file2.txt", ios::out | ios::app);
    while (in.read((char *)&t, sizeof(t)))
    {
        if (strcmp(t.phoneNumber1, phonenumber) == 0)
        {
            strcpy(t.phoneNumber1, newphonenumber);
            out.write((char *)&t, sizeof(t));
        }
        else if (strcmp(t.phoneNumber2, phonenumber) == 0)
        {
            strcpy(t.phoneNumber2, newphonenumber);
            out.write((char *)&t, sizeof(t));
        }
        else
            out.write((char *)&t, sizeof(t));
    }
    in.close();
    out.close();
    remove("main1.txt");
    rename("file2.txt", "main1.txt");
}

void update_info2(char phonenumber[20], char new_address[20])
{
    ifstream in;
    in.open("main1.txt");
    fstream out;
    out.open("file2.txt", ios::out | ios::app);
    while (in.read((char *)&t, sizeof(t)))
    {
        if (strcmp(t.phoneNumber1, phonenumber) == 0 || strcmp(t.phoneNumber2, phonenumber) == 0)
        {
            strcpy(t.address, new_address);
            out.write((char *)&t, sizeof(t));
        }
        else
            out.write((char *)&t, sizeof(t));
    }
    in.close();
    out.close();
    remove("main1.txt");
    rename("file2.txt", "main1.txt");
}

void update_info(int serial_no, unordered_map<int, pair<string, pair<string, pair<string, pair<string, string>>>>> &m)
{
    string phone_number, new_phonenumber, new_address;
    char phonenumber[30];
    char newPhone[30];
    char add[30];
    int flag1 = 0, flag2 = 0;
    cout << "-------------------------------------------------------------------" << endl;
    cout << " Enter the phone number of the person : " << endl;
    cin >> phone_number;
    cout << "-------------------------------------------------------------------" << endl;
    if (serial_no == 1)
    {
        auto itr = m.begin();
        while (itr != m.end())
        {
            if (itr->second.second.second.second.first == phone_number)
            {
                cout << " Enter your new phone number : " << endl;
                cin >> new_phonenumber;
                itr->second.second.second.second.first = new_phonenumber;
                strcpy(phonenumber, phone_number.c_str());
                strcpy(newPhone, new_phonenumber.c_str());
                update_info1(phonenumber, newPhone);
                flag1 = 1;
            }
            else if (itr->second.second.second.second.second == phone_number)
            {
                cout << " Enter your new phone number : " << endl;
                cin >> new_phonenumber;
                itr->second.second.second.second.second = new_phonenumber;
                strcpy(phonenumber, phone_number.c_str());
                strcpy(newPhone, new_phonenumber.c_str());
                update_info1(phonenumber, newPhone);
                flag1 = 1;
            }
            itr++;
        }
        if (flag1 == 1){
            cout << " The phone number has been updated Sucessfully " << endl;
            print_info(m);
        }
        else
            cout<<" Phone Number not found "<<endl;
    }
    else if (serial_no == 2)
    {
        auto itr = m.begin();
        while (itr != m.end())
        {
            if (itr->second.second.second.second.first == phone_number || itr->second.second.second.second.second == phone_number)
            {
                cout << " Enter Your Address :" << endl;
                cin >> new_address;
                itr->second.second.first = new_address;
                strcpy(phonenumber, phone_number.c_str());
                strcpy(add, new_address.c_str());
                update_info2(phonenumber,add);
                flag2 = 1;
                break;
            }
            itr++;
        }
        if (flag2 == 1){
            cout << " The address has been updated SuccessFully " << endl;
            print_info(m);
        }
        else
        cout<<" Address not found "<<endl;
    }
    getch();
}
void update_record(unordered_map<int, pair<string, pair<string, pair<string, pair<string, string>>>>> &m)
{
    int choice;
    do
    {
        system("cls");
        cout << "-------------------------------------------------------------------" << endl;
        cout << " Press 1 to update the phone number " << endl;
        cout << " Press 2 to update the address " << endl;
        cout << " Press 3 to exit " << endl;
        cout << " Enter your choice : ";
        cin >> choice;
        cout << "-------------------------------------------------------------------" << endl;
        switch (choice)
        {
        case 1:
            update_info(1, m);
            break;
        case 2:
            update_info(2, m);
            break;
        case 3:
            break;
        }
    } while (choice != 3);
}

void deleteInfo(char phonenumber[20])
{
    ifstream in;
    fstream out;
    int flag = 0;
    in.open("main1.txt");
    out.open("file2.txt", ios::app | ios::out);
    while (in.read((char *)&t, sizeof(t)))
    {
        if (strcmp(t.phoneNumber1, phonenumber) == 0 || strcmp(t.phoneNumber2, phonenumber) == 0)
        {
            flag = 1;
        }
        else
            out.write((char *)&t, sizeof(t));
    }
    in.close();
    out.close();
    remove("main1.txt");
    rename("file2.txt", "main1.txt");
}

void delete_record(unordered_map<int, pair<string, pair<string, pair<string, pair<string, string>>>>> &m)
{
    string phonenumber;
    int flag = 0;
    cout << "-------------------------------------------------------------------" << endl;
    cout << " Enter the phone Number of the person You want to remove :" << endl;
    cin >> phonenumber;
    char phone_number[20];
    auto itr = m.begin();
    while (itr != m.end())
    {
        if (itr->second.second.second.second.first == phonenumber || itr->second.second.second.second.second == phonenumber)
        {
            // itr->second.first = " ";
            // itr->second.second.first = " ";
            // itr->second.second.second.first = " ";
            // itr->second.second.second.second.first = " ";
            // itr->second.second.second.second.second = " ";
            flag = 1;
            strcpy(phone_number, phonenumber.c_str());
            deleteInfo(phone_number);
            m.erase(itr);
            break;
        }
        itr++;
    }
    if (flag == 1)
        cout << " The record has been deleted Sucessfully " << endl;
    cout << "-------------------------------------------------------------------" << endl;
    print_info(m);
}
int main()
{
    unordered_map<int, pair<string, pair<string, pair<string, pair<string, string>>>>> m;
    transfer_tomap(m);
    int choice;
    cout << "         Please wait for a few minutes... we are fetching record from the database " << endl;
    system("color E");
    system("cls");
    do
    {
        system("cls");
        system("color 7");
        do
        {
            ascii_art();
        } while (false);
        cout << "-------------------------------------------------------------------" << endl;
        ani(" Press 1 to insert data in table ");
        cout << endl;
        cout << "-------------------------------------------------------------------" << endl;
        ani(" Press 2 to view data ");
        cout << endl;
        cout << "-------------------------------------------------------------------" << endl;
        ani(" Press 3 to Search in the file ");
        cout << endl;
        cout << "-------------------------------------------------------------------" << endl;
        ani(" Press 4 to Update information in the table ");
 11
        cout << endl;
        cout << "-------------------------------------------------------------------" << endl;
        ani(" Press 5 to delete information in the table ");
        cout << endl;
    
        cout << "-------------------------------------------------------------------" << endl;
        ani(" Press 6 to exit ");
        cout << endl;
        cout << "-------------------------------------------------------------------" << endl;
        ani("Enter your choice : ");
        cin >> choice;
        cout << "-------------------------------------------------------------------" << endl;
        switch (choice)
        {
        case 1:
            system("cls");
            insert_info();
            ani("       Press any key to continue");
            getch();
            break;
        case 2:
            system("cls");
            transfer_tomap(m);
            print_info(m);
            ani("       Press any key to continue");
            getch();
            break;
        case 3:
            system("cls");
            transfer_tomap(m);
            search_info(m);
            ani("       Press any key to continue");
            getch();
            break;
        case 4:
            system("cls");
            transfer_tomap(m);
            update_record(m);
            ani("       Press any key to continue");
            getch();
            break;
        case 5:
            system("cls");
            transfer_tomap(m);
            delete_record(m);
            ani("       Press any key to continue");
            getch();
            break;
        case 6:
            ani("Thank You!!");
            exit(0);
        }
    } while (choice != 6);
    return 0;
}
