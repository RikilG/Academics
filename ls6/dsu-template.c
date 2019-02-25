//disjoint union set template code.

int dsu[10000]; //declare in global

int root(int u) {
    while(u!=dsu[u])
        u=dsu[u];
    return u;
}

void unon(int u, int v) { //union - keyword in c.
    dsu[root(u)] = root(v);
}

int fin(int u, int v) { //check if u and v
    return root(u)==root(v);
}

void init(int n) { //just to initialize array for dsu
    for(int i=0;i<n;i++)
        dsu[i]=i;
}