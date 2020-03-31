#include <iostream>
#include"mooncal.h"
using namespace std; 
class DateTime {
	private:
  		int year,month,day;
  		int hour,minute,second; 
		int seconds;     //从1970年1月1日0时开始计算的秒数 
	public:
  		DateTime();
  		DateTime(int y, int m, int d, int hour, int minute, int second); 
  		int GetSeconds();  //得到seconds的值 
  		DateTime(const DateTime &dt);
  		~DateTime();
  		void showTime();
  		void showMoon();  //作业：将当前公历转换为农历显示出来 
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
	printf("当前时间：%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
}
void DateTime::showMoon(){
	//#include"mooncal.h"
	const char *ChDay[] = {"*","初一","初二","初三","初四","初五",
	                       "初六","初七","初八","初九","初十",
	                       "十一","十二","十三","十四","十五",
	                       "十六","十七","十八","十九","二十",
	                       "廿一","廿二","廿三","廿四","廿五",
	                       "廿六","廿七","廿八","廿九","三十"
	                      };
	const char *ChMonth[] = {"*","正","二","三","四","五","六","七","八","九","十","十一","腊"};
	char str[13] = "";
	if (LunarCalendar(year,month,day))
	{
		strcat(str,"闰");
		strcat(str,ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
	}
	else
		strcat(str,ChMonth[(LunarCalendarDay & 0x3C0) >> 6]);
	strcat(str,"月");
	strcat(str,ChDay[LunarCalendarDay & 0x3F]);
	printf("当前时间(农历)：");
	puts(str);
}
