/*--------------------------------------------------*/
/*Search:
bool CPythonNetworkStream::SendItemDropPacket(TItemPos pos, DWORD elk)

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
bool CPythonNetworkStream::SendItemDropPacket(TItemPos pos, DWORD elk, DWORD cheque)
#else
bool CPythonNetworkStream::SendItemDropPacket(TItemPos pos, DWORD elk)
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
bool CPythonNetworkStream::SendItemDropPacketNew(TItemPos pos, DWORD elk, DWORD count)

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
bool CPythonNetworkStream::SendItemDropPacketNew(TItemPos pos, DWORD elk, DWORD count, DWORD cheque)
#else
bool CPythonNetworkStream::SendItemDropPacketNew(TItemPos pos, DWORD elk, DWORD count)
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