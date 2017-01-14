#include<bits/stdc++.h>
using namespace std;


int main()
{
        ios::sync_with_stdio(false);

        string small,large;

        string s1 = "Hello World ";
        string s2 = "Hello Wo";

        int index = 0;


        if(s1.size() > s2.size())
        {
           small = s2;
           large = s1;
        }

        else
        {
          small = s1;
          large = s2;
        }


        for(int i=0; i<large.size(); i++)
        {
            if(index==small.size() || large[i] != small[index])  break;
            //if(large[i] != small[index])   break;
            else                   index++;
        }

       if(index==0)   cout<<" have no common prefix";
       else           cout<<large.substr(0,index);
}




















//Length of longest common prefix /lcp
//Source : http://ideone.com/9tjrWp




import java.util.*;
import java.lang.*;
import java.io.*;

class Ideone
{
    public static void main (String[] args) throws java.lang.Exception
    {
        String s = "Hello Wo";
        String s2 = "Hello World";
        String small,large;
      
        if(s.length() > s2.length())  
        {
           small = s2;
           large = s;
        }
      
        else              
        {
          small = s;
          large = s2;
        }
      
        int index = 0;
        for(char c: large.toCharArray())
        {
            if(index==small.length()) break;
            if(c != small.charAt(index)) break;
            index++;
        }
        if(index==0)   System.out.println(""+s+ " and "+s2+ " have no common prefix");
        else           System.out.println((large.substring(0,index)).length());
    }
}
