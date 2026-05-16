#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;

struct Info {
    int size;
    int align;
    int memoryStart;
    vector<pair<string,string>> member;
    Info() {
        ;
    }
    Info(int size,int align) {
        this->size=size;
        this->align=align;
    }
};

map<string,Info> types;

Info global;
int globalPtr;

void bindType(string name,Info info) {
    types.insert({name,info});
}

void init() {
    Info _byt(1,1);
    Info _sho(2,2);
    Info _int(4,4);
    Info _lon(8,8);
    bindType("byte",_byt);
    bindType("short",_sho);
    bindType("int",_int);
    bindType("long",_lon);
}

void movePtr(int& ptr,int align) {
    if (ptr%align==0) return;
    else ptr=(ptr/align+1)*align;
}

vector<string> splitDot(string s) {
    string now;
    vector<string> ans;
    for (int i=0;i<s.size();++i) {
        if (s[i]!='.') {
            now.push_back(s[i]);
        } else {
            ans.push_back(now);
            now.clear();
        }
    }
    ans.push_back(now);
    return ans;
}

signed main() {
    init();
    scanf("%lld",&n);
    int debug=0;
    while (n--) {
        int op;
        scanf("%lld",&op);
        debug++;
        if (op==1) {
            string s;
            int k;
            cin>>s>>k;
            Info newType(0,0);
            int ptr=0;
            while (k--) {
                string t,name;
                cin>>t>>name;
                newType.member.push_back({t,name});
                Info readType=types.find(t)->second;
                movePtr(ptr,readType.align);
                newType.align=max(newType.align,readType.align);
                ptr+=readType.size;
            }
            newType.size=ptr;
            movePtr(newType.size,newType.align);
            types.insert({s,newType});
            printf("%lld %lld\n",newType.size,newType.align);
        } else if (op==2) {
            string t,n;
            cin>>t>>n;
            global.member.push_back({t,n});
            Info readType=types.find(t)->second;
            movePtr(globalPtr,readType.align);
            printf("%lld\n",globalPtr);
            globalPtr+=readType.size;
        } else if (op==3) {
            string s;
            cin>>s;
            Info* info=&global;
            int ptr=0;
            vector<string> element=splitDot(s);
            for (int i=0;i<element.size();++i) {
                string& target=element[i];
                for (int j=0;j<info->member.size();++j) {
                    pair<string,string>& member=info->member[j];
                    Info& memberInfo=types.find(member.first)->second;
                    movePtr(ptr,memberInfo.align);
                    if (member.second!=target) {
                        ptr+=memberInfo.size;
                    } else {
                        info=&memberInfo;
                        break;
                    }
                }
            }
            printf("%lld\n",ptr);
        } else if (op==4) {
            int addr;
            scanf("%lld",&addr);
            if (addr>=globalPtr) {
                puts("ERR");
                continue;
            }
            Info* info=&global;
            int ptr=0;
            bool flag=false;
            string ans;
            while (true) {
                bool ok=false;
                bool hasMember=false;
                for (int i=0;i<info->member.size();++i) {
                    hasMember=true;
                    pair<string,string>& member=info->member[i];
                    Info& memberInfo=types.find(member.first)->second;
                    movePtr(ptr,memberInfo.align);
                    int ptrEnd=ptr+memberInfo.size-1;
                    if (addr>=ptr && addr<=ptrEnd) {
                        if (flag) ans.push_back('.');
                        flag=true;
                        ans+=member.second;
                        info=&memberInfo;
                        ok=true;
                        break;
                    } else if (addr<ptr) {
                        ans="ERR";
                        break;
                    }
                    ptr=ptrEnd+1;
                }
                if (!ok) {
                    if (hasMember) ans="ERR";
                    break;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

/*
4
1 a 2
short aa
int ab
1 b 2
a ba
long bb
2 b x
3 x.ba.ab
*/