/*--------------------------------------------------*/
/*Search:
	PyModule_AddIntConstant(poModule, "ITEM_TYPE_BELT",				CItemData::ITEM_TYPE_BELT);

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	PyModule_AddIntConstant(poModule, "ITEM_TYPE_CHEQUE", CItemData::ITEM_TYPE_CHEQUE);
#endif
/*--------------------------------------------------*/