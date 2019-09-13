# ********************************************************************** #
#Search in def Refresh(self)
			if vnum == 1 or itemCount==0:
				itemCount=0
#Add after:
			if app.ENABLE_OFFLINE_SHOP_USE_CHEQUE:
				if vnum == 80020:
					itemCount=0
# ********************************************************************** #
#Search in def __ShowToolTip(self, slot):
					self.tooltipItem.AddItemData(int(it["vnum"]),it["sockets"],it["attrs"])

#Replace with:
					if app.ENABLE_OFFLINE_SHOP_USE_CHEQUE:
						if it["vnum"]==80020:
							self.tooltipItem.ClearToolTip()
							self.tooltipItem.SetTitle(localeInfo.NumberToCheque(it["count"]))
							self.tooltipItem.AppendDescription(uiScriptLocale.GIFT_MONEY_DESC, 26)
							self.tooltipItem.AppendDescription(item.GetItemSummary(), 26, 0xffBEB47D)
							self.tooltipItem.ShowToolTip()
						else:
							self.tooltipItem.AddItemData(int(it["vnum"]),it["sockets"],it["attrs"])
					else:
						self.tooltipItem.AddItemData(int(it["vnum"]),it["sockets"],it["attrs"])
# ********************************************************************** #