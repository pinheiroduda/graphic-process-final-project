
#include <iostream>
#include <vector>
#include <thread>

using namespace std;

struct CoinCoord
{
  int x;
  int y;
};

Coord getRandomCoordForCoin(TileMap *tmap)
{
  int x = rand() % tmap->getWidth();
  int y = rand() % tmap->getHeight();
  return {x, y};
}

bool coinHasFloor(TileMap *tmap)
{

  for (int i = 0; i < tmap->getWidth(); i++)
  {
    for (int j = 0; j < tmap->getHeight(); j++)
    {
      if (tmap->getTile(i, j) != 1)
      {
        return true;
      }
    }
  }

  return false;
}

void spawnCoin(TileMap *tmap)
{
  Coord coinCoord = getRandomCoordForCoin(tmap);
  while (tmap->getTile(coinCoord.x, coinCoord.y) != 0)
  {
    coinCoord = getRandomCoordForCoin(tmap);
  }

  tmap->setTile(coinCoord.x, coinCoord.y, 3);
}

void startSpawningCoins(TileMap *tmap)
{
  while (coinHasFloor(tmap))
  {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(2000));
    spawnCoin(tmap);
  }
}
