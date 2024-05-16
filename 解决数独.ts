function solveSudoku(board: string[][]): void | string[][] {
  let result: string[][] = [];
  // 检查一个数独的行，能否放当前的数字
  function checkRow(str: string, row: number): boolean {
    for (let i = 0; i < 9; i++) {
      if (str == board[row][i]) {
        return false;
      }
    }
    return true;
  }
  // 检查一个数独的列，能否放当前的数字
  function checkColumn(str: string, column: number): boolean {
    for (let i = 0; i < 9; i++) {
      if (str == board[i][column]) {
        return false;
      }
    }
    return true;
  }
  // 检查当前所在的3*3方格内是否能放指定的数字
  function checkTxT(str: string, row: number, column: number): boolean {
    let r: number = parseInt((row / 3) + '') * 3;
    let c: number = parseInt((column / 3) + '') * 3;
    let _r: number = r + 3;
    let _c: number = c + 3;
    for (;r < _r;r++) {
      for (c = _c-3;c < _c;c++) {
        if (board[r][c] == str) {
          return false;
        }
      }
    }
    return true;
  }
  // console.log(board)
  // 递归解决
  function dfs(row: number, column: number) {
    if (column == 9) {
      row = row + 1;
      column = 0;
    }
    if (row == 9) {
      // console.log(board)
      // 到这里说明所有的格子都填数字了
      return true;
    } else if (board[row][column] == '.' || board[row][column] == '') {
      // 该位置可以放数字
      for (let i = 1;i <= 9;i++) {
        if (checkColumn(i+'', column) && checkRow(i+'', row) && checkTxT(i+'', row, column)) {
          board[row][column] = i+'';// 放值
          // 递归下一个位置
          if (dfs(row, column+1)) {
            return true;
          } else {
            // 回溯
            board[row][column] = '.';
          }
        }
      }
    } else {
      // 当前位置已经有数字了，则直接进行递归找下一个位置
      return dfs(row, column+1);
    }
  }
  dfs(0 ,0);
  return board;
};
let data:string[][] = [
  ['7','','','','','4','','2',''],
  ['','9','','','','','3','',''],
  ['','','','','','6','','','8'],
  ['','8','','9','','','','',''],
  ['','3','5','','','','','','9'],
  ['','','','','7','2','','4',''],
  ['','','9','5','2','','','',''],
  ['','','','','','','8','6','7'],
  ['1','','','3','','','','','']
]
// let data:string[][] = [
//   ['','5','6','.','7','','','','2'],
//   ['8','4','','','3','1','9','','5'],
//   ['9','3','','8','','','4','7',''],
//   ['3','8','','5','','','2','',''],
//   ['7','','','','','','1','5','4'],
//   ['5','2','1','6','','','','','3'],
//   ['','','8','','','','6','2','9'],
//   ['6','','5','1','8','','','',''],
//   ['','','3','4','','','','','8']
// ]
console.log(solveSudoku(
  data
))

// console.log(data);