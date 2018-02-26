/*input


5 9
1 2 1
2 3 3
3 4 2
4 5 2
1 5 3
1 4 6
2 3 9
2 5 10000
1 3 19

9 8
1 2 1
1 3 1
1 4 1
1 5 1
1 6 1
1 7 1
1 8 1
1 9 1

*/
#include<bits/stdc++.h>

using namespace std;

typedef long long           ll;
typedef vector<int>         vi;
typedef pair<int,int>       ii;

#define endl                '\n'
#define ff                  first
#define pf                  printf
#define ss                  second
#define MX                  309
#define pb                  push_back
#define DB                  pf("Hi\n")
#define pf1(a)              pf("%lld\n",a)
#define sc1(a)              scanf("%lld",&a)
#define mod(a,m)            (((a%m)+m)%m)
#define all(c)              (c).begin(),(c).end()
#define mem(a,b)            memset(a, b, sizeof(a))
#define RD                  freopen("trip.in","r",stdin)
#define WR                  freopen("trip.out","w",stdout)
#define rep(i,a,b)          for(int i=int(a)-(a>b);i!=(b)-(a>b);i+=1-2*(a>b))
#define TC                  int ___T,case_n = 1;scanf("%d ",&___T);while(___T-->0)

ll arr[MX][MX],arr1[MX][MX];

void init(int n)
{
   mem(arr,1);
   mem(arr1,1);
   for(int i=0;i<=n;i++)arr[i][i]=0,arr1[i][i]=0;
}

int main()
{
    //RD;
    //WR;
    //init();
    ll n,sum=0,q,a,b,w,num=0,k;

    sc1(n);
    init(n+1);
    sc1(q);

    for(int i=0;i<q;i++)
    {
       sc1(a);
       sc1(b);
       sc1(w);


       arr[a][b] = arr[b][a] = min(w,arr[a][b]);
       arr1[a][b] = arr1[b][a] = 1;
    }


    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((arr[i][k]+arr[k][j]<arr[i][j]))
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                    arr1[i][j] = arr1[i][k] + arr1[k][j];
                }
                else if((arr[i][k]+arr[k][j]==arr[i][j]))
                arr1[i][j] = min(arr1[i][j],arr1[i][k] + arr1[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            sum+=arr1[i][j];
            num++;
        }
    }
    printf("%.9f\n",(double)sum/num);
}

