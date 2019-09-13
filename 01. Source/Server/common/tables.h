/*--------------------------------------------------*/
/*Search:
	short	horse_skill_point;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	int		cheque;
#endif
/*--------------------------------------------------*/
/*Search:
	DWORD		price;	// PC, shop_table_ex.txt 상점에만 이용

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	DWORD		cheque;
#endif
/*--------------------------------------------------*/