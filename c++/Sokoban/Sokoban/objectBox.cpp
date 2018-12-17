#include "objectBox.h"

bool ObjectBox::CheckPosition(const Position movePos)
{
	// 현재 박스 위치가 정상적인지 확인
	if (!IsinMapNow())
	{
		return false;
	}

	// 다음으로 움직일 위치 확인
	int dx = GetX() + movePos.x;
	int dy = GetY() + movePos.y;

	if (!IsinMapNow(dy, dx))
	{
		return false;
	}

	// 다음에 움직여질 위치가 벽인지 확인
	if (map[dy][dx] == WALL)
	{
		return false;
	}

	if (map[dy][dx] == BOX || map[dy][dx] == HOLEWITHBOX)
	{
		return false;
	}

	return true;
}

void ObjectBox::MovePosition(const Position movePos)
{
	if (!CheckPosition(movePos))
	{
		return;
	}

	// 현재 박스의 위치
	int curX = GetX();
	int curY = GetY();

	// 현재 서있는 위치의 맵 타입 변경(박스가 위치한 자리)
	if (map[curY][curX] == HOLEWITHBOX)
	{
		map[curY][curX] = HOLE;
	}
	else
	{
		map[curY][curX] = EMPTY;
	}

	int nextX = curX + movePos.x;
	int nextY = curY + movePos.y;

	if (map[nextY][nextX] == HOLE)
	{
		map[nextY][nextX] = HOLEWITHBOX;
	}
	else
	{
		map[nextY][nextX] = BOX;
	}
}