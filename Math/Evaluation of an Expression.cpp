/*
 * Input: A mathematical expression
 * Output: Its result
 * Complexity: O(n), where n = len(expression)
 */


#include <fstream>

using namespace std;

ifstream fin("evaluare.in");
ofstream fout("evaluare.out");

char *p,E[100010];
int calculateSum();
int calculateProduct();
int calculateBraket();
int calculateNumber();
int main()
{
    p=E;
    fin>>p;
    fout<<calculateSum();
    return 0;
}
int calculateSum()
{
    int result=calculateProduct();
    while(*p=='+'||*p=='-')
    {
        if(*p=='+'){p++;result+=calculateProduct();}
        else       {p++;result-=calculateProduct();}
    }
    return result;
}
int calculateProduct()
{
    int result=calculateBraket();
    while(*p=='*'||*p=='/')
    {
        if(*p=='*'){p++;result*=calculateBraket();}
        else       {p++;result/=calculateBraket();}
    }
    return result;
}
int calculateBraket()
{
    if(*p=='(')
    {
        p++;
        int result=calculateSum();
        p++;
        return result;
    }
    return calculateNumber();
}
int calculateNumber()
{
    int result=0;
    while(isdigit(*p))
    {
        result=10*result+*p-'0';
        p++;
    }
    return result;
}