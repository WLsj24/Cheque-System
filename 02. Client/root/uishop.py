# ********************************************************************** #
#Search:
		itemPrice = shop.GetItemPrice(slotPos)

#Add after:
		if app.ENABLE_CHEQUE_SYSTEM:
			itemCheque = shop.GetItemCheque(slotPos)
# ********************************************************************** #
#Search:
		itemBuyQuestionDialog.SetText(localeInfo.DO_YOU_BUY_ITEM(itemName, itemCount, localeInfo.NumberToMoneyString(itemPrice)))

#Replace with:
		if app.ENABLE_CHEQUE_SYSTEM:
			if itemCheque > 0 and itemPrice <=0:
				itemBuyQuestionDialog.SetText(localeInfo.DO_YOU_BUY_ITEM_CHEQUE_SIN_YANG(itemName, itemCount, localeInfo.NumberToCheque(itemCheque)))
			elif itemCheque <= 0 and itemPrice > 0:
				itemBuyQuestionDialog.SetText(localeInfo.DO_YOU_BUY_ITEM(itemName, itemCount, localeInfo.NumberToGoldNotText(itemPrice)))
			elif itemCheque > 0 and itemPrice > 0:
				itemBuyQuestionDialog.SetText(localeInfo.DO_YOU_BUY_ITEM_YANG_CHEQUE(itemName, itemCount, localeInfo.NumberToGoldNotText(itemPrice),localeInfo.NumberToGoldNotText(itemCheque) ))
		else:
			itemBuyQuestionDialog.SetText(localeInfo.DO_YOU_BUY_ITEM(itemName, itemCount, localeInfo.NumberToMoneyString(itemPrice)))
# ********************************************************************** #