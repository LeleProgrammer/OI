#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define TIMESTAMP cerr<<fixed<<setprecision(3)<<clock()*1.0/CLOCKS_PER_SEC<<"s"<<endl;
#define _rep(i,a,b) for (int i=(a);i<=(b);++i)
#define _reps(i,a,b,c) for (int i=(a);i<=(b);c)
#define _rrep(i,a,b) for (int i=(a);i>=(b);--i)
#define _rreps(i,a,b,c) for (int i=(a);i>=(b);c)
#define _iter(i,a) for (auto i=a.begin();i!=a.end();++i)
#define _graph(i,u) for (int i=h[u];~i;i=ne[i])
#define _dinic(i,u) for (int i=cur[u];~i && k<limit;i=ne[i])
#define rint register int
#define LL long long
#define i32 signed
#define i64 long long
#define i128 __int128
#define u32 unsigned
#define u64 unsigned long long
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

namespace IO {
    template<typename T> inline void read(T& x) {
        int s=1; char c=getchar(); x=0;
        while (!isdigit(c)) { if (c=='-') s=-1; c=getchar(); }
        while (isdigit(c)) x=x*10+(c-'0'),c=getchar();
        x*=s;
    }
    inline void readstr(string& x) {
        x.clear(); char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c)) x.push_back(c),c=getchar();
    }
    inline void readstr(char* x) {
        int idx=0; char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c)) x[idx++]=c,c=getchar();
        x[idx]='\0';
    }
    template<typename T> inline void write(T x) {
        if (x<0) putchar('-'),x=-x;
        if (x/10) write(x/10);
        putchar('0'+(x%10));
    }
    template<typename T> inline void writesp(T x) { write(x); putchar(' '); }
    template<typename T> inline void writeln(T x) { write(x); putchar(10); }
    inline void writestr(string& x) { _iter(it,x) putchar(*it); }
    inline void writestr(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)) putchar(x[i]); putchar(10); }
};

using namespace IO;

const int N=7;
const int inf=1e9;

int n,m,T;
int lasSouth,lasNorth;
vector<int> southPos,northPos;
double southExtraDefend=1,northExtraDefend=1;
double southExtraAttack=1,northExtraAttack=1;
double activeSkillWeak[]={0,0.1,0.12,0.15,0.17,0.2};
double activeSkillAverage[]={0,0.06,0.07,0.08,0.09,0.1};
double activeSkillStrong[]={0,2.1,2.17,2.24,2.32,2.4};
double passiveSkillWeak[]={0,0.013,0.016,0.019,0.022,0.025};
double passiveSkillAverage[]={0,0.01,0.02,0.03,0.04,0.05};
double passiveSkillStrong[]={0,0.01,0.02,0.03,0.04,0.05};
pdi southMaxhpDecreaseEffect[N],northMaxhpDecreaseEffect[N];
char nowTeam[2][15]={"South","North"};

struct PersonData {
    char type[15];
    int lv,maxhp;
    double atk,def;
    int skillLv,passivesklLv;
    char weapontype;
    double weaponatk;
    int hp;
    double skillExtra;
} south[N],north[N];

void test(PersonData& a) {
    printf("%s Lv=%d maxhp=%d atk=%lf def=%lf skillLv=%d passivesklLv=%d %c weaponatk=%lf\n",a.type,a.lv,a.maxhp,a.atk,a.def,a.skillLv,a.passivesklLv,a.weapontype,a.weaponatk);
}

PersonData readOnePerson() {
    PersonData ans;
    char weapontype[2];
    scanf("%s Lv=%d maxhp=%d atk=%lf def=%lf skillLv=%d passivesklLv=%d %s weaponatk=%lf",ans.type,&(ans.lv),&(ans.maxhp),&(ans.atk),&(ans.def),&(ans.skillLv),&(ans.passivesklLv),&weapontype,&(ans.weaponatk));
    ans.weapontype=weapontype[0];
    return ans;
}

void swapSouthNorth() {
    _rep(i,1,N-1) swap(south[i],north[i]);
    swap(lasSouth,lasNorth);
    swap(n,m);
    swap(southPos,northPos);
    swap(southExtraDefend,northExtraDefend);
    swap(southExtraAttack,northExtraAttack);
    _rep(i,1,N-1) swap(southMaxhpDecreaseEffect[i],northMaxhpDecreaseEffect[i]);
    swap(nowTeam[0],nowTeam[1]);
}

double updateRaceControlExtra(char attack[],char defend[]) {
    double raceControlExtra;
    if (!strcmp(attack,"Weak")) {
        if (!strcmp(defend,"Weak")) raceControlExtra=1.0;
        else if (!strcmp(defend,"Average")) raceControlExtra=0.9;
        else raceControlExtra=1.1;
    } else if (!strcmp(attack,"Average")) {
        if (!strcmp(defend,"Weak")) raceControlExtra=1.1;
        else if (!strcmp(defend,"Average")) raceControlExtra=1.0;
        else raceControlExtra=0.9;
    } else {
        if (!strcmp(defend,"Weak")) raceControlExtra=0.9;
        else if (!strcmp(defend,"Average")) raceControlExtra=1.1;
        else raceControlExtra=1.0;
    }
    return raceControlExtra;
}

int getWorkPerson(int round) {
    if (round<=2) {
        int id=inf;
        _rep(i,1,n) if (south[i].hp>0) id=min(id,i);
        return id;
    }
    int id=inf;
    _rep(i,lasSouth+1,n) if (south[i].hp>0) id=min(id,i);
    if (id==inf) {
        _rep(i,1,lasSouth) if (south[i].hp>0) id=min(id,i);
        return id;
    }
    return id;
}

double getPositionExtra(int a,int d) {
    int k=abs((a-d)%6);
    if (!k) return 1.25;
    else if (k==1 || k==5) return 1.00;
    else if (k==2 || k==4) return 0.75;
    else return 0.00;
}

void damage(int from,int target,double positionExtra,double basicAttackStrength,double raceControlExtra) {
    // cout<<"!!!!!!: basic attack strength: "<<basicAttackStrength<<endl;
    double defendRate=north[target].def*min(northExtraDefend,1.1);
    // cout<<defendRate<<endl;
    double attackStrength=basicAttackStrength*south[from].skillExtra*min(southExtraAttack,1.1)*raceControlExtra*positionExtra;
    // cout<<attackStrength<<"="<<basicAttackStrength<<" "<<south[from].skillExtra<<" "<<min(southExtraAttack,1.1)<<" "<<raceControlExtra<<" "<<positionExtra<<endl;
    int dec=attackStrength/defendRate;
    printf("%s %d took %d damage from %s %d -> %d/%d\n",nowTeam[1],target,dec,nowTeam[0],from,max(0,north[target].hp-dec),north[target].maxhp);
    north[target].hp-=dec;
    if (north[target].hp<=0) {
        if (!strcmp(north[target].type,"Average")) northExtraDefend-=passiveSkillAverage[north[target].passivesklLv];
        else if (!strcmp(north[target].type,"Strong")) northExtraAttack-=passiveSkillStrong[north[target].passivesklLv];
    }
}

void doBasicAttack(int from,int target,int atkpos,int ddgpos,double positionExtra) {
    double raceControlExtra=updateRaceControlExtra(south[from].type,north[target].type);
    double basicAttackStrength=south[from].atk*south[from].weaponatk;
    damage(from,target,positionExtra,basicAttackStrength,raceControlExtra);
}

void doSpecialAttack(int from,int target,int atkpos,int ddgpos,double positionExtra) {
    // cout<<"!!!!!!!!"<<endl;
    // test(south[from]);
    // test(north[target]);
    // cout<<"........"<<endl;
    if (south[from].weapontype=='B') {
        double basicAttackStrength=south[from].atk*south[from].weaponatk*1.25;
        double raceControlExtra=updateRaceControlExtra(south[from].type,north[target].type);
        damage(from,target,positionExtra,basicAttackStrength,raceControlExtra);
    } else if (south[from].weapontype=='G') {
        vector<int> persons;
        int dpos;
        _rep(i,0,m-1) {
            if (northPos[i]==target) {
                dpos=i;
                break;
            }
        }
        persons.emplace_back(northPos[dpos]);
        _rrep(i,dpos-1,0) {
            if (north[northPos[i]].hp>0) {
                persons.emplace_back(northPos[i]);
                break;
            }
        }
        _rep(i,dpos+1,(int)northPos.size()-1) {
            if (north[northPos[i]].hp>0) {
                persons.emplace_back(northPos[i]);
                break;
            }
        }
        int damagedCnt=(int)persons.size();
        // cout<<damagedCnt<<endl;
        _iter(it,persons) {
            double raceControlExtra=updateRaceControlExtra(south[from].type,north[*it].type);
            damage(from,*it,positionExtra,south[from].atk*south[from].weaponatk*1.35/damagedCnt,raceControlExtra);
        }
    } else {
        vector<int> persons;
        int dpos;
        _rep(i,0,m-1) {
            if (northPos[i]==target) {
                dpos=i;
                break;
            }
        }
        _rrep(i,dpos-1,0) {
            if (north[northPos[i]].hp>0) {
                persons.emplace_back(northPos[i]);
                break;
            }
        }
        _rep(i,dpos+1,(int)northPos.size()-1) {
            if (north[northPos[i]].hp>0) {
                persons.emplace_back(northPos[i]);
                break;
            }
        }
        double raceControlExtra=updateRaceControlExtra(south[from].type,north[target].type);
        damage(from,target,positionExtra,south[from].atk*south[from].weaponatk*1.15,raceControlExtra);
        _iter(it,persons) {
            double raceControlExtra=updateRaceControlExtra(south[from].type,north[*it].type);
            damage(from,*it,positionExtra,south[from].atk*south[from].weaponatk*0.23,raceControlExtra);
        }
    }
}

void doActiveSkill(int from,int target) {
    if (!strcmp(south[from].type,"Weak")) {
        printf("%s %d applied %s skill to %s %d\n",nowTeam[0],from,south[from].type,nowTeam[0],target);
        if (south[target].hp!=south[target].maxhp) printf("%s %d recovered +%d hp -> %d/%d\n",nowTeam[0],target,(int)(south[target].maxhp*activeSkillWeak[south[from].skillLv]),min((int)(south[target].hp+south[target].maxhp*activeSkillWeak[south[from].skillLv]),south[target].maxhp),south[target].maxhp);
        south[target].hp+=south[target].maxhp*activeSkillWeak[south[from].skillLv];
        south[target].hp=min(south[target].hp,south[target].maxhp);
    } else if (!strcmp(south[from].type,"Average")) {
        printf("%s %d applied %s skill to %s %d\n",nowTeam[0],from,south[from].type,nowTeam[1],target);
        northMaxhpDecreaseEffect[target]={activeSkillAverage[south[from].skillLv],0};
    } else {
        printf("%s %d applied %s skill to %s %d\n",nowTeam[0],from,south[from].type,nowTeam[0],target);
        south[target].skillExtra=activeSkillStrong[south[from].skillLv];
    }
}

void doWeakPassiveSkill() {
    double inc=0;
    _rep(i,1,n) {
        if (strcmp(south[i].type,"Weak")) continue;
        if (south[i].hp>0) {
            inc+=passiveSkillWeak[south[i].passivesklLv];
            inc=min(inc,0.05);
        }
    }
    if (!inc) return;
    _rep(i,1,n) {
        if (south[i].hp>0) {
            // cout<<south[i].hp<<" "<<south[i].maxhp<<" "<<inc<<endl;
            if (south[i].hp!=south[i].maxhp) printf("%s %d recovered +%d hp -> %d/%d\n",nowTeam[0],i,(int)(south[i].maxhp*inc),min(south[i].maxhp,south[i].hp+(int)(+south[i].maxhp*inc)),south[i].maxhp);
            south[i].hp+=(int)(south[i].maxhp*inc);
            south[i].hp=min(south[i].hp,south[i].maxhp);
        }
    }
}

void doAveragePassiveSkill() {
    _rep(i,1,n) if (!strcmp(south[i].type,"Average")) southExtraDefend+=passiveSkillAverage[south[i].passivesklLv];
    _rep(i,1,m) if (!strcmp(north[i].type,"Average")) northExtraDefend+=passiveSkillAverage[north[i].passivesklLv];
}

void doStrongPassiveSkill() {
    _rep(i,1,n) if (!strcmp(south[i].type,"Strong")) southExtraAttack+=passiveSkillStrong[south[i].passivesklLv];
    _rep(i,1,m) if (!strcmp(north[i].type,"Strong")) northExtraAttack+=passiveSkillStrong[north[i].passivesklLv];
}

int checkWin() {
    bool ok;
    ok=true;
    _rep(i,1,n) {
        if (south[i].hp>0) {
            ok=false;
            break;
        }
    }
    if (ok) return 0;
    ok=true;
    _rep(i,1,m) {
        if (north[i].hp>0) {
            ok=false;
            break;
        }
    }
    if (ok) return 1;
    return -1;
}

int main() {
    // FRR("P9381_final_1.in");
    // FRW("P9381_my.out");
    read(n),read(m);
    _rep(i,1,n) south[i]=readOnePerson(),south[i].hp=south[i].maxhp,south[i].skillExtra=1;
    _rep(i,1,m) north[i]=readOnePerson(),north[i].hp=north[i].maxhp,north[i].skillExtra=1;
    _rep(i,1,n) {
        if (i&1) southPos.emplace(southPos.begin(),i);
        else southPos.emplace_back(i);
    }
    _rep(i,1,m) {
        if (i&1) northPos.emplace(northPos.begin(),i);
        else northPos.emplace_back(i);
    }
    doAveragePassiveSkill();
    doStrongPassiveSkill();
    read(T);
    _rep(i,1,T) {
        doWeakPassiveSkill();
        char op[15];
        scanf("%s",op);
        int workPerson=getWorkPerson(i);
        if (!strcmp(op,"Basicattack")) {
            int target,atkpos,ddgpos;
            scanf(" target=%d atkpos=%d ddgpos=%d",&target,&atkpos,&ddgpos);
            doBasicAttack(workPerson,target,atkpos,ddgpos,getPositionExtra(atkpos,ddgpos));
            south[workPerson].skillExtra=1;
        } else if (!strcmp(op,"Specialattack")) {
            int target,atkpos,ddgpos;
            scanf(" target=%d atkpos=%d ddgpos=%d",&target,&atkpos,&ddgpos);
            doSpecialAttack(workPerson,target,atkpos,ddgpos,getPositionExtra(atkpos,ddgpos));
            south[workPerson].skillExtra=1;
        } else {
            int target;
            scanf(" target=%d",&target);
            doActiveSkill(workPerson,target);
        }
        _rep(i,1,m) {
            if (northMaxhpDecreaseEffect[i].first>0 && north[i].hp>0) {
                northMaxhpDecreaseEffect[i].second++;
                int dec=north[i].maxhp*northMaxhpDecreaseEffect[i].first;
                north[i].hp-=dec;
                printf("%s %d took %d damage from skill -> %d/%d\n",nowTeam[1],i,dec,max(0,north[i].hp),north[i].maxhp);;
                if (north[i].hp<=0) {
                    if (!strcmp(north[i].type,"Average")) northExtraDefend-=passiveSkillAverage[north[i].passivesklLv];
                    else if (!strcmp(north[i].type,"Strong")) northExtraAttack-=passiveSkillStrong[north[i].passivesklLv];
                }
                if (northMaxhpDecreaseEffect[i].second==3) {
                    northMaxhpDecreaseEffect[i]={0,0};
                }
            }
        }
        lasSouth=workPerson;
        if (!strcmp(nowTeam[0],"North")) {
            printf("North: ");
            _iter(it,southPos) printf("%d/%d ",max(0,south[*it].hp),south[*it].maxhp);
            putchar(10);
            swapSouthNorth();
            printf("South: ");
            _iter(it,southPos) printf("%d/%d ",max(0,south[*it].hp),south[*it].maxhp);
            putchar(10);
        } else {
            swapSouthNorth();
            printf("North: ");
            _iter(it,southPos) printf("%d/%d ",max(0,south[*it].hp),south[*it].maxhp);
            putchar(10);
            swapSouthNorth();
            printf("South: ");
            _iter(it,southPos) printf("%d/%d ",max(0,south[*it].hp),south[*it].maxhp);
            putchar(10);
            swapSouthNorth();
        }
        putchar(10);
    }
    int winner=checkWin();
    if (~winner) {
        printf("Team %s won.",nowTeam[winner^1]);
    }
    return 0;
}