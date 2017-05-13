//account.cpp
#include "account.h"
#include <iostream>
#include <cmath>
using namespace std;
double SavingsAccount::total=0;

SavingsAccount::SavingsAccount(const Date &date, const string &id, double rate)
:id(id),balance(0),rate(rate),lastDate(date),accumulation(0){
	date.show();
	cout<<"\t#"<<id<<" is created"<<endl;
}
void SavingsAccount::record(const Date &date,double amount, const string &desc){
	accumulation=accumulate(date);
	lastDate=date;
	amount=floor(amount*100+0.5)/100;
	balance+=amount;
	total+=amount;
	date.show();
	cout<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<"\t"<<desc<<endl;
}
void SavingsAccount::error(const string &msg)const{
	cout<<"Error(#"<<id<<"):"<<msg<<endl;
}
void SavingsAccount::deposit(const Date &date, double amount,const string &desc){
	record(date, amount, desc);
}
void SavingsAccount::withdraw(const Date &date, double amount,const string &desc){
	if (amount>getBalance())
		error("Error: not enough money");
	else
		record(date,-amount,desc);
}
void SavingsAccount::settle(const Date &date){
	double interest=accumulate(date)*rate/date.distance(Date(date.getYear()-1,1,1));
	if (interest!=0)
		record(date,interest,"interest");
	accumulation=0;
}
void SavingsAccount::show() const{
	cout<<"#"<<id<<"\tBalance:"<<balance;
}