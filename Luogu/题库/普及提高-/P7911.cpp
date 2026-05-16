#include <bits/stdc++.h>
using namespace std;

bool ip_ok(int d) {
    if (d>=0 && d<=255) {
        return true;
    } else {
        return false;
    }
}

bool port_ok(int d) {
    if (d>=0 && d<=65535) {
        return true;
    } else {
        return false;
    }
}

bool full_ok(int a,int b,int c,int d,int port) {
    if (ip_ok(a) && ip_ok(b) && ip_ok(c) && ip_ok(d) && port_ok(port)) {
        return true;
    } else {
        return false;
    }
}

string get_ip_string(int a,int b,int c,int d,int port) {
    stringstream ss;
    ss<<a<<"."<<b<<"."<<c<<"."<<d<<":"<<port;
    string result;
    ss>>result;
    return result;
}

map<string,int> servers;

int main() {
    int n;
    scanf("%d",&n);
    string type;
    int a,b,c,d,port,now_reading;
    char ch;
    string in_ip;
    bool ok;
    for (int i=0;i<n;++i) {
        cin>>type;
        now_reading=1;
        a=b=c=d=port=-1;
        ok=true;
        cin>>in_ip;
        int j=0;
        while (true) {
            if (j<in_ip.size()) {
                ch=in_ip[j];
            } else {
                ch=' ';
            }
            // printf("%c %d %d.%d.%d.%d:%d %d\n",ch,now_reading,a,b,c,d,port,ok);
            if (!isdigit(ch)) {
                if (ch=='.' && now_reading<=3) {
                    ++now_reading;
                } else if (ch==':' && now_reading==4) {
                    ++now_reading;
                } else if (now_reading==5 && isspace(ch)) {
                    if (ok) {
                        if (full_ok(a,b,c,d,port)) {
                            string ipstring;
                            ipstring=get_ip_string(a,b,c,d,port);
                            if (type=="Server") {
                                if (servers.find(ipstring)==servers.end()) {
                                    servers.insert(make_pair(ipstring,i+1));
                                    printf("OK\n");
                                    break;
                                } else {
                                    printf("FAIL\n");
                                    break;
                                }
                            } else {
                                auto iter=servers.find(ipstring);
                                if (iter!=servers.end()) {
                                    printf("%d\n",(*iter).second);
                                    break;
                                } else {
                                    printf("FAIL\n");
                                    break;
                                }
                            }
                        } else {
                            printf("ERR\n");
                            break;
                        }
                    } else {
                        printf("ERR\n");
                        break;
                    }
                } else {
                    printf("ERR\n");
                    break;
                }
            } else {
                if (a==0 && now_reading==1) {
                    ok=false;
                }
                if (b==0 && now_reading==2) {
                    ok=false;
                }
                if (c==0 && now_reading==3) {
                    ok=false;
                }
                if (d==0 && now_reading==4) {
                    ok=false;
                }
                if (port==0 && now_reading==5) {
                    ok=false;
                }
                // printf("ok:%d\n",ok);
                if (a==-1 && now_reading==1) a=0;
                if (b==-1 && now_reading==2) b=0;
                if (c==-1 && now_reading==3) c=0;
                if (d==-1 && now_reading==4) d=0;
                if (port==-1 && now_reading==5) port=0;
                switch (now_reading) {
                    case 1: {
                        a=a*10+(ch-'0');
                        if (a>255) {
                            ok=false;
                        }
                        break;
                    }
                    case 2: {
                        b=b*10+(ch-'0');
                        if (b>255) {
                            ok=false;
                        }
                        break;
                    }
                    case 3: {
                        c=c*10+(ch-'0');
                        if (c>255) {
                            ok=false;
                        }
                        break;
                    }
                    case 4: {
                        d=d*10+(ch-'0');
                        if (d>255) {
                            ok=false;
                        }
                        break;
                    }
                    case 5: {
                        port=port*10+(ch-'0');
                        if (port>65535) {
                            ok=false;
                        }
                    }
                    default: {
                        break;
                    }
                }
            }
            ++j;
        }
    }
}