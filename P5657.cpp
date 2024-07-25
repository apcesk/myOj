#include<iostream>
int n;
unsigned long long k;
int main(){
   	std::cin>>n>>k;
    k^=k>>1;
    while(~--n)std::cout<<(k>>n&1);
    return 0;
}