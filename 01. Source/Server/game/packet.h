/*--------------------------------------------------*/
/*Search in:
typedef struct command_item_drop

This:
	DWORD	gold;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	DWORD	cheque;
#endif
/*--------------------------------------------------*/
/*Search in:
typedef struct command_item_drop2

This:
	DWORD	gold;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	DWORD	cheque;
#endif
/*--------------------------------------------------*/
/*Search:
	EXCHANGE_SUBHEADER_CG_CANCEL,	/* arg1 == not used */

/*Add after:*/
#ifdef ENABLE_CHEQUE_SYSTEM
	EXCHANGE_SUBHEADER_CG_CHEQUE_ADD,
#endif
/*--------------------------------------------------*/
/*Search:
	SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_EX,

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	SHOP_SUBHEADER_GC_NOT_ENOUGH_CHEQUE,
	SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_CHEQUE,
#endif
/*--------------------------------------------------*/
/*Search:
	DWORD       price;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	DWORD	cheque;
#endif
/*--------------------------------------------------*/
/*Search:
	EXCHANGE_SUBHEADER_GC_LESS_GOLD,	/* arg1 == not used */

/*Add after:*/
#ifdef ENABLE_CHEQUE_SYSTEM
	EXCHANGE_SUBHEADER_GC_CHEQUE_ADD,
	EXCHANGE_SUBHEADER_GC_LESS_CHEQUE,
#endif
/*--------------------------------------------------*/