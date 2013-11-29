#include "jen.h"
#include "unit.h"
#include <cmath>
#include <iostream>

sideOfBoard jen::findSide (int minR,int maxR,int minC,int maxC)
{
	if(minR==0)
	{
		return bup;
	}
	else if(maxR==(ROWS-1))
	{
		return bdn;
	}
	else if(minC==0)
	{
		return blt;
	}
	else if(maxC==(COLS-1))
	{
		return brt;
	}
}
void jen::upStrat(int minR,int maxR,int minC,int maxC, SitRep sitrep)
{

}
void jen::dnStrat(int minR,int maxR,int minC,int maxC, SitRep sitrep)
{

}
void jen::rtStrat(int minR,int maxR,int minC,int maxC, SitRep sitrep)
{

}
void jen::ltStrat(int minR,int maxR,int minC,int maxC, SitRep sitrep)
{

}

void jen::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	sideOfBoard loca = findSide(minR, maxR, minC, maxC);
	if(loca == bup)
	{

	}
	else if(loca == bdn)
	{

	}
	else if(loca == brt)
	{

	}
	else if(loca == blt)
	{

	}

	if(rank==infantry)
	{
		if(maxC>(COLS/2)) // If on the right side of the board
		{
			int i;
			for(i=0; i<20; i++) //Place the infantry in each space of the first column
			{
				if (minR+i<maxR)
				{
					sitrep.thing[minR+i][minC].rank=infantry;
				}
				else if (minR+i>maxR) 
				{
					sitrep.thing[(minR+i)-maxR][minC+1].rank=infantry;//If the first row isn't long enough for the whole infantry
				}
			}
		}
		if(maxC<(COLS/2)) //If on the left side of the board
		{
			int i;
			for(i=0; i<20; i++) //Place the infantry in each space of the first column
			{
				if (minR+i<maxR) 
				{
					sitrep.thing[minR+i][maxC].rank=infantry; 
				}
				else if (minR+i>maxR)
				{
					sitrep.thing[(minR+i)-maxR][maxC-1].rank=infantry; //If the first row isn't long enough for the whole infantry
				}
			}
		}
	}
	if(rank==crown) //Place the king
	{
		if(maxC<(COLS/2)) //If on the left side of the board
		{
			int crownRow = (maxR-minR)/2; //in the center on the back row
			sitrep.thing[crownRow][minC];
		}
		else //or the right
		{
			int crownRow = (maxR-minR)/2; //in the center on the back row
			sitrep.thing[crownRow][maxC];
		}

	if(rank==archer)
	{


	}

	/*bool done=false;
	int tr,tc;
	Dir td;
	while(!done){
		tr=minR+rand()%(maxR-minR);	
		tc=minC+rand()%(maxC-minC);	
		if(sitrep.thing[tr][tc].what==space)done=true;
	}
	int rdist=ROWS/2-tr;
	int cdist=COLS/2-tc;
	if(abs(rdist)<abs(cdist)){
		if(cdist>0)td=rt;
		else td=lt;
	}else{
		if(rdist>0)td=up;
		else td=dn;
	}
	r=tr;
	c=tc;
	dir=td;*/
	}
}


// tell someone what you want to do
Action jen::Recommendation(SitRep sitrep)
{	
	// this code is provided as an example only
	// use at your own risk
	Action a; 

	// first, try to attack in front of you
	int tr=r,tc=c;
	switch(dir)
	{
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if(tr>=0&&tr<ROWS&&tc>=0&&tc<COLS)
	{
		if(sitrep.thing[tr][tc].what==unit)
		{
			if(sitrep.thing[tr][tc].tla!=tla)
			{
				a.action=attack;
				a.ar=tr;
				a.ac=tc;
				return a;
			}
		}
	}	
	// there is not an enemy in front of me
	// so head to the nearest enemy
	if(dir==sitrep.nearestEnemy.dirFor)
	{
		a.action=fwd;
		a.maxDist=1;
		if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
		return a;
	} else 
	{
		a.action=turn;
		a.dir=sitrep.nearestEnemy.dirFor;
		return a;
	}
	a.action=nothing;
	return a;
	
}

