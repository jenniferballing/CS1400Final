#ifndef jen_H
#define jen_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

enum sideOfBoard {bup, bdn, brt, blt};

class jen : public Unit {
public:
	jen():Unit(){}

	jen(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){} 

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	// put unit on board
	Action Recommendation(SitRep sitrep);
	// tell someone what you want to do

private:
	sideOfBoard findSide (int minR,int maxR,int minC,int maxC);
	void upStrat(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	void dnStrat(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	void rtStrat(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	void ltStrat(int minR,int maxR,int minC,int maxC, SitRep sitrep);


};
#endif
