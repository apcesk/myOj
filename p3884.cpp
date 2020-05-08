#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n;//输入共有n个节点
int map[101][3];//map[i][0]->代表i点的左子树，map[i][1]代表i点的右子树，map[i][2]代表该节点的父节点
bool _map[101];//表示该节点是否被访问过,0代表没有访问过
int wild[101];//100个节点深度最深为100
int from, to;//代表从哪个节点到哪个节点
struct node{
    int p, deep;//p代表当前节点的值，deep代表当前节点的深度
};
queue<node> q;//创建一个队列q
int deep;//deep代表树的深度，wild代表树的宽度。
//广搜求深度和宽度
void bfs(int t){//传入广搜的节点
    q.push((node){t, 1});//根节点入队
    _map[t] = 1;//标记根节点已经被访问过
    while (!q.empty()){//只要队不为空
        node now_node = q.front();//取出当前的节点
        //当前节点的左右子树入队
        if (map[now_node.p][0] && !_map[map[now_node.p][0]]) {//有左子树切左子树没有被访问过
            q.push((node){map[now_node.p][0], now_node.deep+1});//左子节点入队
            _map[map[now_node.p][0]] = 1;//标记该节点
        }
        if (map[now_node.p][1] && !_map[map[now_node.p][1]]) {//有右子树且右子树没有被访问过
            q.push((node){map[now_node.p][1], now_node.deep + 1});//右子节点入队
            _map[map[now_node.p][1]] = 1;//标记该节点
        }
        deep = max(deep, now_node.deep);//保存树的深度
        wild[now_node.deep]++;//当前深度的元素+1，记录当前深度的宽度;
        q.pop();//出队
    }
}

int find_father(int f, int t){//两个参数，代表从哪个位置到哪个位置
	//找到两个节点的公共父亲
    int f_father_list[101];//存放f的所有父级节点
    int t_father_list[101];//存放t的所有父级节点
    f_father_list[1] = map[f][2];//第一个f的父节点(不包括自身)
    f_father_list[0] = f;//标记自己为父节点
    t_father_list[1] = map[t][2];//第一个t的父节点(不包括自身)
    t_father_list[0] = t;//标记自己为父节点
	for (int i = 2;i <= n;++i){
        f_father_list[i] = map[f_father_list[i - 1]][2];
        t_father_list[i] = map[t_father_list[i - 1]][2];
    }
    //接下来从已有的所有f的父亲中找到t的父亲
    for (int i = 0;i <= n && f_father_list[i] != 0;++i){
        for (int j = 0;j <= n && t_father_list[j] != 0;++j){
            if (f_father_list[i] == t_father_list[j]){//找到了相同的父亲节点
                return i*2 + j;
            }
        }
    }
    // return 0;
}
int main(){
    scanf("%d", &n);
    for (int i = 1;i < n;i++){
        int p, t;
        scanf("%d %d", &p, &t);
        if (!map[p][0]){//优先输入左子树
            map[p][0] = t;
        }else{//如果该节点的左子树存在则输入右子树
            map[p][1] = t;
        }
        map[t][2] = p;//t节点的父亲为p
    }
    bfs(1);//找深度和宽度
    int max_wild = 0;
    for (int i = 1;i <= 100;++i){//得出最大宽度
    	if (wild[i] > max_wild){
    		max_wild = wild[i];
		}
	}
    scanf("%d %d", &from, &to);//输入两个节点
    printf("%d\n%d\n", deep, max_wild);//输出深度和宽度
    //找路径
    printf("%d", find_father(from, to));
    return 0;
}