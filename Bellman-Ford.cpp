#include <iostream>

using namespace std;

struct muchie {int i,j,c;};
muchie M[11000];
int D[101],n,sursa,k;

int BellmanFord(muchie M[], int n, int sursa, int contorMuchii, int Distante[]) ///returneaza 0 daca avem ciclu negativ, 1 daca nu avem
{
    for(int i=1;i<=n;i++) D[i]=1e6;
        Distante[sursa]=0;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=contorMuchii;j++)
        {
            int a=M[j].i;
            int b=M[j].j;
            int c=M[j].c;
            if(Distante[a]!=1e6 && Distante[b]>Distante[a]+c)
            {
                if(i==n) ///avem ciclu negativ
                    return 0;
                D[b]=D[a]+c;
            }
        }
    return 1;

}

int main()
{
    cin>>n>>sursa;
    int x,y,z;
    while(cin>>x>>y>>z)
    {
        M[++k]={x,y,z};
    }
    if(BellmanFord(M,n,sursa,k,D)==0)
    {
        cout<<"Avem ciclu negativ!";
    }
    else
    {
        for(int i=1;i<=n;i++)
            if(D[i]==1e6) cout<<-1<<" ";
            else cout<<D[i]<<" ";
    }
    return 0;
}
