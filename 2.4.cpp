void merge(int *a,int n,int *b,int m,int *c){
    int p1=0,p2=0,p3=0;
    while(p1<n&&p2<m){
       if(a[p1]<b[p2]){
        c[p3]=a[p1];
        p1++;
        p3++;
    }
    else {
        c[p3]=b[p2];
        p2++;
        p3++;
    } 
    }
    while(p1<n){
        c[p3]=a[p1];
        p1++;
        p3++;
    }
    while(p2<m){
        c[p3]=b[p2];
        p2++;
        p3++;
    }
}