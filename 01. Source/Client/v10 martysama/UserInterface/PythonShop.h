/*--------------------------------------------------*/
/*Search:
	void AddPrivateShopItemStock(TItemPos ItemPos, uint8_t dwDisplayPos, uint32_t dwPrice);

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	void AddPrivateShopItemStock(TItemPos ItemPos, uint8_t dwDisplayPos, uint32_t dwPrice, uint32_t);
#else
	void AddPrivateShopItemStock(TItemPos ItemPos, uint8_t dwDisplayPos, uint32_t dwPrice);
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
