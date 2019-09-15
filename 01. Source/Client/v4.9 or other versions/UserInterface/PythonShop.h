/*--------------------------------------------------*/
/*Search:
		void AddPrivateShopItemStock(TItemPos ItemPos, BYTE byDisplayPos, DWORD dwPrice);

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		void AddPrivateShopItemStock(TItemPos ItemPos, BYTE dwDisplayPos, DWORD dwPrice, DWORD);
#else
		void AddPrivateShopItemStock(TItemPos ItemPos, BYTE byDisplayPos, DWORD dwPrice);
#endif
/*--------------------------------------------------*/
/*Search:
	int GetPrivateShopItemPrice(TItemPos ItemPos);

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		int GetPrivateShopItemCheque(TItemPos ItemPos);
#endif
/*--------------------------------------------------*/
