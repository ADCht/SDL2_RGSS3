#pragma once
#include <stdint.h>
#include <vector>
#include <algorithm>

class ED_Table
{
public:
	ED_Table(int x, int y = 1, int z = 1);
	ED_Table(const ED_Table& other);
	~ED_Table() { return; }

	int xSize() const { return xs; }
	int ySize() const { return ys; }
	int zSize() const { return zs; }
	
	int16_t get(int x, int y = 0, int z = 0) const;
	void set(int16_t value, int x, int y = 0, int z = 0);
	
	void resize(int x, int y, int z);
	void resize(int x, int y);
	void resize(int x);

	inline int16_t& at(int x, int y = 0, int z = 0)
	{
		return data[xs * ys * z + xs * y + x];
	}

	inline const int16_t& at(int x, int y = 0, int z = 0) const
	{
		return data[xs * ys * z + xs * y + x];
	}

private:
	int xs, ys, zs;
	std::vector<int16_t> data;
};
