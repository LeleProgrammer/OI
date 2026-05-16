#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int Q;
int now; // 0: red, 1: blue
string eat;

enum Types {
    NO=0,
    BC=1,
    BH=2,
    BE=3,
    BG=4,
    BK=5,
    BD=6,
    BS=7,
    RC=8,
    RH=9,
    RE=10,
    RG=11,
    RK=12,
    RD=13,
    RS=14,
};

int getColor(int type) {
    if (type==0) return -1;
    else if (type<=7) return 1;
    else return 0;
}

int arr[10][9]={
    {RC,RH,RE,RG,RK,RG,RE,RH,RC},
    {NO,NO,NO,NO,NO,NO,NO,NO,NO},
    {RD,NO,NO,NO,NO,NO,NO,NO,RD},
    {RS,NO,RS,NO,RS,NO,RS,NO,RS},
    {NO,NO,NO,NO,NO,NO,NO,NO,NO},
    {NO,NO,NO,NO,NO,NO,NO,NO,NO},
    {BS,NO,BS,NO,BS,NO,BS,NO,BS},
    {BD,NO,NO,NO,NO,NO,NO,NO,BD},
    {NO,NO,NO,NO,NO,NO,NO,NO,NO},
    {BC,BH,BE,BG,BK,BG,BE,BH,BC}
};

struct Info {
    string name;
    vector<pii> d; // direct
    vector<pii> b[10]; // barrier
    Info() {
        ;
    }
    Info(string name) {
        this->name=name;
    }
};

vector<Info> in;

void initInfo() {
    Info no;
    Info rk("red captain");
    Info bk("blue captain");
    Info rg("red guard");
    Info bg("blue guard");
    Info re("red elephant");
    Info be("blue elephant");
    Info rh("red horse");
    Info bh("blue horse");
    Info rc("red car");
    Info bc("blue car");
    Info rd("red duck");
    Info bd("blue duck");
    Info rs("red soldier");
    Info bs("blue soldier");
    // captain
    rk.d.push_back({1,0});
    rk.b[0].push_back({0,0});
    rk.d.push_back({-1,0});
    rk.b[1].push_back({0,0});
    rk.d.push_back({0,1});
    rk.b[2].push_back({0,0});
    rk.d.push_back({0,-1});
    rk.b[3].push_back({0,0});
    bk.d.push_back({1,0});
    bk.b[0].push_back({0,0});
    bk.d.push_back({-1,0});
    bk.b[1].push_back({0,0});
    bk.d.push_back({0,1});
    bk.b[2].push_back({0,0});
    bk.d.push_back({0,-1});
    bk.b[3].push_back({0,0});
    // guard
    rg.d.push_back({1,1});
    rg.b[0].push_back({0,0});
    rg.d.push_back({-1,-1});
    rg.b[1].push_back({0,0});
    rg.d.push_back({1,-1});
    rg.b[2].push_back({0,0});
    rg.d.push_back({-1,1});
    rg.b[3].push_back({0,0});
    bg.d.push_back({1,1});
    bg.b[0].push_back({0,0});
    bg.d.push_back({-1,-1});
    bg.b[1].push_back({0,0});
    bg.d.push_back({1,-1});
    bg.b[2].push_back({0,0});
    bg.d.push_back({-1,1});
    bg.b[3].push_back({0,0});
    // elephant
    re.d.push_back({2,2});
    re.b[0].push_back({1,1});
    re.d.push_back({2,-2});
    re.b[1].push_back({1,-1});
    re.d.push_back({-2,2});
    re.b[2].push_back({-1,1});
    re.d.push_back({-2,-2});
    re.b[3].push_back({-1,-1});
    be.d.push_back({2,2});
    be.b[0].push_back({1,1});
    be.d.push_back({2,-2});
    be.b[1].push_back({1,-1});
    be.d.push_back({-2,2});
    be.b[2].push_back({-1,1});
    be.d.push_back({-2,-2});
    be.b[3].push_back({-1,-1});
    // horse
    rh.d.push_back({2,1});
    rh.b[0].push_back({1,0});
    rh.d.push_back({1,2});
    rh.b[1].push_back({0,1});
    rh.d.push_back({2,-1});
    rh.b[2].push_back({1,0});
    rh.d.push_back({1,-2});
    rh.b[3].push_back({0,-1});
    rh.d.push_back({-2,1});
    rh.b[4].push_back({-1,0});
    rh.d.push_back({-1,2});
    rh.b[5].push_back({0,1});
    rh.d.push_back({-2,-1});
    rh.b[6].push_back({-1,0});
    rh.d.push_back({-1,-2});
    rh.b[7].push_back({0,-1});
    bh.d.push_back({2,1});
    bh.b[0].push_back({1,0});
    bh.d.push_back({1,2});
    bh.b[1].push_back({0,1});
    bh.d.push_back({2,-1});
    bh.b[2].push_back({1,0});
    bh.d.push_back({1,-2});
    bh.b[3].push_back({0,-1});
    bh.d.push_back({-2,1});
    bh.b[4].push_back({-1,0});
    bh.d.push_back({-1,2});
    bh.b[5].push_back({0,1});
    bh.d.push_back({-2,-1});
    bh.b[6].push_back({-1,0});
    bh.d.push_back({-1,-2});
    bh.b[7].push_back({0,-1});
    // car, a little bit special, too lazy to init here, haha
    // duck
    rd.d.push_back({3,2});
    rd.b[0].push_back({2,1});
    rd.b[0].push_back({1,0});
    rd.d.push_back({2,3});
    rd.b[1].push_back({1,2});
    rd.b[1].push_back({0,1});
    rd.d.push_back({-3,2});
    rd.b[2].push_back({-2,1});
    rd.b[2].push_back({-1,0});
    rd.d.push_back({-2,3});
    rd.b[3].push_back({-1,2});
    rd.b[3].push_back({0,1});
    rd.d.push_back({3,-2});
    rd.b[4].push_back({2,-1});
    rd.b[4].push_back({1,0});
    rd.d.push_back({2,-3});
    rd.b[5].push_back({1,-2});
    rd.b[5].push_back({0,-1});
    rd.d.push_back({-3,-2});
    rd.b[6].push_back({-2,-1});
    rd.b[6].push_back({-1,0});
    rd.d.push_back({-2,-3});
    rd.b[7].push_back({-1,-2});
    rd.b[7].push_back({0,-1});
    bd.d.push_back({3,2});
    bd.b[0].push_back({2,1});
    bd.b[0].push_back({1,0});
    bd.d.push_back({2,3});
    bd.b[1].push_back({1,2});
    bd.b[1].push_back({0,1});
    bd.d.push_back({-3,2});
    bd.b[2].push_back({-2,1});
    bd.b[2].push_back({-1,0});
    bd.d.push_back({-2,3});
    bd.b[3].push_back({-1,2});
    bd.b[3].push_back({0,1});
    bd.d.push_back({3,-2});
    bd.b[4].push_back({2,-1});
    bd.b[4].push_back({1,0});
    bd.d.push_back({2,-3});
    bd.b[5].push_back({1,-2});
    bd.b[5].push_back({0,-1});
    bd.d.push_back({-3,-2});
    bd.b[6].push_back({-2,-1});
    bd.b[6].push_back({-1,0});
    bd.d.push_back({-2,-3});
    bd.b[7].push_back({-1,-2});
    bd.b[7].push_back({0,-1});
    // soldier
    rs.d.push_back({1,1});
    rs.b[0].push_back({0,0});
    rs.d.push_back({-1,-1});
    rs.b[1].push_back({0,0});
    rs.d.push_back({1,-1});
    rs.b[2].push_back({0,0});
    rs.d.push_back({-1,1});
    rs.b[3].push_back({0,0});
    rs.d.push_back({0,1});
    rs.b[4].push_back({0,0});
    rs.d.push_back({0,-1});
    rs.b[5].push_back({0,0});
    rs.d.push_back({1,0});
    rs.b[6].push_back({0,0});
    rs.d.push_back({-1,0});
    rs.b[7].push_back({0,0});
    bs.d.push_back({1,1});
    bs.b[0].push_back({0,0});
    bs.d.push_back({-1,-1});
    bs.b[1].push_back({0,0});
    bs.d.push_back({1,-1});
    bs.b[2].push_back({0,0});
    bs.d.push_back({-1,1});
    bs.b[3].push_back({0,0});
    bs.d.push_back({0,1});
    bs.b[4].push_back({0,0});
    bs.d.push_back({0,-1});
    bs.b[5].push_back({0,0});
    bs.d.push_back({1,0});
    bs.b[6].push_back({0,0});
    bs.d.push_back({-1,0});
    bs.b[7].push_back({0,0});
    // register info
    in.push_back(no);
    in.push_back(bc);
    in.push_back(bh);
    in.push_back(be);
    in.push_back(bg);
    in.push_back(bk);
    in.push_back(bd);
    in.push_back(bs);
    in.push_back(rc);
    in.push_back(rh);
    in.push_back(re);
    in.push_back(rg);
    in.push_back(rk);
    in.push_back(rd);
    in.push_back(rs);
}

bool checkValid(pii pos) {
    if (pos.first>=0 && pos.first<10 && pos.second>=0 && pos.second<9) return true;
    else return false;
}

pii getPos(pii pos,pii bias) {
    return {pos.first+bias.first,pos.second+bias.second};
}

bool move(pii from,pii to) {
    int type=arr[from.first][from.second]; // get type
    if (type==NO) return false; // nothing to move
    if (getColor(type)!=now) return false; // not the right color
    Info dat=in[type]; // get info
    if (type==RC || type==BC) { // car
        if (from.first-to.first && from.second-to.second) return false;
        int dx=to.first==from.first?0:((to.first-from.first)/abs(to.first-from.first));
        int dy=to.second==from.second?0:((to.second-from.second)/abs(to.second-from.second));
        pii pos=from;
        while (true) {
            pos.first+=dx;
            pos.second+=dy;
            if (pos.first==to.first && pos.second==to.second) {
                int toType=arr[to.first][to.second]; // get type
                if (toType==NO) {
                    eat="NA";
                } else if (getColor(toType)==now) { // same color
                    return false;
                } else {
                    Info toDat=in[toType]; // get info
                    eat=toDat.name;
                }
                arr[to.first][to.second]=arr[from.first][from.second];
                arr[from.first][from.second]=NO;
                return true;
            }
            int type=arr[pos.first][pos.second];
            if (type==NO) continue;
            return false;
        }
    }
    bool flag=false;
    for (int i=0;i<dat.d.size();++i) {
        pii t=dat.d[i];
        t=getPos(from,t);
        if (t.first==to.first && t.second==to.second) {
            bool ok=true;
            for (int j=0;j<dat.b[i].size();++j) {
                pii forb=dat.b[i][j];
                if (forb.first==0 && forb.second==0) continue;
                forb=getPos(from,forb);
                int forbType=arr[forb.first][forb.second];
                if (forbType!=NO) {
                    ok=false;
                    break;
                }
            }
            if (ok) {
                int toType=arr[to.first][to.second]; // get type
                if (toType==NO) {
                    eat="NA";
                } else if (getColor(toType)==now) { // same color
                    continue;
                } else {
                    Info toDat=in[toType]; // get info
                    eat=toDat.name;
                }
                arr[to.first][to.second]=arr[from.first][from.second];
                arr[from.first][from.second]=NO;
                flag=true;
                break;
            }
        }
    }
    return flag; // succeeded or not
}

bool isKing(int type) {
    return type==BK || type==RK;
}

void printBoard() {
    for (int i=0;i<10;++i) {
        for (int j=0;j<9;++j) {
            printf("%d ",arr[i][j]);
        }
        putchar(10);
    }
}

bool checkChallenge() {
    for (int i=0;i<10;++i) {
        for (int j=0;j<9;++j) {
            if (arr[i][j]==NO) continue;
            int type=arr[i][j];
            Info dat=in[type];
            if (type==RC || type==BC) {
                int dx[4]={0,1,0,-1};
                int dy[4]={1,0,-1,0};
                for (int p=0;p<4;++p) {
                    int x=dx[p];
                    int y=dy[p];
                    pii pos={i,j};
                    while (true) {
                        pos.first+=x;
                        pos.second+=y;
                        if (!checkValid(pos)) break;
                        int type=arr[pos.first][pos.second];
                        if (type==NO) continue;
                        if (isKing(type) && getColor(type)!=getColor(arr[i][j])) return true;
                        break;
                    }
                }
            }
            for (int k=0;k<dat.d.size();++k) {
                pii to=dat.d[k];
                to=getPos({i,j},to);
                if (!checkValid(to)) continue;
                int color=getColor(arr[to.first][to.second]);
                if (getColor(arr[i][j])!=color && isKing(arr[to.first][to.second])) {
                    bool ok=true;
                    for (int p=0;p<dat.b[i].size();++p) {
                        pii forb=dat.b[k][p];
                        if (forb.first==0 && forb.second==0) continue;
                        forb=getPos({i,j},forb);
                        if (arr[forb.first][forb.second]!=NO) {
                            ok=false;
                            break;
                        }
                    }
                    if (ok) return true;
                }
            }
        }
    }
    return false;
}

int checkOver() {
    int winner=0; // -1: red, 1: blue, 0: none
    bool redAlive=false;
    bool blueAlive=false;
    for (int i=0;i<10;++i) {
        for (int j=0;j<9;++j) {
            if (arr[i][j]==RK) redAlive=true;
            else if (arr[i][j]==BK) blueAlive=true;
        }
    }
    if (redAlive && blueAlive) winner=0;
    else if (redAlive) winner=-1;
    else winner=1;
    return winner;
}

int main() {
    initInfo();
    scanf("%d",&Q);
    while (Q--) {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if (checkOver()!=0) {
            puts("Invalid command");
            continue;
        }
        string fromName=in[arr[x1][y1]].name;
        bool legal=move({x1,y1},{x2,y2});
        if (!legal) {
            puts("Invalid command");
            continue;
        }
        printf("%s;",fromName.c_str());
        printf("%s;",eat.c_str());
        bool cha=checkChallenge();
        int winner=checkOver();
        if (!winner) {
            if (cha) printf("yes;");
            else printf("no;");
            printf("no");
        } else {
            printf("no;");
            printf("yes");
        }
        putchar(10);
        now^=1; // change
        eat=""; // reset
    }
    return 0;
}