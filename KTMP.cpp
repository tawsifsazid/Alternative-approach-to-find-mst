/**
	* Author   : Muhammad Tawsif Sazid
	* Military Institute and Science and Technology
	*
	*
**/

#include <bits/stdc++.h>
#define pii acos(-1)
#define ll long long
#define pare pair<int,int>
#define eps 1e-9
#define max 60006
#define read(type) readInt<type>()


/****** Template of some basic operations *****/

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

/**********************************************/

using namespace std;

///dir array for Queen int dxq[10] = {-1,-1,-1,1,1,1,0,0};
///dir array for Queen int dyq[10] = {-1,0,1,-1,0,1,-1,1};
///dir array for knight int dxk[10] = {-2,-2,-1,-1,1,1,2,2};
///dir array for knight int dyk[10] = {1,-1,-2,2,-2,2,-1,1};

int n,parent[300005],edge_nisi = 0,final_ans = 0,m,cl_kore_dao;

struct node {
    int cost, u, v , id;

    bool operator < (const node& a )const{
        return cost > a.cost;
    }
};
///vector<node>E[200005];
priority_queue< node , vector < node > > Q[400005];
vector<node>temp;


void init(){
    int i,j,k;
    for(i=0;i<=200000;i++){
        parent[i] = i;
    }
    edge_nisi = 0;
    final_ans = 0;

    for(i = 0; i<400000; i++){
        while(!Q[i].empty()){
            Q[i].pop();
        }
    }

    ///memset(res,0,sizeof res);
    temp.clear();
}

int fnd(int r){
    if(r == parent[r])return r;
    else{
        parent[r] = fnd(parent[r]);
        return parent[r];
    }
}
void print_queue(int index){
    cout<<"Printing Queue"<<endl;
    while(!Q[index].empty()){
        node aa = Q[index].top();
        cout<<aa.u<<" "<<aa.v<<" "<<aa.cost<<endl;
        Q[index].pop();
    }
    cout<<endl<<endl;

}
void check_merge(int num){
    ///print_queue(number);

    int number = fnd(num);
    ///cout<<"ashole "<<number<<" but asche "<<num<<endl;
    node ext = Q[number].top();

    int fixed1,fixed2,lel;
    fixed1 = ext.u;
    fixed2 = ext.v;
    lel = ext.cost;
    ///cout<<fixed1<<" "<<fixed2<<" "<<lel<<endl;
    ///res[fixed1][fixed2] = 1;
    ///res[fixed2][fixed1] = 1;


    while(!Q[number].empty()){
        ext = Q[number].top();
        Q[number].pop();
        if(fixed1 == ext.u && fixed2 == ext.v ){}
        else{
            ///cout<<"thaktese"<<ext.u<<" "<<ext.v<<" "<<ext.cost<<endl;
            temp.push_back(ext);
        }
    }
    int arekjon = fnd(fixed2);
    ///cout<<" 2nd node "<<arekjon<<endl;
    ///print_queue(arekjon);
    while(!Q[arekjon].empty()){
        ext = Q[arekjon].top();
        ///cout<<"testing "<<ext.u<<" "<<ext.v<<" "<<ext.cost<<endl;
        Q[arekjon].pop();
        if((fixed2 == ext.u && fixed1 == ext.v) || (fixed1 == ext.u && fixed2 == ext.v) ){}
        else{
            ///cout<<"thaktese "<<ext.u<<" "<<ext.v<<" "<<ext.cost<<endl;
            temp.push_back(ext);
        }
    }
    ///cout<<"merge hoilo "<<number<<" "<<arekjon<<endl;
    ///parent[arekjon] = number;
     if(number != arekjon){
            final_ans = final_ans + lel;
            edge_nisi++;
            parent[arekjon] = number;
     }
    for(int i=0;i<temp.size();i++){
        Q[number].push(temp[i]);
    }
    ///print_queue(number);
    cl_kore_dao = number;
    temp.clear();



   // int p1 = fnd();
    //int p2 = fnd();
}

void KTMP(){
    int i,j,k;
    while(1){
       if(edge_nisi == n-1)break;
       /// cout<<"new turn"<<endl;
        for(i = 0;i<n; i++){
            if(edge_nisi == n-1)break;

                ///cout<<i<<" "<<k_parent<<endl;
                ///Q[k_parent].pop();
                ///cout<<"check a jachhe "<<take.u<<" "<<take.v<<" "<<take.cost<<endl;
                check_merge(i);
                ///cl_kore_dao = fnd(i);
                ///break;
        }
        ///break;
    }
}

int main(){
    clock_t tStart = clock();
    /* Do your stuff here */
    ///printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
///    return 0;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i,j,k,a,b,cst,ch = 0;

    while(cin>>n>>m){
        if(n == 0 && m == 0)break;
        init();
        k = 0;
        ///ch++;
        for(i=0;i<m;i++){
            cin>>a>>b>>cst;
            k = k + cst;
            node lol;
            lol.u = a;
            lol.v = b;
            lol.cost = cst;
            ///E[a].push_back(lol);
            Q[a].push(lol);
            lol.u = b;
            lol.v = a;
            lol.cost = cst;
            Q[b].push(lol);
            ///E[b].push_back(lol);
        }
        ///cout<<"s"<<endl;
/*
        for(i=0;i<n;i++){
                print_queue(i);
         ///   build_minheap(i,E[i].size());
            ///print(i,E[i].size());
        }
*/
        ///cout<<"input done"<<endl;
        ///E[0].erase(E[0].begin());
        ///print(0,E[0].size());
        KTMP();
        cout<<final_ans<<endl;
        //if(!Q[cl_kore_dao].empty()) cout<<"ues"<<endl;
        //else{
        //    cout<<"lel"<<endl;
        //}

        ///if(ch == 1)break;
    }
    ///printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
