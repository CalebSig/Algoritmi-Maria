#include <fstream>
using namespace std;

ifstream cin("dijkstra.in");
ofstream cout("dijkstra.out");

int A[105][105],D[105],n,p,Q[1001],st,dr;

void dijkstra(int p)
{
    for(int i=1;i<=n;i++)
        D[i]=1e6;
    D[p]=0;
    Q[++st]=p;
    dr=1;
    while(st<=dr)
    {
        int varf=Q[st++];
        for(int nou=1;nou<=n;nou++)
            if(A[varf][nou] && D[nou]>D[varf]+A[varf][nou])
            {
                Q[++dr]=nou;
                D[nou]=D[varf]+A[varf][nou];
            }
    }
}

int main()
{

    cin>>n>>p;
    int a,b,c;
    while(cin>>a>>b>>c) A[a][b]=c;
    dijkstra(p);
    for(int i=1;i<=n;i++)
        if(D[i]==1e6) cout<<"-1 ";
        else cout<<D[i]<<" ";
    return 0;
}
