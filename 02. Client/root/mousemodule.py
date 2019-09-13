# ********************************************************************** #
#Search:
	def AttachMoney(self, owner, type, count):
		[...]

#Add after:
	if app.ENABLE_CHEQUE_SYSTEM:
		def AttacCheque(self, owner, type, count):
			self.LastAttachedSlotNumber = self.AttachedSlotNumber
			self.AttachedFlag = True
			self.AttachedOwner = owner
			self.AttachedType = type
			self.AttachedSlotNumber = -2
			self.AttachedItemIndex = player.ITEM_CHEQUE
			self.AttachedCount = count
			self.AttachedIconHandle = grpImage.Generate("icon/item/80020.tga")
			self.AttachedIconHalfWidth = grpImage.GetWidth(self.AttachedIconHandle) / 2
			self.AttachedIconHalfHeight = grpImage.GetHeight(self.AttachedIconHandle) / 2
			wndMgr.AttachIcon(self.AttachedType, self.AttachedItemIndex, self.AttachedSlotNumber, 1, 1)
			if count > 1:
				self.countNumberLine.SetNumber(str(count))
				self.countNumberLine.Show()
			#grpText.SetText(self.AttachedCountTextLineHandle, str(count))
# ********************************************************************** #