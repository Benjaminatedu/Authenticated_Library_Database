#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn()
{
    string user, pass, un, pw;

    cout << "Username: "; cin >> user;
    cout << "Password: "; cin >> pass;

    ifstream read("data\\" + user + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == user && pw == pass)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;

    cout << "1: Register\n2: Login\nYour Choice: "; cin >> choice;

    if (choice == 1)
    {
        string username, password;

        cout << "Select a Username : "; cin >> username;
        cout << "Select a Password : "; cin >> password;

        ofstream file;
        file.open("c:\\" + username + ".txt");
        file << username << endl << password;
        file.close();

        main();
    }
    else if (choice == 2)
    {
        bool status = IsLoggedIn();

        if (!status)
        {
            cout << "!False Login!" << endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Login Successful!" << endl;
            
            system("PAUSE");
            return 1;
        }
    }
    
}