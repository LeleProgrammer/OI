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
#define _riter(i,a) for (auto i=a.rbegin();i!=a.rend();++i)
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

namespace IO {
    template<typename T> inline void read(T& x) {
        int s=1; char c=getchar(); x=0;
        while (!isdigit(c)) { if (c=='-') s=-1; c=getchar(); }
        while (isdigit(c) && c!=EOF) x=x*10+(c-'0'),c=getchar();
        x*=s;
    }
    inline void readstr(string& x) {
        x.clear(); char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c) && c!=EOF) x.push_back(c),c=getchar();
    }
    inline void readstr(char* x) {
        int idx=0; char c=getchar();
        while (isspace(c)) c=getchar();
        while (!isspace(c) && c!=EOF) x[idx++]=c,c=getchar();
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
    inline void writestr(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); }
    inline void writestrsp(string& x) { _iter(it,x) putchar(*it); putchar(' '); }
    inline void writestrsp(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(' '); }
    inline void writestrln(string& x) { _iter(it,x) putchar(*it); putchar(10); }
    inline void writestrln(char* x) { _rep(i,0,strlen(x)-1) putchar(x[i]); putchar(10); }
};

using namespace IO;

map<string,int> varTypes; // 0: int, 1: array
map<string,int> varData;
map<string,unordered_map<int,int>> arrayData;

void strip(string& s) {
	while (!s.empty() && isspace(s.back())) s.pop_back();
	int pos=0;
	_rep(i,0,(int)s.size()-1) {
		if (!isspace(s[i])) {
			pos=i;
			break;
		}
	}
	if (pos) s.erase(s.begin(),s.begin()+pos);
}

string readline() {
	string s;
	getline(cin,s);
	if (cin.eof()) return "END";
	strip(s);
	return s;
}

int analysisType(string s) {
	/*
	0: vars
	1: ihu
	2: hor
	3: while
	4: yosoro
	5: set
	6: ENDS
	7: an empty line
	*/
	if (s.empty()) return 7;
	if (s=="END") return 6;
	if (s[0]=='{') { // vars ihu hor while
		int pos=1;
		string cur="";
		while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
		while (pos<=(int)s.size()-1 && !isspace(s[pos])) cur.push_back(s[pos++]);
		if (cur=="vars") return 0;
		else if (cur=="ihu") return 1;
		else if (cur=="hor") return 2;
		else if (cur=="while") return 3;
		else exit(1000);
	} else if (s[0]==':') { // yosoro set
		int pos=1;
		string cur="";
		while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
		while (pos<=(int)s.size()-1 && !isspace(s[pos])) cur.push_back(s[pos++]);
		if (cur=="yosoro") return 4;
		else if (cur=="set") return 5;
		else exit(1001);
	} else if (s[0]=='}') return 6;
	else exit(1002);
}

void processVars() {
	while (true) {
		string s=readline();
		if (s=="}") break;
		int pos=0;
		string varName="";
		while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
		while (pos<=(int)s.size()-1 && !isspace(s[pos]) && s[pos]!=':') varName.push_back(s[pos++]);
		while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
		while (pos<=(int)s.size()-1 && s[pos]==':') pos++;
		while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
		if (s[pos]=='a') { // array
			varTypes[varName]=1;
		} else if (s[pos]=='i') { // int
			varTypes[varName]=0;
		} else exit(1003);
	}
}

int toInt(string& s) {
	int ans=0;
	int k=1;
	_rep(i,0,(int)s.size()-1) {
		if (isdigit(s[i])) ans=ans*10+s[i]-'0';
		else if (s[i]=='-') k=-k;
		else exit(1006);
	}
	return ans*k;
}

int processPureExpression(string& s) {
	/*
	s: a number, a variable, or an array with an index
	*/
	if (isdigit(s[0]) || s[0]=='-') return toInt(s);
	bool array=false;
	_rep(i,0,(int)s.size()-1) if (s[i]=='[') array=true;
	if (!array) return varData[s];
	string t="";
	string indexExpr="";
	int start=0;
	_rep(i,0,(int)s.size()-1) {
		if (s[i]!=']' && start==1) indexExpr.push_back(s[i]);
		else if (s[i]==']' && start==1) start=2;
		else if (s[i]=='[' && start==0) start=true;
		else if (start==0) t.push_back(s[i]);
	}
	int index=processPureExpression(indexExpr);
	// cout<<"fetch: "<<t<<" "<<index<<" /// "<<indexExpr<<endl;
	return arrayData[t][index];
}

int& processPureExpressionWithQuote(string& s) {
	/*
	s: a variable, or an array with an index
	*/
	bool array=false;
	_rep(i,0,(int)s.size()-1) if (s[i]=='[') array=true;
	if (!array) return varData[s];
	string t="";
	string indexExpr="";
	int start=0;
	_rep(i,0,(int)s.size()-1) {
		if (s[i]!=']' && start==1) indexExpr.push_back(s[i]);
		else if (s[i]==']' && start==1) start=2;
		else if (s[i]=='[' &&start==0) start=true;
		else if (start==0) t.push_back(s[i]);
	}
	int index=processPureExpression(indexExpr);
	// cout<<"fetch: "<<t<<" "<<index<<" /// "<<indexExpr<<endl;
	return arrayData[t][index];
}

int processExpression(string& s) {
	/*
	s: something +/- something +/- something ...
	*/
	int ans=0;
	int k=1;
	string expr="";
	_rep(i,0,(int)s.size()-1) {
		if (s[i]=='+' || s[i]=='-') {
			if (!expr.empty()) { // except (negative at the beginning)
				int value=processPureExpression(expr);
				value*=k;
				ans+=value;
				expr="";
			}
			if (s[i]=='+') k=1;
			else k=-1;
		} else expr.push_back(s[i]);
	}
	if (!expr.empty()) {
		int value=processPureExpression(expr);
		value*=k;
		ans+=value;
	}
	return ans;
}

bool processTrueFalse(string operation,string exprA,string exprB) {
	int valueA=processExpression(exprA);
	int valueB=processExpression(exprB);
	bool res;
	if (operation=="lt") res=(valueA<valueB);
	else if (operation=="gt") res=(valueA>valueB);
	else if (operation=="le") res=(valueA<=valueB);
	else if (operation=="ge") res=(valueA>=valueB);
	else if (operation=="eq") res=(valueA==valueB);
	else if (operation=="neq") res=(valueA!=valueB);
	else exit(1005);
	return res;
}

bool haveLeftBracket(string& s) {
	_iter(it,s) if ((*it)=='{') return true;
	return false;
}

void run(bool ignore,bool readFromStringVector,vector<string>* readCodes) {
	int ptr=0;
	while (true) {
		string s;
		if (!readFromStringVector) s=readline();
		else {
			if (ptr==(int)(*readCodes).size()) break;
			else s=(*readCodes)[ptr++];
		}
		int type=analysisType(s);
		// printf("Detected code type: %d\n",type);
		if (type==7) continue;
		if (type==6) break; // END
		else if (ignore) continue;
		if (type==0) { // vars
			processVars();
		} else if (type==1) { // ihu
			int pos=0;
			string operation,exprA,exprB;
			while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
			while (pos<=(int)s.size()-1 && s[pos]=='{') pos++;
			while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
			if (s[pos]!='i' || s[pos+1]!='h' || s[pos+2]!='u') exit(1004);
			pos+=3;
			while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
			while (pos<=(int)s.size()-1 && !isspace(s[pos]) && s[pos]!=',') operation.push_back(s[pos++]);
			while (pos<=(int)s.size()-1 && (isspace(s[pos]) || s[pos]==',')) pos++;
			while (pos<=(int)s.size()-1 && s[pos]!=',') { if (!isspace(s[pos])) exprA.push_back(s[pos]); pos++; }
			while (pos<=(int)s.size()-1 && (isspace(s[pos]) || s[pos]==',')) pos++;
			while (pos<=(int)s.size()-1) { if (!isspace(s[pos])) exprB.push_back(s[pos]); pos++; }
			vector<string> codes;
			int rem=1;
			while (true) {
				string s;
				if (!readFromStringVector) s=readline();
				else {
					if (ptr==(int)(*readCodes).size()) break;
					else s=(*readCodes)[ptr++];
				}
				if (haveLeftBracket(s)) rem++;
				int type=analysisType(s);
				if (type==6) rem--;
				if (!rem) break;
				codes.emplace_back(s);
			}
			bool res=processTrueFalse(operation,exprA,exprB);
			if (res) run(false,true,&codes);
		} else if (type==2) { // hor
			int pos=0;
			string varName,exprA,exprB;
			while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
			while (pos<=(int)s.size()-1 && s[pos]=='{') pos++;
			while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
			if (s[pos]!='h' || s[pos+1]!='o' || s[pos+2]!='r') exit(1004);
			pos+=3;
			while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
			while (pos<=(int)s.size()-1 && !isspace(s[pos]) && s[pos]!=',') varName.push_back(s[pos++]);
			while (pos<=(int)s.size()-1 && (isspace(s[pos]) || s[pos]==',')) pos++;
			while (pos<=(int)s.size()-1 && s[pos]!=',') { if (!isspace(s[pos])) exprA.push_back(s[pos]); pos++; }
			while (pos<=(int)s.size()-1 && (isspace(s[pos]) || s[pos]==',')) pos++;
			while (pos<=(int)s.size()-1) { if (!isspace(s[pos])) exprB.push_back(s[pos]); pos++; }
			int valueA=processExpression(exprA);
			int valueB=processExpression(exprB);
			vector<string> codes;
			int rem=1;
			while (true) {
				string s;
				if (!readFromStringVector) s=readline();
				else {
					if (ptr==(int)(*readCodes).size()) break;
					else s=(*readCodes)[ptr++];
				}
				if (haveLeftBracket(s)) rem++;
				int type=analysisType(s);
				if (type==6) rem--;
				if (!rem) break;
				codes.emplace_back(s);
			}
			int& var=processPureExpressionWithQuote(varName);
			_rep(i,valueA,valueB) {
				// cout<<":::::::::::::: FOR "<<valueA<<" "<<valueB<<" "<<i<<endl;
				var=i;
				run(false,true,&codes);
			}
		} else if (type==3) { // while
			int pos=0;
			string operation,exprA,exprB;
			while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
			while (pos<=(int)s.size()-1 && s[pos]=='{') pos++;
			while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
			if (s[pos]!='w' || s[pos+1]!='h' || s[pos+2]!='i' || s[pos+3]!='l' || s[pos+4]!='e') exit(1004);
			pos+=5;
			while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
			while (pos<=(int)s.size()-1 && !isspace(s[pos]) && s[pos]!=',') operation.push_back(s[pos++]);
			while (pos<=(int)s.size()-1 && (isspace(s[pos]) || s[pos]==',')) pos++;
			while (pos<=(int)s.size()-1 && s[pos]!=',') { if (!isspace(s[pos])) exprA.push_back(s[pos]); pos++; }
			while (pos<=(int)s.size()-1 && (isspace(s[pos]) || s[pos]==',')) pos++;
			while (pos<=(int)s.size()-1) { if (!isspace(s[pos])) exprB.push_back(s[pos]); pos++; }
			vector<string> codes;
			int rem=1;
			while (true) {
				string s;
				if (!readFromStringVector) s=readline();
				else {
					if (ptr==(int)(*readCodes).size()) break;
					else s=(*readCodes)[ptr++];
				}
				if (haveLeftBracket(s)) rem++;
				int type=analysisType(s);
				if (type==6) rem--;
				if (!rem) break;
				codes.emplace_back(s);
			}
			while (processTrueFalse(operation,exprA,exprB)) {
				// cout<<"::::::::::::::::::::::: WHILE "<<exprA<<" "<<operation<<" "<<exprB<<";;;;; "<<processExpression(exprA)<<" "<<operation<<" "<<processExpression(exprB)<<endl;
				run(false,true,&codes);
			}
		} else if (type==4) { // yosoro
			string expr;
			int pos=0;
			while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
			while (pos<=(int)s.size()-1 && s[pos]==':') pos++;
			while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
			if (s[pos]!='y' || s[pos+1]!='o' || s[pos+2]!='s' || s[pos+3]!='o' || s[pos+4]!='r' || s[pos+5]!='o') exit(1007);
			pos+=6;
			while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
			while (pos<=(int)s.size()-1) { if (!isspace(s[pos])) expr.push_back(s[pos]); pos++; }
			int value=processExpression(expr);
			writesp(value);
		} else if (type==5) { // set
			int pos=0;
			string exprA,exprB;
			while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
			while (pos<=(int)s.size()-1 && s[pos]==':') pos++;
			while (pos<=(int)s.size()-1 && isspace(s[pos])) pos++;
			if (s[pos]!='s' || s[pos+1]!='e' || s[pos+2]!='t') exit(1008);
			pos+=3;
			while (pos<=(int)s.size()-1 && s[pos]!=',') { if (!isspace(s[pos])) exprA.push_back(s[pos]); pos++; }
			while (pos<=(int)s.size()-1 && (isspace(s[pos]) || s[pos]==',')) pos++;
			while (pos<=(int)s.size()-1) { if (!isspace(s[pos])) exprB.push_back(s[pos]); pos++; }
			int& var=processPureExpressionWithQuote(exprA);
			int value=processExpression(exprB);
			var=value;
		}
	}
}

int main() {
	run(false,false,nullptr);
}

/*
{ vars
    chika:int
    you:int
    ruby:array[int, 1..2]
    i:int
}

:yosoro 2

:set chika, 1
:set you, 2
:yosoro chika + you

{ ihu eq, chika, 1
    :set you, 3
    :yosoro 1
}

{ hor i, 1, you
    :yosoro i
}

:set i, 1
{ while le, i, 2
    :yosoro i
    :set ruby[i], i+1
    :yosoro ruby[i]
    :set i, i+1
}
*/