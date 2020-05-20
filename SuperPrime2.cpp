//��ҵ��ɾ������ļ����࣬ʹ�ü̳з���ʵ����ͬ�Ĺ��ܡ� 
#include <iostream>
class Prime {
  public:
  	Prime():number(0) {
	}
  	Prime(int n):number(n) {
	}
	~Prime() {
	}
  	virtual bool isPrime() { 
  	  //2��number-1������ 
  	  for(int i=2;i<number;i++){
  	  	if(number % i == 0)
  	  		return false; 
	  }
  	  return false;
	}
  private:
  	const int number;
}; 
class PrimeSet: public Prime {
  public:
  	PrimeSet(int size) {
  	  //���ϵĹ���ʲô�� 
  	  set = new Prime*[size];
  	  this->size = size;
  	  index = 0;
	}
	~PrimeSet() {
  	  delete[] set;
	}
 	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i]->isPrime())
  	      count += 1;
	  return count; 
	}
	
	bool add(Prime *p) {  
	  if(index == size)  return false;
	  set[index] = p;
	  index += 1;
	  return true;
	}
	bool isAllPrime() {
	  for(int i = 0; i < index; i++)
	    if (!set[i]->Prime::isPrime())
	      return false;
	  return true;
	} 
  private:
  	Prime **set;
	int size, index;
};

class SuperPrime : public Prime {
  public:
  	SuperPrime():Prime(0), pset(3) {  //Ϊʲô�����У� 
  	}
  	SuperPrime(int n):Prime(n), pset(3) {
	  // number split into N
	  int temp = n;
	  int tsum=0,tmulti=1,tsquaresum=0;
	  while(temp > 0) {
	  	int t = temp % 10;
	  	temp /= 10;
	  	//pset.add(t);  //��ҵ����������Ϊ���󣿻��Ǻ�/��/ƽ����Ϊ���� 
	  	tsum+=t;
		tmulti*=t;
		tsquaresum+=(t*t);
	  } 
	  psum=new Prime(tsum);
	  pset.add(psum);
	  pmulti=new Prime(tmulti);
	  pset.add(pmulti);
	  psquaresum=new Prime(tsquaresum); 
	  pset.add(psquaresum);
	}
  	~SuperPrime() {
	}
  	bool isPrime() {   //��/����Ľӿڣ�������˵����� 
	  if (Prime::isPrime() && pset.isAllPrime())
	    return true; 
  	  return false;
	}
  private:
  	PrimeSet pset;
  	Prime *psum;
  	Prime *pmulti;
  	Prime *psquaresum;
};
int main() {
  SuperPrime p(13);
  SuperPrime sp(113);
  PrimeSet set(2);
  set.add(&sp); 
  set.add(&p);
  std::cout << "How Many : " << set.count() << std::endl;
  return 0;
}
