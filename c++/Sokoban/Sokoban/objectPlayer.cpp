#include "objectPlayer.h"

bool ObjectPlayer::CheckPosition(const Position movePos)
{
	// 현재 플레이어의 위치가 정상적인지 확인
	if (!IsinMapNow())
	{
		return false;
	}

	// 다음으로 움직일 위치가 가능한 위치인지 확인
	int dx = GetX() + movePos.x;
	int dy = GetY() + movePos.y;

	if (!IsinMapNow(dy, dx))
		return false;

	// 다음으로 움직일 위치가 벽인지 확인
	if (map[dy][dx] == WALL)
		return false;

	// 다음으로 움직일 위치가 박스 혹은 홀 위의 박스인지 확인
	if (map[dy][dx] == BOX || map[dy][dx] == HOLEWITHBOX)
	{
		//TODO: 박스가 밀릴 수 있는 지 확인
		ObjectBox* pBox = new ObjectBox();
		pBox->SetX(dx);
		pBox->SetY(dy);
		if (!pBox->CheckPosition(movePos))
		{
			return false;
		}
		
		pBox->MovePosition(movePos);
		delete pBox;
	}

	return true;
}

void ObjectPlayer::MovePosition(const Position movePos)
{
	if (!CheckPosition(movePos))
		return;

	// 이동 가능
	int curX = GetX();
	int curY = GetY();

	// 홀 위의 플레이어가 있는 상태인지
	if (map[curY][curX] == HOLEWITHPLAYER)
		map[curY][curX] = HOLE;
	// 홀이 비어있는 상태인지
	else
		map[curY][curX] = EMPTY;

	int nextX = curX + movePos.x;
	int nextY = curY + movePos.y;

	SetX(nextX);
	SetY(nextY);

	if (map[nextY][nextX] == HOLE)
		map[nextY][nextX] = HOLEWITHPLAYER;
	else
		map[nextY][nextX] = PLAYER;

}
