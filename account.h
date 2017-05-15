//account.h
#ifndef _ACCOUNT_H__
#define _ACCOUNT_H__

#include "date.h"
#include "accumulator.h"
#include <string>

class Account {
private:
	std::string id;
	double balance;
	static double total;
protected:
	Account(const Date &date,const std::string &id);
	void record(const Date &date,double amount,const std::string &desc);
	void error(const std::string &msg)const;
public:
	const std::string &getId() const {return id;}
	double getBalance() const {return balance;}
	static double getTotal() {return total;}
	virtual void deposit(const Date &date,double amount, const std::string &desc)=0;
	virtual void withdraw(const Date &date, double amount,const std::string &desc)=0;
	virtual void settle(const Date&date)=0;
	virtual void show() const;
};


class SavingsAccount: public Account{
private:
	Accumulator acc;
	double rate;
public:
	SavingsAccount(const Date&date, const std::string &id,double rate);
	double getRate() const {return rate;}
	//存入
	void deposit(const Date &date, double amount,const std::string &desc);
	//取出
	void withdraw(const Date &date, double amount,const std::string &desc);
	void settle(const Date &date); //结算年利率，每年1.1调用
};

class CreditAccount: public Account{
private:
	Accumulator acc;  //计息工具
	double credit;  //信用额度
	double rate;   //欠款日利率
	double fee;  //信用卡年费
	double getDebt() const{
		double balance=getBalance();
		return (balance<0?balance:0);
	}
public:
	CreditAccount(const Date&date, const std::string &id,double credit,double rate,double fee);
	double getCredit() const {return credit;}
	double getRate() const {return rate;}
	double getFee() const {return fee;}
	double getAvailableCredit() const{
		if (getBalance()<0)
			return credit+getBalance();
		else return credit;
	}
	//存入
	void deposit(const Date &date, double amount,const std::string &desc);
	//取出
	void withdraw(const Date &date, double amount,const std::string &desc);
	void settle(const Date &date);
	void show() const;
};
#endif