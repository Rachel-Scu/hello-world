//作业：完成以下框架的代码细节，程序能编译运行得到正确结果 
#include <iostream>
using namespace std;
class SuperPrime {
  public:
  	SuperPrime():number(0),size(0) {
  		//cout<<"constructor called"<<endl;
	}
  	~SuperPrime() {
  		//cout<<"destuctor called"<<endl;
	}
  	bool isSuperPrime() {
  	  split();
  	  int a = sum();
	  int b = multi();
	  int c = squareSum();
	  //cout<<"The number "<<number<<" : "<<"a:"<<a<<" "<<"b:"<<b<<" "<<"c:"<<c<<endl;
	  if (isPrime(number) && isPrime(a) && isPrime(b) && isPrime(c)){
	  	return true; 
	  }
  	  return false;
	}
	int GetNumber(){
		return number;
	}
	int SetNumber(int setnum){
		number=setnum;
	}
  private:
  	int number;
  	int N[100], size;
  	bool isPrime(int n) { 
  	  for(int i = 2; i < n; i++){
        if (n % i == 0) 
            return false;
      }
    	return true;
	}
	void split() {
	  // number split into N
	  int Number=number;
	  int i=0;
	  while(Number>0){
	  	N[i]=Number%10;
	  	Number/=10;
	  	i++;
	  	size++;
	  }
	}
	int sum() {
	  int s=0;
	  for(int i=0;i<size;i++){
	  	s+=N[i];
	  }	
	  return s;
	}
	int multi() {
	  int mul=1;
	  for(int i=0;i<size;i++){
	  	mul*=N[i];
	  }
	  return mul;
	}
	int squareSum() {
	  int ss=0;
	  for(int i=0;i<size;i++){
	  	ss=ss+N[i]*N[i];
	  }
	  return ss;
	}
};
class Set {
  public:
  	Set(int from, int to){
  	  size = to-from+1;
  	  From=from;
  	  To=to; 
	}
  	~Set() {
	}
  	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++){
  	  	set[i].SetNumber(i+From);
  	    if(set[i].isSuperPrime())
  	      count += 1;
	  }
	  return count; 
	}
  	int sum() {
  	  int sum = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i].isSuperPrime())
  	      sum += set[i].GetNumber(); 
	  return sum; 
	}
  private:
  	SuperPrime set[1000];
  	int size;
  	int From,To; 
};
int main() {
  Set ss(100, 999);    //求从100到999之间的超级素数 
  std::cout << "How Many: " << ss.count() << std::endl;
  std::cout << "Sum is " << ss.sum() << std::endl;
  return 0;
}
