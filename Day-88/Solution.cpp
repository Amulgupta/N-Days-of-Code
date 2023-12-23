#include<iostream>

using namespace std;

#define MAX 128
long long mat[MAX][MAX],mat1[MAX][MAX],mat2[MAX][MAX];
int n;

void bigmod(long long p,long long m)
{
      long long int i,j,k;
      if (p == 0)
      {
          for(i=0;i<(1<<n);i++)mat[i][i]=1;
          return ;
      }

      else if (p%2 == 0)
      {
            bigmod(p/2,m);
            for(i=0;i<(1<<n);i++)
            for(j=0;j<(1<<n);j++)
            {
                mat2[i][j]=0;
                    for(k=0;k<(1<<n);k++)
                    {
                        long long x=(mat[i][k]*mat[k][j]);
                        if(x>=m)x%=m;
                        mat2[i][j]=(mat2[i][j]+x);
                        if(mat2[i][j]>=m)mat2[i][j]%=m;
                    }
            }
            for(i=0;i<(1<<n);i++)
            for(j=0;j<(1<<n);j++)
            {
                mat[i][j]=mat2[i][j];
            }
            return ;
       }
      else
      {
            bigmod(p-1,m);
            for(i=0;i<(1<<n);i++)
            for(j=0;j<(1<<n);j++)
            {
                mat2[i][j]=0;
                    for(k=0;k<(1<<n);k++)
                    {
                        long long x=(mat1[i][k]*mat[k][j]);
                        if(x>=m)x%=m;
                        mat2[i][j]=(mat2[i][j]+x);
                        if(mat2[i][j]>=m)mat2[i][j]%=m;
                    }
            }
            for(i=0;i<(1<<n);i++)
            for(j=0;j<(1<<n);j++)
            {
                mat[i][j]=mat2[i][j];
            }

        return;
        }
}

int chk(int ix,int jx)
{
    int lix=-1;int ljx=-1;
    for(int i=0;i<n;i++)
    {
        if(ix%2==lix&&jx%2==ljx&&lix==ljx)return 0;
        lix=ix%2;ljx=jx%2;
        ix/=2;jx/=2;
    }
    return 1;
}

int main()
{

    long long m;
    cin>>n>>m;
    {

        for(int i=0;i<(1<<n);i++)
            for(int j=0;j<(1<<n);j++)
            {
                mat1[i][j]=chk(i,j);
            }
            long long MOD=1000000007;
            bigmod(m-1,MOD);
            long long sum=0;

            for(int i=0;i<(1<<n);i++)
            {
                for(int j=0;j<(1<<n);j++)
                {
                    sum=(sum+mat[i][j])%MOD;
                }
            }

            cout<<sum<<endl;


    }
return 0;
}
