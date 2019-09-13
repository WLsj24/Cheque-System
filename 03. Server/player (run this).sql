/*--------------------------------------------------*/
/* 1. Run this: */
ALTER TABLE `player`
ADD COLUMN `cheque` int(11) NOT NULL DEFAULT 0 COMMENT 'ENABLE_CHEQUE_SYSTEM' AFTER `horse_skill_point`;
ALTER TABLE `player_deleted`
ADD COLUMN `cheque` int(11) NOT NULL DEFAULT 0 COMMENT 'ENABLE_CHEQUE_SYSTEM' AFTER `horse_skill_point`;
/*--------------------------------------------------*/
/* 2. Run this: */
ALTER TABLE `player_shop`
ADD COLUMN `cheque` int(11) NOT NULL DEFAULT 0 COMMENT 'ENABLE_OFFLINE_SHOP_USE_CHEQUE' AFTER `channel`;
ALTER TABLE `player_shop_items`
ADD COLUMN `cheque` int(11) NOT NULL DEFAULT 0 COMMENT 'ENABLE_OFFLINE_SHOP_USE_CHEQUE' AFTER `price`;
/*--------------------------------------------------*/