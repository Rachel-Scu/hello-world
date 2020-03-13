#include<iostream>
#include<cmath>
using namespace std;
class Prime {
public:
  Prime(int num);
  ~Prime();

  bool isPrime();

  Prime sumBit();
  Prime multiBit();
  Prime sqaureSumBit();
private:
  const int mNum;
};
Prime::Prime(int num):mNum(num){}
Prime::~Prime(){}
Prime Prime::sumBit(){
	int Num=mNum,sum=0;
	while(Num){
		sum+=Num%10;
		Num/=10;
	}
  	return sum;
}
Prime Prime::sqaureSumBit(){
	int Num=mNum,sum=0;
	while(Num){
		sum+=pow(Num%10,2);
		Num/=10;
	}
  	return sum;
}
Prime Prime::multiBit(){
	int Num=mNum,sum=0;
	while(Num){
		sum*=(Num%10);
		Num/=10;
	}
  	return sum;
}
bool Prime::isPrime(){
	int Num=mNum; 
	for(int i=2;i<Num;i++){
		if(Num%i==0){
			return false;
		}
	} 
  	return true;
}

int main() {
	for(int i=100;i<=9999;i++){
		Prime pm(i);
  		Prime sb = pm.sumBit();
  		Prime mb = pm.multiBit();
  		Prime ssb = pm.sqaureSumBit();
  		if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime()){
  				cout<<i<<" is super prime."<<endl;
  		}//to do sth
	}
  	return 0;
}
