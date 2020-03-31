#include <iostream>
#include"mooncal.h"
using namespace std; 
class DateTime {
	private:
  		int year,month,day;
  		int hour,minute,second; 
		int seconds;     //��1970��1��1��0ʱ��ʼ��������� 
	public:
  		DateTime();
  		DateTime(int y, int m, int d, int hour, int minute, int second); 
  		int GetSeconds();  //�õ�seconds��ֵ 
  		DateTime(const DateTime &dt);
  		~DateTime();
  		void showTime();
  		void showMoon();  //��ҵ������ǰ����ת��Ϊũ����ʾ���� 
};

int main() {
	DateTime dt, dt1(2020, 3, 27, 10, 40, 55);
	DateTime dt2(dt), &dt3 = dt;
	DateTime *dt4 = &dt;
	dt.showTime();
	dt.showMoon();
	dt1.showTime();
	dt1.showMoon();
	dt2.showTime();
	dt2.showMoon();
	dt3.showTime();
	dt3.showMoon();
	dt4->showTime();
	dt4->showMoon();
	return 0;
}
DateTime::DateTime()
{
	year=1970;month=1;day=1;
	hour=0;minute=0;second=0;
	seconds=0;
}
DateTime::DateTime(int y, int m, int d, int hour, int minute, int second)
{
	year=y;month=m;day=d;
	this->hour=hour;this->minute=minute;this->second=second;
	this->seconds=this->GetSeconds();
}
DateTime::DateTime(const DateTime &dt)
{
	year=dt.year;month=dt.month;day=dt.day;
	hour=dt.hour;minute=dt.minute;day=dt.day;
	seconds=dt.seconds;
}
int DateTime::GetSeconds()
{
	int Day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int seconds=0;
	if(year%400==0 || (year%4==0&&year%400!=0))
		Day[2]=29;
	seconds=(year-1970)*31536000;
	for(int i=1;i<month;i++)
		seconds+=86400*Day[i];
	seconds=seconds+(day-1)*86400+hour*3600+minute*60+second;
	return seconds;
}
DateTime::~DateTime() 
{
	cout << " Go die, Ha~Ha~" <<endl;
}
void DateTime::showTime()
{
	printf("��ǰʱ�䣺%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
}
void DateTime::showMoon(){
	//#include"mooncal.h"
	const char *ChDay[] = {"*","��һ","����","����","����","����",
	                       "����","����","����","����","��ʮ",
	                       "ʮһ","ʮ��","ʮ��","ʮ��","ʮ��",
	                       "ʮ��","ʮ��","ʮ��","ʮ��","��ʮ",
	                       "إһ","إ��","إ��","إ��","إ��",
	                       "إ��","إ��","إ��","إ��","��ʮ"
	                      };
	const char *ChMonth[] = {"*","��","��","��","��","��","��","��","��","��","ʮ","ʮһ","��"};
	char str[13] = "";
	if (LunarCalendar(year,month,day))
	{
		strcat(str,"��");
		strcat(str,ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
	}
	else
		strcat(str,ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
	strcat(str,"��");
	strcat(str,ChDay[LunarCalendarDay & 0x3F]);
	printf("��ǰʱ��(ũ��)��");
	puts(str);
}