/*--------------------------------------------------*/
/*Search:
	int64_t nTotalMoney = 0;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	int64_t nTotalCheque = 0;
#endif
/*--------------------------------------------------*/
/*Search:
		nTotalMoney += static_cast<int64_t>((pTable+n)->price);

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		nTotalCheque += static_cast<int64_t>((pTable + n)->cheque);
#endif
/*--------------------------------------------------*/
/*Search:
	nTotalMoney += static_cast<int64_t>(GetGold());

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	nTotalCheque += static_cast<int64_t>(GetCheque());
#endif
/*--------------------------------------------------*/
/*Search:
	if (GOLD_MAX <= nTotalMoney)
	{
		[...]
	}

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	if (CHEQUE_MAX <= nTotalCheque)
	{
		sys_err("[OVERFLOW_CHEQUE] Overflow (CHEQUE_MAX) id %u name %s", GetPlayerID(), GetName());
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't create a shop with more than %d won."), CHEQUE_MAX-1);
		return;
	}
#endif
/*--------------------------------------------------*/
/*Search:
	tab.skill_group	= m_points.skill_group;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	tab.cheque		= GetCheque();
#endif
/*--------------------------------------------------*/
/*Search:
	GetDesc()->Packet(&pack, sizeof(TPacketGCPoints));

Add BEFORE:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	pack.points[POINT_CHEQUE] = GetCheque();
#endif
/*--------------------------------------------------*/
/*Search:
	SetGold(t->gold);

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	SetCheque(t->cheque);
#endif
/*--------------------------------------------------*/
/*Search:
	long lSPRecovery = GetPoint(POINT_SP_RECOVERY);

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	int iCheque = GetPoint(POINT_CHEQUE);
#endif
/*--------------------------------------------------*/
/*Search:
	SetPoint(POINT_PC_BANG_DROP_BONUS, 0);
	// END_PC_BANG_ITEM_ADD

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	SetPoint(POINT_CHEQUE, iCheque);
#endif
/*--------------------------------------------------*/
/*Search:
		case POINT_GOLD:
			{
				[...]
			}
			break;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		case POINT_CHEQUE:
			{
				const int64_t nTotalCheque = static_cast<int64_t>(GetCheque()) + static_cast<int64_t>(amount);
				if (CHEQUE_MAX <= nTotalCheque)
				{
					sys_err("[OVERFLOW_CHEQUE] OriCheque %d AddedCheque %d id %u Name %s ", GetCheque(), amount, GetPlayerID(), GetName());
					LogManager::instance().CharLog(this, GetCheque() + amount, "OVERFLOW_CHEQUE", "");
					return;
				}
				SetCheque(GetCheque() + amount);
				val = GetCheque();
			}
			break;
#endif
/*--------------------------------------------------*/
/*--------------------------------------------------*/
/*--------------------------------------------------*/
/*Search in:
void CHARACTER::OpenMyShop(const char * c_pszSign, TShopItemTable * pTable, BYTE bItemCount, DWORD id)

This:
	int64_t nTotalMoney = 0;

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
	int64_t nTotalCheque = 0;
#endif
/*--------------------------------------------------*/
/*Search in:
void CHARACTER::OpenMyShop(const char * c_pszSign, TShopItemTable * pTable, BYTE bItemCount, DWORD id)

This:
		nTotalMoney += static_cast<int64_t> ((pTable + n)->price);

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
		nTotalCheque += static_cast<int64_t>((pTable + n)->cheque);
#endif
/*--------------------------------------------------*/
/*Search in:
void CHARACTER::OpenMyShop(const char * c_pszSign, TShopItemTable * pTable, BYTE bItemCount, DWORD id)

This:
	nTotalMoney += static_cast<int64_t> (GetGold());

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
	nTotalCheque += static_cast<int64_t>(GetCheque());
#endif
/*--------------------------------------------------*/
/*Search in:
void CHARACTER::OpenMyShop(const char * c_pszSign, TShopItemTable * pTable, BYTE bItemCount, DWORD id)

This:
	if (GOLD_MAX <= nTotalMoney)
	{
		sys_err("[OVERFLOW_GOLD] Overflow (GOLD_MAX) id %u name %s", GetPlayerID(), GetName());
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("20억 냥을 초과하여 상점을 열수가 없습니다"));
		return;
	}

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
	if (CHEQUE_MAX <= nTotalCheque)
	{
		sys_err("[OVERFLOW_GOLD] Overflow (GOLD_MAX) id %u name %s", GetPlayerID(), GetName());
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't create a shop with more than %d won."), CHEQUE_MAX-1);
		return;
	}
#endif
/*--------------------------------------------------*/
/*Search in:
void CHARACTER::UpdateShopItems()

This:
	SQLMsg * Msg(DBManager::instance().DirectQuery("SELECT id,vnum,count,display_pos,price,%s,%s from player_shop_items where shop_id='%d'", szSockets, szAttrs, GetPrivShop()));

Replace with:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
	SQLMsg * Msg(DBManager::instance().DirectQuery("SELECT id,vnum,count,display_pos,price,cheque,%s,%s from player_shop_items where shop_id='%d'", szSockets, szAttrs, GetPrivShop()));
#else
	SQLMsg * Msg(DBManager::instance().DirectQuery("SELECT id,vnum,count,display_pos,price,%s,%s from player_shop_items where shop_id='%d'", szSockets, szAttrs, GetPrivShop()));
#endif
/*--------------------------------------------------*/
/*Search in:
void CHARACTER::UpdateShopItems()

This:
			str_to_number(shop->price, row[col++]);

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
			str_to_number(shop->cheque, row[col++]);
#endif
/*--------------------------------------------------*/
/*Search in:
void CHARACTER::LoadPrivShops()

This:
	SQLMsg * pkMsg(DBManager::instance().DirectQuery("SELECT id,shop_vid,replace(replace(name,' ','\\\\'),'#','_'),gold,item_count,(select count(id) from player_shop_items where shop_id=player_shop.id),DATEDIFF(date_close,now()) AS days,UNIX_TIMESTAMP(date_close) from player_shop WHERE player_id=%d", GetPlayerID()));

Replace with:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
	SQLMsg * pkMsg(DBManager::instance().DirectQuery("SELECT id,shop_vid,replace(replace(name,' ','\\\\'),'#','_'),gold,cheque,item_count,(select count(id) from player_shop_items where shop_id=player_shop.id),DATEDIFF(date_close,now()) AS days,UNIX_TIMESTAMP(date_close) from player_shop WHERE player_id=%d", GetPlayerID()));
#else
	SQLMsg * pkMsg(DBManager::instance().DirectQuery("SELECT id,shop_vid,replace(replace(name,' ','\\\\'),'#','_'),gold,item_count,(select count(id) from player_shop_items where shop_id=player_shop.id),DATEDIFF(date_close,now()) AS days,UNIX_TIMESTAMP(date_close) from player_shop WHERE player_id=%d", GetPlayerID()));
#endif
/*--------------------------------------------------*/
/*Search in:
void CHARACTER::LoadPrivShops()

This:
			str_to_number(shop.gold, row[col++]);

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
			str_to_number(shop.cheque, row[col++]);
#endif
/*--------------------------------------------------*/
/*Search in:
void CHARACTER::SendShops(bool isGm)

This:
		ChatPacket(CHAT_TYPE_COMMAND, "shop_add %d %d %s %lld %d %d %d %d", it->second.shop_id, it->second.shop_vid, it->second.szSign, it->second.gold, it->second.item_count, it->second.rest_count, it->second.days, it->second.date_close);

Replace with:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
		ChatPacket(CHAT_TYPE_COMMAND, "shop_add %d %d %s %lld %d %d %d %d %d", it->second.shop_id, it->second.shop_vid, it->second.szSign, it->second.gold, it->second.item_count, it->second.rest_count, it->second.days, it->second.date_close, it->second.cheque);
#else
		ChatPacket(CHAT_TYPE_COMMAND, "shop_add %d %d %s %lld %d %d %d %d", it->second.shop_id, it->second.shop_vid, it->second.szSign, it->second.gold, it->second.item_count, it->second.rest_count, it->second.days, it->second.date_close);
#endif
/*--------------------------------------------------*/
/*Search in:
void CHARACTER::OpenShop(DWORD id, const char *name, bool onboot)

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
/*Search in:
void CHARACTER::OpenShop(DWORD id, const char *name, bool onboot)

This:
			str_to_number(shop->price, row[col++]);

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
			str_to_number(shop->cheque, row[col++]);
#endif
/*--------------------------------------------------*/
/*Search in:
void CHARACTER::DeleteMyShop()

This:
		SQLMsg * pkMsg(DBManager::instance().DirectQuery("SELECT gold FROM player_shop where id='%d'", GetPrivShop()));

Replace with:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
		SQLMsg * pkMsg(DBManager::instance().DirectQuery("SELECT gold, cheque FROM player_shop where id='%d'", GetPrivShop()));
#else
		SQLMsg * pkMsg(DBManager::instance().DirectQuery("SELECT gold FROM player_shop where id='%d'", GetPrivShop()));
#endif
/*--------------------------------------------------*/
/*Search in:
void CHARACTER::DeleteMyShop()

This:
				if (gold>0)
				{
					char query[1024];
					sprintf(query, "INSERT INTO player_gift SET \
					owner_id=%d,vnum=1,count='%s',reason=\"%s\",`from`=replace(\"%s\",' ','_'),status='WAIT',date_add=NOW()",
					GetPrivShopOwner(), row[0], LC_TEXT("SHOP_REASON"), GetName());
					DBManager::instance().DirectQuery(query);
				}

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
				DWORD dwCheque;
				str_to_number(dwCheque, row[1]);
				if (dwCheque>0)
				{
					char query[1024];
					sprintf(query, "INSERT INTO player_gift SET \
													owner_id=%d,vnum=80020,count='%s',reason=\"%s\",`from`=replace(\"%s\",' ','_'),status='WAIT',date_add=NOW()",
													GetPrivShopOwner(), row[1], LC_TEXT("SHOP_REASON"), GetName());
					DBManager::instance().DirectQuery(query);
				}
#endif
/*--------------------------------------------------*/