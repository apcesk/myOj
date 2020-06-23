#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map <string, string> m;// 映射关系m[a] = b; 代表a的祖先为b
string find(string x) // 寻找x的祖先
{
    if (x != m[x]) // 如果当前这个人的祖宗不是自己，则说明他的祖宗另有其人
    {
        m[x] = find(m[x]);// 则让他的祖宗修改为最大级别的祖宗
    }
    return m[x];// 返回祖宗元素
}
string s,s1;
int main()
{
    char ch;
    cin>>ch;// 输入第一个字符
    while (ch != '$')// 如果不是$则说明还要继续输入
    {
        cin>>s;
        if (ch == '#')// 如果输入的是# 则说明当前这个人，是个祖宗
        {
            s1 = s;// 保存一下当前的字符串
            if (m[s] == "") m[s] = s;// 并且判断当前这个祖宗有没有"祖宗"，如果没有就让他自己作为祖宗
        }
        else if (ch == '+')// 如果输入的是+ 则说明当前这个人是个孙子
        {
            m[s] = s1;// 孙子的祖宗指向s1
        }
        else
        {
            cout<<s<<' '<<find(s)<<endl;// 输出当前的人和他的祖宗
        }
        cin>>ch;
        
        
    }
    return 0;
}
