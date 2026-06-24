#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int Rows;
int Columns;
int IndexSRow;
int IndexSColumn;
vector<vector<char>> Matrix;
string Output;
bool isValidIndices(int IndexRow,int IndexColumn)
{
    if((IndexRow>Rows)||(IndexRow<=0)||(IndexColumn>Columns)||(IndexColumn<=0))
        return false;
    return true;
}
int LastIndexRow;
int LastIndexColumn;
void DFS(int IndexRow,int IndexColumn,char c)
{
    Matrix[IndexRow][IndexColumn]='.';
    LastIndexRow=IndexRow;
    LastIndexColumn=IndexColumn;
    if(c!='-')
        Output+=c;
    if(Matrix[IndexRow][IndexColumn]=='.')
    {
        if((isValidIndices(IndexRow-1,IndexColumn))&&(Matrix[IndexRow-1][IndexColumn]!='.'))
           DFS(IndexRow-1,IndexColumn,'U');
        else if((isValidIndices(IndexRow+1,IndexColumn))&&(Matrix[IndexRow+1][IndexColumn]!='.'))
            DFS(IndexRow+1,IndexColumn,'D');
        else if((isValidIndices(IndexRow,IndexColumn-1))&&(Matrix[IndexRow][IndexColumn-1]!='.'))
            DFS(IndexRow,IndexColumn-1,'L');
        else if((isValidIndices(IndexRow,IndexColumn+1))&&(Matrix[IndexRow][IndexColumn+1]!='.'))
            DFS(IndexRow,IndexColumn+1,'R');
    }
}
int main(int argc,char *argv[])
{
    Output="";
    IndexSRow=-1;
    IndexSColumn=-1;
    LastIndexRow=-1;
    LastIndexColumn=-1;
    cin>>Rows>>Columns;
    Matrix.resize(Rows+2,vector<char>(Columns+2,'-'));
    for(int i=1;i<=Rows;i++)
    {
        for(int j=1;j<=Columns;j++)
        {
            cin>>Matrix[i][j];
            if(Matrix[i][j]=='S')
            {
                IndexSRow=i;
                IndexSColumn=j;
            }
        }
    }
    DFS(IndexSRow,IndexSColumn,'-');
    cout<<Output;
    if(LastIndexRow==IndexSRow)
    {
        if(LastIndexColumn==IndexSColumn+1)
            cout<<"L";
        else
            cout<<"R";
    }
    else
    {
        if(LastIndexRow==IndexSRow-1)
            cout<<"D";
        else
            cout<<"U";
    }
    cout<<"\n";
    return 0;
}