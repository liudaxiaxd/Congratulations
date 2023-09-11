#include<iostream>
using namespace std;
bool swi(char one,char two,char plain[]);
int count_sum=0;
int main(){
    int sum = 0;
    const int max = 0x7f;
    string cipher="lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi bpr xjvni mkd ymibrut jx irhx wi bpr riirkvr jx ymbinlmtmipw utn qmumbr dj w ipmhh but bj rhnvwdmbr bpr yjeryrkbi jx bpr qmbm mvvjudwko bj yt wkbrusurbmbwjk lmird jk xjubt trmui jx ibndtwb wi kjb mk rmit bmiq bj rashmwk rmvp yjeryrkb mkd wbi iwokwxwvmkvr mkd ijyr ynib urymwk nkrashmwkrd bj ower m vjyshrbr rashmkmbwjk jkr cjnhd pmer bj lr fnmhwxwrd mkdwkiswurd bj invp mk rabrkb bpmb pr vjnhd urmvp bpr ibmbr jx rkhwopbrkrd ywkd vmsmlhr jx urvjokwgwko ijnkdhrii ijnkd mkd ipmsrhrii ipmsr w dj kjb drry ytirhx bpr xwkmh mnbpjuwbt lnb yt rasruwrkvr cwbp qmbm pmi hrxb kj djnlb bpmb bpr xjhhjcwko wi bpr sujsru msshwvmbwjk mkd wkbrusurbmbwjk w jxxru yt bprjuwri wk bpr pjsr bpmb bpr riirkvr jx jqwkmcmk qmumbr cwhh urymwk wkbmvb";
    vector<int>ps;
    char plain[1000];
    int count[max] = {0};
    for(int i=0;i<cipher.length();i++){
        count[cipher[i]]++;
        count_sum++;
        sum++;
        if(cipher[i]==' '){plain[i] = ' ';sum--;}
    }
    for(int i=0x61;i<0x7B;i++){
        int len = ps.size();
        int flag = 1;
        for(int j=0;j<len;j++){
            if(count[ps[j]]<count[i]){
                ps.insert(ps.begin()+j,i);
                flag--;
                break;
            }
        }
        if(flag) ps.push_back(i);
    }
    cout<<"sum:"<<sum<<endl;
    for(int i=0;i<26;i++){
        cout<<(char)ps[i]<<":"<<count[ps[i]];
        for(int j=0;j<count[ps[i]];j++){
            cout<<'*';
        }
        cout<<endl;
    }
    string alpha_fre = "etaoinsrhlducfmwygpbvkxjqz";
    for(int i=0;i<26;i++){
        int pos = 0;
        do{
            pos = cipher.find((char)ps[i]);
            cipher[pos] = ' ';
            plain[pos] = alpha_fre[i];
        }while(pos!=string::npos);
    }
    cout<<plain<<endl;

    char one;
    char two;
    while(1){
        cout<<"\n\nEnter like \"a b\" to switch a and b, enter ~ to exit."<<endl;
        cin>>one;
        if(one == '~') break;
        cin>>two;
        swi(one,two,plain);
        cout<<plain<<"\n\n"<<endl;
    }
}

bool swi(char one,char two,char plain[]){
    for(int i=0;i<count_sum;i++){
        if(plain[i]==one) plain[i]=two;
        else if(plain[i]==two) plain[i]=one;
    }
    return true;
}
/*输入这个可以得到答案
g b
r h
r i
c u
m u
g d
r o
m f
n i
n r
w p
l y
l g
x v
g y
g d
w g
w k


输入加个回车
*/