#include <fstream>

using namespace std;

ifstream cin("roy-floyd.in");
ofstream cout("roy-floyd.out");

int n,m,D[101][101];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            D[i][j]=1e6; ///initializam cu inf matr
    for(int i=1;i<=m;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        D[x][y]=c; ///muchiile initiale
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(D[i][k]+D[k][j]<=D[i][j]) D[i][j]=D[i][k]+D[k][j]; ///verificam toate drumurile intermediare
    for(int i=1;i<=n;i++,cout<<endl) ///afisare pt problema Roy-Floyd id 589
        for(int j=1;j<=n;j++)
            if(i==j) cout<<0<<" ";
            else if(D[i][j]==1e6) cout<<-1<<" ";
            else cout<<D[i][j]<<" ";
    return 0;
}
