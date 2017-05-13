//account.cpp
#include "account.h"
#include <iostream>
#include <cmath>
using namespace std;
double SavingsAccount::total=0;

SavingsAccount::SavingsAccount(const Date &date, int id, double rate)
:id(id),balance(0),rate(rate),lastDate(date),accumulation(0){
	date.show();
	cout<<"\t#"<<id<<" is created"<<endl;
}
void SavingsAccount::record(const Date &date,double amount){
	accumulation=accumulate(date);
	lastDate=date;
	amount=floor(amount*100+0.5)/100;
	balance+=amount;
	total+=amount;
	date.show();
	cout<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}
void SavingsAccount::deposit(const Date &date, double amount){
	record(date, amount);
}
void SavingsAccount::withdraw(const Date &date, double amount){
	if (amount>getBalance())
		cout<<"Error: not enough money"<<endl;
	else
		record(date,-amount);
}
void SavingsAccount::settle(const Date &date){
	double interest=accumulate(date)*rate/date.distance(Date(date.getYear()-1,1,1));
	if (interest!=0)
		record(date,interest);
	accumulation=0;
}
void SavingsAccount::show() const{
	cout<<"#"<<id<<"\tBalance:"<<balance;
}