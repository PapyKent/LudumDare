#include "Physic.h"

using namespace std;

Physic::Physic(void)
{
}


Physic::~Physic(void)
{
}

bool Physic::collision(int xHero, int yHero, int xBad, int yBad){


	if(xHero/32==xBad/32){
		if(yHero/32 == yBad/32){
			return true;
		}
	}else{
		if(fabs(double(xHero-xBad))<20){
			if(fabs(double(yHero-yBad))<20){
				return true;
			}
		}
	}

	return false;

}
