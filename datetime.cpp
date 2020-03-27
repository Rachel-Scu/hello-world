#include <iostream>
class DateTime {
private:
  int year, month, day;
  int hour, minute, second;
public:
  DateTime();
  DateTime(int year,int month,int day,int hour, int minute,int  second);
  ~DateTime();
  void showTime();
  void showMoon();  //��ҵ������ǰ����ת��Ϊũ����ʾ���� 
};
int main() {
  DateTime dt, dt1(2020,3,27,10,40,55);
  dt.showTime();
  dt1.showTime();
  return 0;
}
DateTime::DateTime()
{
  year = 2020; month = 3; day = 20;
  hour = 11; minute = 27; second = 55;
}
DateTime::DateTime(int year,int month,int day,int hour, int minute,int  second){
	this->year=year;this->month=month;this->day=day;
	this->hour=hour;this->minute=minute;this->second=second;
}
DateTime::~DateTime() 
{
  std::cout << this << " Go die, Ha~Ha~" << std::endl;
}
void DateTime::showTime()
{
  printf("��ǰʱ�䣺%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
}
void DateTime::showMoon(){
	year = 2020; month = 2; day = 27;
  	hour = 11; minute = 27; second = 55;
  	showTime();
}
 
