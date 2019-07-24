// Algue.C
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct FCell
{
    int mEv;
    struct FCell* mChildA;
    struct FCell* mChildB;
    char mDir;
};

typedef struct FCell FCell;
typedef struct FCell FAlgua;

FCell* CreateCell()
{
    FCell* tmp = malloc( sizeof( FCell ) );
    tmp->mEv = 4;
    tmp->mChildA = NULL;
    tmp->mChildB = NULL;
    tmp->mDir = '<';
    return tmp;
}

FCell* CreateCellWithParam( int iEv, char iDir )
{
    FCell* tmp = malloc( sizeof( FCell ) );
    tmp->mEv = iEv;
    tmp->mChildA = NULL;
    tmp->mChildB = NULL;
    tmp->mDir = iDir;
    return tmp;
}


FAlgua* CreateAlgua()
{
    return  CreateCell();
}

void DivideCell( FCell* iCell )
{
    iCell->mChildA = CreateCellWithParam( 4, '<' );
    iCell->mChildB = CreateCellWithParam( 5, '>' );
}

void EvolveCell( FCell* iCell )
{
    if( iCell->mEv < 10 )
        ++(iCell->mEv);

    if( iCell->mEv == 9 )
        DivideCell( iCell );
}


void EvolveAlgua( FAlgua* iAlgua )
{
    FCell* head = iAlgua;
    if( !head ) return;
    EvolveAlgua( head->mChildA );
    EvolveAlgua( head->mChildB );
    EvolveCell( head );
}

int GetAlguaDepthRecursive( FAlgua* iAlgua, int iDepth )
{
    FCell* head = iAlgua;
    if( !head ) return iDepth;
    int nextDepth = iDepth + 1;
    int depthA = GetAlguaDepthRecursive( head->mChildA, nextDepth );
    int depthB = GetAlguaDepthRecursive( head->mChildB, nextDepth );
    return depthA > depthB ? depthA : depthB;
}

int GetAlguaDepth( FAlgua* iAlgua )
{
    return  GetAlguaDepthRecursive( iAlgua, 0 );
}

void PrintAlguaAtDepthRecursive( FAlgua* iAlgua, int iTargetDepth, int iCurrentDepth )
{
    FCell* head = iAlgua;
    if( !head ) return;
    if( iCurrentDepth < iTargetDepth )
    {
        int nextDepth = iCurrentDepth + 1;
        PrintAlguaAtDepthRecursive( head->mChildA, iTargetDepth, nextDepth );
        PrintAlguaAtDepthRecursive( head->mChildB, iTargetDepth, nextDepth );
    }
    else if( iTargetDepth == iCurrentDepth )
    {
        printf( "%c", head->mDir );
    }
}

void PrintAlguaAtDepth( FAlgua* iAlgua, int iDepth )
{
    PrintAlguaAtDepthRecursive( iAlgua, iDepth, 0 );
}

void PrintAlgua( FAlgua* iAlgua )
{
    FCell* head = iAlgua;
    if( !head ) return;
    int depth = GetAlguaDepth( iAlgua );
    for( int i = 0; i < depth; ++i )
    {
        PrintAlguaAtDepth( iAlgua, i );
        printf( "\n" );
    }
}

int main()
{
    FAlgua* algua = CreateAlgua();

    for( int i = 0; i < 34; ++i )
        EvolveAlgua( algua );

    PrintAlgua( algua );
}
