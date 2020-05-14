//作业：删除多余的集合类，使用继承方法实现相同的功能。 
#include <iostream>
class Prime {
  public:
  	Prime():number(0) {
	}
  	Prime(int n):number(n) {
	}
	~Prime() {
	}
  	bool isPrime() { 
  	  //2到number-1的因子 
  	  for(int i=2;i<number;i++){
  	  	if(number%i==0)
  	  		return false;
	  } 
  	  return true;
	}
  private:
  	const int number;
}; 

class SuperPrime : public Prime {
  public:
  	SuperPrime():Prime(0){  
  	}
  	SuperPrime(int n):Prime(n){
	  // number split into N
	  int temp = n;
	  int tsum=0,tmulti=1,tsquaresum=0;
	  while(temp > 0) {
	  	int t = temp % 10;
	  	temp /= 10;
	  	tsum+=t;
		tmulti*=t;
		tsquaresum+=(t*t);
		psum=new Prime(tsum);
		pmulti=new Prime(tmulti);
		psquaresum=new Prime(tsquaresum);   //作业：单个数字为对象？还是和/积/平方和为对象？ 
	  } 
	}
  	~SuperPrime() {
	}
  	bool isPrime() {   //类/对象的接口，更抽象说是外观 
	  if (Prime::isPrime() && psum->isPrime() && pmulti->isPrime() && psquaresum->isPrime())
	    return true; 
  	  return false;
	}
  private:
  	Prime *psum;
  	Prime *pmulti;
  	Prime *psquaresum;
};
int main() {
  SuperPrime sp(113);
  if (sp.isPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
  return 0;
}
