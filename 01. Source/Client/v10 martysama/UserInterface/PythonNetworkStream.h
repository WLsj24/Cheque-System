/*--------------------------------------------------*/
/*Search:
	bool SendItemDropPacket(TItemPos pos, uint32_t elk);
	bool SendItemDropPacketNew(TItemPos pos, uint32_t elk, uint32_t count);

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	bool SendItemDropPacket(TItemPos pos, uint32_t elk, uint32_t cheque);
	bool SendItemDropPacketNew(TItemPos pos, uint32_t elk, uint32_t count, uint32_t cheque);
#else
	bool SendItemDropPacket(TItemPos pos, uint32_t elk);
	bool SendItemDropPacketNew(TItemPos pos, uint32_t elk, uint32_t count);
#endif
/*--------------------------------------------------*/
/*Search:
	bool SendExchangeElkAddPacket(uint32_t elk);

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	bool SendExchangeChequeAddPacket(uint32_t elk);
#endif
/*--------------------------------------------------*/