// #include <bits/stdc++.h>
// using namespace std;

// int Bonus_FlatNumber(string a)
// {
//     for(int i=0;i<a.length();i++)
//     {
//         if(a[i]>57||a[i]<48) {return 0;break;}
//     }
//     return -35;
// }
// int Bonus_FlatLower(string a)
// {
//     for(int i=0;i<a.length();i++)
//     {
//         if(a[i]>122||a[i]<97) {return 0;break;}
//     }
//     return -15;
// }
// int Number_Excess(string a)
// {
//     return(a.length()-8);
// }
// int Number_Upper(string a)
// {
//     int dem=0;
//     for(int i=0;i<a.length();i++)
//     {
//         if(a[i]>=65&&a[i]<=90)
//             dem++;
//     }
//     return dem;
// }
// int Number_Numbers(string a)
// {
//     int dem=0;
//     for(int i=0;i<a.length();i++)
//     {
//         if(a[i]>=48&&a[i]<=57)
//             dem++;
//     }
//     return dem;
// }
// int Number_Symbols(string a)
// {
//     int dem=0;
//     for(int i=0;i<a.length();i++)
//     {
//         if(a[i]=='!'||a[i]=='~'||a[i]=='_'||a[i]=='^'||a[i]=='?'||a[i]=='@'||(a[i]>=35&&a[i]<=38)||a[i]=='*')
//             dem++;
//     }
//     return dem;
// }
// int Bonus_Combo(string a)
// {
//     if(Number_Symbols(a)>0&&Number_Numbers(a)>0&&Number_Upper(a)>0)
//         return 25;
//     else if((Number_Symbols(a)>0&&Number_Numbers(a)>0)||(Number_Symbols(a)>0&&Number_Upper(a)>0)||(Number_Numbers(a)>0&&Number_Upper(a)>0))
//         return 15;
//     else return 0;
// }
// bool Kiemtra(string a)
// {
//     for(int i=0;i<a.length();i++)
//     {
//         if(a[i]=='.'||a[i]=='/'||a[i]=='\''||a[i]=='\\'||a[i]==','||a[i]=='"'||a.length()<8)
//             return 1;
//     }

//     return 0;
// }
// int main()
// {
//     string a;
//     cin>>a;
//     int s=40+3*Number_Excess(a)+4*Number_Upper(a)+5*Number_Numbers(a)+5*Number_Symbols(a)+Bonus_Combo(a)+Bonus_FlatLower(a)+Bonus_FlatNumber(a);
//     if(Kiemtra(a)==1) cout<<"KhongHopLe";
//     else
//     {
//         if(s<50) cout<<"Yeu";
//         else if(s>=50&&s<75) cout<<"Vua";
//         else if(s>=75&&s<100) cout<<"Manh";
//         else if(s>=100) cout<<"RatManh";
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int Number_Numbers( string chuoi)
{
    int n=chuoi.length(),count=0;
    for (int i=0;i<n;i++)
    {
        if (chuoi[i]>=48 && chuoi [i]<=57) 
        {
            count++;
        }
       
    } return count;
}
int Number_Symbols(string chuoi)
{  // [! , @ , # , $ , % , ^ , & , * , ? , _ , ~]
    int count=0,n=chuoi.length();
    for (int i=0;i<n;i++)
    {
     if (  (chuoi[i]>=35 && chuoi[i]<=38) || chuoi[i]==42|| chuoi[i]=='@'|| chuoi[i]==92 || chuoi[i]==63 || chuoi[i]==95 ||chuoi [i]=='~'|| chuoi[i]=='!' )
       
        count ++;
    }
    return count;
}
int Number_Upper(string chuoi)
{
    int count=0,n=chuoi.length();
    for (int i=0;i<n;i++)
    {
        if (chuoi[i]>=65 && chuoi[i]<=90 )
        count ++;
    }
    return count;
}
int Number_Excess(string chuoi)
{
    return (chuoi.length()-8);
}
int Bonus_FlatNumber(string chuoi)
{
    int n=chuoi.length();
    for (int i=0;i<n;i++)
    {
        if (chuoi[i]<48 || chuoi [i]>57) 
        {
            return 0;
            break;
        }
       
    } return -35;
}
int Bonus_FlatLower(string chuoi)
{
    int n=chuoi.length();
    for (int i=0;i<n;i++)
    {
        if (chuoi[i]<97 || chuoi[i]>122) 
        {
            return 0; 
            break;
            
        }
       
    } return -15;
}
int Bonus_combo(string chuoi)
{
    if ( Number_Upper(chuoi)>0 && Number_Numbers(chuoi)>0 && Number_Symbols(chuoi)>0 )
    return 25;
    else if ( (Number_Symbols(chuoi)>0 && Number_Numbers(chuoi)>0) || (Number_Symbols(chuoi)>0 && Number_Upper(chuoi)>0) ||  (Number_Numbers(chuoi)>0 && Number_Upper(chuoi)>0))
    return 15;
    else return 0;
}
// Nếu mật khẩu chứa các có độ dài < 8 hoặc có một trong các dấu [ . , \ , / , ‘ ‘, ’,’ ] thì làmột mật khẩu không hợp lệ .
bool check(string chuoi)
{
    int n=chuoi.length();
    for (int i=0;i<n;i++)
    {
         
       if (chuoi[i]=='.'||chuoi[i]=='/'||chuoi[i]=='\''||chuoi[i]==','||chuoi[i]=='"'||n<8)
        return 0;
    }
    return 1;
}
int main()
{
    string chuoi;
    cin>>chuoi;
    int score=40+3*Number_Excess(chuoi)+4*Number_Upper(chuoi)+5*Number_Numbers(chuoi)+5*Number_Symbols(chuoi)+Bonus_combo(chuoi)+Bonus_FlatLower(chuoi)+Bonus_FlatNumber(chuoi);
    if (check(chuoi)==0) cout<<"Khong hop le";
    else 
    {
        if (score < 50) cout<<"Yeu";
        else if (score>=50 && score < 75 ) cout<<"Vua";
        else if (score>=75 && score <100) cout<<"Manh";
        else if (score>=100) cout<<"Rat manh";
    }
    return 0;
}