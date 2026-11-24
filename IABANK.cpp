#include <iostream>
#include <string>
#include <ctime>

#if defined(__EMSCRIPTEN__)
#include <emscripten/emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

using namespace std;

extern "C"
{
    // This attribute ensures the compiler doesn't optimize out the function
    EMSCRIPTEN_KEEPALIVE
    int addNumbers(int a, int b)
    {
        return a + b;
    }
}

int main()
{
    string name, username, password, greeting;
    string savedUsername, savedPassword;
    double balance = 0.0;
    bool hasAccount = false;

    time_t now = time(0);
    tm *local = localtime(&now);
    int hour = local->tm_hour;

    if (hour < 12)
    {
        greeting = "Good Morning";
    }
    else if (hour < 18)
    {
        greeting = "Good Afternoon";
    }
    else if (hour < 21)
    {
        greeting = "Good Evening";
    }
    else
    {
        greeting = "Good Night";
    }

    cout << greeting << "! Enter your name: ";
    getline(cin, name);
    cout << "Hello " << name << endl;

    int choice;
    cout << "1. Create Account\n2. Log In\n";
    cin >> choice;
    cin.ignore(); // clear the leftover newline

    if (choice == 1)
    {
        cout << "Choose a username: ";
        getline(cin, savedUsername);
        cout << "Choose a password: ";
        getline(cin, savedPassword);
        hasAccount = true;
        cout << "Account created!" << endl;
    }
    else if (choice != 2)
    {
        cout << "Invalid choice." << endl;
        return 0;
    }

    if (!hasAccount)
    {
        cout << "No account found. Please create one first." << endl;
        return 0;
    }

    cout << "Enter Username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    if (username == savedUsername && password == savedPassword)
    {
        cout << "Welcome, " << name << "!" << endl;
    }
    else
    {
        char forgot;
        cout << "Login failed. Forgot password? (y/n): ";
        cin >> forgot;

        if (forgot == 'y' || forgot == 'Y')
        {
            cout << "Password reset link sent." << endl;
        }
    }

    if (balance < 0 && balance > -100)
    {
        cout << "Warning: Your account is overdrawn." << endl;
    }
    else if (balance <= -100)
    {
        cout << "Alert: Your account is severely overdrawn." << endl;
    }

    if (balance + 1)

        if (balance > 1000 && balance < 10000)
        {
            cout << "CONGRATULATIONS! You are on track to reach high financail goals!" << endl;
        }
        else if (balance >= 100000)
        {
            cout << "CONGRATULATIONS! You have reached a high financial goal!" << endl;
        }
    return 0;
}