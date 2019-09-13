/*--------------------------------------------------*/
/*Search:
	int pc_get_money(lua_State * L)
	{
		lua_pushnumber(L, CQuestManager::instance().GetCurrentCharacterPtr()->GetGold());
		return 1;
	}

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	int pc_get_cheque(lua_State *L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
		lua_pushnumber(L, ch->GetCheque());
		return 1;
	}
	int pc_set_cheque(lua_State *L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
		if (lua_isnumber(L, 1))
			ch->PointChange(POINT_CHEQUE, lua_tonumber(L, 1));

		return 1;
	}
#endif
/*--------------------------------------------------*/
/*Search:
			{ "get_gold",		pc_get_money		},

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
			{ "set_cheque", pc_set_cheque },
			{ "get_cheque", pc_get_cheque },
#endif
/*--------------------------------------------------*/