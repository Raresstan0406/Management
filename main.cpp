#include<iostream>
#include<vector>
#include<set>
#include<iomanip>
#include<algorithm>

using namespace std;

class turist
{
public:
    int id;
    string oras;
    int pret;
    turist(int i, string o, int p)
    {
        id=i;
        oras=o;
        pret=p;
    }
};

bool sortare(turist a, turist b)
{
    if(a.pret<b.pret)
        return true;
    return false;
}
int main()
{
    int ok1=0;
    string c, oras;
    int id,pret;
    vector<turist>v;
    vector<turist>Praga;
    while(cin>>c)
    {
        if(c=="inregistrare")
        {
            cin>>id>>oras>>pret;
            v.push_back(turist(id,oras,pret));
        }
        if(c=="afiseaza")
        {
            int ok=0;
            cin>>oras;
            for(int i=0;i<v.size();i++)
            {
                if(v[i].oras==oras)
                {
                    cout<<v[i].id<<" ";
                    ok=1;
                }
            }
            if(ok==0)
            {
                cout<<"Nicio vacanta gasita!"<<"\n";
            }
            if(ok==1)
            {
                cout<<"\n";
            }
        }
        if(c=="rezerva")
        {
            int ok=0;
            cin>>id;
            for(int i=0;i<v.size();i++)
            {
                if(v[i].id==id)
                {
                    if(v[i].oras=="Praga")
                    {
                        ok1=1;
                        Praga.push_back(v[i]);
                    }
                    v.erase(v.begin()+i);
                    cout<<"Felicitari!"<<"\n";
                    ok=1;
                }
            }
            if(ok==0)
            {
                cout<<"Eroare!"<<"\n";
            }
        }
    }
    set<string>orase;
    if(v.size()==0)
    {
        cout<<"Nicio vacanta disponibila!";
        cout<<"\n";
    }
    else
    {
        for(int i=0;i<v.size();i++)
        {
            orase.insert(v[i].oras);
        }
        for(auto it:orase)
            cout<<it<<" ";
        cout<<"\n";
    }
    int ok=0;
    double val=0;
    double s=0;
    int ct=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].oras=="Paris")
        {
            s+=v[i].pret;
            ok=1;
            ct++;
        }
    }
    if(ok==0)
    {
        cout<<fixed<<setprecision(3)<<s<<"\n";
    }
    else
    {
        cout<<fixed<<setprecision(3)<<s/ct<<"\n";
    }
    if(v.size()==0)
    {
        cout<<fixed<<setprecision(3)<<val<<"\n";
    }
    else
    {
        sort(v.begin(),v.end(),sortare);
        if(v[0].oras=="Praga")
        {
            Praga.push_back(v[0]);
        }
        cout<<v[0].id<<","<<v[0].oras<<","<<v[0].pret<<"\n";
    }
    s=0;
    if(ok1==0)
    {
        cout<<fixed<<setprecision(3)<<val<<"\n";
    }
    else
    {
        for(int i=0;i<Praga.size();i++)
        {
            s+=1.3*Praga[i].pret;
        }
        cout<<fixed<<setprecision(3)<<s<<"\n";
    }
    return 0;
}