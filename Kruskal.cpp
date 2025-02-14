#include <fstream>
using namespace std;

ifstream cin("kruskal.in");
ofstream cout("kruskal.out");

int n,m,s,k,T[101];



struct muchie{int i,j,c;}M[5005],A[5005];

int root(int v)
{
    if(T[v]==v) return v;
    return T[v]=root(T[v]);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) T[i]=i;
    for(int i=1; i<=m; i++)
    {
        cin>>M[i].i>>M[i].j>>M[i].c;
    }
    for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
            if(M[i].c>M[j].c)
            {
                muchie aux=M[i];
                M[i]=M[j];
                M[j]=aux;
            }
    for(int i=1;i<=m;i++)
    {
        int a=root(M[i].i);
        int b=root(M[i].j);
        if(a!=b)
        {
            T[b]=a;
            s+=M[i].c;
            A[++k]=M[i];
        }
    }
    cout<<s<<endl;
    for(int i=1;i<=k;i++)
        cout<<A[i].i<<" "<<A[i].j<<endl;
    return 0;
}
