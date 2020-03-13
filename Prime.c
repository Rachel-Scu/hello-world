/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
//2018/11/14 更新
#include <stdio.h>
#include<math.h>
int sum_bit(int num) {
	int sum=0;
	while(num){
		sum+=num%10;
		num/=10;
	}
  	return sum;
}

int multi_bit(int num) {
	int sum=0;
	while(num){
		sum*=(num%10);
		num/=10;
	}
  	return sum;
}

int square_sum_bit(int num) {
	int sum=0;
	while(num){
		sum+=pow(num%10,2);
		num/=10;
	}
  	return sum;
}

int isprime(int num) {
	int i;
	for(i=2;i<num;i++){
		if(num%i==0){
			return 0;
		}
	} 
  	return 1;
}

int main() {
	int i; 
	for(i=100;i<=9999;i++){
		if(isprime(i)&&isprime(sum_bit(i))&&isprime(multi_bit(i))&&isprime(square_sum_bit(i))){
  			printf("%d is super prime.\n",i);
  		}
	}
    //to do sth
}
