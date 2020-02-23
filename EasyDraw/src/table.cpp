#include "table.h"

ED_Table::ED_Table(int x, int y /*= 1*/, int z /*= 1*/)
	: xs(x), ys(y), zs(z),
	data(x* y* z)
{
	return;
}

ED_Table::ED_Table(const ED_Table& other)
	: xs(other.xs), ys(other.ys), zs(other.zs),
	data(other.data)
{
	return;
}

int16_t ED_Table::get(int x, int y, int z) const
{
	return data[xs * ys * z + xs * y + x];
}

void ED_Table::set(int16_t value, int x, int y, int z)
{
	if (x < 0 || x >= xs
		|| y < 0 || y >= ys
		|| z < 0 || z >= zs)
	{
		return;
	}

	data[xs * ys * z + xs * y + x] = value;
}

void ED_Table::resize(int x, int y, int z)
{
	if (x == xs && y == ys && z == zs)
		return;

	std::vector<int16_t> newData(x * y * z);

	for (int k = 0; k < std::min(z, zs); ++k)
		for (int j = 0; j < std::min(y, ys); ++j)
			for (int i = 0; i < std::min(x, xs); ++i)
				newData[x * y * k + x * j + i] = at(i, j, k);

	data.swap(newData);

	xs = x;
	ys = y;
	zs = z;

	return;
}

void ED_Table::resize(int x, int y)
{
	resize(x, y, zs);
}

void ED_Table::resize(int x)
{
	resize(x, ys, zs);
}
