#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
 
using namespace std;
 
int main()
{
    string msg;
    int flag,i,j;
    do
    {
        flag=0;
       cout<<"\n\n Enter the message (having bits 0 or 1 only) : ";
       cin>>msg;
       for(i=0;i<msg.length();i++)
       {
           if(msg[i]!='0'&&msg[i]!='1')
            flag=1;
       }
    }while(flag==1);
 
    string divisor("1011");
    string divisor_0("0000");
    const int div_len=4;
    string codeword(msg);
    string remainder;
    string temp_remainder;
 
    for(i=0 ; i<div_len-1 ; i++)
    {
        codeword +='0';
    }
    cout<<"\n\n Codeword after appending "<<div_len-1<<" zeroes is : "<<codeword;
 
    //for first division.
    if(codeword[0]=='0')   //use divisor_0.
    {
        for(i=1;i<div_len;i++)
        {
            if(codeword[i]=='0')
                remainder+='0';
            else
                remainder+='1';
        }
    }
 
    else
    {
        for(i=1;i<div_len;i++)
        {
            if(codeword[i]==divisor[i])
                remainder+='0';
            else
                remainder+='1';
        }
    }
 
    //for further divisions.
    for(i ; i<codeword.length() ; i++)
    {
        remainder+=codeword[i];
        if(remainder[0]=='0')  //use divisor_0.
        {
            for(j=1;j<div_len;j++)
            {
                if(remainder[j]=='0')
                    temp_remainder +='0';
                else
                    temp_remainder += '1';
            }
        }
 
        else     //use divisor.
        {
            for(j=1;j<div_len;j++)
            {
                if(remainder[j]==divisor[j])
                    temp_remainder +='0';
                else
                    temp_remainder += '1';
            }
        }
 
        remainder=temp_remainder;
        temp_remainder.clear();
    }
    cout<<"\n\n Remainder of the division performed is : "<<remainder;
    codeword.replace(msg.length() , div_len-1 , remainder);
    cout<<"\n\n Codeword is : "<<codeword;
    cout<<"\n\n Dataword is : "<<msg;
    cout<<"\n\n Remainder is : "<<remainder<<"\n\n";
 
    ofstream fout;
    fout.open("crc.txt",ios::out);
    fout<<codeword;
    fout.close();
 
    getch();
    return 0;
}
