/*Basic Bank Account System*/

/* UML   

+---------------------+
|      BankAccount    |
+---------------------+
| - accountNumber: string |
| - balance: double   |
| - ownerName: string |
+---------------------+
| + deposit(amount: double): void |
| + withdraw(amount: double): bool |
| + getBalance(): double |
| + displayInfo(): void |
+---------------------+


*/


#include <iostream>
#include <string>
using namespace std;


class BankAccount {
    private:
    string accountNumber;
    double balance;
    string ownerName;

    public:
    //constructor 
        BankAccount(string accN,string name,double initital_balance = 0.0):accountNumber(accN),ownerName(name),balance(initital_balance){}

        //deposit 
        void deposit(double amount)
        {
            if (amount >0)
            {
                balance +=amount;
                cout << "Deposited $" << amount << endl;
            }

        }
    
        //withdraw
        bool withdraw(double amount) 
        {
            if (amount > 0 && balance >=amount)
            {
                    balance -=amount;
                    cout << "Withdrew $" << amount << endl;
                    return true;
            }

            else {
                cout << "Insufficient funds or invalid amount" << endl;
                return false;
            }
        }

        //get balance
        double getbalance()
        {
            return balance;
        }

        //display info
        void displayInfo() const {
        cout << "Account Number: " << accountNumber << "\n"
             << "Owner: " << ownerName << "\n"
             << "Balance: $" << balance << endl;
    }


};

// int main()
// {

//         BankAccount myaacount("A12345","Tony",5000);
//         myaacount.deposit(1000);
//         myaacount.withdraw(250);
//         double balance =  myaacount.getbalance();
//         cout<<"Blanace$"<<balance<<endl;
//         myaacount.displayInfo();
//     return 0;
// }

