#include "Field.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void fieldInit(Field *fieldP,const char file[])
{
	int x,y;
    FILE *filename;
    int i , j;
    char random_field[19][30];
    filename=fopen(file,"r");
    for (i = 0; i < 19; i++)
{

    for (j = 0; j < 30; j++)
    {
         fscanf(filename, "%c", &random_field[i][j]);

    }

    fscanf(filename, "\n");
}

    for (i = 0; i < 19; i++)
{

    for (j = 0; j < 30; j++)
    {
        printf("%c",random_field[i][j]);
    }

    printf("\n");
}
    fclose(filename);
    fieldP->dimX = 30;
	fieldP->dimY = 19;

	fieldP->tab = (char**)malloc(sizeof(char *)*fieldP->dimY);
	for (y=0; y<fieldP->dimY; y++)
		fieldP->tab[y] = (char *)malloc(sizeof(char)*fieldP->dimX);

	for(y=0;y<fieldP->dimY;y++)
		{for(x=0;x<fieldP->dimX;x++)
	fieldP->tab[y][x] = random_field[y][x];}

}
void fieldFree(Field *fieldP)
{
	int y;

	for (y=0; y<fieldP->dimY; y++)
    free(fieldP->tab[y]);
	free(fieldP->tab);

	fieldP->dimX = 0;
	fieldP->dimY = 0;
	fieldP->tab = NULL;
}
int fieldPosValid(const Field *fieldP, const int x, const int y)
{
	if (x>=0 && x<fieldP->dimX && y>=0 && y<fieldP->dimY && fieldP->tab[y][x]!='#')
		return 1;
	else
		return 0;
}

const char fieldGetXY(const Field *fieldP, const int x, const int y)
{
	assert( x>=0) ;
	assert( y>=0) ;
	assert( x<fieldP->dimX ) ;
	assert( y<fieldP->dimY ) ;
	return fieldP->tab[y][x];
}

void fieldSetXY(const Field *fieldP, const int x, const int y, const char val)
{
	assert( x>=0) ;
	assert( y>=0) ;
	assert( x<fieldP->dimX ) ;
	assert( y<fieldP->dimY ) ;
	fieldP->tab[y][x] = val;
}
const int fieldGetDimX(const Field *fieldP)
{
	return fieldP->dimX;
}

const int fieldGetDimY(const Field *fieldP)
{
	return fieldP->dimY;
}
