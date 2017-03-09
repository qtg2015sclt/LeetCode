int **ary = new int*[row_num];
for(int i = 0;i < row_num;i++)
  ary[i] = new int[col_num];

vector<vector<int> > ary(row_num, vector<int>(col_num, 0));
