//account.h
#ifndef _ACCOUNT_H__
#define _ACCOUNT_H__
#include "date.h"

class SavingsAccount {
private:
	int id;
	double balance;
	double rate;
	Date lastDate;
	double accumulation;
	static double total;
	void record(const Date &date, double amount);
	double accumulate(const Date &date) const{
		return accumulation+balance*date.distance(lastDate);
	}
public:
	SavingsAccount(const Date &date, int id, double rate);
	int getId() const {return id;}
	double getBalance() const {return balance;}
	double getRate() const {return rate;}
	static double getTotal() {return total;}
	void deposit(const Date &date, double amount);
	void withdraw(const Date &date, double amount);
	void settle(const Date &date); //结算年利率，每年1.1调用
	void show() const;
};

#endif