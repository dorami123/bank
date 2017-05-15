//account.cpp
#include "account.h"
#include <iostream>
#include <cmath>
using namespace std;
double Account::total=0;

// SavingsAccount::SavingsAccount(const Date &date, const string &id, double rate)
// :id(id),balance(0),rate(rate),lastDate(date),accumulation(0){
// 	date.show();
// 	cout<<"\t#"<<id<<" is created"<<endl;
// }
//Account类实现
Account::Account(const Date &date, const string &id)
:id(id),balance(0){
	date.show();
	cout<<"\t#"<<id<<" is created"<<endl;
}
// void SavingsAccount::record(const Date &date,double amount, const string &desc){
// 	accumulation=accumulate(date);
// 	lastDate=date;
// 	amount=floor(amount*100+0.5)/100;
// 	balance+=amount;
// 	total+=amount;
// 	date.show();
// 	cout<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<"\t"<<desc<<endl;
// }
void Account::record(const Date &date,double amount, const string &desc){
	amount=floor(amount*100+0.5)/100;
	balance+=amount;
	total+=amount;
	date.show();
	cout<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<"\t"<<desc<<endl;
}
void Account::error(const string &msg)const{
	cout<<"Error(#"<<id<<"):"<<msg<<endl;
}
// void SavingsAccount::deposit(const Date &date, double amount,const string &desc){
// 	record(date, amount, desc);
// }
// void SavingsAccount::withdraw(const Date &date, double amount,const string &desc){
// 	if (amount>getBalance())
// 		error("Error: not enough money");
// 	else
// 		record(date,-amount,desc);
// }
// void SavingsAccount::settle(const Date &date){
// 	double interest=accumulate(date)*rate/date.distance(Date(date.getYear()-1,1,1));
// 	if (interest!=0)
// 		record(date,interest,"interest");
// 	accumulation=0;
// }
void Account::show() const{
	cout<<"#"<<id<<"\tBalance:"<<balance;
}
//SavingsAccount类相关成员函数实现
SavingsAccount::SavingsAccount(const Date&date, const string &id,double rate)
	:Account(date,id),rate(rate),acc(date,0){
}
void SavingsAccount::deposit(const Date &date,double amount, const string &desc){
	record(date,amount,desc);
	acc.change(date,getBalance());
}
void SavingsAccount::withdraw(const Date &date,double amount, const string &desc){
	if (amount>getBalance())
		error("Error: not enough money");
	else{
		record(date,-amount,desc);
		acc.change(date,getBalance());}
}
void SavingsAccount::settle(const Date &date){
	double interest=acc.getSum(date)*rate
		/date.distance(Date(date.getYear()-1,1,1));
	if (interest!=0) record(date,interest,"interest");
	acc.reset(date,getBalance());
}

//CreditAccount 类相关成员函数的实现
CreditAccount::CreditAccount(const Date&date, const string &id,double credit,double rate,double fee)
	:Account(date,id),credit(credit),rate(rate),fee(fee),acc(date,0){}
void CreditAccount::deposit(const Date &date,double amount, const string &desc){
	record(date,amount,desc);
	acc.change(date,getDebt());
}
void CreditAccount::withdraw(const Date &date, double amount,const string &desc){
	if (amount>getBalance()+credit)
		error("Error: not enough credit");
	else{
		record(date,-amount,desc);
		acc.change(date,getDebt());
	}
}
void CreditAccount::settle(const Date&date){
	double interest=acc.getSum(date)*rate;  //按日计息
	if (interest!=0) record(date,interest,"interest");
	if (date.getMonth()==1)
		record(date,-fee,"annual fee");
	acc.reset(date,getDebt());
}
void CreditAccount::show() const{
	Account::show();
	cout<<"\tAvailable credit:"<<getAvailableCredit();
}