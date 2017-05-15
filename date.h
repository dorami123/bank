//date.h
#ifndef _DATE_H__
#define _DATE_H__
class Date{
private:
	int year;
	int month;
	int day;
	int totalDays;
public:
	Date(int year,int month,int day);
	int getYear() const {return year;}
	int getMonth() const {return month;}
	int getDay() const {return day;}
	int getMaxDay() const;
	bool isLeapYear() const {
		return (year%4==0 && year%100!=0)||year%400==0;
	} //判断是否为闰年
	void show() const;
	//计算两个日期相差天数
	int operator -(const Date& date) const{
		return totalDays-date.totalDays;
	}
};


#endif