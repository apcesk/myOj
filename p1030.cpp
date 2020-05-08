#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
/*
    basic_string::substr
    basic_string substr(size_type _Off = 0,size_type _Count = npos) const;
    参数如下 :
    _Off : 所需的子字符串的起始位置。字符串中第一个字符的索引为 0,默认值为0。
    _Count : 复制的字符数目
    返回值 : 一个子字符串，从其指定的位置开始
    例如：
    string str1 = "hello,world";
    string str2 = str1.substr(6, 5);
    cout<<str2;
    输出结果:world;
*/
//根左右
void printPre(string mid, string aft){//用后序和中序来找先序
    //找根
    if (mid.length() > 0){//子树还有
        //输出根
        printf("%c", aft[aft.length() - 1]);
        //对中序进行拆分，找到根的位置，进行左右拆分
        int k = mid.find(aft[aft.length() - 1]);//中间节点，对它进行拆分递归
        //进行递归求解
        printPre(mid.substr(0, k), aft.substr(0, k));
        printPre(mid.substr(k + 1), aft.substr(k, mid.length() - k - 1));
    }
}
int main(){
    /*
    给出中序和后序遍历，求先序遍历
    */
    string mid,aft;
    cin>>mid;//输入中序遍历
    cin>>aft;//输入后序遍历
    printPre(mid, aft);
    return 0;
}