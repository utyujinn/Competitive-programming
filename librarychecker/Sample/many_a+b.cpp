#include<iostream>
using namespace std;

const int BUF_SZ=1<<15;

inline namespace Input {
char buf[BUF_SZ];
int pos;
int len;
char next_char() {
	if (pos == len) {
		pos = 0;
		len = (int)fread(buf, 1, BUF_SZ, stdin);
		if (!len) { return EOF; }
	}
	return buf[pos++];
}

int read_long() {
	long x;
	char ch;
	int sgn = 1;
	while (!isdigit(ch = next_char())) {
		if (ch == '-') { sgn *= -1; }
	}
	x = ch - '0';
	while (isdigit(ch = next_char())) { x = x * 10 + (ch - '0'); }
	return x * sgn;
}
}  // namespace Input



int main(){
  long t=read_long();
  long a,b;
  for(;t--;){
		a=read_long();
		b=read_long();
    cout<<a+b<<"\n";
  }
}
