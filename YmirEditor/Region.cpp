#include "Region.h"

void Region::setRegionInfo(CLIMATE c, RELIEF r, VEGETATION v, WATER w, WORLDOBJECT o)
{
	climate = c;
	relief = r;
	vegetation = v;
	water = w;
	object = o;
}
