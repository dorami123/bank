//account.h
#ifndef _ACCOUNT_H__
#define _ACCOUNT_H__
#include "date.h"
#include <string>

class SavingsAccount {
private:
	std::string id;
	double balance;
	double rate;
	Date lastDate;
	double accumulation;
	static double total;
	void record(const Date &date, double amount,const std::string &desc);
	//报告错误信息
	void error(const std::string &msg)const;
	double accumulate(const Date &date) const{
		return accumulation+balance*date.distance(lastDate);
	}
public:
	SavingsAccount(const Date &date, const std::string &id, double rate);
	std::string getId() const {return id;}
	double getBalance() const {return balance;}
	double getRate() const {return rate;}
	static double getTotal() {return total;}
	void deposit(const Date &date, double amount,const std::string &desc);
	void withdraw(const Date &date, double amount,const std::string &desc);
	void settle(const Date &date); //结算年利率，每年1.1调用
	void show() const;
};

#endif