#include<iostream>
using namespace std;
#include<iomanip>
#include<string>
double Verified_Output(const string &message){
    double amount;
    do
    {
        cout<<message;
        cin>> amount;
        if (amount < 0)
        {
            cout<<"The amount can not be negative."<<endl;
        }
        
    }while (amount < 0.0);
    return amount;
}
double Calculate_Mtax(int balance , double monthlytax_rate){
    double monthlytax;
    monthlytax = balance * monthlytax_rate;
    return monthlytax;
}
double Calculate_deposits(double deposits[], int months){
    double total = 0;
    for(int x = 0; x < months; x++){
        total += deposits[x];
    }
    return total;
}
double Calculate_Withdrawls(double withdrawls[], int months){
    double wtotal = 0;
    for(int y = 0; y < months; y++){
        wtotal += withdrawls[y];
    }
    return wtotal;
}
double Calculate_TTax(double Taxes[], int months){
    double Ttotal = 0;
    for(int t = 0; t < months; t++){
        Ttotal += Taxes[t];
    }
    return Ttotal;
}
int main(){
    int months;
    double annual_Tax_Rate, monthly_Tax_Rate, balance, previous_balance;
    double deposits[100];
    double withdrawls[100];
    double taxes[100];
    cout<<"Enter your previous account balance: ";
    cin >> previous_balance;
    cout<<"Enter the annual tax rate. Note Pls enter it in percentage: ";
    cin >> annual_Tax_Rate;
    cout<<"Enter the total number of months to keep record of: ";
    cin >> months;
    monthly_Tax_Rate = (annual_Tax_Rate / 100.0) / 12.0;

    balance = previous_balance;
    int x = 0;
    while (x < months)
    {
        cout<<"Record for month"<<x + 1<<":"<<endl;
        deposits[x] = Verified_Output("Enter deposit amount: ");
        balance += deposits[x];
        withdrawls[x] = Verified_Output("Enter withdrawl amount: ");
        balance -= withdrawls[x];
        taxes[x] = Calculate_Mtax(balance , monthly_Tax_Rate);
        balance -= taxes[x];
        cout<<"The deducted tax is: "<<taxes[x]<<endl;
        cout<<"Balance after tax deduction is for month "<<x + 1<<" is: "<<fixed<<setprecision(2)<<balance<<endl;
        x += 1;
    }
    double Total_Deposits = Calculate_deposits(deposits , months);
    double Total_Withdrawls = Calculate_Withdrawls(withdrawls , months);
    double Total_Tax = Calculate_TTax(taxes , months);

    cout<<"===== Transaction Summary =====\n"<<endl;
    cout<<"Final Balance: "<<fixed<<setprecision(2)<<balance<<endl;
    cout<<"Total Deposits: "<<fixed<<setprecision(2)<<Total_Deposits<<endl;
    cout<<"Total Withdrawls: "<<fixed<<setprecision(2)<<Total_Withdrawls<<endl;
    cout<<"Total Tax Deducted: "<<fixed<<setprecision(2)<<Total_Tax<<endl;
}
