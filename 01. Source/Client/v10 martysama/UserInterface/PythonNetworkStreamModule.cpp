/*--------------------------------------------------*/
/*Search:
	rkNetStream.SendItemDropPacket(Cell, 0);

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	rkNetStream.SendItemDropPacket(Cell, 0, 0);
#else
	rkNetStream.SendItemDropPacket(Cell, 0);
#endif
/*--------------------------------------------------*/
/*Search:
	rkNetStream.SendItemDropPacketNew(Cell, 0, count);

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	rkNetStream.SendItemDropPacketNew(Cell, 0, count, 0);
#else
	rkNetStream.SendItemDropPacketNew(Cell, 0, count);
#endif
/*--------------------------------------------------*/
/*Search:
	rkNetStream.SendItemDropPacket(TItemPos(RESERVED_WINDOW, 0), static_cast<uint32_t>(iElk));

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	rkNetStream.SendItemDropPacket(TItemPos(RESERVED_WINDOW, 0), static_cast<uint32_t>(iElk), 0);
#else
	rkNetStream.SendItemDropPacket(TItemPos(RESERVED_WINDOW, 0), static_cast<uint32_t>(iElk));
#endif
/*--------------------------------------------------*/
/*Search:
	rkNetStream.SendItemDropPacketNew(TItemPos(RESERVED_WINDOW, 0), static_cast<uint32_t>(iElk), 0);

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	rkNetStream.SendItemDropPacketNew(TItemPos(RESERVED_WINDOW, 0), static_cast<uint32_t>(iElk), 0, 0);
#else
	rkNetStream.SendItemDropPacketNew(TItemPos(RESERVED_WINDOW, 0), static_cast<uint32_t>(iElk), 0);
#endif
/*--------------------------------------------------*/
/*Search:
PyObject * netSendGoldDropPacketNew(PyObject * poSelf, PyObject * poArgs)
{
	[...]
}

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
PyObject * netSendChequeDropPacketNew(PyObject * poSelf, PyObject * poArgs)
{
	int Cheque;
	if (!PyTuple_GetInteger(poArgs, 0, &Cheque))
		return Py_BuildException();

	CPythonNetworkStream & rkNetStream = CPythonNetworkStream::Instance();
	rkNetStream.SendItemDropPacketNew(TItemPos(RESERVED_WINDOW, 0), 0, 0, static_cast<uint32_t>(Cheque));
	return Py_BuildNone();
}
#endif
/*--------------------------------------------------*/
/*Search:
PyObject * netSendExchangeElkAddPacket(PyObject * poSelf, PyObject * poArgs)
{
	[...]
}

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
PyObject * netSendExchangeChequeAddPacket(PyObject * poSelf, PyObject * poArgs)
{
	int cheque;
	if (!PyTuple_GetInteger(poArgs, 0, &cheque))
		return Py_BuildException();

	CPythonNetworkStream& rkNetStream = CPythonNetworkStream::Instance();
	rkNetStream.SendExchangeChequeAddPacket(cheque);
	return Py_BuildNone();
}
#endif
/*--------------------------------------------------*/
/*Search:
									  {"SendGoldDropPacketNew", netSendGoldDropPacketNew, METH_VARARGS},

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
									  {"SendGoldChequePacketNew", netSendChequeDropPacketNew, METH_VARARGS},
#endif
/*--------------------------------------------------*/
/*Search:
									  {"SendExchangeElkAddPacket", netSendExchangeElkAddPacket, METH_VARARGS},

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
									  {"SendExchangeChequeAddPacket", netSendExchangeChequeAddPacket, METH_VARARGS},
#endif

/*--------------------------------------------------*/
