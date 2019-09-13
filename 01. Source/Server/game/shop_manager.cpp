/*--------------------------------------------------*/
/*Search in :
bool CShopManager::CreateOfflineShop(LPCHARACTER owner, const char *szSign, const std::vector<TShopItemTable *> pTable, DWORD id)

This:
				sprintf(query, "%s, price='%d'", query, pTable[i]->price);

Add after:
*/
#ifdef ENABLE_OFFLINE_SHOP_USE_CHEQUE
				sprintf(query, "%s, cheque='%d'", query, pTable[i]->cheque);
#endif
/*--------------------------------------------------*/