#include "account.h"
#include <iostream>
using namespace std;

int main(){
	Date date(2008,11,1);
	//建立几个账户
	SavingsAccount accounts[]={
		SavingsAccount(date,"赵晓的账户",0.015),
		SavingsAccount(date,"傻喵的账户",0.015)
	};
	CreditAccount ca(date,"傻狗的账户",10000,0.0005,50);
	const int n=sizeof(accounts)/sizeof(SavingsAccount);
	//11月份账目
	accounts[0].deposit(Date(2008,11,5),5000,"salary");
	accounts[1].deposit(Date(2008,11,25),10000,"sell stock 0323");
	ca.withdraw(Date(2008,11,15),2000,"buy a cell");
	//结算信用卡
	ca.settle(Date(2008,12,1));
	//12月份账目
	accounts[0].deposit(Date(2008,12,5),5500,"salary");
	ca.deposit(Date(2008,12,1),2016,"pay the credit");
	//结算并输出
	cout<<endl;
	for(int i=0;i<n;i++){
		accounts[i].settle(Date(2009,1,1));
		accounts[i].show();
		cout<<endl;
	}
	ca.settle(Date(2009,1,1));
	ca.show(); cout<<endl;
	cout<<"Total:"<<Account::getTotal()<<endl;
	return 0;
}