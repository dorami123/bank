//accumulator.h
#ifndef _ACCUMULATOR_H__
#define _ACCUMULATOR_H__
#include "date.h"
class Accumulator{
private:
	Date lastDate;
	double value;
	double sum;
public:
	Accumulator(const Date& date, double value)
		:lastDate(date),value(value),sum(0){}
	double getSum(const Date& date)const{            //计算按日期累加值
		return sum+value*(date-lastDate);
	}
	void change(const Date& date,double value){      //按一次存取款变更修改累加值和value
		sum=getSum(date);
		lastDate=date;
		this->value=value;
	}
	void reset(const Date &date,double value){       //计息后累加值清0
		lastDate=date;
		this->value=value;
		sum=0;
	}
};

#endif