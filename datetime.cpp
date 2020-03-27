#include <iostream>
class DateTime {
private:
  static int sth;
  int year, month, day;
  int hour, minute, second; 
public:
  DateTime();
  DateTime(int year,int month,int day,int hour, int minute,int  second);
  DateTime(const DateTime &dt);
  ~DateTime();
  void showTime();
};
int DateTime::sth=0;
int main() {
  //只有三个对象 
  DateTime dt, dt1(2020,3,27,10,40,55);
  DateTime dt2(dt1),&dt3=dt;    // 引用 不是一个实际对象 
  DateTime *dt4=&dt;    //指针 不是一个实际对象 
  dt.showTime();
  dt1.showTime();
  dt2.showTime();
  dt3.showTime();
  dt4->showTime();
  return 0;
}
DateTime::DateTime()
{
  year = 2020; month = 3; day = 20;
  hour = 11; minute = 27; second = 55;
  sth=11;
  std::cout<<"1-Constructor called"<<std::endl;
}
DateTime::DateTime(int year,int month,int day,int hour, int minute,int  second){
	this->year=year;this->month=month;this->day=day;
	this->hour=hour;this->minute=minute;this->second=second;
	std::cout<<"2-Constructor called"<<std::endl;
}
DateTime::DateTime(const DateTime &dt){
	year=dt.year;month=dt.month;day=dt.day;
	hour=dt.hour;minute=dt.minute;second=dt.second;
	std::cout<<"Copy constructor called"<<std::endl;
}
DateTime::~DateTime() 
{
  std::cout << "Destrucor called" << std::endl;
}
void DateTime::showTime()
{
  printf("当前时间：%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
  std::cout<<sth<<std::endl;
}

 
