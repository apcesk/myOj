#include<iostream>
using namespace std;
// 这是一个结构体，把它想想是一个对象
struct ditan{
	int a,b,g,k;//a,b表示地毯的左下角坐标,g,k代表在坐标轴上的长度 
}D[10001];
int n;//代表有n张地毯
int x,y;//表示所求点的坐标，覆盖在最上面的地毯是哪一个 
int main()
{
	cin>>n;
	for(int i = 0;i < n;i++){
    // 输入铺设一块地毯的起点坐标和所占的长度和宽度
		cin>>D[i].a>>D[i].b>>D[i].g>>D[i].k;
	}
	cin>>x>>y;//录入指定的坐标
	int whr = -1;// 记录覆盖指定点的地毯的下标
	bool flag = 0;// 标记当前的点是否被地毯覆盖，默认为0，代表没有被覆盖
	//如果想要覆盖该点，那么地毯的起始坐标应该 a <= x  b <= y a+g>=x b+k>=y;
	for(int i = 0;i < n;i++){
		if(D[i].a <= x && D[i].b <= y && D[i].a + D[i].g >= x && D[i].b + D[i].k >= y){
			//记录当前的i
			whr = i;
			flag = 1;
		}
	} 
	if(flag){
		cout<<whr+1;
	}else{
		cout<<-1;
	}
	return 0;
}

