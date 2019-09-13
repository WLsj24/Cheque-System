/*--------------------------------------------------*/
/*Search:
	if (item->GetType() == ITEM_ELK)
		item->SetSkipSave(true);

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	else if (item->GetType() == ITEM_CHEQUE)
		item->SetSkipSave(true);
#endif
/*--------------------------------------------------*/
/*Search:
	if (item->GetType() == ITEM_ELK) // 돈은 아무 처리가 필요하지 않음
		;

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	if (item->GetType() == ITEM_ELK || item->GetType() == ITEM_CHEQUE)
		;
#else
	if (item->GetType() == ITEM_ELK) // 돈은 아무 처리가 필요하지 않음
		;
#endif
/*--------------------------------------------------*/