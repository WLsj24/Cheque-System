/*--------------------------------------------------*/
/*Search:
bool CHARACTER::DropGold(int gold)
{
	[...]
}

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
bool CHARACTER::DropCheque(int cheque)
{
	//return false; // If you don't want to be able to drop won
	if (cheque <= 0 || cheque > GetCheque())
		return false;
	if (cheque >= CHEQUE_MAX)
		return false;
	if (!CanHandleItem())
		return false;
	LPITEM item = ITEM_MANAGER::instance().CreateItem(80020, cheque);
	if (item)
	{
		PIXEL_POSITION pos = GetXYZ();
		if (item->AddToGround(GetMapIndex(), pos))
		{
			PointChange(POINT_CHEQUE, -cheque, true);
			item->StartDestroyEvent(60);
		}
		Save();
		return true;
	}
	return false;
}
#endif
/*--------------------------------------------------*/
/*Search:
void CHARACTER::GiveGold(int iAmount)
{
	[...]
}

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
void CHARACTER::GiveCheque(int iAmount)
{
	if (iAmount <= 0)
		return;

	PointChange(POINT_CHEQUE, iAmount, true);
}
#endif
/*--------------------------------------------------*/
/*Search:
			if (item->GetType() == ITEM_ELK)
			{
				[...]
			}

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
			else if (item->GetType() == ITEM_CHEQUE)
			{
				if (item->GetCount() + GetCheque() > CHEQUE_MAX - 1)
					return false;
				GiveCheque(item->GetCount());
				item->RemoveFromGround();
				M2_DESTROY_ITEM(item);
				Save();
			}
#endif
/*--------------------------------------------------*/