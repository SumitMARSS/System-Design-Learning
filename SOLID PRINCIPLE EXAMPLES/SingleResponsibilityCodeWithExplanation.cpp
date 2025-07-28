//Single Responsibility Principle

// this class doesn't follow single reason to change class as (class has only one reason to change)
#include <bits/stdc++.h>
using namespace std;

class Bank{
    virtual void acountManager(){};
    virtual void accountInfoHandler(){};
    virtual void cashbackHandler(){};
    virtual ~Bank(){}
};

//here iinheritance doesn't needed because we can directly create single responsibility class

//correct and converting into SRP
// Each class now has only one reason to change
class AccountManager {
public:
    void manageAccount() {
        cout << "Managing account for customers" << endl;
    }
};

class AccountInfoHandler {
public:
    void handleInfo() {
        cout << "Handling info about customer" << endl;
    }
};

class CashBackHandler {
public:
    void handleCashback() {
        cout << "Handling cashback info about customer" << endl;
    }
};

int main() {
    AccountManager manager1;
    AccountInfoHandler infoHandler;
    CashBackHandler cashbackHandler;

    manager1.manageAccount();
    infoHandler.handleInfo();
    cashbackHandler.handleCashback();

    return 0;
}