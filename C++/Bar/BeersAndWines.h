#include "wine.h"
#include "beer.h"

class Heineken : public Beer
{
public:
	Heineken() :Beer("Heineken"){}
};
class Goldstar : public Beer
{
public:
	Goldstar() :Beer("Goldstar"){}
};
class Maccabi : public Beer
{
public:
	Maccabi() :Beer("Maccabi"){}
};
class Tuborg : public Beer
{
public:
	Tuborg() :Beer("Tuborg"){}
};



class EmeraldRieslingCarmel : public WhiteWine
{
public:
	EmeraldRieslingCarmel(int year) : WhiteWine("Emerald Riesling Carmel", year){}
};
class GoldenSmadar : public WhiteWine
{
public:
	GoldenSmadar(int year ): WhiteWine("Golden Smadar", year){}
};
class YardenShardone : public WhiteWine
{
public:
	YardenShardone(int year) : WhiteWine("Jordan Shardone", year){}
};



class Chianti : public RedWine
{
public:
	Chianti(int year) : RedWine("Chianti", year){}
};
class YardenMountHermonRed :public RedWine
{
public:
	YardenMountHermonRed(int year) : RedWine("Jordan Mount Hermon Red", year){}
};
class YardenCabernetSauvignon :public RedWine
{
public:
	YardenCabernetSauvignon(int year) : RedWine("Yarden Cabernet Sauvignon", year){}
};
class ChadeauMargot :public RedWine
{
public:
	ChadeauMargot(int year) : RedWine("Chadeau Margot", year){}
};