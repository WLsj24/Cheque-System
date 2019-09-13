/*--------------------------------------------------*/
/*Search:
	"ITEM_BELT",								//35

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	"ITEM_CHEQUE",
#endif
/*--------------------------------------------------*/
/*Search in string* arIAFVSubType[] = {0,	//0:
	0, // 34

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	0, // 35 cheque
#endif
/*--------------------------------------------------*/
/*Search in int arNumberOfSubtype[] =:
	0, //34

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	0, // 35
#endif
/*--------------------------------------------------*/