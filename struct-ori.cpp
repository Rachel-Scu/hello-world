#include<iostream>
using namespace std;
class DateTime{
	private:
		int year,month,day;
		int hour,minute,second;
	public:
		void inTime();
		void showTime();    //static 只能在该.cpp中使用 
}; 
int main(){
	DateTime dt,dt1;
	dt.inTime();
	dt.showTime();
	dt1.inTime();
	dt1.showTime();  
	return 0;
}
void DateTime::inTime(){
	year=2020;month=3;day=13;
	hour=10;minute=25;second=55;
}
void DateTime::showTime(){
	printf("当前时间：%d/%d/%d %d:%d:%d\n",year,month,day,hour,minute,second);
}
