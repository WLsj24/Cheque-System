# ********************************************************************** #
#Search:
g_itemPriceDict={}

#Add after:
if app.ENABLE_CHEQUE_SYSTEM:
	g_itemChequeDict={}
# ********************************************************************** #
#Search:
	global g_itemPriceDict

#Add after:
	if app.ENABLE_CHEQUE_SYSTEM:
		global g_itemChequeDict
# ********************************************************************** #
#Search:
	g_itemPriceDict={}

#Add after:
	if app.ENABLE_CHEQUE_SYSTEM:
		g_itemChequeDict={}
# ********************************************************************** #
#Search:
def IsPrivateShopItemPriceList():
	[...]

#Add after:
if app.ENABLE_CHEQUE_SYSTEM:
	def IsPrivateShopItemChequeList():
		global g_itemChequeDict
		if g_itemChequeDict:
			return True
		else:
			return False
# ********************************************************************** #
#Search:
def GetPrivateShopItemPrice(itemVNum):
	[...]

#Add after:
if app.ENABLE_CHEQUE_SYSTEM:
	def SetPrivateShopItemCheque(itemVNum, itemPrice):
		global g_itemChequeDict
		g_itemChequeDict[int(itemVNum)]=itemPrice

	def GetPrivateShopItemCheque(itemVNum):
		try:
			global g_itemChequeDict
			return g_itemChequeDict[itemVNum]
		except KeyError:
			return 0
# ********************************************************************** #
#Search:
			if itemPrice>0:
				priceInputBoard.SetValue(itemPrice)

#Add after:
			if app.ENABLE_CHEQUE_SYSTEM:
				itemCheque=GetPrivateShopItemCheque(itemVNum)
				if itemCheque>0:
					priceInputBoard.SetValueCheque(itemCheque)
# ********************************************************************** #
#Search:
			text = self.priceInputBoard.GetText()

			if not text:
				return True

			if not text.isdigit():
				return True

			if int(text) <= 0:
				return True

#Replace with:
		if app.ENABLE_CHEQUE_SYSTEM:
			text = self.priceInputBoard.GetText()
			cheque = self.priceInputBoard.GetTextCheque()
			if not text:
				return
			if not text.isdigit():
				return

			if not cheque:
				return
			if not cheque.isdigit():
				return

			if int(cheque) <=0 and int(text)<=0:
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.CHEQUE_NO_ADD_SALE_PRICE)
				return
		else:
			text = self.priceInputBoard.GetText()

			if not text:
				return True

			if not text.isdigit():
				return True

			if int(text) <= 0:
				return True
# ********************************************************************** #
#Search:
			shop.AddPrivateShopItemStock(attachedInvenType, sourceSlotPos, targetSlotPos, price)

#Replace with:
		if app.ENABLE_CHEQUE_SYSTEM:
			chequep = int(self.priceInputBoard.GetTextCheque())
			if IsPrivateShopItemChequeList():
				SetPrivateShopItemCheque(self.priceInputBoard.itemVNum, chequep)
			shop.AddPrivateShopItemStock(attachedInvenType, sourceSlotPos, targetSlotPos, price, chequep)
		else:
			shop.AddPrivateShopItemStock(attachedInvenType, sourceSlotPos, targetSlotPos, price)
# ********************************************************************** #