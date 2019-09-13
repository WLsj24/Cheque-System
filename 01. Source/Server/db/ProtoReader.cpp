/*--------------------------------------------------*/
/*Search:
		"ITEM_BELT",								//35

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		"ITEM_CHEQUE",
#endif
/*--------------------------------------------------*/
/*Search in 	static string* arSubType[]:
		0,			//34

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		0,			// 35
#endif
/*--------------------------------------------------*/
/*Search in 	static int arNumberOfSubtype[_countof(arSubType)]:
		0, // 34

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		0,	// 35
#endif
/*--------------------------------------------------*/