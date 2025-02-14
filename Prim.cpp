#include <fstream>
using namespace std;

ifstream cin("prim.in");
ofstream cout("prim.out");

int A[105][105],n,m,s,T[105],P[105],val[105];

int nmin(int P[],int val[])
{
    int q=1e9,vmin;
    for(int i=1;i<=n;i++)
        if(!P[i] && val[i]<q)
            q=val[i],vmin=i;
    return vmin;
}

void prim(int vf)
{
    T[vf]=0;
    for(int i=1;i<=n;i++) val[i]=1e9; ///initial toate varfurile vor fi la inf fata de arbore
    val[vf]=0;
    for(int q=1;q<=n;q++)
    {
        int u=nmin(P,val); ///extragem varful care se afla la dist minima fata de arbore
        P[u]=1; ///adaugam varful in arbore
        for(int i=1;i<=n;i++)
            if(A[i][u] && !P[i] && A[i][u]<val[i]) ///actualizam vectorul de dist fata de arbore si de tati
                T[i]=u,val[i]=A[i][u];
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        A[x][y]=A[y][x]=z;
    }
    prim(1);
    for(int i=1;i<=n;i++) s+=val[i];
    cout<<s<<endl;
    for(int i=1;i<=n;i++)
        cout<<T[i]<<" ";
    return 0;
}
