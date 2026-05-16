extern "C" int Seniorious(int x);

extern "C" int Chtholly(int n,int c) {
    int l=1,r=n;
    while (l<=r) {
        int mid=l+r>>1;
        int k=Seniorious(mid);
        if (k<0) l=mid+1;
        else if (k>0) r=mid-1;
        else return mid;
    }
    return 0;
}