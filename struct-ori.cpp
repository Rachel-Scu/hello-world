#include<iostream>
using namespace std;
class DateTime{
	private:
		int year,month,day;
		int hour,minute,second;
	public:
		DateTime();
		~DateTime();
		void showTime(); 
		void showMoon();   
}; 
int main(){
	DateTime dt,dt1;
	dt.showTime();
	dt1.showMoon();  
	return 0;
}
DateTime::DateTime(){
	cout<<this<<endl;
	year=2020;month=3;day=20;
	hour=11;minute=46;second=55;
}
DateTime::~DateTime(){
	cout<<this<<"Desrtuctor called"<<endl;
}
void DateTime::showMoon(){
	year=2020;month=2;day=27;
	hour=11;minute=46;second=55;
	showTime();
}
void DateTime::showTime(){
	printf("当前时间：%d/%d/%d %d:%d:%d\n",year,month,day,hour,minute,second);
}
