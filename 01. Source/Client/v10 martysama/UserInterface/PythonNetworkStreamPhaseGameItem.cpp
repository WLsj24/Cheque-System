/*--------------------------------------------------*/
/*Search:
bool CPythonNetworkStream::SendItemDropPacket(TItemPos pos, uint32_t elk)

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
bool CPythonNetworkStream::SendItemDropPacket(TItemPos pos, uint32_t elk, uint32_t cheque)
#else
bool CPythonNetworkStream::SendItemDropPacket(TItemPos pos, uint32_t elk)
#endif
/*--------------------------------------------------*/
/*Search:
	itemDropPacket.elk = elk;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	itemDropPacket.cheque = cheque;
#endif
/*--------------------------------------------------*/
/*Search:
bool CPythonNetworkStream::SendItemDropPacketNew(TItemPos pos, uint32_t elk, uint32_t count)

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
bool CPythonNetworkStream::SendItemDropPacketNew(TItemPos pos, uint32_t elk, uint32_t count, uint32_t cheque)
#else
bool CPythonNetworkStream::SendItemDropPacketNew(TItemPos pos, uint32_t elk, uint32_t count)
#endif
/*--------------------------------------------------*/
/*Search:
	itemDropPacket.gold = elk;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	itemDropPacket.cheque = cheque;
#endif
/*--------------------------------------------------*/