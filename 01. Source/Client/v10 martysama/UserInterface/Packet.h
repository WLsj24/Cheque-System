/*--------------------------------------------------*/
/*Search in:
typedef struct command_item_drop

This:
	uint32_t elk;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	uint32_t cheque;
#endif
/*--------------------------------------------------*/
/*Search in:
typedef struct command_item_drop2
	uint32_t gold;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	uint32_t cheque;
#endif
/*--------------------------------------------------*/
/*Search:
	EXCHANGE_SUBHEADER_CG_CANCEL, // arg1 == not used

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	EXCHANGE_SUBHEADER_CG_CHEQUE_ADD,
#endif
/*--------------------------------------------------*/
/*Search in:
typedef struct SShopItemTable

This:
	uint32_t price; // PC 상점에만 이용

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	uint32_t cheque;
#endif
/*--------------------------------------------------*/
/*Search:
	POINT_ENERGY_END_TIME = 129, // 129 기력 종료 시간

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	POINT_CHEQUE = 145, // Check if "145" is not been used for other
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
	EXCHANGE_SUBHEADER_GC_LESS_ELK, // arg1 == not used

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	EXCHANGE_SUBHEADER_GC_CHEQUE_ADD,
	EXCHANGE_SUBHEADER_GC_LESS_CHEQUE,
#endif
/*--------------------------------------------------*/