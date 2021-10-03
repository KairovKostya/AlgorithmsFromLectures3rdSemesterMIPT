#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
const int k = 26;

struct node{
    int to[k];
    bool term = false;
    int link;
    node(){
        std::memset(to, -1, k);
    }
};

std::vector<node> t(1);

void add (const std::string& s){
    int v = 0;
    for(int i =0; i < s.size(); ++i){
        if(t[v].to[s[i]] == -1){
            t.push_back(node());
            t[v].to[s[i]]=int(t.size()) -1;
        }
        v = t[v].to[s[i]];
    }
    t[v].term = true;
}

void AhoCorasick(){
    t[0].link = 0;
    for(int c = 0; c < k; ++c){
        if(t[0].to[c]!=-1){
            continue;
        }
        t[0].to[c] = 0;
    }
    std::queue<int> q;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (int c = 0; c < k; ++c){
            int u = t[v].to[c];
            if(t[u].link!=-1) continue;
            t[u].link = (v==0 ? 0 : t[t[v].link].to[c]);
            for (int d = 0; d < k; ++d){
                if(t[u].to[d]!=-1){
                    continue;
                }
                t[u].to[d] = t[t[u].link].to[d];
            }
            q.push(u);
        }
        
    }
    
}

int main() {
    add("aboba");
}
