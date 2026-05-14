#include <bits/stdc++.h>

using namespace std;

int main()
{
        int l , m ;  // 马路长度l  区域数目m
        cin >> l >> m ;
        int u[m] , v[m] ;       //创建数组容纳数据 可是我想用数组的方式来表示树木是否存在 且树木存在为1 不存在为0 最后查找1的数量
        for (int i = 0 ; i < m ; i++)
        {
                cin >> u[i] >> v[i] ;
        }
        int tree[l+1]; // 因为树木数=长度l+1
        for (int i = 0 ; i <= l ; i++)
                tree[i] = 1 ;           //树木初始化完成
        for (int i = 0 ; i < m ; i++)
        {
                for (int j=u[i];j<=v[i];j++)
                        tree[j]=0;
        }
        int sum = 0 ;
        for (int i=0;i<=l;i++)
        {
                if (tree[i]==1)
                        sum+=1;
        }
        cout<<sum<<endl ;
}