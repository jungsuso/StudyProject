#include "objectBox.h"

bool ObjectBox::CheckPosition(const Position movePos)
{
	// ���� �ڽ� ��ġ�� ���������� Ȯ��
	if (!IsinMapNow())
	{
		return false;
	}

	// �������� ������ ��ġ Ȯ��
	int dx = GetX() + movePos.x;
	int dy = GetY() + movePos.y;

	if (!IsinMapNow(dy, dx))
	{
		return false;
	}

	// ������ �������� ��ġ�� ������ Ȯ��
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

	// ���� �ڽ��� ��ġ
	int curX = GetX();
	int curY = GetY();

	// ���� ���ִ� ��ġ�� �� Ÿ�� ����(�ڽ��� ��ġ�� �ڸ�)
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