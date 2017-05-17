#include "account.h"
#include "array.h"
#include <iostream>
using namespace std;

int main(){
	Date date(2008,11,1);
	//建立几个账户
	// SavingsAccount sa1(date,"赵晓的账户",0.015);
	// SavingsAccount sa2(date,"傻喵的账户",0.015);
	// CreditAccount ca(date,"傻狗的账户",10000,0.0005,50);
	Array<Account*> accounts(0);
	//const int n=sizeof(accounts)/sizeof(Account *); //账户总数
	cout<<"(a)add account (d) deposit (w) withdraw (s) show (c) change day (n) next month (e) exit"<<endl;
	char cmd;
	do{
		date.show();
		cout<<"\tTotal: "<<Account::getTotal()<<"\tcommand>";
		char type;
		int index, day;
		double amount,credit,rate,fee;
		Account *account;
		string id,desc;
		cin>>cmd;
		switch (cmd){
		case 'a':
			cin>>type>>id;
			if(type=='s'){
				cin>>rate;
				account=new SavingsAccount(date,id,rate);
			}else{
				cin>>credit>>rate>>fee;
				account=new CreditAccount(date,id,credit,rate,fee);
			}
			accounts.resize(accounts.getSize()+1);
			accounts[accounts.getSize()-1]=account;
			break;
		case 'd':
			cin>>index>>amount;
			getline(cin,desc);
			accounts[index]->deposit(date,amount,desc);
			break;
		case 'w':
			cin>>index>>amount;
			getline(cin,desc);
			accounts[index]->withdraw(date,amount,desc);
			break;
		case 's':
			for (int i=0;i<accounts.getSize();i++){
				cout<<"["<<i<<"]";
				accounts[i]->show();
				cout<<endl;
			}
			break;
		case 'c':
			cin>>day;
			if (day<date.getDay())
				cout<<"You cannot specify a previous day";
			else if (day>date.getMaxDay())
				cout<<"Invalid day";
			else
				date=Date(date.getYear(),date.getMonth(),day);
			break;
		case 'n':
			if (date.getMonth()==12)
				date=Date(date.getYear()+1,1,1);
			else
				date=Date(date.getYear(),date.getMonth()+1,1);
			for (int i=0;i<accounts.getSize();i++)
				accounts[i]->settle(date);
			break;
		}
	}while (cmd!='e');

	// //11月份账目
	// accounts[0].deposit(Date(2008,11,5),5000,"salary");
	// accounts[1].deposit(Date(2008,11,25),10000,"sell stock 0323");
	// ca.withdraw(Date(2008,11,15),2000,"buy a cell");
	// //结算信用卡
	// ca.settle(Date(2008,12,1));
	// //12月份账目
	// accounts[0].deposit(Date(2008,12,5),5500,"salary");
	// ca.deposit(Date(2008,12,1),2016,"pay the credit");
	// //结算并输出
	// cout<<endl;
	// for(int i=0;i<n;i++){
	// 	accounts[i].settle(Date(2009,1,1));
	// 	accounts[i].show();
	// 	cout<<endl;
	// }
	// ca.settle(Date(2009,1,1));
	// ca.show(); cout<<endl;
	for (int i=0;i<accounts.getSize();i++)
		delete accounts[i];
	return 0;
}