/*--------------------------------------------------*/
/*Search:
			"horse_skill_point = %d, "

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
			"cheque = %d, "
#endif
/*--------------------------------------------------*/
/*Search:
		pkTab->horse_skill_point

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		, pkTab->cheque
#endif
/*--------------------------------------------------*/
/*Search in:
void CClientManager::QUERY_PLAYER_LOAD(CPeer * peer, DWORD dwHandle, TPlayerLoadPacket * packet)

This:
												"horse_skill_point "

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
												", cheque "
#endif
/*--------------------------------------------------*/
/*Search:
	str_to_number(pkTab->horse_skill_point, row[col++]);

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	str_to_number(pkTab->cheque, row[col++]);
#endif
/*--------------------------------------------------*/