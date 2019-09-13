/*--------------------------------------------------*/
/*Search:
		bool SendItemDropPacket(TItemPos pos, DWORD elk);
		bool SendItemDropPacketNew(TItemPos pos, DWORD elk, DWORD count);

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		bool SendItemDropPacket(TItemPos pos, DWORD elk, DWORD cheque);
		bool SendItemDropPacketNew(TItemPos pos, DWORD elk, DWORD count, DWORD cheque);
#else
		bool SendItemDropPacket(TItemPos pos, DWORD elk);
		bool SendItemDropPacketNew(TItemPos pos, DWORD elk, DWORD count);
#endif
/*--------------------------------------------------*/
/*Search:
		bool SendExchangeElkAddPacket(DWORD elk);

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		bool SendExchangeChequeAddPacket(DWORD elk);
#endif
/*--------------------------------------------------*/