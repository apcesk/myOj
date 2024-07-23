/**
 * 枚举每个数字的所有因子
 */

// int n;// n*n
// for (int i = 1;i <= n;i++) {
//   for (int j = 1;j <= i;j++) {
//     if (i % j == 0) cnt++;
//   }
// }
// int n;
// // n * sqrt(n) 10^6, 10^3
// for (int i = 1;i <= n;i++) {
//   for (int j = 1;j <= sqrt(i);j++) {
//     if (i % j == 0) cnt += 2;
//     if (j * j == i) cnt -= 1;
//   }
// }

// 1 到 n之间所有的数字，每个数字都会做因数
// 计算每个数字当因数的次数
// int cnt = 0;
// for (int i = 1;i <= n;i++) {
//   cnt += n / i;
// }