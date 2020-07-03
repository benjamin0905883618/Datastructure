#include<iostream>
using namespace std;

struct edge{
    int u,v;
    int weight;

    edge(int u,int v,int w) : u(u),v(v),weight(w){}

};

int* dSet;
void Disjointinit(int n){
    dSet = new int [n];
    for(int i = 0;i < n;i++){
        dSet[i] = i;
    }
}
int findSet(int n){
    if(n != dSet[n])
        dSet[n] = findSet(dSet[n]);
    return dSet[n];
}
void mergeSet(int u,int v){
    int fu = findSet(u);
    int fv = findSet(v);
    int fn = (fu < fv)?fu:fv;
    dSet[fu] = fn;
    dSet[fv] = fn;
}

void swap(edge *a,edge *b){
    edge *temp = new edge(a->u,a->v,a->weight);
    a->u = b->u;
    a->v = b->v;
    a->weight = b->weight;
    b->u = temp->u;
    b->v = temp->v;
    b->weight = temp->weight;
}

class HeapSort{
private:
    int parent(int idx){return idx/2;}
    int left(int idx){return idx * 2;}
    int right(int idx){return 2 * idx + 1;}
public:
    HeapSort(){
        data = new edge* [25001];
        data[0] = new edge(0,0,0);
    }
    int size(){return data[0]->weight;}
    bool empty(){return (size() == 0);}
    void clear(){data[0]->weight = 0;}
    void push(int u,int v,int w){
        data[0]->weight++;
        data[size()] = new edge(u,v,w);
        int cur = size();
        while(cur > 1 && data[cur]->weight < data[parent(cur)]->weight){
            swap(data[cur],data[parent(cur)]);
            cur = parent(cur);
        }
    }
    void pop(){
        int flag = 0;
        while(!empty()){
            //cout << "ok" << endl;
            edge *ret = new edge(data[1]->u,data[1]->v,data[1]->weight);
            //cout << ret.u << " " << ret.v << " " << ret.weight << endl;
            data[1]->u = data[size()]->u;
            data[1]->v = data[size()]->v;
            data[1]->weight = data[size()]->weight;
            //cout << data[1].u << " " << data[1].v << " " << data[1].weight << endl;
            int cur = 1;
            while(true){
                if(right(cur) < size() && data[right(cur)]->weight < data[left(cur)]->weight && data[right(cur)]->weight < data[cur]->weight){
                    swap(data[cur],data[right(cur)]);
                    cur = right(cur);
                }
                else if(left(cur) < size() && data[left(cur)]->weight < data[right(cur)]->weight && data[left(cur)]->weight < data[cur]->weight){
                    swap(data[cur],data[left(cur)]);
                    cur = left(cur);
                }
                else {break;}
            }
            //cout << "ok" << endl;
            data[0]->weight--;
            //cout << findSet(ret->u) << " " << findSet(ret->v) << " " << ret->weight << endl;
            if(findSet(ret->u) != findSet(ret->v)){
                mergeSet(ret->u,ret->v);
            }
            else if(findSet(ret->u) == findSet(ret->v)){
                if(flag == 0){
                    flag = 1;
                    cout << ret->weight;
                }
                else
                    cout << " " << ret->weight;

            }
        }
        if(flag == 0)
            cout << "forest";
    }
    ~HeapSort(){}

protected:
    edge **data;
};

int main(){
    int n,m;
    while(cin >> n >> m){
        if(n == m && n == 0)
            break;
        Disjointinit(n);
        HeapSort h;
        for(int i = 0;i < m;i++){
            int u,v,w;
            cin >> u >> v >> w;
            h.push(u,v,w);
        }
        h.pop();
        cout << endl;
    }
}
