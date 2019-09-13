/*--------------------------------------------------*/
//Step 1
/*--------------------------------------------------*/
/*Search:
			item.itemid	= pkItem->GetID();

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
			item.cheque = pTable->cheque;
#endif
/*--------------------------------------------------*/
/*Search:
				item.price = item_table->dwGold * item.count;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
			item.cheque = 0;
#endif
/*--------------------------------------------------*/
/*Search:
			pack2.items[i].price = item.price;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		pack2.items[i].cheque = item.cheque;
#endif
/*--------------------------------------------------*/
/*Search:
	pack2.item.price	= m_itemVector[pos].price;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	pack2.item.cheque = m_itemVector[pos].cheque;
#endif
/*--------------------------------------------------*/


/*--------------------------------------------------*/
//Step 2
/*--------------------------------------------------*/
/*Search in:
int CShop::Buy(LPCHARACTER ch, BYTE pos)

This:
	if (r_item.price <= 0)
	{
		LogManager::instance().HackLog("SHOP_BUY_GOLD_OVERFLOW", ch);
		return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
	}

Add after:
*/
#ifdef ENABLE_SHOP_USE_CHEQUE
	if (r_item.cheque<0)
	{
		LogManager::instance().HackLog("SHOP_BUY_CHEQUE_OVERFLOW", ch);
		return SHOP_SUBHEADER_GC_NOT_ENOUGH_CHEQUE;
	}
#endif
/*--------------------------------------------------*/
/*Search in:
int CShop::Buy(LPCHARACTER ch, BYTE pos)

This:
	DWORD dwPrice = r_item.price;

Add after:
*/
#ifdef ENABLE_SHOP_USE_CHEQUE
	DWORD dwCheque = r_item.cheque;
#endif
/*--------------------------------------------------*/
/*Search in:
int CShop::Buy(LPCHARACTER ch, BYTE pos)

This:
	if (ch->GetGold() < (int) dwPrice)
	{
		sys_log(1, "Shop::Buy : Not enough money : %s has %d, price %d", ch->GetName(), ch->GetGold(), dwPrice);
		return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
	}

Replace with:
*/
#ifdef ENABLE_SHOP_USE_CHEQUE
	if ((int)dwPrice>0 && (int)dwCheque > 0) // Yang-Cheque
	{
		if (ch->GetGold() < (int)dwPrice || ch->GetCheque() < (int)dwCheque)
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_CHEQUE;
	}
	else if ((int)dwPrice>0 && (int)dwCheque <= 0) // Yang
	{
		if (ch->GetGold() < (int)dwPrice)
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
	}
	else if ((int)dwPrice<=0 && (int)dwCheque > 0) // cheque
	{
		if (ch->GetCheque() < (int)dwCheque)
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_CHEQUE;
	}
#else
	if (ch->GetGold() < (int) dwPrice)
	{
		sys_log(1, "Shop::Buy : Not enough money : %s has %d, price %d", ch->GetName(), ch->GetGold(), dwPrice);
		return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
	}
#endif
/*--------------------------------------------------*/
/*Search in:
int CShop::Buy(LPCHARACTER ch, BYTE pos)

This:
	ch->PointChange(POINT_GOLD, -dwPrice, false);

Add after:
*/
#ifdef ENABLE_SHOP_USE_CHEQUE
	ch->PointChange(POINT_CHEQUE, -dwCheque, false);
#endif
/*--------------------------------------------------*/