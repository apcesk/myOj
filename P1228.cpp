/**
 * P1228 地毯填补问题
 */
#include<iostream>

using namespace std;
/*  
	地毯形式： 
		1: 1 1
		   1 0

		2: 1 1
		   0 1

		3: 0 1
		   1 1

		4: 1 0
		   1 1
	
	----------
	考虑最小的地毯
	2 * 2地毯，有任何一个位置不能放置的情况下，都可以使用一块地毯进行填补。
	考虑是4 * 4的地毯。
	折合一下，这是4个2*2地毯。
	已知有一个位置不能放置，那个位置必然处于4个2*2的位置之一。
	那么对于剩余的3个2*2的，能否铺成即为最重要的部分。
	由图得出，剩余的3个2*2的，可以由4种不同的地毯铺成。
	---------
	任意的2^k * 2^k次方的地毯，都可以被降低成4个更小的。
	-----
	分治求解
	已知矩阵的起点是1，1，长度为len(2的次方数)
	那么左上角的矩阵是 起点：sx,sy, 终点：len/2, len/2            1,1 => 2, 2
	那么右上角的矩阵是 起点：sx, sy+len/2, 终点： len/2, len      1,3 => 2, 4
	那么左下角的矩阵是 起点：sx+len/2, sy, 终点： len, len/2      3,1 => 4, 2
	那么右下角的矩阵是 起点：sx+len/2, sy+len/2, 终点：len, len   3,3 => 4, 4
	// 带入一个4*4的大小矩阵进去
	1,1	1,2	1,3	1,4
	2,1	2,2	2,3	2,4
	3,1	3,2	3,3	3,4
	4,1	4,2	4,3	4,4
*/
#define int long long
const int N = 1e3 + 10;
int k, x, y, len;// 2^k次方，公主在x，y
int mitrix[N][N];
// x,y是公主所在的位置(也想像成每个矩形中缺失的角，sx和sy代表当前矩阵的起点
void dfs(int x, int y, int sx, int sy, int len) {// 填补地毯
	if (len == 1) return ;// 长度为1，不可能。
	// 否则，先判断公主在哪个更小的矩阵中
  // 1,1 公主， 矩阵2*2
  // 1 - 1 = 0, 1 - 1 = 0
	if (x - sx <= len / 2 - 1 && y - sy <= len / 2 - 1) {// 此时公主在左上角的矩阵中。
		// 代入数据验证，假设矩阵大小是2*2
		// 在四个矩阵交汇的中间点，填充1号地毯
		printf("%lld %lld 1\n", sx + len / 2, sy + len / 2);// 当前公主在左上角。
    // 说明右上、左下、右下三个矩阵是要缺失一角的。
		dfs(x, y, sx, sy, len / 2);// 左上角 1, 1, 2 => (1,1) -> (2,2)
		// 让右上角的矩阵，缺失左下角
		dfs(sx + len / 2 - 1, sy + len / 2, sx, sy + len / 2, len / 2);//右上角 空缺位置: (2, 3), 矩阵：(1, 3) => (2, 4);
		// 让左下角的矩阵，缺失右上角
		dfs(sx + len / 2, sy + len / 2 - 1,sx + len / 2, sy, len / 2);//左下角 空缺位置: (3, 2) (3, 1) => (4, 2);
		// 让右下角的矩阵，缺失左上角
		dfs(sx + len / 2, sy + len / 2, sx + len / 2, sy + len / 2,len / 2);//右下角 空缺位置: (3, 3) (3, 3) => (4,4);
	} else if (x - sx <= len / 2 - 1 && y - sy > len / 2 - 1) {// 此时公主在右上角的矩阵中
		// 同理，在四个矩阵交汇的中间点，填充2号地毯
		printf("%lld %lld 2\n", sx + len / 2, sy + len / 2 - 1);// 2号形态的地毯拐角在左下角
		// 左上角的矩阵，缺失右下角
		dfs(sx + len / 2 - 1, sy + len / 2 - 1, sx, sy, len / 2); 
		// 右上角的矩阵，保持原样
		dfs(x, y, sx, sy + len / 2, len / 2);
		// 左下角的矩阵，缺失右上角
		dfs(sx + len / 2, sy + len / 2 - 1, sx + len / 2, sy, len / 2);
		// 右下角的矩阵，缺失左上角
		dfs(sx + len / 2, sy + len / 2, sx + len / 2, sy + len / 2, len / 2);
	} else if (x - sx > len / 2 - 1 && y - sy <= len / 2 - 1) {// 此时公主在左下角中
		// 此时左下角有公主，让另外三个矩阵缺失。则需要填补3号地毯
		printf("%lld %lld 3\n", sx + len / 2 - 1, sy + len / 2);
		// 左上角的矩阵缺失右下角
		dfs(sx + len / 2 - 1, sy + len / 2 - 1, sx, sy, len / 2); 
		// 右上角的矩阵缺失左下角
		dfs(sx + len / 2 - 1, sy + len / 2, sx, sy + len / 2, len / 2);
		// 左下角矩阵保持不变
		dfs(x, y, sx + len / 2, sy, len / 2);
		// 右下角矩阵缺失左上角
		dfs(sx + len / 2, sy + len / 2, sx + len / 2, sy + len / 2, len / 2);
	} else {// 公主在右下角的矩阵
		printf("%lld %lld 4\n", sx + len / 2 - 1, sy + len / 2 - 1);
		// 	左上角的矩阵缺失右下角
		dfs(sx + len / 2 - 1, sy + len / 2 - 1, sx, sy, len / 2); 
		// 右上角的矩阵缺失左下角
		dfs(sx + len / 2 - 1, sy + len / 2, sx, sy + len / 2, len / 2);
		// 左下角的矩阵缺失右上角
		dfs(sx + len / 2, sy + len / 2 - 1, sx + len / 2, sy, len / 2);
		// 右下角矩阵不变
		dfs(x, y, sx + len / 2, sy + len / 2, len / 2);
	}
}
signed main() {
  cin >> k >> x >> y;
  len = 1 << k;// 矩阵的大小
  dfs(x, y, 1, 1, len);
  return 0;
}
/**
DDDDD           IIIIII        OOOOOOOO
DD  DD            II          OO    OO
DD   DD           II          OO    OO
DD    DD          II          OO    OO
DD    DD          II          OO    OO
DD    DD          II          OO    OO
DD   DD           II          OO    OO
DD  DD            II          OO    OO
DDDDD           IIIIII        OOOOOOOO
*/