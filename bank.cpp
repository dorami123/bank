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
	const int n=sizeof(accounts)/sizeof(SavingsAccount);
	//11月份账目
	accounts[0].deposit(Date(2008,11,5),5000,"salary");
	accounts[1].deposit(Date(2008,11,25),10000,"sell stock 0323");
	//12月份账目
	accounts[0].deposit(Date(2008,12,5),5500,"salary");
	accounts[1].withdraw(Date(2008,12,20),4000,"buy a laptop");
	//结算并输出
	cout<<endl;
	for(int i=0;i<n;i++){
		accounts[i].settle(Date(2009,1,1));
		accounts[i].show();
		cout<<endl;
	}
	cout<<"Total:"<<SavingsAccount::getTotal()<<endl;
	return 0;
}