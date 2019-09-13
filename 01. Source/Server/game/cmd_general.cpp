/*--------------------------------------------------*/
/*Search in :
bool GetGift(LPCHARACTER ch, DWORD id,bool all=false)

This:
			if (vnum == 1)
			{
				long long nTotalMoney = ch->GetGold()+count;
				if (GOLD_MAX <= nTotalMoney)
				{
					sys_err("[OVERFLOW_GOLD] Overflow (GOLD_MAX) id %u name %s", ch->GetPlayerID(), ch->GetName());
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("20억 냥을 초과하여 상점을 열수가 없습니다"));
					return true;
				}
				ch->PointChange(POINT_GOLD, count, false);
			}

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
			else if (vnum == 80020)
			{
				long long nTotalMoney = ch->GetCheque() + count;
				if (CHEQUE_MAX <= nTotalMoney)
				{
					sys_err("[OVERFLOW_CHEQUE] Overflow (CHEQUE_MAX) id %u name %s", ch->GetPlayerID(), ch->GetName());
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't exceed the limit of 99 won."));
					return true;
				}
				ch->PointChange(POINT_CHEQUE, count, false);
			}
#endif
/*--------------------------------------------------*/
/*Search:
ACMD(do_shop_yang)
{
	[...]
}

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
ACMD(do_shop_cheque)
{
	if (ch->IsObserverMode() || ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen() || ch->GetMyShop())
		return;
	DWORD id;
	char arg1[256];
	one_argument(argument, arg1, sizeof(arg1));
	if (!*arg1)
		return;
	str_to_number(id, arg1);
	if (*arg1)
	{
		SQLMsg * pkMsg(DBManager::instance().DirectQuery("SELECT cheque from player_shop WHERE id = %d", id));
		SQLResult * pRes = pkMsg->Get();
		if (pRes->uiNumRows>0)
		{
			MYSQL_ROW row;
			while ((row = mysql_fetch_row(pRes->pSQLResult)) != NULL)
			{
				long long gold;
				str_to_number(gold, row[0]);
				if (gold >0)
				{
					long long nTotalMoney = ch->GetCheque() + gold;
					if (CHEQUE_MAX <= nTotalMoney)
					{
						sys_err("[OVERFLOW_CHEQUE] Overflow (CHEQUE_MAX) id %u name %s", ch->GetPlayerID(), ch->GetName());
						ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't exceed the limit of 99 won."));
						return;
					}
					ch->PointChange(POINT_CHEQUE, gold, false);
					TPrivShop s = ch->GetPrivShopTable(id);
					s.gold = s.gold - gold;
					s.rest_count = s.item_count - 1;
					ch->UpdatePrivShopTable(s.shop_id, s);
					ch->SendShops();
					DBManager::instance().DirectQuery("UPDATE player_shop SET cheque=cheque - %lld WHERE id = %d", gold, id);
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("SHOP_CHEQUE_ADD"));
				}
			}
		}
	}
}
#endif
/*--------------------------------------------------*/
/*Search in :
ACMD(do_shop_update_item)

This:
		if (args.size() == 4)

Replace with:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
		if (args.size() == 5)
#else
		if (args.size() == 4)
#endif
/*--------------------------------------------------*/
/*Search in :
ACMD(do_shop_update_item)

This:
			str_to_number(price, args[3].c_str());

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
			DWORD cheque;
			str_to_number(cheque, args[4].c_str());
#endif
/*--------------------------------------------------*/
/*Search in :
ACMD(do_shop_update_item)

This:
				if (pRes->uiNumRows > 0)
					DBManager::instance().DirectQuery("UPDATE player_shop_items SET price=%lld WHERE id = %d and shop_id=%d", price, item_id, shop_id);

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
				if (pRes->uiNumRows > 0)
					DBManager::instance().DirectQuery("UPDATE player_shop_items SET cheque=%d WHERE id = %d and shop_id=%d", cheque, item_id, shop_id);
#endif
/*--------------------------------------------------*/
/*Search in :
ACMD(do_shop_update_item)

This:
		else if (args.size() == 6)

Replace with:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
		else if (args.size() == 7)
#else
		else if (args.size() == 6)
#endif
/*--------------------------------------------------*/
/*Search in :
ACMD(do_shop_update_item)

This:
			if (price <= 0)
				return;

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
			DWORD cheque;
			str_to_number(cheque, args[6].c_str());
			if (cheque < 0)
				return;
#endif
/*--------------------------------------------------*/
/*Search in :
ACMD(do_shop_update_item)

This:
				sprintf(query, "%s, price='%lld'", query, price);

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
				sprintf(query, "%s, cheque='%d'", query, cheque);
#endif
/*--------------------------------------------------*/
/*Search in :
ACMD(do_shop_refresh_items)

This:
	SQLMsg * pkMsg(DBManager::instance().DirectQuery("SELECT id,vnum,count,display_pos,price,%s,%s from player_shop_items where shop_id='%d'", szSockets, szAttrs, id));

Replace with:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
	SQLMsg * pkMsg(DBManager::instance().DirectQuery("SELECT id,vnum,count,display_pos,price,cheque,%s,%s from player_shop_items where shop_id='%d'", szSockets, szAttrs, id));
#else
	SQLMsg * pkMsg(DBManager::instance().DirectQuery("SELECT id,vnum,count,display_pos,price,%s,%s from player_shop_items where shop_id='%d'", szSockets, szAttrs, id));
#endif
/*--------------------------------------------------*/
/*Search in :
ACMD(do_shop_refresh_items)

This:
			int col = 5;

Replace with:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
			int col = 6;
#else
			int col = 5;
#endif
/*--------------------------------------------------*/
/*Search in :
ACMD(do_shop_refresh_items)

This:
			ch->ChatPacket(CHAT_TYPE_COMMAND, "shop_item %s#%s#%s#%s#%s#%s#%s", row[0], row[1], row[2], row[3], row[4], sockets, attrs);

Replace with:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
			ch->ChatPacket(CHAT_TYPE_COMMAND, "shop_item %s#%s#%s#%s#%s#%s#%s#%s", row[0], row[1], row[2], row[3], row[4], row[5], sockets, attrs);
#else
			ch->ChatPacket(CHAT_TYPE_COMMAND, "shop_item %s#%s#%s#%s#%s#%s#%s", row[0], row[1], row[2], row[3], row[4], sockets, attrs);
#endif
/*--------------------------------------------------*/